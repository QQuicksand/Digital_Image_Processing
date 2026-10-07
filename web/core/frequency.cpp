// Fourier transform, frequency-domain filters and restoration (project 04).
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

#include "dip.hpp"

namespace dip {

namespace {

using cplx = std::complex<double>;
constexpr double kPi = 3.14159265358979323846;

int nextPow2(int n) {
    int p = 1;
    while (p < n) p <<= 1;
    return p;
}

// In-place iterative radix-2 FFT on `n` elements spaced `stride` apart.
void fft1d(cplx* data, int n, int stride, bool inverse) {
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) std::swap(data[i * stride], data[j * stride]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * kPi / len * (inverse ? 1 : -1);
        cplx wl(std::cos(ang), std::sin(ang));
        for (int i = 0; i < n; i += len) {
            cplx w(1);
            for (int k = 0; k < len / 2; ++k) {
                cplx u = data[(i + k) * stride];
                cplx v = data[(i + k + len / 2) * stride] * w;
                data[(i + k) * stride] = u + v;
                data[(i + k + len / 2) * stride] = u - v;
                w *= wl;
            }
        }
    }
    if (inverse)
        for (int i = 0; i < n; ++i) data[i * stride] /= n;
}

// Complex field of power-of-two size P x Q.
struct Field {
    int P, Q;  // width, height
    std::vector<cplx> v;

    Field(int P, int Q) : P(P), Q(Q), v(size_t(P) * Q) {}
    cplx& at(int x, int y) { return v[size_t(y) * P + x]; }

    void fft(bool inverse) {
        for (int y = 0; y < Q; ++y) fft1d(&v[size_t(y) * P], P, 1, inverse);
        for (int x = 0; x < P; ++x) fft1d(&v[x], Q, P, inverse);
    }
};

// Pad to a power-of-two field, with zeros or (`replicate`) by repeating the
// edge pixels. With `center`, multiply by (-1)^(x+y) so the zero frequency
// lands in the middle of the spectrum.
Field toField(const std::vector<double>& img, int w, int h, bool center,
              bool replicate = false) {
    Field f(nextPow2(w), nextPow2(h));
    int fw = replicate ? f.P : w, fh = replicate ? f.Q : h;
    for (int y = 0; y < fh; ++y)
        for (int x = 0; x < fw; ++x) {
            double v = img[size_t(std::min(y, h - 1)) * w + std::min(x, w - 1)];
            f.at(x, y) = center && ((x + y) & 1) ? -v : v;
        }
    return f;
}

std::vector<double> toDoubles(const Gray& g) { return {g.px.begin(), g.px.end()}; }

// Real part of the (un-centred) field, cropped to w x h.
std::vector<double> realPart(Field& f, int w, int h, bool center) {
    std::vector<double> out(size_t(w) * h);
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x) {
            double v = f.at(x, y).real();
            out[size_t(y) * w + x] = center && ((x + y) & 1) ? -v : v;
        }
    return out;
}

// Linear stretch to 0..255. `clip` ignores that fraction of outliers at each
// end (0 = plain min-max).
Gray normalize(const std::vector<double>& v, int w, int h, double clip = 0.0) {
    double lo, hi;
    if (clip > 0) {
        std::vector<double> sorted(v);
        size_t k = size_t(clip * (sorted.size() - 1));
        std::nth_element(sorted.begin(), sorted.begin() + k, sorted.end());
        lo = sorted[k];
        std::nth_element(sorted.begin(), sorted.end() - 1 - k, sorted.end());
        hi = sorted[sorted.size() - 1 - k];
    } else {
        auto [mn, mx] = std::minmax_element(v.begin(), v.end());
        lo = *mn;
        hi = *mx;
    }
    double range = hi - lo;
    Gray out(w, h);
    for (size_t i = 0; i < v.size(); ++i)
        out.px[i] = range > 1e-12 ? clamp8((v[i] - lo) * 255.0 / range) : 0;
    return out;
}

Gray clampToGray(const std::vector<double>& v, int w, int h) {
    Gray out(w, h);
    for (size_t i = 0; i < v.size(); ++i) out.px[i] = clamp8(v[i]);
    return out;
}

// Distance of (x, y) from the centre of a centred P x Q spectrum.
inline double centredDistance(int x, int y, int P, int Q) {
    return std::hypot(x - P / 2.0, y - Q / 2.0);
}

}  // namespace

Spectrum fourierSpectrum(const Gray& g) {
    Field f = toField(toDoubles(g), g.w, g.h, true);
    f.fft(false);

    // YNEW = G * [log(1+|F|) - FMIN] / [FMAX - FMIN] with G = 255.
    std::vector<double> mag(f.v.size()), phase(f.v.size());
    for (size_t i = 0; i < f.v.size(); ++i) {
        mag[i] = std::log1p(std::abs(f.v[i]));
        phase[i] = std::arg(f.v[i]);
    }
    Spectrum s;
    s.magnitude = normalize(mag, f.P, f.Q);
    s.phase = normalize(phase, f.P, f.Q);

    f.fft(true);
    s.inverse = clampToGray(realPart(f, g.w, g.h, true), g.w, g.h);
    return s;
}

Gray frequencyFilter(const Gray& g, FilterShape shape, double cutoff, bool highpass,
                     int order) {
    cutoff = std::max(cutoff, 1e-3);
    Field f = toField(toDoubles(g), g.w, g.h, true, true);
    f.fft(false);
    for (int y = 0; y < f.Q; ++y)
        for (int x = 0; x < f.P; ++x) {
            double D = centredDistance(x, y, f.P, f.Q);
            double low = 0;
            switch (shape) {
                case FilterShape::Ideal: low = D <= cutoff ? 1.0 : 0.0; break;
                case FilterShape::Butterworth:
                    low = 1.0 / (1.0 + std::pow(D / cutoff, 2.0 * order));
                    break;
                case FilterShape::Gaussian:
                    low = std::exp(-(D * D) / (2 * cutoff * cutoff));
                    break;
            }
            f.at(x, y) *= highpass ? 1.0 - low : low;
        }
    f.fft(true);
    std::vector<double> out = realPart(f, g.w, g.h, true);
    if (!highpass) return clampToGray(out, g.w, g.h);
    for (double& v : out) v = std::abs(v);
    return normalize(out, g.w, g.h);
}

Gray homomorphicFilter(const Gray& g, double gammaH, double gammaL, double D0, double c) {
    D0 = std::max(D0, 1e-3);
    std::vector<double> logImg(g.px.size());
    for (size_t i = 0; i < g.px.size(); ++i) logImg[i] = std::log1p(double(g.px[i]));

    Field f = toField(logImg, g.w, g.h, true, true);
    f.fft(false);
    for (int y = 0; y < f.Q; ++y)
        for (int x = 0; x < f.P; ++x) {
            double D = centredDistance(x, y, f.P, f.Q);
            double H = (gammaH - gammaL) * (1 - std::exp(-c * D * D / (D0 * D0))) + gammaL;
            f.at(x, y) *= H;
        }
    f.fft(true);
    std::vector<double> out = realPart(f, g.w, g.h, true);
    for (double& v : out) v = std::expm1(v);
    return normalize(out, g.w, g.h, 0.005);
}

RestoreResult motionBlurRestore(const Gray& g, double length, double angleDeg,
                                double noiseSigma, Restoration method, double param) {
    int P = nextPow2(g.w), Q = nextPow2(g.h);

    // Pad by edge replication so the circular blur has no hard seams.
    Field F = toField(toDoubles(g), g.w, g.h, false, true);
    F.fft(false);

    // Point-spread function: a line segment through the origin (wrapped).
    Field H(P, Q);
    length = std::max(1.0, length);
    double a = angleDeg * kPi / 180.0;
    int steps = std::max(1, int(std::ceil(length * 4)));
    for (int i = 0; i < steps; ++i) {
        double t = (steps == 1 ? 0.0 : double(i) / (steps - 1) - 0.5) * (length - 1);
        int x = int(std::lround(t * std::cos(a))), y = int(std::lround(-t * std::sin(a)));
        H.at(((x % P) + P) % P, ((y % Q) + Q) % Q) += 1.0 / steps;
    }
    H.fft(false);

    // Blurred image G = F H (+ noise).
    Field G(P, Q);
    for (size_t i = 0; i < G.v.size(); ++i) G.v[i] = F.v[i] * H.v[i];
    G.fft(true);
    std::mt19937 rng(1234);
    std::normal_distribution<double> noise(0.0, std::max(noiseSigma, 1e-9));
    std::vector<double> blurred(size_t(P) * Q);
    for (size_t i = 0; i < G.v.size(); ++i) {
        blurred[i] = G.v[i].real() + (noiseSigma > 0 ? noise(rng) : 0.0);
        G.v[i] = blurred[i];
    }
    G.fft(false);

    // Restore.
    for (int y = 0; y < Q; ++y)
        for (int x = 0; x < P; ++x) {
            cplx h = H.at(x, y), gv = G.at(x, y);
            cplx est;
            if (method == Restoration::Inverse) {
                double du = std::min(x, P - x), dv = std::min(y, Q - y);
                bool inside = param <= 0 || std::hypot(du, dv) <= param;
                est = inside && std::abs(h) > 1e-3 ? gv / h : (inside ? gv : cplx(0));
            } else {
                double h2 = std::norm(h);
                est = std::conj(h) / (h2 + std::max(param, 0.0)) * gv;
            }
            G.at(x, y) = est;
        }
    G.fft(true);

    RestoreResult r;
    r.blurred = Gray(g.w, g.h);
    r.restored = Gray(g.w, g.h);
    for (int y = 0; y < g.h; ++y)
        for (int x = 0; x < g.w; ++x) {
            r.blurred.at(x, y) = clamp8(blurred[size_t(y) * P + x]);
            r.restored.at(x, y) = clamp8(G.at(x, y).real());
        }
    return r;
}

}  // namespace dip
