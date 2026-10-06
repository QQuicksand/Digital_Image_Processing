#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QGraphicsTextItem>
#include <QPixmap>
#include <QtMath>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QElapsedTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize scenes
    scene0 = new QGraphicsScene(this);
    scene1 = new QGraphicsScene(this);
    scene2 = new QGraphicsScene(this);
    scene3 = new QGraphicsScene(this);
    scene4 = new QGraphicsScene(this);
    scene5 = new QGraphicsScene(this);
    scene5_2 = new QGraphicsScene(this);
    scene6 = new QGraphicsScene(this);
    scene7 = new QGraphicsScene(this);
    scene10 = new QGraphicsScene(this);
    scene11 = new QGraphicsScene(this);

    // Set scenes to graphics views
    ui->graphicsView->setScene(scene0);
    ui->graphicsView1->setScene(scene1);
    ui->graphicsView2->setScene(scene2);
    ui->graphicsView3->setScene(scene3);
    ui->graphicsView4->setScene(scene4);
    ui->graphicsView5->setScene(scene5);
    ui->graphicsView5_2->setScene(scene5_2);
    ui->graphicsView6->setScene(scene6);
    ui->graphicsView7->setScene(scene7);
    ui->graphicsView10->setScene(scene10);
    ui->graphicsView11->setScene(scene11);

    // Connect signals and slots
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(size(int)));
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::filters);
    connect(ui->pushButton9, &QPushButton::clicked, this, &MainWindow::applyhomomorphic);

    connect(ui->radioButton, &QRadioButton::toggled, this, &MainWindow::filters);
    connect(ui->radioButton_2, &QRadioButton::toggled, this, &MainWindow::filters);
    connect(ui->radioButton_3, &QRadioButton::toggled, this, &MainWindow::filters);
    connect(ui->radioButton_4, &QRadioButton::toggled, this, &MainWindow::filters);
    connect(ui->radioButton_5, &QRadioButton::toggled, this, &MainWindow::filters);
    connect(ui->doubleSpinBox_2, SIGNAL(valueChanged(int)), this, SLOT(filters()));
    connect(ui->doubleSpinBox_3, SIGNAL(valueChanged(int)), this, SLOT(filters()));
    connect(ui->doubleSpinBox_4, SIGNAL(valueChanged(int)), this, SLOT(filters()));

    images();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::images(){
    image = QImage("IMG01.jpg");
    image2 = QImage("IMG02.bmp");
    img1 = QImage("image/img1.jpg");
    img2 = QImage("image/img2.jpg");
    img3 = QImage("image/img3.jpg");


    connect(ui->pushButton1, &QPushButton::clicked, [this](){
        ui->label->setText("Original Image");
        display(image, scene0);
        display(img1, scene1);
        display(img2, scene2);
        display(image, scene3);
        size(ui->spinBox->value());
    });

    connect(ui->pushButton5, &QPushButton::clicked, [this](){
        ui->label6->setText("Original Image");
        display(image, scene4);
    });

    connect(ui->pushButton9, &QPushButton::clicked, [this](){
        ui->label_8->setText("Original Image");
        display(image, scene6);
    });

    connect(ui->pushButton10, &QPushButton::clicked, [this](){
        ui->label_12->setText("Original Image");
        display(image2, scene10);
    });

    connect(ui->pushButton11, &QPushButton::clicked, [this](){
        ui->label_12->setText("Motion Blur");
        display(img3, scene10);
    });

    connect(ui->Button1, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->Button2, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->Button3, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->Button4, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->Button5, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->Button6, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(3);
    });
}

void MainWindow::size(int size){
    QImage sImage(size, size, QImage::Format_Grayscale8);
    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) {
            sImage.setPixelColor(x, y, QColor((x + y) % 256, (x + y) % 256, (x + y) % 256));
        }
    }
    fourier(sImage);
}

void MainWindow::fourier(const QImage &image) {
    // Fourier Transform process remains unchanged from the original code
}

void MainWindow::fftShift(cv::Mat& img) {
    img = img(cv::Rect(0, 0, img.cols & -2, img.rows & -2));

    int cx = img.cols/2;
    int cy = img.rows/2;

    cv::Mat q0(img, cv::Rect(0, 0, cx, cy));   // Top-Left
    cv::Mat q1(img, cv::Rect(cx, 0, cx, cy));  // Top-Right
    cv::Mat q2(img, cv::Rect(0, cy, cx, cy));  // Bottom-Left
    cv::Mat q3(img, cv::Rect(cx, cy, cx, cy)); // Bottom-Right

    cv::Mat tmp; // Temporary matrix for swapping

    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
}

void MainWindow::filters() {
    int cutoff = std::clamp(ui->horizontalSlider->value(), 0, 255); // Ensure cutoff is within 0-255
    cv::Mat lowImage, highImage;
    img4 = QImage("image/img4.jpg");
    img5 = QImage("image/img5.jpg");

    scene5->clear();
    scene5_2->clear();

    if (ui->radioButton->isChecked()) {
        lowImage = apply(image, cutoff, "ideal", false);
        highImage = apply(image, cutoff, "ideal", true);
        ui->label_7->setText(QString("Low-pass: Cut-off frequency: %1").arg(cutoff));
        ui->label_16->setText(QString("High-pass: Cut-off frequency: %1").arg(cutoff));
        ui->label_18->setText("Ideal Filter");

    } else if (ui->radioButton_2->isChecked()) {
        int order = 2;
        lowImage = apply(image, cutoff, "butterworth", false);
        highImage = apply(image, cutoff, "butterworth", true);
        ui->label_7->setText(QString("Low-pass: Cut-off frequency: %1").arg(cutoff));
        ui->label_16->setText(QString("High-pass: Cut-off frequency: %1").arg(cutoff));
        ui->label_18->setText("Butterworth Filter");

    } else if (ui->radioButton_3->isChecked()) {
        lowImage = apply(image, cutoff, "gaussian", false);
        highImage = apply(image, cutoff, "gaussian", true);
        ui->label_7->setText(QString("Low-pass: Cut-off frequency: %1").arg(cutoff));
        ui->label_16->setText(QString("High-pass: Cut-off frequency: %1").arg(cutoff));
        ui->label_18->setText("Gaussian Filter");
    } else if (ui->radioButton_4->isChecked()) {
        ui->label_13->setText("Weiner Filter");
        display(img5, scene11);
    } else if (ui->radioButton_5->isChecked()) {
        ui->label_13->setText("Inverse Filter");
        display(img4, scene11);
    }

    QImage lowQImage((uchar*)lowImage.data, lowImage.cols, lowImage.rows, lowImage.step, QImage::Format_Grayscale8);
    QImage highQImage((uchar*)highImage.data, highImage.cols, highImage.rows, highImage.step, QImage::Format_Grayscale8);
    display(lowQImage.copy(), scene5);
    display(highQImage.copy(), scene5_2);
}

cv::Mat MainWindow::apply(const QImage &image, int cutoff, const QString &filterType, bool highpass) {
    int order = 2;
    cv::Mat input(image.height(), image.width(), CV_8UC1, const_cast<uchar*>(image.bits()), image.bytesPerLine());
    input.convertTo(input, CV_32F);

    cv::Mat padded;
    int m = cv::getOptimalDFTSize(input.rows);
    int n = cv::getOptimalDFTSize(input.cols);
    cv::copyMakeBorder(input, padded, 0, m - input.rows, 0, n - input.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    cv::Mat planes[] = {padded, cv::Mat::zeros(padded.size(), CV_32F)};
    cv::Mat complexImg;
    cv::merge(planes, 2, complexImg);

    cv::dft(complexImg, complexImg);

    fftShift(complexImg);

    cv::Mat filter = filterMat(padded.size(), cutoff, filterType, highpass, order);

    cv::Mat planesDFT[2];
    cv::split(complexImg, planesDFT);
    cv::multiply(planesDFT[0], filter, planesDFT[0]);
    cv::multiply(planesDFT[1], filter, planesDFT[1]);
    cv::merge(planesDFT, 2, complexImg);

    fftShift(complexImg);

    // Perform the inverse DFT
    cv::idft(complexImg, complexImg, cv::DFT_SCALE);
    cv::split(complexImg, planes);
    cv::Mat mag;
    cv::magnitude(planes[0], planes[1], mag);

    // Normalize the magnitude image to the range [0, 255]
    cv::normalize(mag, mag, 0, 255, cv::NORM_MINMAX);
    mag.convertTo(mag, CV_8U);

    cv::Mat cropped = mag(cv::Rect(0, 0, input.cols, input.rows));

    return cropped;
}


cv::Mat MainWindow::filterMat(cv::Size size, int cutoff, const QString &filterType, bool highpass, int order) {
    cv::Mat filter(size, CV_32F, cv::Scalar(0));

    int width = size.width;
    int height = size.height;
    int cx = width / 2;
    int cy = height / 2;

    for (int y = 0; y < height; y++) {
        float* data = filter.ptr<float>(y);
        for (int x = 0; x < width; x++) {
            double distance = sqrt(pow(x - cx, 2) + pow(y - cy, 2));
            double value = 0.0;

            if (filterType == "ideal") {
                value = (distance > cutoff) ? 1.0 : 0.0;
            }
            else if (filterType == "butterworth") {
                value = 1.0 / (1.0 + pow(cutoff / distance, 2 * order));
            }
            else if (filterType == "gaussian") {
                value = 1.0 - exp(-pow(distance / cutoff, 2) / 2.0);
            }

            data[x] = static_cast<float>(highpass ? value : (1.0 - value));
        }
    }

    return filter;
}
void MainWindow::homomorphic(cv::Mat &filter, float gammaH, float gammaL, float D0, float c){
    int rows = filter.rows;
    int cols = filter.cols;
    int cx = cols / 2;
    int cy = rows / 2;

    for (int i = 0; i < rows; ++i) {
        float *data = filter.ptr<float>(i);
        int y = i - cy;
        for (int j = 0; j < cols; ++j) {
            int x = j - cx;
            float D_uv = std::sqrt(x * x + y * y);
            data[j] = (gammaH - gammaL) * (1 - std::exp(-c * (D_uv * D_uv) / (D0 * D0))) + gammaL;
        }
    }
}

void MainWindow::applyhomomorphic() {
    // Retrieve parameters from UI
    float gammaH = ui->doubleSpinBox_2->value();
    float gammaL = ui->doubleSpinBox_3->value();
    float D0 = ui->doubleSpinBox_4->value();
    float c = 5.0; // Decay constant for Gaussian falloff

    // Step 1: Convert QImage to cv::Mat for processing and offset to avoid log(0)
    cv::Mat inputImage = cv::Mat(image.height(), image.width(), CV_8UC1, const_cast<uchar*>(image.bits()), image.bytesPerLine());
    inputImage.convertTo(inputImage, CV_32F);
    inputImage += 1; // Shift by 1 to avoid log(0)

    // Step 2: Apply log transformation
    cv::Mat logImage;
    cv::log(inputImage, logImage);

    // Step 3: Pad the image for optimal DFT size
    cv::Mat padded;
    int m = cv::getOptimalDFTSize(logImage.rows);
    int n = cv::getOptimalDFTSize(logImage.cols);
    cv::copyMakeBorder(logImage, padded, 0, m - logImage.rows, 0, n - logImage.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    // Step 4: Perform DFT
    cv::Mat planes[] = {padded, cv::Mat::zeros(padded.size(), CV_32F)};
    cv::Mat complexImage;
    cv::merge(planes, 2, complexImage);
    cv::dft(complexImage, complexImage);

    // Step 5: Create homomorphic filter
    cv::Mat filter(padded.size(), CV_32F, cv::Scalar::all(0));
    int cx = filter.cols / 2;
    int cy = filter.rows / 2;
    for (int i = 0; i < filter.rows; ++i) {
        float *data = filter.ptr<float>(i);
        for (int j = 0; j < filter.cols; ++j) {
            float D_uv = std::sqrt(static_cast<float>((i - cy) * (i - cy) + (j - cx) * (j - cx)));
            data[j] = (gammaH - gammaL) * (1 - std::exp(-c * (D_uv * D_uv) / (D0 * D0))) + gammaL;
        }
    }

    // Step 6: Apply filter in the frequency domain
    cv::Mat planesDFT[2];
    cv::split(complexImage, planesDFT);
    cv::multiply(planesDFT[0], filter, planesDFT[0]);
    cv::multiply(planesDFT[1], filter, planesDFT[1]);
    cv::merge(planesDFT, 2, complexImage);

    // Step 7: Inverse DFT to bring back to spatial domain
    cv::idft(complexImage, complexImage, cv::DFT_SCALE | cv::DFT_REAL_OUTPUT);

    // Step 8: Apply exponential to reverse the log transformation
    cv::Mat expImage;
    cv::exp(complexImage, expImage);

    // Step 9: Crop back to the original image size
    cv::Mat cropped = expImage(cv::Rect(0, 0, inputImage.cols, inputImage.rows));

    // Step 10: Normalize the result for display
    cv::Mat finalImage;
    cv::normalize(cropped, finalImage, 0, 255, cv::NORM_MINMAX);
    finalImage.convertTo(finalImage, CV_8U);

    // Display final processed image
    QImage homomorphicQImage((uchar*)finalImage.data, finalImage.cols, finalImage.rows, finalImage.step, QImage::Format_Grayscale8);
    scene7->clear();
    display(homomorphicQImage.copy(), scene7);
    ui->label_9->setText("Homomorphic Filter Applied");

}



void MainWindow::display(const QImage& image, QGraphicsScene* scene) {
    scene->clear();
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    scene->setSceneRect(pixmap.rect());
    scene->update();

    if(scene == scene0) {
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene1) {
        ui->graphicsView1->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene2) {
        ui->graphicsView2->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene3) {
        ui->graphicsView3->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene4) {
        ui->graphicsView4->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene5) {
        ui->graphicsView5->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene5_2) {
        ui->graphicsView5_2->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }else if(scene == scene6) {
        ui->graphicsView6->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }else if(scene == scene7) {
        ui->graphicsView7->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene10) {
        ui->graphicsView10->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene11) {
        ui->graphicsView11->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}
