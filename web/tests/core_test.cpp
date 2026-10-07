// Native sanity tests for the image processing core.
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <numeric>

#include "../core/dip.hpp"

using namespace dip;

static int failures = 0;

#define CHECK(cond)                                                       \
    do {                                                                  \
        if (!(cond)) {                                                    \
            std::fprintf(stderr, "%s:%d: CHECK failed: %s\n", __FILE__,  \
                         __LINE__, #cond);                                \
            ++failures;                                                   \
        }                                                                 \
    } while (0)

static Gray gradientImage(int w, int h) {
    Gray g(w, h);
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x) g.at(x, y) = uint8_t((x * 255) / (w - 1));
    return g;
}

static Rgba colorImage(int w, int h) {
    Rgba im(w, h);
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x) {
            uint8_t* p = im.at(x, y);
            p[0] = uint8_t(x * 255 / (w - 1));
            p[1] = uint8_t(y * 255 / (h - 1));
            p[2] = uint8_t(x < w / 2 ? 40 : 220);
        }
    return im;
}

static double meanAbsDiff(const Gray& a, const Gray& b) {
    double s = 0;
    for (size_t i = 0; i < a.px.size(); ++i) s += std::abs(int(a.px[i]) - int(b.px[i]));
    return s / a.px.size();
}

static void testLevels() {
    Gray g = decode64("01\nAV\n");
    CHECK(g.w == 2 && g.h == 2);
    CHECK(g.at(0, 0) == 0 && g.at(1, 0) == 1 && g.at(0, 1) == 10 && g.at(1, 1) == 31);
    CHECK(addConstant(g, 5).at(1, 1) == 31);
    CHECK(addConstant(g, -5).at(0, 0) == 0);
    CHECK(multiplyConstant(g, 2).at(0, 1) == 20);
    CHECK(toLevels(fromLevels(g)).px == g.px);
    Gray d = differenceX(g);
    CHECK(d.at(1, 1) == 21 && d.at(0, 1) == 0);
    std::vector<int> h = histogram(fromLevels(g), kLevels);
    CHECK(std::accumulate(h.begin(), h.end(), 0) == 4);
    CHECK(h[31] == 1 && h[0] == 1);
}

static void testEnhancement() {
    Gray g = gradientImage(64, 16);
    Gray t = threshold(g, 128);
    CHECK(t.at(0, 0) == 0 && t.at(63, 0) == 255);
    CHECK(scaleImage(g, 50).w == 32);
    CHECK(quantize(g, 2).at(63, 0) == 255 && quantize(g, 2).at(0, 0) == 0);
    CHECK(brightnessContrast(g, 10, 1.0).at(0, 0) == 10);
    Gray dark(32, 32, 100);
    for (int x = 0; x < 16; ++x) dark.at(x, 0) = 110;
    Gray eq = equalizeHistogram(dark);
    CHECK(eq.at(20, 20) == 0 && eq.at(0, 0) == 255);
    Rgba c = colorImage(16, 16);
    CHECK(absDifference(toGrayAverage(c), toGrayWeighted(c)).w == 16);
}

static void testSpatial() {
    Gray flat(40, 30, 77);
    CHECK(smoothFilter(flat, 5).px == flat.px);
    CHECK(sharpenFilter(flat, 5, 3.0).px == flat.px);
    CHECK(medianFilter(flat, 7).px == flat.px);
    Gray edge = sobelFilter(flat);
    CHECK(*std::max_element(edge.px.begin(), edge.px.end()) == 0);

    Gray noisy(40, 30, 50);
    noisy.at(10, 10) = 255;  // salt
    CHECK(medianFilter(noisy, 3).at(10, 10) == 50);

    Gray step(40, 40, 0);
    for (int y = 0; y < 40; ++y)
        for (int x = 20; x < 40; ++x) step.at(x, y) = 200;
    CHECK(sobelFilter(step).at(20, 20) > 200);
    Gray mh = marrHildreth(step, 9, 1.5, 5);
    int edges = 0;
    for (int y = 5; y < 35; ++y) edges += mh.at(19, y) == 255 || mh.at(20, y) == 255;
    CHECK(edges > 25);

    Gray le = localEnhancement(step, 3, 0.0, 0.4, 0.0, 10.0, 2.0);
    CHECK(le.w == step.w && le.at(30, 30) == 200);
}

static void testFrequency() {
    Gray g = gradientImage(50, 40);
    Spectrum s = fourierSpectrum(g);
    CHECK(s.magnitude.w == 64 && s.magnitude.h == 64);
    CHECK(meanAbsDiff(s.inverse, g) < 1.0);

    Gray low = frequencyFilter(g, FilterShape::Gaussian, 1e6, false);
    CHECK(meanAbsDiff(low, g) < 1.0);
    for (int shape = 0; shape < 3; ++shape) {
        Gray hp = frequencyFilter(g, FilterShape(shape), 10, true);
        CHECK(hp.w == g.w && hp.h == g.h);
    }
    Gray homo = homomorphicFilter(g, 1.0, 1.0, 30);
    CHECK(homo.w == g.w);

    RestoreResult wiener = motionBlurRestore(g, 9, 30, 0, Restoration::Wiener, 1e-6);
    CHECK(meanAbsDiff(wiener.blurred, g) > 0.5);
    CHECK(meanAbsDiff(wiener.restored, g) < meanAbsDiff(wiener.blurred, g));
    RestoreResult inv = motionBlurRestore(g, 9, 0, 0, Restoration::Inverse, 0);
    CHECK(inv.restored.w == g.w);
}

static void testColor() {
    Rgba c = colorImage(32, 24);
    for (auto fn : {toCMY, toHSI, toXYZ, toLab, toYUV}) CHECK(fn(c).w == 32);
    CHECK(toCMY(c).at(0, 0)[0] == 255);
    Rgba bar = colorBar(ColorMap::Jet);
    CHECK(bar.w == 256);
    CHECK(colorBar(ColorMap::Hot).at(255, 0)[2] == 255);

    Rgba two(20, 10);
    for (int y = 0; y < 10; ++y)
        for (int x = 0; x < 20; ++x) {
            uint8_t* p = two.at(x, y);
            p[0] = x < 10 ? 200 : 10;
            p[1] = 30;
            p[2] = x < 10 ? 20 : 180;
        }
    for (int space = 0; space < 3; ++space) {
        Rgba seg = kmeansSegment(two, 2, ColorSpace(space));
        CHECK(std::abs(seg.at(0, 0)[0] - 200) < 8);
        CHECK(std::abs(seg.at(19, 9)[2] - 180) < 8);
    }
}

static void testGeometry() {
    Rgba c = colorImage(40, 30);
    CHECK(fisheye(c, 3).w == 40);
    CHECK(kaleidoscope(c, 8).h == 30);
    CHECK(wavy(c, 0, 0.1).px == c.px);
    CHECK(spiral(c, 0).px == c.px);
    CHECK(ripple(c, 0, 0.1).px == c.px);

    Gray a = gradientImage(37, 29);
    FusionResult same = waveletFusion(a, a, 3);
    CHECK(meanAbsDiff(same.fused, a) < 1.0);
    Gray b(37, 29, 0);
    FusionResult f = waveletFusion(a, b, 1);
    CHECK(f.fused.w == 37 && f.subbands.h == 29);

    SlicResult s = slicSuperpixels(c, 12, 10, true);
    CHECK(s.superpixels > 4 && s.superpixels < 40);
    CHECK(s.image.w == 40);
}

int main() {
    testLevels();
    testEnhancement();
    testSpatial();
    testFrequency();
    testColor();
    testGeometry();
    if (failures) {
        std::fprintf(stderr, "%d check(s) failed\n", failures);
        return EXIT_FAILURE;
    }
    std::puts("all core tests passed");
    return EXIT_SUCCESS;
}
