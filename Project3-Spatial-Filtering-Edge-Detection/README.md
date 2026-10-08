# Project 3 — Spatial Filtering & Edge Detection

A Qt desktop tool for mask-based spatial filtering: smoothing, sharpening, median
filtering, Sobel edges, Marr-Hildreth (Laplacian of Gaussian) edge detection, and
statistics-based local enhancement compared against histogram equalization.

**Highlights**

- Convolution on padded images with adjustable mask size / coefficients
- Low-pass (smoothing), high-pass (sharpening), order-statistics (median) and Sobel filters
- Marr-Hildreth edge detector with configurable σ, kernel size and zero-crossing threshold
- Local enhancement driven by local vs. global mean and standard deviation

---

## 1. Spatial Filtering with Masks

A program for spatial filtering operations using various types of masks, used to study
how the mask size affects the processed image and the computation time.

| Smoothing filter (low-pass) | Sharpening filter (high-pass) |
|:--:|:--:|
| ![Smoothing](docs/images/smoothing.jpg) | ![Sharpening](docs/images/sharpening.jpg) |

| Order-statistics filter (median) | Sobel filter |
|:--:|:--:|
| ![Median](docs/images/median.jpg) | ![Sobel](docs/images/sobel.jpg) |

### Implementation

**Smoothing & sharpening.** Convolution is applied to a padded image; the mask size is
adjustable for smoothing, and both mask size and center coefficient for sharpening.

![Convolution with padding](docs/images/code-convolution.png)

![Smoothing and sharpening kernels](docs/images/code-smooth-sharpen.png)

**Median filter**

![Median filter](docs/images/code-median.png)

**Sobel filter**

![Sobel filter](docs/images/code-sobel.png)

## 2. Marr-Hildreth Edge Detection

The Marr-Hildreth method convolves the image with the Laplacian of Gaussian (LoG)
operator, the second derivative of a Gaussian filter:

1. Smooth the image with a Gaussian filter.
2. Convolve the result with a Laplacian mask.
3. Detect zero crossings; the zero-crossing threshold controls how many weak edges survive.

**σ = 1, kernel size = 15**

| | |
|:--:|:--:|
| ![](docs/images/log-s1-k15-a.jpg) | ![](docs/images/log-s1-k15-b.jpg) |
| ![](docs/images/log-s1-k15-c.png) | ![](docs/images/log-s1-k15-d.jpg) |

**σ = 1, kernel size = 5**

| | |
|:--:|:--:|
| ![](docs/images/log-s1-k5-a.jpg) | ![](docs/images/log-s1-k5-b.png) |
| ![](docs/images/log-s1-k5-c.png) | ![](docs/images/log-s1-k5-d.jpg) |

**σ = 3, kernel size = 13**

| | |
|:--:|:--:|
| ![](docs/images/log-s3-k13-a.png) | ![](docs/images/log-s3-k13-b.png) |
| ![](docs/images/log-s3-k13-c.png) | ![](docs/images/log-s3-k13-d.png) |

## 3. Local Enhancement

Goals:

1. Reproduce the enhanced result for the test pattern (`Image 4-1.jpg`).
2. Process the test images (`Image 4-1.jpg`, `Image 4-2.jpg`) with local enhancement and
   compare the results with histogram equalization.
3. Study the effect of the neighborhood size `Sxy`.

### Parameters

| Symbol | Meaning |
|---|---|
| `mG` | global mean (average intensity of the whole image) |
| `sG` | global standard deviation (intensity variation) |
| `k₀, k₁` | thresholds on the local mean |
| `k₂, k₃` | thresholds on the local standard deviation |
| `C` | intensity multiplier used for enhancement |

### Procedure

1. Pad the image.
2. Compute the global and local mean and standard deviation.
3. Visit every pixel.
4. Enhance the pixel if its local statistics fall inside the thresholds.

$$
\begin{cases}
k_0 \cdot m_G \le m_{S_{xy}} \le k_1 \cdot m_G \\
k_2 \cdot s_G \le s_{S_{xy}} \le k_3 \cdot s_G
\end{cases}
$$

If both conditions hold, the pixel is enhanced: `g(x, y) = C · f(x, y)`.
Otherwise it is left unchanged: `g(x, y) = f(x, y)`.

![Local enhancement](docs/images/local-enhancement.png)

The local enhancement function compares local statistics (mean and standard deviation)
with the global ones. The result depends on the chosen parameters
(`lSize`, `k0`, `k1`, `k2`, `k3`, `C`) and can bring out details in both bright and dark
regions.

![Local enhancement implementation](docs/images/code-local-enhancement.png)

### Histogram Equalization (comparison)

Histogram equalization improves global contrast by spreading the most frequent
intensity values, but it can over-enhance the image and lose details in very bright or
very dark areas.

![Histogram equalization](docs/images/histogram-equalization.png)

### Effect of Neighborhood Size `Sxy`

| Mask size = 1 | Mask size = 33 | Mask size = 81 |
|:--:|:--:|:--:|
| ![Mask 1](docs/images/mask-1.png) | ![Mask 33](docs/images/mask-33.png) | ![Mask 81](docs/images/mask-81.png) |

---

## Theory Notes

Hand-worked derivations: kernel separability (outer products, Laplacian / Roberts /
Sobel), cascaded Gaussian kernels, convolution of impulses and the frequency response
of the Laplacian and 4-neighbor averaging kernels.

| | |
|:--:|:--:|
| ![Separable kernels and cascaded Gaussians](docs/images/theory-1.png) | ![Separability of sharpening kernels](docs/images/theory-2.png) |
| ![Sobel separability](docs/images/theory-3.png) | ![Convolution of impulses](docs/images/theory-4.png) |
| ![Frequency response of spatial kernels](docs/images/theory-5.png) | |

---

## Run

Windows only. Open `bin/SpatialFiltering.exe`. The Qt runtime and the test images
(`bin/Image 3-*.jpg`, `bin/Image 4-*.jpg`) are bundled next to the executable.

## Build

```bash
cmake -S src -B build -G Ninja -DCMAKE_PREFIX_PATH=<path-to-Qt>
cmake --build build
```

Test images are loaded relative to the working directory; copy the `Image *.jpg` files
from `bin/` next to the built executable.

## Structure

```text
src/    C++ / Qt source (main.cpp, mainwindow.*, CMakeLists.txt)
bin/    prebuilt Windows executable + Qt runtime + test images
docs/   figures used in this README
```
