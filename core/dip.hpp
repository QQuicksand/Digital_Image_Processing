// Portable digital image processing core.
// Pure C++17 (no Qt / OpenCV) so it builds natively and to WebAssembly.
#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace dip {

// ---------------------------------------------------------------- images ---

struct Gray {
    int w = 0, h = 0;
    std::vector<uint8_t> px;

    Gray() = default;
    Gray(int w, int h, uint8_t v = 0) : w(w), h(h), px(size_t(w) * h, v) {}
    uint8_t& at(int x, int y) { return px[size_t(y) * w + x]; }
    uint8_t at(int x, int y) const { return px[size_t(y) * w + x]; }
};

// 8-bit RGBA, the layout used by the HTML canvas.
struct Rgba {
    int w = 0, h = 0;
    std::vector<uint8_t> px;

    Rgba() = default;
    Rgba(int w, int h) : w(w), h(h), px(size_t(w) * h * 4, 255) {}
    uint8_t* at(int x, int y) { return &px[(size_t(y) * w + x) * 4]; }
    const uint8_t* at(int x, int y) const { return &px[(size_t(y) * w + x) * 4]; }
};

uint8_t clamp8(double v);

Gray toGrayAverage(const Rgba& im);   // (R + G + B) / 3
Gray toGrayWeighted(const Rgba& im);  // 0.299 R + 0.587 G + 0.114 B
Rgba toRgba(const Gray& g);
Gray resizeBilinear(const Gray& g, int newW, int newH);
Rgba resizeBilinear(const Rgba& im, int newW, int newH);

// Histogram of a gray image with `bins` equal-width bins over [0, 256).
std::vector<int> histogram(const Gray& g, int bins = 256);

// ------------------------------------------- 01 gray-level operations ---
// Images in this module hold 32 gray levels (0..31).

constexpr int kLevels = 32;

// Decode a `.64` text image: characters 0-9 / A-V map to levels 0..31.
Gray decode64(const std::string& text);
Gray toLevels(const Gray& g);    // 0..255 -> 0..31
Gray fromLevels(const Gray& g);  // 0..31  -> 0..255

Gray addConstant(const Gray& levels, int c);           // clamped to [0, 31]
Gray multiplyConstant(const Gray& levels, double c);   // clamped to [0, 31]
Gray averageImages(const Gray& a, const Gray& b);      // b resized to a
Gray differenceX(const Gray& levels);                  // f(x,y) - f(x-1,y), clamped

// -------------------------------------------------- 02 enhancement ---

Gray absDifference(const Gray& a, const Gray& b);
Gray threshold(const Gray& g, int t);                    // >= t -> 255
Gray scaleImage(const Gray& g, double percent);          // bilinear resampling
Gray quantize(const Gray& g, int levels);
Gray brightnessContrast(const Gray& g, int brightness, double contrast);
Gray equalizeHistogram(const Gray& g);

// ------------------------------------------- 03 spatial filtering ---

using Kernel = std::vector<std::vector<double>>;

Gray convolve(const Gray& g, const Kernel& k);          // reflect padding
Gray smoothFilter(const Gray& g, int size);             // box (mean) filter
Gray sharpenFilter(const Gray& g, int size, double coefficient);
Gray medianFilter(const Gray& g, int size);
Gray sobelFilter(const Gray& g);
Kernel laplacianOfGaussian(int size, double sigma);
// Marr-Hildreth: LoG response + zero crossings whose contrast exceeds
// `thresholdPercent` % of the maximum response.
Gray marrHildreth(const Gray& g, int size, double sigma, double thresholdPercent);
Gray localEnhancement(const Gray& g, int size, double k0, double k1, double k2,
                      double k3, double C);

// ------------------------------------------- 04 frequency domain ---

enum class FilterShape { Ideal = 0, Butterworth = 1, Gaussian = 2 };

struct Spectrum {
    Gray magnitude;  // log-scaled, normalized, centered
    Gray phase;      // centered phase angle
    Gray inverse;    // IDFT reconstruction
};

Spectrum fourierSpectrum(const Gray& g);
Gray frequencyFilter(const Gray& g, FilterShape shape, double cutoff, bool highpass,
                     int order = 2);
Gray homomorphicFilter(const Gray& g, double gammaH, double gammaL, double D0,
                       double c = 1.0);

enum class Restoration { Inverse = 0, Wiener = 1 };

struct RestoreResult {
    Gray blurred;
    Gray restored;
};

// Simulate linear motion blur (length px at angle degrees) plus Gaussian noise,
// then restore with an inverse filter (param = cut-off radius, 0 = none) or a
// Wiener filter (param = noise-to-signal ratio K).
RestoreResult motionBlurRestore(const Gray& g, double length, double angleDeg,
                                double noiseSigma, Restoration method, double param);

// --------------------------------------------- 05 color processing ---

Rgba toCMY(const Rgba& im);
Rgba toHSI(const Rgba& im);
Rgba toXYZ(const Rgba& im);
Rgba toLab(const Rgba& im);
Rgba toYUV(const Rgba& im);

enum class ColorMap { Autumn = 0, Bone, Jet, Winter, Rainbow, Hot };

Rgba applyColorMap(const Gray& g, ColorMap map);
Rgba colorBar(ColorMap map, int width = 256, int height = 24);

enum class ColorSpace { RGB = 0, HSI = 1, Lab = 2 };

Rgba kmeansSegment(const Rgba& im, int k, ColorSpace space, unsigned seed = 7);

// ------------------------------- 06 geometry, wavelets, superpixels ---

Rgba fisheye(const Rgba& im, double strength);
Rgba kaleidoscope(const Rgba& im, int segments);
Rgba wavy(const Rgba& im, double amplitude, double frequency);
Rgba spiral(const Rgba& im, double twist);
Rgba ripple(const Rgba& im, double amplitude, double frequency);

struct FusionResult {
    Gray fused;
    Gray subbands;  // LL | LH / HL | HH mosaic of the fused coefficients
};

// Haar DWT fusion: average the approximation band, keep the detail
// coefficient with the larger magnitude. `b` is resized to `a`.
FusionResult waveletFusion(const Gray& a, const Gray& b, int levels);

struct SlicResult {
    Rgba image;
    int superpixels = 0;
};

SlicResult slicSuperpixels(const Rgba& im, int numSuperpixels, double compactness,
                           bool drawBoundaries, int iterations = 10);

}  // namespace dip
