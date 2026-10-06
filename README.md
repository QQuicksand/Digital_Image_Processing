# Digital Image Processing — C++ / Qt

A collection of digital image processing projects implemented in **C++ with Qt**, developed for the Digital Image Processing course at **National Taiwan University**.

The projects cover spatial- and frequency-domain image processing, image enhancement, color-space transformation, segmentation, geometric transformation, wavelets, and superpixels. Each assignment is implemented as an interactive Qt application for visualizing processing results.

## Highlights

- C++17 application development with Qt Widgets
- Interactive image-processing GUI using Qt
- CMake-based project configuration
- Pixel-level image manipulation and algorithm implementation
- Spatial-domain filtering and edge detection
- Frequency-domain filtering and image restoration
- Color-space transformation and image segmentation
- Geometric image transformation
- Discrete Wavelet Transform (DWT)
- K-means and SLIC superpixel segmentation
- OpenCV used for selected advanced image-processing operations

## Technologies

- **Languages:** C++17
- **GUI:** Qt / Qt Widgets
- **Build:** CMake
- **Computer Vision:** OpenCV
- **Concepts:** Digital Image Processing, Computer Vision, Image Enhancement, Segmentation

## Projects

### HW1 — Gray-Level Operations and Histogram Analysis

Implemented fundamental gray-level image operations and histogram analysis.

- Gray-level addition, subtraction, and multiplication
- Image averaging
- Gradient image generation
- Histogram calculation and visualization
- Interactive image processing through a Qt GUI

### HW2 — Image Enhancement and Histogram Processing

Implemented fundamental intensity and image-enhancement operations.

- Thresholding
- Grayscale conversion
- Brightness and contrast adjustment
- Image resizing
- Histogram equalization
- Interactive parameter adjustment through Qt

### HW3 — Spatial Filtering and Edge Detection

Implemented spatial-domain filtering and edge-detection techniques.

- Smoothing filters
- Sharpening filters
- Order-statistics filtering
- Sobel edge detection
- Marr-Hildreth edge detection
- Zero-crossing detection
- Local enhancement
- Histogram equalization
- Convolution and image padding

### HW4 — Frequency-Domain Processing and Image Restoration

Explored frequency-domain image processing using Fourier analysis.

- Fourier transform processing
- Frequency-spectrum shifting
- Ideal frequency filters
- Butterworth filters
- Gaussian filters
- Homomorphic filtering
- Image restoration

### HW5 — Color Processing and Image Segmentation

Implemented color-space transformations and clustering-based segmentation.

- RGB → CMY
- RGB → HSI
- RGB → XYZ
- RGB → YUV
- Pseudo-color mapping
- K-means image segmentation
- Segmentation in different color spaces
- Interactive segmentation parameters

### HW6 — Geometric Processing, Wavelets, and Superpixels

Implemented geometric transformations and advanced image-processing methods.

- Fisheye transformation
- Kaleidoscope transformation
- Wavy transformation
- Spiral transformation
- Ripple transformation
- Image fusion
- Discrete Wavelet Transform (DWT)
- Superpixel segmentation
- SLIC implementation

The SLIC algorithm is organized as a dedicated C++ module with `slic.cpp` and `slic.h`.

## GUI Development

The assignments use Qt Widgets to provide interactive interfaces for loading images, configuring processing parameters, and visualizing results.

Common Qt components include:

- `QMainWindow`
- `QGraphicsView`
- `QGraphicsScene`
- `QImage`
- `QPixmap`
- Qt signals and slots

## Project Structure

```text
Digital_Image_Processing/
├── README.md
├── .gitignore
├── docs/
│   └── screenshots/
├── HW1/
│   └── code/
│       ├── CMakeLists.txt
│       ├── main.cpp
│       ├── mainwindow.cpp
│       ├── mainwindow.h
│       └── mainwindow.ui
├── HW2/
│   └── code/
├── HW3/
│   └── code/
├── HW4/
│   └── code/
├── HW5/
│   └── code/
└── HW6/
    └── code/
        ├── CMakeLists.txt
        ├── main.cpp
        ├── mainwindow.cpp
        ├── mainwindow.h
        ├── mainwindow.ui
        ├── slic.cpp
        └── slic.h
```

## Building

Each assignment contains its own `CMakeLists.txt`.

For example:

```bash
cd HW6/code
cmake -S . -B build
cmake --build build
```

Open the corresponding CMake project in Qt Creator if you prefer a GUI-based development workflow.

> Build directories and IDE-generated files are intentionally excluded from this repository.

## Selected Results

Screenshots can be added here to demonstrate the interactive GUI and representative processing results.

Recommended examples:

1. **HW3 — Sobel / Marr-Hildreth edge detection**
2. **HW5 — K-means segmentation**
3. **HW6 — SLIC superpixel segmentation**

Example:

```markdown
![HW3 Edge Detection](docs/screenshots/hw3-edge-detection.png)
```

## Learning Outcomes

Through these projects, I gained hands-on experience with:

- C++ programming for image-processing applications
- Qt GUI development
- CMake-based C++ project organization
- Pixel-level image manipulation
- Spatial and frequency-domain processing
- Edge detection and image enhancement
- Color-space transformation
- Image segmentation
- Algorithm implementation and debugging
- Visualization of intermediate and final processing results
