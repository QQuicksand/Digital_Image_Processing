#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QImage>
#include <QPixmap>
#include <QGraphicsTextItem>
#include <QElapsedTimer>
#include <QButtonGroup>
#include <cmath>
#include <QDebug>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene1 = new QGraphicsScene(this);
    scene2 = new QGraphicsScene(this);
    scene4 = new QGraphicsScene(this);
    scene5 = new QGraphicsScene(this);
    scene6 = new QGraphicsScene(this);
    scene7 = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene1);
    ui->graphicsView_2->setScene(scene2);
    ui->graphicsView_4->setScene(scene4);
    ui->graphicsView_5->setScene(scene5);
    ui->graphicsView_6->setScene(scene6);
    ui->graphicsView_7->setScene(scene7);
    ui->graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView_2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView_4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView_5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView_6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView_7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::filters);
    connect(ui->spinBox2, &QSpinBox::valueChanged, this, &MainWindow::applyMarr);
    connect(ui->doubleSpinBox_2, &QDoubleSpinBox::valueChanged, this, &MainWindow::enhancement);
    connect(ui->doubleSpinBox_3, &QDoubleSpinBox::valueChanged, this, &MainWindow::enhancement);
    connect(ui->doubleSpinBox_4, &QDoubleSpinBox::valueChanged, this, &MainWindow::enhancement);
    connect(ui->doubleSpinBox_5, &QDoubleSpinBox::valueChanged, this, &MainWindow::enhancement);
    connect(ui->doubleSpinBox_6, &QDoubleSpinBox::valueChanged, this, &MainWindow::enhancement);
    connect(ui->doubleSpinBox_7, &QDoubleSpinBox::valueChanged, this, &MainWindow::enhancement);
    connect(ui->doubleSpinBox_8, &QDoubleSpinBox::valueChanged, this, &MainWindow::applyMarr);

    connect(ui->verticalSlider, &QSlider::valueChanged, this, &MainWindow::filters);
    connect(ui->radioButton1, &QRadioButton::toggled, this, &MainWindow::filters);
    connect(ui->radioButton2, &QRadioButton::toggled, this, &MainWindow::filters);
    connect(ui->radioButton3, &QRadioButton::toggled, this, &MainWindow::filters);
    connect(ui->radioButton4, &QRadioButton::toggled, this, &MainWindow::filters);
    connect(ui->radioButton5, &QRadioButton::toggled, this, &MainWindow::enhancement);
    connect(ui->radioButton6, &QRadioButton::toggled, this, &MainWindow::enhancement);

    images();
}

MainWindow::~MainWindow(){
    delete ui;
}

// load images & set buttons
void MainWindow::images(){
    image1 = QImage("Image 3-1.jpg");
    image2 = QImage("Image 3-2.JPG");
    image3 = QImage("Image 3-3.JPG");
    image4 = QImage("Image 3-4.JPG");
    image5 = QImage("Image 4-1.jpg");
    image6 = QImage("Image 4-2.jpg");

    connect(ui->pushButton1, &QPushButton::clicked, [this](){
        ui->label->setText("Image 1");
        image = image1;
        display(image, scene1);
        filters();
    });

    connect(ui->pushButton2, &QPushButton::clicked, [this](){
        ui->label->setText("Image 2");
        image = image2;
        display(image, scene1);
        filters();
    });

    connect(ui->pushButton3, &QPushButton::clicked, [this](){
        ui->label->setText("Image 3");
        image = image3;
        display(image, scene1);
        filters();
    });

    connect(ui->pushButton4, &QPushButton::clicked, [this](){
        ui->label->setText("Image 4");
        image = image4;
        display(image, scene1);
        filters();
    });

    connect(ui->pushButton5, &QPushButton::clicked, [this](){
        ui->label->setText("Image 1");
        image = image1;
        display(image, scene4);
        filters();
        applyMarr();
    });

    connect(ui->pushButton6, &QPushButton::clicked, [this](){
        ui->label->setText("Image 2");
        image = image2;
        display(image, scene4);
        filters();
        applyMarr();
    });

    connect(ui->pushButton7, &QPushButton::clicked, [this](){
        ui->label->setText("Image 3");
        image = image3;
        display(image, scene4);
        filters();
        applyMarr();
    });

    connect(ui->pushButton8, &QPushButton::clicked, [this](){
        ui->label->setText("Image 4");
        image = image4;
        display(image, scene4);
        filters();
        applyMarr();
    });

    connect(ui->pushButton9, &QPushButton::clicked, [this](){
        ui->label->setText("Image 1");
        image = image5;
        display(image, scene6);
        enhancement();
    });

    connect(ui->pushButton10, &QPushButton::clicked, [this](){
        ui->label->setText("Image 2");
        image = image6;
        display(image, scene6);
        enhancement();
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
}

void MainWindow::display(const QImage& image, QGraphicsScene* scene){
    scene->clear();
    QPixmap pixmap = QPixmap::fromImage(image);
    QGraphicsPixmapItem* pixmapItem = scene->addPixmap(pixmap);
    scene->setSceneRect(pixmap.rect());
    if (scene == scene1) {
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if (scene == scene2) {
        ui->graphicsView_2->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if (scene == scene4){
        ui->graphicsView_4->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if (scene == scene5){
        ui->graphicsView_5->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if (scene == scene6){
        ui->graphicsView_6->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}

//PART: Spatial Filter
//use radioButton to apply filter & mask size/coefficients
void MainWindow::filters() {
    int size = ui->spinBox->value();
    double coefficient = ui->verticalSlider->value();
    QElapsedTimer timer;
    timer.start();

    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(image.height());

    QImage fImage = apply(image, size, coefficient);
    display(fImage, scene2);

    QString name;
    if (ui->radioButton1->isChecked()) name = "low-pass filter";
    else if (ui->radioButton2->isChecked()) name = "high-pass filter";
    else if (ui->radioButton3->isChecked()) name = "order-statistics filter";
    else if (ui->radioButton4->isChecked()) name = "sobel filter";

    ui->statusbar->showMessage(QString("time taken (%1): %2 ms").arg(name).arg(timer.elapsed()));
    ui->progressBar->setValue(image.height());
}

//apply each filters
QImage MainWindow::apply(const QImage& image, int size, double coefficient) {
    if (ui->radioButton1->isChecked()) {
        ui->label_4->setText(QString("mask size: %1x%1").arg(size));
        return smooth(image, size);
    } else if (ui->radioButton2->isChecked()) {
        ui->label_4->setText(QString("mask size: %1x%1, coefficient: %2").arg(size).arg(coefficient));
        return sharp(image, size, coefficient);
    } else if (ui->radioButton3->isChecked()) {
        ui->label_4->setText(QString("mask size: %1x%1").arg(size));
        return order(image, size);
    } else if (ui->radioButton4->isChecked()) {
        return sobel(image);
    }
    return image;
}

//apply filter with given kernel
QImage MainWindow::fil(const QImage& image, const QVector<QVector<double>>& kernel) {
    int padding = kernel.size() / 2;
    QImage padImage = pad(image, padding);
    QImage result = image;

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            double sum = 0;     //accummulate convolution result
            for (int ky = 0; ky < kernel.size(); ++ky) {
                for (int kx = 0; kx < kernel[0].size(); ++kx) {
                    int px = x + kx;        //shift pixel by x-direction
                    int py = y + ky;        //shift pixel in y-direction
                    sum += qGray(padImage.pixelColor(px, py).rgb()) * kernel[ky][kx];       //product of grayscaleValue and kernel
                }
            }
            int value = qBound(0, static_cast<int>(sum), 255);      //clamp the result in [0, 255]
            result.setPixelColor(x, y, QColor(value, value, value));
        }
        ui->progressBar->setValue(y);
    }
    return result;
}

QImage MainWindow::pad(const QImage& image, int padding) {
    QImage padImage(image.width() + 2 * padding, image.height() + 2 * padding, image.format());
    padImage.fill(Qt::black);

    //copy the image to the center of padded image
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            padImage.setPixelColor(x + padding, y + padding, image.pixelColor(x, y));
        }
    }

    //pad left & right edges
    for (int y = 0; y < padImage.height(); ++y) {
        for (int x = 0; x < padding; ++x) {
            padImage.setPixelColor(x, y, padImage.pixelColor(2 * padding - x, y));
            padImage.setPixelColor(padImage.width() - 1 - x, y, padImage.pixelColor(padImage.width() - 1 - 2 * padding + x, y));
        }
    }

    //pad up & down edges
    for (int x = 0; x < padImage.width(); ++x) {
        for (int y = 0; y < padding; ++y) {
            padImage.setPixelColor(x, y, padImage.pixelColor(x, 2 * padding - y));
            padImage.setPixelColor(x, padImage.height() - 1 - y, padImage.pixelColor(x, padImage.height() - 1 - 2 * padding + y));
        }
    }

    return padImage;
}

QImage MainWindow::smooth(const QImage& image, int size) {
    QVector<QVector<double>> kernel(size, QVector<double>(size, 1.0 / (size * size)));
    return fil(image, kernel);
}

QImage MainWindow::sharp(const QImage& image, int size, double coefficient) {
    QVector<QVector<double>> kernel(size, QVector<double>(size, -coefficient / (size * size)));
    kernel[size / 2][size / 2] += 1 + coefficient;      //increase center weight
    return fil(image, kernel);
}

QImage MainWindow::order(const QImage& image, int size) {
    int padding = size / 2;
    QImage padImage = pad(image, padding);
    QImage result = image;

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            std::vector<int> values;
            for (int dy = -padding; dy <= padding; ++dy) {
                for (int dx = -padding; dx <= padding; ++dx) {
                    values.push_back(qGray(padImage.pixelColor(x + padding + dx, y + padding + dy).rgb()));  //get grayscaleValue of neighbor
                }
            }
            std::nth_element(values.begin(), values.begin() + values.size() / 2, values.end());     //median values
            int median = values[values.size() / 2];
            result.setPixelColor(x, y, QColor(median, median, median));
        }
        ui->progressBar->setValue(y);
    }
    return result;
}

QImage MainWindow::sobel(const QImage& image) {
    QVector<QVector<double>> kernelX = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};        //x-kernel
    QVector<QVector<double>> kernelY = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};        //y-kernel

    QImage gradX = fil(image, kernelX);
    QImage gradY = fil(image, kernelY);

    QImage result = image;
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            int gx = qGray(gradX.pixelColor(x, y).rgb());       //x-gradient
            int gy = qGray(gradY.pixelColor(x, y).rgb());       //y-gradient
            int magnitude = qMin(255, static_cast<int>(std::sqrt(gx*gx + gy*gy)));      //gradient magnitude
            result.setPixelColor(x, y, QColor(magnitude, magnitude, magnitude));        //set gradient magnitude to pixel
        }
        ui->progressBar->setValue(y);
    }
    return result;
}


//PART: image enhancement
//apply enhancement(local & equalization)
void MainWindow::enhancement(){
    int lSize = ui->doubleSpinBox_2->value();       //local region size
    double k0 = ui->doubleSpinBox_3->value();
    double k1 = ui->doubleSpinBox_4->value();
    double k2 = ui->doubleSpinBox_5->value();
    double k3 = ui->doubleSpinBox_6->value();
    double c = ui->doubleSpinBox_7->value();
    QElapsedTimer timer;
    timer.start();

    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(image.height());

    QImage enImage;
    if (ui->radioButton5->isChecked()){
        enImage = localEn(image, lSize, k0, k1, k2, k3, c);
        ui->label_9->setText("Local Enhancement");
    } else if (ui->radioButton6->isChecked()){
        enImage = histEq(image);
        ui->label_9->setText("Histogram Equalization");
    }
    display(enImage, scene7);

    QString name;
    if (ui->radioButton5->isChecked()) name="local enhancement";
    else if (ui->radioButton6->isChecked()) name="histogram equalization";

    ui->statusbar->showMessage(QString("time taken (%1): %2 ms").arg(name).arg(timer.elapsed()));
    ui->progressBar2->setValue(image.height());
}

//local enhancement method
QImage MainWindow::localEn(const QImage& image, int size, double k0, double k1, double k2, double k3, double c){
    int padding = size / 2;
    QImage padImage = pad(image, padding);
    QImage result = image.copy();

    double mG = 0.0;        //global mean
    double sG = 0.0;        //global standard deviation
    int totalPixels = image.width() * image.height();

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            int pixel = qGray(image.pixel(x, y));
            mG += pixel;
            sG += pixel * pixel;
        }
    }
    mG /= totalPixels;
    sG = sqrt(sG / totalPixels - mG * mG);

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            double mL = 0.0;        //local mean
            double vL = 0.0;     //local variance

            for (int dy = -padding; dy <= padding; ++dy) {
                for (int dx = -padding; dx <= padding; ++dx) {
                    int pixel = qGray(padImage.pixel(x + padding + dx, y + padding + dy));
                    mL += pixel;
                    vL += pixel * pixel;
                }
            }
            mL /= (size * size);
            vL = (vL / (size * size)) - (mL * mL);
            double sL = sqrt(vL);       //local standard deviation

            int pixel = qGray(image.pixel(x, y));
            double enhance = pixel;

            if (k0 * mG <= mL && mL <= k1 * mG &&
                k2 * sG <= sL && sL <= k3 * sG) {

                enhance = pixel * c;
            }else{
                enhance = pixel;
            }

            int value = qBound(0, qRound(enhance), 255);
            result.setPixelColor(x, y, QColor(value, value, value));
        }
        ui->progressBar2->setValue(y);
    }
    return result;
}

//histogram equalization
QImage MainWindow::histEq(const QImage& image) {
    QImage output = image.copy();
    int histogram[256] = {0};
    int cdf[256] = {0};

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            histogram[qGray(image.pixel(x,y))]++;
        }
    }

    cdf[0] = histogram[0];
    for (int i = 1; i < 256; ++i) {
        cdf[i] = cdf[i-1] + histogram[i];
    }

    int cdfMin = 0;
    for (int i = 0; i < 256; ++i) {
        if (cdf[i] > 0) {
            cdfMin = cdf[i];
            break;
        }
    }
    int totalPixels = image.width() * image.height();
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            int value = image.pixelColor(x, y).value();
            int newValue = static_cast<int>(255.0 * cdf[value] / totalPixels);
            output.setPixelColor(x, y, QColor(newValue, newValue, newValue));
        }
        ui->progressBar2->setValue(y);
    }
    return output;
}

//PART: Marr Hildreth
void MainWindow::applyMarr(){
    int kernelSize = ui->spinBox2->value();
    double sigma = ui->doubleSpinBox_8->value();

    QElapsedTimer timer;
    timer.start();

    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(image.height());

    QImage gray = image.convertToFormat(QImage::Format_Grayscale8);
    QVector<QVector<double>> kernel = logKernel(kernelSize, sigma);
    QImage log = conv(gray, kernel);
    QImage edImage = zeroCrossing(log);

    display(edImage, scene5);
    ui->label_7->setText("Marr Hildreth method");

    ui->statusbar->showMessage(QString("Marr-Hildreth edge detection time: %1 ms").arg(timer.elapsed()));
    ui->progressBar3->setValue(image.height());
}

QImage MainWindow::marr(const QImage& image, int kernelSize, double sigma){
    QImage gray = image.convertToFormat(QImage::Format_Grayscale8);

    // Generate LoG kernel
    QVector<QVector<double>> kernel = logKernel(kernelSize, sigma);
    qDebug() << "LoG Kernel:" << kernel;

    // Apply convolution with the LoG kernel
    QImage logResult = conv(gray, kernel);

    // Perform zero-crossing detection to extract edges
    QImage edges = zeroCrossing(logResult);

    return edges;
}

QVector<QVector<double>> MainWindow::logKernel(int size, double sigma) {
    int halfSize = size / 2;
    QVector<QVector<double>> kernel(size, QVector<double>(size));
    double sigma2 = sigma * sigma;
    double normalization = -1.0 / (2* M_PI * sigma2);

    for (int y = -halfSize; y <= halfSize; ++y) {
        for (int x = -halfSize; x <= halfSize; ++x) {
            double r2 = x * x + y * y;
            double value = normalization * ((r2 - 2 * sigma2) / (sigma2*sigma2) * std::exp(-r2 / (2 * sigma2)));
            kernel[y + halfSize][x + halfSize] = value;
        }
        ui->progressBar3->setValue(y);
    }
    return kernel;
}

QImage MainWindow::conv(const QImage &input, const QVector<QVector<double>> &kernel) {
    int kSize = kernel.size();
    int halfKSize = kSize / 2;
    QImage output(input.size(), QImage::Format_Grayscale16);

    for (int y = halfKSize; y < input.height() - halfKSize; ++y) {
        for (int x = halfKSize; x < input.width() - halfKSize; ++x) {
            double sum = 0.0;
            for (int ky = -halfKSize; ky <= halfKSize; ++ky) {
                for (int kx = -halfKSize; kx <= halfKSize; ++kx) {
                    sum += qGray(input.pixel(x + kx, y + ky)) * kernel[ky + halfKSize][kx + halfKSize];
                }
            }
            int value = qBound(0, static_cast<int>(sum+128), 255);
            output.setPixel(x, y, value);
        }
        ui->progressBar3->setValue(y);
    }
    return output;
}

QImage MainWindow::zeroCrossing(const QImage &input) {
    QImage output(input.size(), QImage::Format_Grayscale8);
    output.fill(Qt::black);
    int threshold = 0; // Adjust this value as needed

    for (int y = 1; y < input.height() - 1; ++y) {
        for (int x = 1; x < input.width() - 1; ++x) {
            int current = qGray(input.pixel(x, y));
            int right = qGray(input.pixel(x + 1, y));
            int down = qGray(input.pixel(x, y + 1));


            if (std::abs(current - right) > threshold || std::abs(current - down) > threshold) {
                output.setPixelColor(x, y, Qt::white); // Mark edge
            }
        }
        ui->progressBar3->setValue(y);
    }
    return output;
}
