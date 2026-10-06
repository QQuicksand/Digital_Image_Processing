# Digital Image Processing

## Image Histogram and Gray-Level Operations

### Histogram of an Image

- Read a `.64` file and convert the ASCII characters `0–9` and `A–V` into grayscale values `0–31`.
- Use the generated `64 × 64` array to construct the image.
- Count the frequency of all 32 grayscale values.
- Display the histogram using Qt.

### Arithmetic Operations of an Image Array

#### Add or Subtract a Constant

- Add a fixed constant to every grayscale value, with the maximum value limited to 31.
- Subtract a fixed constant from every grayscale value, with the minimum value limited to 0.
- Visualize the resulting image and histogram interactively.

#### Multiply by a Constant

- Multiply every grayscale value by a fixed constant.
- Visualize the resulting image and histogram.

#### Image Averaging

- Create a new image by averaging two input images pixel by pixel.

#### Difference / Gradient Image

Implement:

```text
g(x, y) = f(x, y) - f(x-1, y)
```

The operation emphasizes intensity differences and image boundaries.

## Qt GUI

The program provides a Qt interface for:

- Loading and displaying images
- Viewing image histograms
- Adjusting arithmetic-operation parameters
- Comparing processed results
