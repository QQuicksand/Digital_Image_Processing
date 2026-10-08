# Digital Image Processing — C++ / Qt

A collection of desktop image-processing tools written in C++17 with Qt (and OpenCV
where needed). Each project is a self-contained GUI application with its source code,
a prebuilt Windows executable and a write-up with result images.

| # | Project | Topics |
|---|---|---|
| Project 1 | [Gray-Level Operations & Histogram Analysis](Project1-Gray-Level-Histogram/) | `.64` image decoding, histogram, add / subtract / multiply, averaging, gradient |
| Project 2 | [Image Enhancement & Histogram Processing](Project2-Image-Enhancement/) | grayscale conversion, thresholding, resampling, brightness / contrast, histogram equalization |
| Project 3 | [Spatial Filtering & Edge Detection](Project3-Spatial-Filtering-Edge-Detection/) | smoothing, sharpening, median, Sobel, Marr-Hildreth (LoG), local enhancement |
| Project 4 | [Frequency-Domain Filtering & Image Restoration](Project4-Frequency-Domain-Restoration/) | FFT, ideal / Butterworth / Gaussian filters, homomorphic filtering, inverse & Wiener filters |
| Project 5 | [Color Processing & K-means Segmentation](Project5-Color-Processing-Segmentation/) | RGB / CMY / HSI / XYZ / L\*a\*b\* / YUV, pseudo-color, k-means segmentation |
| Project 6 | [Geometric Transforms, Wavelet Fusion & SLIC Superpixels](Project6-Geometric-Wavelet-Superpixel/) | fisheye, kaleidoscope, wavy, spiral, ripple, DWT fusion, SLIC |
| Term Project | [HoneyBee Tracker](TermProject-HoneyBee-Tracker/) | bee detection & tracking in video (demo) |

## Preview

| Histogram | Enhancement | Edge detection |
|:--:|:--:|:--:|
| ![](Project1-Gray-Level-Histogram/docs/images/histogram-lisa.png) | ![](Project2-Image-Enhancement/docs/images/histogram-equalization.png) | ![](Project3-Spatial-Filtering-Edge-Detection/docs/images/sobel.jpg) |
| **Frequency domain** | **Color segmentation** | **Geometric transforms** |
| ![](Project4-Frequency-Domain-Restoration/docs/images/fft-ui.jpg) | ![](Project5-Color-Processing-Segmentation/docs/images/rgb-k50.png) | ![](Project6-Geometric-Wavelet-Superpixel/docs/images/spiral.png) |

## Quick Start (Windows)

1. Clone the repository (Git LFS is used for the bundled `.dll` files):

   ```bash
   git lfs install
   git clone https://github.com/QQuicksand/Digital_Image_Processing.git
   ```

2. Open a project's `bin/` folder and run its `.exe`. The Qt runtime and sample images
   are bundled, so the GUI starts directly.

## Project Layout

```text
ProjectN-Subject/
├── README.md      write-up with algorithms and result images
├── src/           C++ / Qt source and CMakeLists.txt
├── bin/           prebuilt Windows executable, runtime DLLs and sample images
└── docs/images/   figures used in the write-up
```

`TermProject-HoneyBee-Tracker/` holds the term project's write-up and demo recording.

## Building from Source

Each `src/` folder is a standalone CMake project:

```bash
cmake -S <project>/src -B build -G Ninja -DCMAKE_PREFIX_PATH=<path-to-Qt>
cmake --build build
```

Projects 02, 04, 05 and 06 also need OpenCV; point `OpenCV_DIR` in their
`CMakeLists.txt` to your OpenCV build. Sample images are loaded relative to the working
directory, so copy them from `bin/` next to the built executable.

## Technologies

- C++17
- Qt 5 / Qt 6 (Widgets)
- OpenCV
- CMake / Ninja
