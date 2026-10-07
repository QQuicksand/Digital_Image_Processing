// Image basics, gray-level operations (project 01) and enhancement (project 02).
#include <algorithm>
#include <cmath>

#include "dip.hpp"

namespace dip {

uint8_t clamp8(double v) {
    if (!(v > 0.0)) return 0;  // also catches NaN
    if (v >= 255.0) return 255;
    return static_cast<uint8_t>(std::lround(v));
}

Gray toGrayAverage(const Rgba& im) {
    Gray g(im.w, im.h);
    for (size_t i = 0; i < g.px.size(); ++i) {
        const uint8_t* p = &im.px[i * 4];
        g.px[i] = static_cast<uint8_t>((p[0] + p[1] + p[2]) / 3);
    }
    return g;
}

Gray toGrayWeighted(const Rgba& im) {
    Gray g(im.w, im.h);
    for (size_t i = 0; i < g.px.size(); ++i) {
        const uint8_t* p = &im.px[i * 4];
        g.px[i] = clamp8(0.299 * p[0] + 0.587 * p[1] + 0.114 * p[2]);
    }
    return g;
}

Rgba toRgba(const Gray& g) {
    Rgba im(g.w, g.h);
    for (size_t i = 0; i < g.px.size(); ++i) {
        im.px[i * 4] = im.px[i * 4 + 1] = im.px[i * 4 + 2] = g.px[i];
    }
    return im;
}

namespace {

// Bilinear sample of channel `c` (stride `n`) at source position (sx, sy).
template <typename Img>
double sampleBilinear(const Img& im, const std::vector<uint8_t>& px, int n, int c,
                      double sx, double sy) {
    int x1 = std::clamp(static_cast<int>(sx), 0, im.w - 1);
    int y1 = std::clamp(static_cast<int>(sy), 0, im.h - 1);
    int x2 = std::min(x1 + 1, im.w - 1);
    int y2 = std::min(y1 + 1, im.h - 1);
    double fx = std::clamp(sx - x1, 0.0, 1.0);
    double fy = std::clamp(sy - y1, 0.0, 1.0);
    auto v = [&](int x, int y) { return double(px[(size_t(y) * im.w + x) * n + c]); };
    return (1 - fx) * (1 - fy) * v(x1, y1) + fx * (1 - fy) * v(x2, y1) +
           (1 - fx) * fy * v(x1, y2) + fx * fy * v(x2, y2);
}

}  // namespace

Gray resizeBilinear(const Gray& g, int newW, int newH) {
    newW = std::max(1, newW);
    newH = std::max(1, newH);
    Gray out(newW, newH);
    double sx = double(g.w) / newW, sy = double(g.h) / newH;
    for (int y = 0; y < newH; ++y)
        for (int x = 0; x < newW; ++x)
            out.at(x, y) = clamp8(sampleBilinear(g, g.px, 1, 0, x * sx, y * sy));
    return out;
}

Rgba resizeBilinear(const Rgba& im, int newW, int newH) {
    newW = std::max(1, newW);
    newH = std::max(1, newH);
    Rgba out(newW, newH);
    double sx = double(im.w) / newW, sy = double(im.h) / newH;
    for (int y = 0; y < newH; ++y)
        for (int x = 0; x < newW; ++x)
            for (int c = 0; c < 4; ++c)
                out.at(x, y)[c] = clamp8(sampleBilinear(im, im.px, 4, c, x * sx, y * sy));
    return out;
}

std::vector<int> histogram(const Gray& g, int bins) {
    bins = std::clamp(bins, 1, 256);
    std::vector<int> h(bins, 0);
    for (uint8_t v : g.px) h[v * bins / 256]++;
    return h;
}

// ------------------------------------------- 01 gray-level operations ---

Gray decode64(const std::string& text) {
    std::vector<std::vector<uint8_t>> rows(1);
    for (char ch : text) {
        if (ch == '\n') {
            rows.emplace_back();
        } else if (ch >= '0' && ch <= '9') {
            rows.back().push_back(uint8_t(ch - '0'));
        } else if (ch >= 'A' && ch <= 'V') {
            rows.back().push_back(uint8_t(ch - 'A' + 10));
        }
    }
    rows.erase(std::remove_if(rows.begin(), rows.end(),
                              [](const auto& r) { return r.empty(); }),
               rows.end());
    size_t width = 0;
    for (const auto& r : rows) width = std::max(width, r.size());

    Gray g(int(width), int(rows.size()), 0);
    for (int y = 0; y < g.h; ++y)
        for (size_t x = 0; x < rows[y].size(); ++x) g.at(int(x), y) = rows[y][x];
    return g;
}

Gray toLevels(const Gray& g) {
    Gray out(g.w, g.h);
    for (size_t i = 0; i < g.px.size(); ++i)
        out.px[i] = uint8_t(std::lround(g.px[i] * (kLevels - 1) / 255.0));
    return out;
}

Gray fromLevels(const Gray& g) {
    Gray out(g.w, g.h);
    for (size_t i = 0; i < g.px.size(); ++i)
        out.px[i] = clamp8(g.px[i] * 255.0 / (kLevels - 1));
    return out;
}

Gray addConstant(const Gray& levels, int c) {
    Gray out(levels.w, levels.h);
    for (size_t i = 0; i < levels.px.size(); ++i)
        out.px[i] = uint8_t(std::clamp(levels.px[i] + c, 0, kLevels - 1));
    return out;
}

Gray multiplyConstant(const Gray& levels, double c) {
    Gray out(levels.w, levels.h);
    for (size_t i = 0; i < levels.px.size(); ++i)
        out.px[i] = uint8_t(std::clamp(int(levels.px[i] * c), 0, kLevels - 1));
    return out;
}

Gray averageImages(const Gray& a, const Gray& b) {
    Gray bb = (b.w == a.w && b.h == a.h) ? b : resizeBilinear(b, a.w, a.h);
    Gray out(a.w, a.h);
    for (size_t i = 0; i < a.px.size(); ++i) out.px[i] = uint8_t((a.px[i] + bb.px[i]) / 2);
    return out;
}

Gray differenceX(const Gray& levels) {
    Gray out(levels.w, levels.h, 0);
    for (int y = 0; y < levels.h; ++y)
        for (int x = 1; x < levels.w; ++x)
            out.at(x, y) = uint8_t(
                std::clamp(levels.at(x, y) - levels.at(x - 1, y), 0, kLevels - 1));
    return out;
}

// -------------------------------------------------- 02 enhancement ---

Gray absDifference(const Gray& a, const Gray& b) {
    Gray out(a.w, a.h);
    for (size_t i = 0; i < a.px.size(); ++i)
        out.px[i] = uint8_t(std::abs(int(a.px[i]) - int(b.px[i])));
    return out;
}

Gray threshold(const Gray& g, int t) {
    Gray out(g.w, g.h);
    for (size_t i = 0; i < g.px.size(); ++i) out.px[i] = g.px[i] < t ? 0 : 255;
    return out;
}

Gray scaleImage(const Gray& g, double percent) {
    percent = std::clamp(percent, 1.0, 400.0);
    return resizeBilinear(g, int(std::lround(g.w * percent / 100.0)),
                          int(std::lround(g.h * percent / 100.0)));
}

Gray quantize(const Gray& g, int levels) {
    levels = std::clamp(levels, 2, 256);
    Gray out(g.w, g.h);
    // Map each value to the centre-scaled representative of its bin so that
    // the darkest bin stays black and the brightest bin reaches white.
    for (size_t i = 0; i < g.px.size(); ++i) {
        int bin = g.px[i] * levels / 256;
        out.px[i] = clamp8(bin * 255.0 / (levels - 1));
    }
    return out;
}

Gray brightnessContrast(const Gray& g, int brightness, double contrast) {
    Gray out(g.w, g.h);
    for (size_t i = 0; i < g.px.size(); ++i)
        out.px[i] = clamp8(contrast * (g.px[i] - 128.0) + 128.0 + brightness);
    return out;
}

Gray equalizeHistogram(const Gray& g) {
    std::vector<int> hist = histogram(g, 256);
    std::vector<long long> cdf(256);
    long long acc = 0;
    for (int i = 0; i < 256; ++i) cdf[i] = (acc += hist[i]);

    long long cdfMin = 0;
    for (long long c : cdf)
        if (c > 0) { cdfMin = c; break; }
    long long total = (long long)g.px.size();

    uint8_t lut[256];
    for (int i = 0; i < 256; ++i) {
        double denom = double(total - cdfMin);
        lut[i] = denom > 0 ? clamp8((cdf[i] - cdfMin) * 255.0 / denom) : uint8_t(i);
    }
    Gray out(g.w, g.h);
    for (size_t i = 0; i < g.px.size(); ++i) out.px[i] = lut[g.px[i]];
    return out;
}

}  // namespace dip
