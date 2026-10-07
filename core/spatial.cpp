// Spatial filtering, edge detection and local enhancement (project 03).
#include <algorithm>
#include <cmath>

#include "dip.hpp"

namespace dip {

namespace {

// Reflect-101 border handling: -1 -> 1, n -> n-2.
inline int reflect(int i, int n) {
    if (n == 1) return 0;
    while (i < 0 || i >= n) i = i < 0 ? -i : 2 * n - 2 - i;
    return i;
}

int oddSize(int size) {
    size = std::max(1, size);
    return size % 2 ? size : size + 1;
}

// Summed-area tables of v and v^2 over the image padded by `r` (reflect).
struct Integral {
    int w, h, r, pw;
    std::vector<double> s, s2;

    Integral(const Gray& g, int r) : w(g.w), h(g.h), r(r), pw(g.w + 2 * r + 1) {
        int ph = g.h + 2 * r + 1;
        s.assign(size_t(pw) * ph, 0.0);
        s2.assign(size_t(pw) * ph, 0.0);
        for (int y = 1; y < ph; ++y) {
            double row = 0, row2 = 0;
            int sy = reflect(y - 1 - r, g.h);
            for (int x = 1; x < pw; ++x) {
                double v = g.at(reflect(x - 1 - r, g.w), sy);
                row += v;
                row2 += v * v;
                s[size_t(y) * pw + x] = s[size_t(y - 1) * pw + x] + row;
                s2[size_t(y) * pw + x] = s2[size_t(y - 1) * pw + x] + row2;
            }
        }
    }

    // Sum (and sum of squares) of the (2r+1)^2 window centred at (x, y).
    void window(int x, int y, double& sum, double& sum2) const {
        int x0 = x, y0 = y, x1 = x + 2 * r + 1, y1 = y + 2 * r + 1;
        auto at = [&](const std::vector<double>& t, int xx, int yy) {
            return t[size_t(yy) * pw + xx];
        };
        sum = at(s, x1, y1) - at(s, x0, y1) - at(s, x1, y0) + at(s, x0, y0);
        sum2 = at(s2, x1, y1) - at(s2, x0, y1) - at(s2, x1, y0) + at(s2, x0, y0);
    }
};

// Convolution returning the raw (unclamped) response.
std::vector<double> convolveRaw(const Gray& g, const Kernel& k) {
    int kh = int(k.size()), kw = int(k[0].size());
    int ry = kh / 2, rx = kw / 2;
    std::vector<double> out(g.px.size());
    for (int y = 0; y < g.h; ++y) {
        for (int x = 0; x < g.w; ++x) {
            double sum = 0;
            for (int j = 0; j < kh; ++j) {
                int sy = reflect(y + j - ry, g.h);
                for (int i = 0; i < kw; ++i) sum += g.at(reflect(x + i - rx, g.w), sy) * k[j][i];
            }
            out[size_t(y) * g.w + x] = sum;
        }
    }
    return out;
}

}  // namespace

Gray convolve(const Gray& g, const Kernel& k) {
    std::vector<double> raw = convolveRaw(g, k);
    Gray out(g.w, g.h);
    for (size_t i = 0; i < raw.size(); ++i) out.px[i] = clamp8(raw[i]);
    return out;
}

Gray smoothFilter(const Gray& g, int size) {
    size = oddSize(size);
    Integral in(g, size / 2);
    Gray out(g.w, g.h);
    double n = double(size) * size;
    for (int y = 0; y < g.h; ++y)
        for (int x = 0; x < g.w; ++x) {
            double s, s2;
            in.window(x, y, s, s2);
            out.at(x, y) = clamp8(s / n);
        }
    return out;
}

// Kernel: -c / n everywhere, centre += 1 + c, i.e. (1 + c) f - c * mean(f).
Gray sharpenFilter(const Gray& g, int size, double coefficient) {
    size = oddSize(size);
    Integral in(g, size / 2);
    Gray out(g.w, g.h);
    double n = double(size) * size;
    for (int y = 0; y < g.h; ++y)
        for (int x = 0; x < g.w; ++x) {
            double s, s2;
            in.window(x, y, s, s2);
            out.at(x, y) = clamp8((1 + coefficient) * g.at(x, y) - coefficient * s / n);
        }
    return out;
}

// Sliding-histogram median (Huang): O(size) per pixel.
Gray medianFilter(const Gray& g, int size) {
    size = oddSize(size);
    int r = size / 2;
    int half = size * size / 2;
    Gray out(g.w, g.h);
    for (int y = 0; y < g.h; ++y) {
        int hist[256] = {0};
        for (int j = -r; j <= r; ++j)
            for (int i = -r; i <= r; ++i)
                hist[g.at(reflect(i, g.w), reflect(y + j, g.h))]++;
        for (int x = 0; x < g.w; ++x) {
            if (x > 0) {
                int xo = reflect(x - r - 1, g.w), xi = reflect(x + r, g.w);
                for (int j = -r; j <= r; ++j) {
                    int sy = reflect(y + j, g.h);
                    hist[g.at(xo, sy)]--;
                    hist[g.at(xi, sy)]++;
                }
            }
            int count = 0, m = 0;
            for (; m < 256; ++m)
                if ((count += hist[m]) > half) break;
            out.at(x, y) = uint8_t(std::min(m, 255));
        }
    }
    return out;
}

Gray sobelFilter(const Gray& g) {
    Kernel kx = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    Kernel ky = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    std::vector<double> gx = convolveRaw(g, kx), gy = convolveRaw(g, ky);
    Gray out(g.w, g.h);
    for (size_t i = 0; i < out.px.size(); ++i) out.px[i] = clamp8(std::hypot(gx[i], gy[i]));
    return out;
}

Kernel laplacianOfGaussian(int size, double sigma) {
    size = oddSize(size);
    sigma = std::max(sigma, 0.1);
    int r = size / 2;
    double s2 = sigma * sigma;
    Kernel k(size, std::vector<double>(size));
    double mean = 0;
    for (int y = -r; y <= r; ++y)
        for (int x = -r; x <= r; ++x) {
            double r2 = x * x + y * y;
            double v = (r2 - 2 * s2) / (s2 * s2) * std::exp(-r2 / (2 * s2));
            k[y + r][x + r] = v;
            mean += v;
        }
    // Force a zero-sum kernel so flat regions give zero response.
    mean /= double(size) * size;
    for (auto& row : k)
        for (double& v : row) v -= mean;
    return k;
}

Gray marrHildreth(const Gray& g, int size, double sigma, double thresholdPercent) {
    std::vector<double> resp = convolveRaw(g, laplacianOfGaussian(size, sigma));
    double maxAbs = 0;
    for (double v : resp) maxAbs = std::max(maxAbs, std::abs(v));
    double t = std::max(0.0, thresholdPercent) / 100.0 * maxAbs;

    Gray out(g.w, g.h, 0);
    auto at = [&](int x, int y) { return resp[size_t(y) * g.w + x]; };
    const int dirs[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    for (int y = 1; y < g.h - 1; ++y)
        for (int x = 1; x < g.w - 1; ++x)
            for (const auto& d : dirs) {
                double a = at(x - d[0], y - d[1]), b = at(x + d[0], y + d[1]);
                if (a * b < 0 && std::abs(a - b) > t) {
                    out.at(x, y) = 255;
                    break;
                }
            }
    return out;
}

Gray localEnhancement(const Gray& g, int size, double k0, double k1, double k2,
                      double k3, double C) {
    size = oddSize(size);
    double n = double(g.px.size());
    double mG = 0, sG = 0;
    for (uint8_t v : g.px) {
        mG += v;
        sG += double(v) * v;
    }
    mG /= n;
    sG = std::sqrt(std::max(0.0, sG / n - mG * mG));

    Integral in(g, size / 2);
    double area = double(size) * size;
    Gray out(g.w, g.h);
    for (int y = 0; y < g.h; ++y)
        for (int x = 0; x < g.w; ++x) {
            double s, s2;
            in.window(x, y, s, s2);
            double mL = s / area;
            double sL = std::sqrt(std::max(0.0, s2 / area - mL * mL));
            double f = g.at(x, y);
            bool enhance = k0 * mG <= mL && mL <= k1 * mG && k2 * sG <= sL && sL <= k3 * sG;
            out.at(x, y) = clamp8(enhance ? C * f : f);
        }
    return out;
}

}  // namespace dip
