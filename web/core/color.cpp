// Color models, pseudo-color and k-means segmentation (project 05).
#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <random>

#include "dip.hpp"

namespace dip {

namespace {

constexpr double kPi = 3.14159265358979323846;
using Vec3 = std::array<double, 3>;

// ---- RGB (0..1) <-> HSI: H in degrees [0, 360), S and I in [0, 1].
Vec3 rgbToHsi(double r, double g, double b) {
    double i = (r + g + b) / 3.0;
    double mn = std::min({r, g, b});
    double s = i > 0 ? 1.0 - mn / i : 0.0;
    double h = 0;
    if (s > 1e-9) {
        double num = 0.5 * ((r - g) + (r - b));
        double den = std::sqrt((r - g) * (r - g) + (r - b) * (g - b)) + 1e-10;
        h = std::acos(std::clamp(num / den, -1.0, 1.0)) * 180.0 / kPi;
        if (b > g) h = 360.0 - h;
    }
    return {h, s, i};
}

Vec3 hsiToRgb(double h, double s, double i) {
    h = std::fmod(std::fmod(h, 360.0) + 360.0, 360.0);
    auto part = [&](double hh) {  // hh in [0, 120)
        double rad = hh * kPi / 180.0;
        double a = i * (1 - s);
        double b = i * (1 + s * std::cos(rad) / std::cos(kPi / 3 - rad));
        return std::pair<double, double>{a, b};
    };
    double r, g, b;
    if (h < 120) {
        auto [lo, hi] = part(h);
        b = lo; r = hi; g = 3 * i - (r + b);
    } else if (h < 240) {
        auto [lo, hi] = part(h - 120);
        r = lo; g = hi; b = 3 * i - (r + g);
    } else {
        auto [lo, hi] = part(h - 240);
        g = lo; b = hi; r = 3 * i - (g + b);
    }
    return {std::clamp(r, 0.0, 1.0), std::clamp(g, 0.0, 1.0), std::clamp(b, 0.0, 1.0)};
}

// ---- sRGB (0..1) <-> XYZ (0..100) <-> CIE L*a*b* (D65).
constexpr double kXn = 95.047, kYn = 100.0, kZn = 108.883;

double toLinear(double c) { return c > 0.04045 ? std::pow((c + 0.055) / 1.055, 2.4) : c / 12.92; }
double toGamma(double c) {
    c = std::clamp(c, 0.0, 1.0);
    return c > 0.0031308 ? 1.055 * std::pow(c, 1 / 2.4) - 0.055 : 12.92 * c;
}

Vec3 rgbToXyz(double r, double g, double b) {
    r = toLinear(r) * 100; g = toLinear(g) * 100; b = toLinear(b) * 100;
    return {r * 0.4124564 + g * 0.3575761 + b * 0.1804375,
            r * 0.2126729 + g * 0.7151522 + b * 0.0721750,
            r * 0.0193339 + g * 0.1191920 + b * 0.9503041};
}

Vec3 xyzToRgb(double X, double Y, double Z) {
    X /= 100; Y /= 100; Z /= 100;
    return {toGamma(X * 3.2404542 - Y * 1.5371385 - Z * 0.4985314),
            toGamma(-X * 0.9692660 + Y * 1.8760108 + Z * 0.0415560),
            toGamma(X * 0.0556434 - Y * 0.2040259 + Z * 1.0572252)};
}

double labF(double t) { return t > 0.008856 ? std::cbrt(t) : (903.3 * t + 16.0) / 116.0; }
double labFInv(double t) { return t * t * t > 0.008856 ? t * t * t : (116.0 * t - 16.0) / 903.3; }

Vec3 rgbToLab(double r, double g, double b) {
    Vec3 xyz = rgbToXyz(r, g, b);
    double fx = labF(xyz[0] / kXn), fy = labF(xyz[1] / kYn), fz = labF(xyz[2] / kZn);
    return {116.0 * fy - 16.0, 500.0 * (fx - fy), 200.0 * (fy - fz)};
}

Vec3 labToRgb(double L, double a, double b) {
    double fy = (L + 16.0) / 116.0, fx = fy + a / 500.0, fz = fy - b / 200.0;
    return xyzToRgb(labFInv(fx) * kXn, labFInv(fy) * kYn, labFInv(fz) * kZn);
}

template <typename Fn>
Rgba mapPixels(const Rgba& im, Fn fn) {
    Rgba out(im.w, im.h);
    for (size_t i = 0; i < size_t(im.w) * im.h; ++i) {
        const uint8_t* p = &im.px[i * 4];
        Vec3 v = fn(p[0] / 255.0, p[1] / 255.0, p[2] / 255.0);
        for (int c = 0; c < 3; ++c) out.px[i * 4 + c] = clamp8(v[c]);
        out.px[i * 4 + 3] = 255;
    }
    return out;
}

}  // namespace

Rgba toCMY(const Rgba& im) {
    return mapPixels(im, [](double r, double g, double b) {
        return Vec3{255 * (1 - r), 255 * (1 - g), 255 * (1 - b)};
    });
}

Rgba toHSI(const Rgba& im) {
    return mapPixels(im, [](double r, double g, double b) {
        Vec3 h = rgbToHsi(r, g, b);
        return Vec3{h[0] / 360.0 * 255.0, h[1] * 255.0, h[2] * 255.0};
    });
}

Rgba toXYZ(const Rgba& im) {
    return mapPixels(im, [](double r, double g, double b) {
        Vec3 x = rgbToXyz(r, g, b);
        return Vec3{x[0] * 2.55, x[1] * 2.55, x[2] * 2.55};
    });
}

Rgba toLab(const Rgba& im) {
    return mapPixels(im, [](double r, double g, double b) {
        Vec3 l = rgbToLab(r, g, b);
        return Vec3{l[0] * 2.55, l[1] + 128.0, l[2] + 128.0};
    });
}

Rgba toYUV(const Rgba& im) {
    return mapPixels(im, [](double r, double g, double b) {
        r *= 255; g *= 255; b *= 255;
        return Vec3{0.299 * r + 0.587 * g + 0.114 * b,
                    -0.169 * r - 0.331 * g + 0.500 * b + 128,
                    0.500 * r - 0.419 * g - 0.081 * b + 128};
    });
}

// ------------------------------------------------------------ colormaps ---

namespace {

double ramp(double v) { return std::clamp(v, 0.0, 1.0); }

Vec3 colorMapValue(ColorMap map, double t) {  // t in [0, 1], returns 0..1
    switch (map) {
        case ColorMap::Autumn: return {1.0, t, 0.0};
        case ColorMap::Winter: return {0.0, t, 1.0 - 0.5 * t};
        case ColorMap::Hot:
            return {ramp(t * 8 / 3), ramp((t - 3.0 / 8) * 8 / 3), ramp((t - 3.0 / 4) * 4)};
        case ColorMap::Bone: {
            // MATLAB-style bone: (7 * gray + reversed hot) / 8.
            Vec3 hot = colorMapValue(ColorMap::Hot, t);
            return {(7 * t + hot[2]) / 8, (7 * t + hot[1]) / 8, (7 * t + hot[0]) / 8};
        }
        case ColorMap::Jet:
            return {ramp(1.5 - std::abs(4 * t - 3)), ramp(1.5 - std::abs(4 * t - 2)),
                    ramp(1.5 - std::abs(4 * t - 1))};
        case ColorMap::Rainbow: {
            // Hue sweep red -> yellow -> green -> blue -> violet.
            double h = t * 270.0 / 60.0;
            double x = 1 - std::abs(std::fmod(h, 2.0) - 1);
            switch (int(h)) {
                case 0: return {1, x, 0};
                case 1: return {x, 1, 0};
                case 2: return {0, 1, x};
                case 3: return {0, x, 1};
                default: return {x, 0, 1};
            }
        }
    }
    return {t, t, t};
}

}  // namespace

Rgba applyColorMap(const Gray& g, ColorMap map) {
    std::array<Vec3, 256> lut;
    for (int i = 0; i < 256; ++i) lut[i] = colorMapValue(map, i / 255.0);
    Rgba out(g.w, g.h);
    for (size_t i = 0; i < g.px.size(); ++i)
        for (int c = 0; c < 3; ++c) out.px[i * 4 + c] = clamp8(lut[g.px[i]][c] * 255.0);
    return out;
}

Rgba colorBar(ColorMap map, int width, int height) {
    Gray ramp(width, height);
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            ramp.at(x, y) = clamp8(width > 1 ? x * 255.0 / (width - 1) : 0);
    return applyColorMap(ramp, map);
}

// --------------------------------------------------------------- k-means ---

Rgba kmeansSegment(const Rgba& im, int k, ColorSpace space, unsigned seed) {
    const size_t n = size_t(im.w) * im.h;
    k = std::clamp(k, 1, 256);

    // Features normalized to roughly [0, 1] per channel.
    std::vector<Vec3> feat(n);
    for (size_t i = 0; i < n; ++i) {
        const uint8_t* p = &im.px[i * 4];
        double r = p[0] / 255.0, g = p[1] / 255.0, b = p[2] / 255.0;
        if (space == ColorSpace::RGB) {
            feat[i] = {r, g, b};
        } else if (space == ColorSpace::HSI) {
            Vec3 h = rgbToHsi(r, g, b);
            feat[i] = {h[0] / 360.0, h[1], h[2]};
        } else {
            Vec3 l = rgbToLab(r, g, b);
            feat[i] = {l[0] / 100.0, (l[1] + 128.0) / 255.0, (l[2] + 128.0) / 255.0};
        }
    }
    auto dist2 = [](const Vec3& a, const Vec3& b) {
        double d0 = a[0] - b[0], d1 = a[1] - b[1], d2 = a[2] - b[2];
        return d0 * d0 + d1 * d1 + d2 * d2;
    };

    // Fit on a random subset for speed, then label every pixel.
    std::mt19937 rng(seed);
    const size_t maxSamples = 40000;
    std::vector<size_t> sample;
    if (n <= maxSamples) {
        sample.resize(n);
        for (size_t i = 0; i < n; ++i) sample[i] = i;
    } else {
        std::uniform_int_distribution<size_t> pick(0, n - 1);
        sample.resize(maxSamples);
        for (size_t& s : sample) s = pick(rng);
    }

    // k-means++ initialization.
    std::vector<Vec3> centers;
    centers.push_back(feat[sample[std::uniform_int_distribution<size_t>(0, sample.size() - 1)(rng)]]);
    std::vector<double> best(sample.size(), std::numeric_limits<double>::max());
    while (int(centers.size()) < k) {
        double total = 0;
        for (size_t i = 0; i < sample.size(); ++i) {
            best[i] = std::min(best[i], dist2(feat[sample[i]], centers.back()));
            total += best[i];
        }
        if (total <= 0) break;  // fewer distinct colors than k
        double r = std::uniform_real_distribution<double>(0, total)(rng);
        size_t idx = 0;
        for (; idx + 1 < sample.size() && (r -= best[idx]) > 0; ++idx) {}
        centers.push_back(feat[sample[idx]]);
    }

    auto nearest = [&](const Vec3& f) {
        int bi = 0;
        double bd = std::numeric_limits<double>::max();
        for (int c = 0; c < int(centers.size()); ++c) {
            double d = dist2(f, centers[c]);
            if (d < bd) { bd = d; bi = c; }
        }
        return bi;
    };

    // Lloyd iterations.
    for (int iter = 0; iter < 20; ++iter) {
        std::vector<Vec3> sum(centers.size(), {0, 0, 0});
        std::vector<int> count(centers.size(), 0);
        for (size_t s : sample) {
            int c = nearest(feat[s]);
            for (int d = 0; d < 3; ++d) sum[c][d] += feat[s][d];
            count[c]++;
        }
        double shift = 0;
        for (size_t c = 0; c < centers.size(); ++c) {
            if (!count[c]) continue;
            Vec3 nc = {sum[c][0] / count[c], sum[c][1] / count[c], sum[c][2] / count[c]};
            shift = std::max(shift, dist2(nc, centers[c]));
            centers[c] = nc;
        }
        if (shift < 1e-8) break;
    }

    // Center colors back in RGB.
    std::vector<Vec3> rgb(centers.size());
    for (size_t c = 0; c < centers.size(); ++c) {
        const Vec3& v = centers[c];
        if (space == ColorSpace::RGB) rgb[c] = v;
        else if (space == ColorSpace::HSI) rgb[c] = hsiToRgb(v[0] * 360.0, v[1], v[2]);
        else rgb[c] = labToRgb(v[0] * 100.0, v[1] * 255.0 - 128.0, v[2] * 255.0 - 128.0);
    }

    Rgba out(im.w, im.h);
    for (size_t i = 0; i < n; ++i) {
        const Vec3& c = rgb[nearest(feat[i])];
        for (int d = 0; d < 3; ++d) out.px[i * 4 + d] = clamp8(c[d] * 255.0);
    }
    return out;
}

}  // namespace dip
