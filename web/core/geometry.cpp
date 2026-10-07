// Geometric transforms, wavelet fusion and SLIC superpixels (project 06).
#include <algorithm>
#include <array>
#include <cmath>
#include <limits>

#include "dip.hpp"

namespace dip {

namespace {

constexpr double kPi = 3.14159265358979323846;

// Inverse warp: every output pixel (x, y) copies the source pixel returned by
// `map`. Sources outside the image keep the original pixel.
template <typename Map>
Rgba warp(const Rgba& im, Map map) {
    Rgba out = im;
    double cx = im.w / 2.0, cy = im.h / 2.0;
    for (int y = 0; y < im.h; ++y)
        for (int x = 0; x < im.w; ++x) {
            double sx, sy;
            map(x - cx, y - cy, sx, sy);
            int nx = int(std::lround(cx + sx)), ny = int(std::lround(cy + sy));
            if (nx >= 0 && nx < im.w && ny >= 0 && ny < im.h)
                std::copy_n(im.at(nx, ny), 4, out.at(x, y));
        }
    return out;
}

}  // namespace

Rgba fisheye(const Rgba& im, double strength) {
    double radius = std::min(im.w, im.h) / 2.0;
    strength = std::max(strength, 1e-3);
    return warp(im, [&](double dx, double dy, double& sx, double& sy) {
        double d = std::hypot(dx, dy), a = std::atan2(dy, dx);
        double nd = std::atan(d / radius * strength) / (kPi / 2) * radius;
        sx = nd * std::cos(a);
        sy = nd * std::sin(a);
    });
}

Rgba kaleidoscope(const Rgba& im, int segments) {
    double seg = 2 * kPi / std::max(segments, 1);
    return warp(im, [&](double dx, double dy, double& sx, double& sy) {
        double d = std::hypot(dx, dy);
        double a = std::fmod(std::atan2(dy, dx) + 2 * kPi, seg);
        if (a > seg / 2) a = seg - a;  // mirror inside each segment
        sx = d * std::cos(a);
        sy = d * std::sin(a);
    });
}

Rgba wavy(const Rgba& im, double amplitude, double frequency) {
    double cx = im.w / 2.0, cy = im.h / 2.0;
    return warp(im, [&](double dx, double dy, double& sx, double& sy) {
        double x = dx + cx, y = dy + cy;
        sx = dx + amplitude * std::sin(frequency * y);
        sy = dy + amplitude * std::sin(frequency * x);
    });
}

Rgba spiral(const Rgba& im, double twist) {
    return warp(im, [&](double dx, double dy, double& sx, double& sy) {
        double d = std::hypot(dx, dy), a = std::atan2(dy, dx) + d * twist;
        sx = d * std::cos(a);
        sy = d * std::sin(a);
    });
}

Rgba ripple(const Rgba& im, double amplitude, double frequency) {
    return warp(im, [&](double dx, double dy, double& sx, double& sy) {
        double d = std::hypot(dx, dy), a = std::atan2(dy, dx);
        d += std::sin(d * frequency) * amplitude;
        sx = d * std::cos(a);
        sy = d * std::sin(a);
    });
}

// ------------------------------------------------------ wavelet fusion ---

namespace {

struct Plane {
    int w, h;
    std::vector<double> v;
    double& at(int x, int y) { return v[size_t(y) * w + x]; }
};

// One level of the 2-D Haar transform on the top-left w x h block, in place:
// LL top-left, HL top-right, LH bottom-left, HH bottom-right.
void haarForward(Plane& p, int w, int h) {
    std::vector<double> tmp(std::max(w, h));
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w / 2; ++x) {
            double a = p.at(2 * x, y), b = p.at(2 * x + 1, y);
            tmp[x] = (a + b) / 2;
            tmp[w / 2 + x] = (a - b) / 2;
        }
        for (int x = 0; x < w; ++x) p.at(x, y) = tmp[x];
    }
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h / 2; ++y) {
            double a = p.at(x, 2 * y), b = p.at(x, 2 * y + 1);
            tmp[y] = (a + b) / 2;
            tmp[h / 2 + y] = (a - b) / 2;
        }
        for (int y = 0; y < h; ++y) p.at(x, y) = tmp[y];
    }
}

void haarInverse(Plane& p, int w, int h) {
    std::vector<double> tmp(std::max(w, h));
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h / 2; ++y) {
            double s = p.at(x, y), d = p.at(x, h / 2 + y);
            tmp[2 * y] = s + d;
            tmp[2 * y + 1] = s - d;
        }
        for (int y = 0; y < h; ++y) p.at(x, y) = tmp[y];
    }
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w / 2; ++x) {
            double s = p.at(x, y), d = p.at(w / 2 + x, y);
            tmp[2 * x] = s + d;
            tmp[2 * x + 1] = s - d;
        }
        for (int x = 0; x < w; ++x) p.at(x, y) = tmp[x];
    }
}

}  // namespace

FusionResult waveletFusion(const Gray& a, const Gray& b, int levels) {
    levels = std::clamp(levels, 1, 6);
    Gray bb = (b.w == a.w && b.h == a.h) ? b : resizeBilinear(b, a.w, a.h);

    // Pad to a multiple of 2^levels by edge replication.
    int m = 1 << levels;
    int W = (a.w + m - 1) / m * m, H = (a.h + m - 1) / m * m;
    auto toPlane = [&](const Gray& g) {
        Plane p{W, H, std::vector<double>(size_t(W) * H)};
        for (int y = 0; y < H; ++y)
            for (int x = 0; x < W; ++x) p.at(x, y) = g.at(std::min(x, g.w - 1), std::min(y, g.h - 1));
        return p;
    };
    Plane pa = toPlane(a), pb = toPlane(bb);
    for (int l = 0, w = W, h = H; l < levels; ++l, w /= 2, h /= 2) {
        haarForward(pa, w, h);
        haarForward(pb, w, h);
    }

    // Fusion rule: average the approximation, max-magnitude for details.
    int llW = W >> levels, llH = H >> levels;
    Plane fused{W, H, std::vector<double>(size_t(W) * H)};
    for (int y = 0; y < H; ++y)
        for (int x = 0; x < W; ++x) {
            double ca = pa.at(x, y), cb = pb.at(x, y);
            fused.at(x, y) = (x < llW && y < llH) ? (ca + cb) / 2
                                                  : (std::abs(ca) >= std::abs(cb) ? ca : cb);
        }

    // Sub-band mosaic for display (details boosted around mid-gray).
    FusionResult r;
    r.subbands = Gray(a.w, a.h);
    for (int y = 0; y < a.h; ++y)
        for (int x = 0; x < a.w; ++x) {
            double v = fused.at(x, y);
            r.subbands.at(x, y) = (x < llW && y < llH) ? clamp8(v) : clamp8(128 + 4 * v);
        }

    for (int l = levels - 1; l >= 0; --l) haarInverse(fused, W >> l, H >> l);
    r.fused = Gray(a.w, a.h);
    for (int y = 0; y < a.h; ++y)
        for (int x = 0; x < a.w; ++x) r.fused.at(x, y) = clamp8(fused.at(x, y));
    return r;
}

// ------------------------------------------------------------------ SLIC ---

namespace {

struct Lab { double l, a, b; };

Lab srgbToLab(const uint8_t* p) {
    auto lin = [](double c) {
        c /= 255.0;
        return c > 0.04045 ? std::pow((c + 0.055) / 1.055, 2.4) : c / 12.92;
    };
    double r = lin(p[0]), g = lin(p[1]), b = lin(p[2]);
    double X = (r * 0.4124564 + g * 0.3575761 + b * 0.1804375) / 0.95047;
    double Y = r * 0.2126729 + g * 0.7151522 + b * 0.0721750;
    double Z = (r * 0.0193339 + g * 0.1191920 + b * 0.9503041) / 1.08883;
    auto f = [](double t) { return t > 0.008856 ? std::cbrt(t) : (903.3 * t + 16.0) / 116.0; };
    double fx = f(X), fy = f(Y), fz = f(Z);
    return {116 * fy - 16, 500 * (fx - fy), 200 * (fy - fz)};
}

struct Center { double l, a, b, x, y; };

}  // namespace

SlicResult slicSuperpixels(const Rgba& im, int numSuperpixels, double compactness,
                           bool drawBoundaries, int iterations) {
    const int W = im.w, H = im.h;
    const size_t N = size_t(W) * H;
    numSuperpixels = std::clamp(numSuperpixels, 1, int(N));
    const double S = std::max(1.0, std::sqrt(double(N) / numSuperpixels));
    const int step = std::max(1, int(std::lround(S)));

    std::vector<Lab> lab(N);
    for (size_t i = 0; i < N; ++i) lab[i] = srgbToLab(&im.px[i * 4]);
    auto L = [&](int x, int y) -> const Lab& { return lab[size_t(y) * W + x]; };
    auto gradient = [&](int x, int y) {
        auto d = [](const Lab& p, const Lab& q) {
            return (p.l - q.l) * (p.l - q.l) + (p.a - q.a) * (p.a - q.a) + (p.b - q.b) * (p.b - q.b);
        };
        return d(L(x + 1, y), L(x - 1, y)) + d(L(x, y + 1), L(x, y - 1));
    };

    // Grid seeds moved to the lowest-gradient position in a 3 x 3 neighbourhood.
    std::vector<Center> centers;
    for (int y = step / 2; y < H; y += step)
        for (int x = step / 2; x < W; x += step) {
            int bx = x, by = y;
            double bg = std::numeric_limits<double>::max();
            for (int dy = -1; dy <= 1; ++dy)
                for (int dx = -1; dx <= 1; ++dx) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 1 || ny < 1 || nx >= W - 1 || ny >= H - 1) continue;
                    double g = gradient(nx, ny);
                    if (g < bg) { bg = g; bx = nx; by = ny; }
                }
            const Lab& c = L(bx, by);
            centers.push_back({c.l, c.a, c.b, double(bx), double(by)});
        }

    std::vector<int> label(N, -1);
    std::vector<double> dist(N);
    const double m2 = compactness * compactness, s2 = S * S;
    for (int it = 0; it < iterations; ++it) {
        std::fill(dist.begin(), dist.end(), std::numeric_limits<double>::max());
        for (int k = 0; k < int(centers.size()); ++k) {
            const Center& c = centers[k];
            int x0 = std::max(0, int(c.x - 2 * S)), x1 = std::min(W - 1, int(c.x + 2 * S));
            int y0 = std::max(0, int(c.y - 2 * S)), y1 = std::min(H - 1, int(c.y + 2 * S));
            for (int y = y0; y <= y1; ++y)
                for (int x = x0; x <= x1; ++x) {
                    const Lab& p = L(x, y);
                    double dc = (p.l - c.l) * (p.l - c.l) + (p.a - c.a) * (p.a - c.a) +
                                (p.b - c.b) * (p.b - c.b);
                    double ds = (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y);
                    double D = dc + ds / s2 * m2;
                    size_t i = size_t(y) * W + x;
                    if (D < dist[i]) { dist[i] = D; label[i] = k; }
                }
        }
        std::vector<Center> sum(centers.size(), {0, 0, 0, 0, 0});
        std::vector<int> count(centers.size(), 0);
        for (int y = 0; y < H; ++y)
            for (int x = 0; x < W; ++x) {
                int k = label[size_t(y) * W + x];
                if (k < 0) continue;
                const Lab& p = L(x, y);
                sum[k].l += p.l; sum[k].a += p.a; sum[k].b += p.b;
                sum[k].x += x; sum[k].y += y;
                count[k]++;
            }
        for (size_t k = 0; k < centers.size(); ++k)
            if (count[k])
                centers[k] = {sum[k].l / count[k], sum[k].a / count[k], sum[k].b / count[k],
                              sum[k].x / count[k], sum[k].y / count[k]};
    }

    // Enforce connectivity: relabel 4-connected components and merge tiny
    // fragments into the previously visited neighbouring segment.
    std::vector<int> out(N, -1);
    std::vector<int> queue;
    const int minSize = std::max(1, int(N / centers.size()) / 4);
    const int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, -1, 0, 1};
    int next = 0;
    for (int y = 0; y < H; ++y)
        for (int x = 0; x < W; ++x) {
            size_t start = size_t(y) * W + x;
            if (out[start] >= 0) continue;
            int adjacent = -1;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx4[d], ny = y + dy4[d];
                if (nx >= 0 && ny >= 0 && nx < W && ny < H && out[size_t(ny) * W + nx] >= 0)
                    adjacent = out[size_t(ny) * W + nx];
            }
            queue.assign(1, int(start));
            out[start] = next;
            for (size_t q = 0; q < queue.size(); ++q) {
                int px = queue[q] % W, py = queue[q] / W;
                for (int d = 0; d < 4; ++d) {
                    int nx = px + dx4[d], ny = py + dy4[d];
                    if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
                    size_t ni = size_t(ny) * W + nx;
                    if (out[ni] < 0 && label[ni] == label[start]) {
                        out[ni] = next;
                        queue.push_back(int(ni));
                    }
                }
            }
            if (int(queue.size()) < minSize && adjacent >= 0) {
                for (int i : queue) out[i] = adjacent;
            } else {
                ++next;
            }
        }

    // Paint each superpixel with its mean RGB color.
    std::vector<std::array<double, 4>> mean(next, {0, 0, 0, 0});
    for (size_t i = 0; i < N; ++i) {
        auto& m = mean[out[i]];
        for (int c = 0; c < 3; ++c) m[c] += im.px[i * 4 + c];
        m[3] += 1;
    }
    SlicResult r;
    r.superpixels = next;
    r.image = Rgba(W, H);
    for (size_t i = 0; i < N; ++i) {
        const auto& m = mean[out[i]];
        for (int c = 0; c < 3; ++c) r.image.px[i * 4 + c] = clamp8(m[c] / m[3]);
    }
    if (drawBoundaries) {
        for (int y = 0; y < H; ++y)
            for (int x = 0; x < W; ++x) {
                int l = out[size_t(y) * W + x];
                bool edge = (x + 1 < W && out[size_t(y) * W + x + 1] != l) ||
                            (y + 1 < H && out[size_t(y + 1) * W + x] != l);
                if (edge) std::fill_n(r.image.at(x, y), 3, uint8_t(255));
            }
    }
    return r;
}

}  // namespace dip
