// Emscripten (embind) bindings: expose the dip core to JavaScript.
// Images cross the boundary as { width, height, data: Uint8ClampedArray RGBA },
// which is the shape of a canvas ImageData.
#include <emscripten/bind.h>
#include <emscripten/val.h>

#include "dip.hpp"

using emscripten::val;

namespace {

dip::Rgba rgbaIn(const val& img) {
    dip::Rgba im;
    im.w = img["width"].as<int>();
    im.h = img["height"].as<int>();
    im.px = emscripten::convertJSArrayToNumberVector<uint8_t>(img["data"]);
    return im;
}

dip::Gray grayIn(const val& img) { return dip::toGrayWeighted(rgbaIn(img)); }
dip::Gray levelsIn(const val& img) { return dip::toLevels(grayIn(img)); }

val out(const dip::Rgba& im) {
    val o = val::object();
    o.set("width", im.w);
    o.set("height", im.h);
    // Constructing from a typed-array view copies the bytes out of the heap.
    o.set("data", val::global("Uint8ClampedArray")
                      .new_(emscripten::typed_memory_view(im.px.size(), im.px.data())));
    return o;
}

val out(const dip::Gray& g) { return out(dip::toRgba(g)); }
val outLevels(const dip::Gray& levels) { return out(dip::fromLevels(levels)); }

val intArray(const std::vector<int>& v) {
    return val::global("Int32Array").new_(emscripten::typed_memory_view(v.size(), v.data()));
}

// ---- 01 gray-level operations (images carry 32 levels).
val decode64(std::string text) { return outLevels(dip::decode64(text)); }
val quantize32(val img) { return outLevels(levelsIn(img)); }
val addConstant(val img, int c) { return outLevels(dip::addConstant(levelsIn(img), c)); }
val multiplyConstant(val img, double c) { return outLevels(dip::multiplyConstant(levelsIn(img), c)); }
val averageImages(val a, val b) { return outLevels(dip::averageImages(levelsIn(a), levelsIn(b))); }
val differenceX(val img) { return outLevels(dip::differenceX(levelsIn(img))); }
val histogram(val img, int bins) { return intArray(dip::histogram(grayIn(img), bins)); }

// ---- 02 enhancement.
val grayAverage(val img) { return out(dip::toGrayAverage(rgbaIn(img))); }
val grayWeighted(val img) { return out(dip::toGrayWeighted(rgbaIn(img))); }
val grayDifference(val img) {
    dip::Rgba im = rgbaIn(img);
    return out(dip::absDifference(dip::toGrayAverage(im), dip::toGrayWeighted(im)));
}
val threshold(val img, int t) { return out(dip::threshold(grayIn(img), t)); }
val scaleImage(val img, double percent) { return out(dip::scaleImage(grayIn(img), percent)); }
val quantize(val img, int levels) { return out(dip::quantize(grayIn(img), levels)); }
val brightnessContrast(val img, int b, double c) {
    return out(dip::brightnessContrast(grayIn(img), b, c));
}
val equalize(val img) { return out(dip::equalizeHistogram(grayIn(img))); }

// ---- 03 spatial filtering.
val smooth(val img, int size) { return out(dip::smoothFilter(grayIn(img), size)); }
val sharpen(val img, int size, double c) { return out(dip::sharpenFilter(grayIn(img), size, c)); }
val median(val img, int size) { return out(dip::medianFilter(grayIn(img), size)); }
val sobel(val img) { return out(dip::sobelFilter(grayIn(img))); }
val marrHildreth(val img, int size, double sigma, double t) {
    return out(dip::marrHildreth(grayIn(img), size, sigma, t));
}
val localEnhancement(val img, int size, double k0, double k1, double k2, double k3, double C) {
    return out(dip::localEnhancement(grayIn(img), size, k0, k1, k2, k3, C));
}

// ---- 04 frequency domain.
val spectrum(val img) {
    dip::Spectrum s = dip::fourierSpectrum(grayIn(img));
    val o = val::object();
    o.set("magnitude", out(s.magnitude));
    o.set("phase", out(s.phase));
    o.set("inverse", out(s.inverse));
    return o;
}
val frequencyFilter(val img, int shape, double cutoff, bool highpass, int order) {
    return out(dip::frequencyFilter(grayIn(img), dip::FilterShape(shape), cutoff, highpass, order));
}
val homomorphic(val img, double gH, double gL, double D0, double c) {
    return out(dip::homomorphicFilter(grayIn(img), gH, gL, D0, c));
}
val restore(val img, double length, double angle, double noise, int method, double param) {
    dip::RestoreResult r = dip::motionBlurRestore(grayIn(img), length, angle, noise,
                                                  dip::Restoration(method), param);
    val o = val::object();
    o.set("blurred", out(r.blurred));
    o.set("restored", out(r.restored));
    return o;
}

// ---- 05 color.
val colorModel(val img, std::string model) {
    dip::Rgba im = rgbaIn(img);
    if (model == "CMY") return out(dip::toCMY(im));
    if (model == "HSI") return out(dip::toHSI(im));
    if (model == "XYZ") return out(dip::toXYZ(im));
    if (model == "Lab") return out(dip::toLab(im));
    if (model == "YUV") return out(dip::toYUV(im));
    return out(im);
}
val pseudoColor(val img, int map) { return out(dip::applyColorMap(grayIn(img), dip::ColorMap(map))); }
val colorBar(int map, int w, int h) { return out(dip::colorBar(dip::ColorMap(map), w, h)); }
val kmeans(val img, int k, int space) {
    return out(dip::kmeansSegment(rgbaIn(img), k, dip::ColorSpace(space)));
}

// ---- 06 geometry, wavelets, superpixels.
val warp(val img, std::string kind, double p1, double p2) {
    dip::Rgba im = rgbaIn(img);
    if (kind == "fisheye") return out(dip::fisheye(im, p1));
    if (kind == "kaleidoscope") return out(dip::kaleidoscope(im, int(p1)));
    if (kind == "wavy") return out(dip::wavy(im, p1, p2));
    if (kind == "spiral") return out(dip::spiral(im, p1));
    if (kind == "ripple") return out(dip::ripple(im, p1, p2));
    return out(im);
}
val waveletFusion(val a, val b, int levels) {
    dip::FusionResult r = dip::waveletFusion(grayIn(a), grayIn(b), levels);
    val o = val::object();
    o.set("fused", out(r.fused));
    o.set("subbands", out(r.subbands));
    return o;
}
val slic(val img, int n, double compactness, bool boundaries) {
    dip::SlicResult r = dip::slicSuperpixels(rgbaIn(img), n, compactness, boundaries);
    val o = out(r.image);
    o.set("superpixels", r.superpixels);
    return o;
}

}  // namespace

EMSCRIPTEN_BINDINGS(dip) {
    using emscripten::function;
    function("decode64", &decode64);
    function("quantize32", &quantize32);
    function("addConstant", &addConstant);
    function("multiplyConstant", &multiplyConstant);
    function("averageImages", &averageImages);
    function("differenceX", &differenceX);
    function("histogram", &histogram);

    function("grayAverage", &grayAverage);
    function("grayWeighted", &grayWeighted);
    function("grayDifference", &grayDifference);
    function("threshold", &threshold);
    function("scaleImage", &scaleImage);
    function("quantize", &quantize);
    function("brightnessContrast", &brightnessContrast);
    function("equalize", &equalize);

    function("smooth", &smooth);
    function("sharpen", &sharpen);
    function("median", &median);
    function("sobel", &sobel);
    function("marrHildreth", &marrHildreth);
    function("localEnhancement", &localEnhancement);

    function("spectrum", &spectrum);
    function("frequencyFilter", &frequencyFilter);
    function("homomorphic", &homomorphic);
    function("restore", &restore);

    function("colorModel", &colorModel);
    function("pseudoColor", &pseudoColor);
    function("colorBar", &colorBar);
    function("kmeans", &kmeans);

    function("warp", &warp);
    function("waveletFusion", &waveletFusion);
    function("slic", &slic);
}
