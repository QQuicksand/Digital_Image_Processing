#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <cmath>
#include <algorithm>
#include <QDebug>
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene1 = new QGraphicsScene(this);
    scene2 = new QGraphicsScene(this);
    scene3 = new QGraphicsScene(this);
    scene4 = new QGraphicsScene(this);
    scene5 = new QGraphicsScene(this);
    scene6 = new QGraphicsScene(this);
    scene7 = new QGraphicsScene(this);
    scene8 = new QGraphicsScene(this);
    scene9 = new QGraphicsScene(this);
    scene10 = new QGraphicsScene(this);
    scene11 = new QGraphicsScene(this);
    scene12 = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene1);
    ui->graphicsView2->setScene(scene2);
    ui->graphicsView3->setScene(scene3);
    ui->graphicsView4->setScene(scene4);
    ui->graphicsView5->setScene(scene5);
    ui->graphicsView6->setScene(scene6);
    ui->graphicsView7->setScene(scene7);
    ui->graphicsView8->setScene(scene8);
    ui->graphicsView9->setScene(scene9);
    ui->graphicsView10->setScene(scene10);
    ui->graphicsView11->setScene(scene11);
    ui->graphicsView12->setScene(scene12);

    QSize viewSize(380, 240);
    ui->graphicsView->setFixedSize(viewSize);
    ui->graphicsView2->setFixedSize(viewSize);
    ui->graphicsView3->setFixedSize(viewSize);
    ui->graphicsView4->setFixedSize(viewSize);
    ui->graphicsView5->setFixedSize(viewSize);
    ui->graphicsView6->setFixedSize(viewSize);
    ui->graphicsView7->setFixedSize(viewSize);
    ui->graphicsView8->setFixedSize(viewSize);
    ui->graphicsView9->setFixedSize(viewSize);
    ui->graphicsView10->setFixedSize(viewSize);
    ui->graphicsView11->setFixedSize(viewSize);
    ui->graphicsView12->setFixedSize(viewSize);
    ui->graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView10->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView11->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView12->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::applyThreshold);
    connect(ui->horizontalSlider2, &QSlider::valueChanged, this, &MainWindow::adjustResolution);
    connect(ui->horizontalSlider3, &QSlider::valueChanged, this, static_cast<void (MainWindow::*)(int)>(&MainWindow::grayScale));
    connect(ui->horizontalSlider4, SIGNAL(valueChanged(int)), this, SLOT(bright_contrast(int)));
    connect(ui->horizontalSlider5, SIGNAL(valueChanged(int)), this, SLOT(bright_contrast(int)));

    images();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::images(){
    originImage = QImage("oly.jpg");

    display(originImage, scene1);
    ui->label1->setText("Original Image");

    scene4->clear();
    QGraphicsScene* histogram = hist(originImage);
    ui->graphicsView4->setScene(histogram);
    ui->graphicsView4->setSceneRect(histogram->sceneRect());

    grayImageA = QImage(originImage.size(), QImage::Format_Grayscale8);
    grayImageB = QImage(originImage.size(), QImage::Format_Grayscale8);

    for (int y = 0; y < originImage.height(); ++y) {
        for (int x = 0; x < originImage.width(); ++x) {
            QRgb pixel = originImage.pixel(x, y);
            int grayA = (qRed(pixel) + qGreen(pixel) + qBlue(pixel)) / 3;
            int grayB = qRound(0.299 * qRed(pixel) + 0.587 * qGreen(pixel) + 0.114 * qBlue(pixel));
            grayImageA.setPixel(x, y, qRgb(grayA, grayA, grayA));
            grayImageB.setPixel(x, y, qRgb(grayB, grayB, grayB));
        }
    }

    connect(ui->pushButton1, &QPushButton::clicked, [this]() {
        updateImage(0);
        ui->label2->setText("GrayscaleA : (R+G+B)/3");
    });

    connect(ui->pushButton2, &QPushButton::clicked, [this]() {
        updateImage(1);
        ui->label2->setText("GrayscaleB : 0.299R+0.587G+0.114B");
    });

    connect(ui->pushButton3, &QPushButton::clicked, [this]() {
        updateImage(2);
        ui->label2->setText("Subtract |A - B|");
    });

    connect(ui->pushButton4, &QPushButton::clicked, this, [this]() {
        equalization();
        ui->label6->setText("Automatic Contrast Adjustment");
    });

    connect(ui->Button1, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->Button2, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    updateImage(0);
    bright_contrast(0);
}

void MainWindow::updateImage(int method){

    if (method == 0) {
        gImage = grayImageA;
    } else if (method == 1) {
        gImage = grayImageB;
    } else if (method == 2){
        gImage = QImage(originImage.size(), QImage::Format_Grayscale8);
        for (int y = 0; y < originImage.height(); ++y) {
            for (int x = 0; x < originImage.width(); ++x) {
                int grayA = qGray(grayImageA.pixel(x, y));
                int grayB = qGray(grayImageB.pixel(x, y));
                int diff = std::abs(grayA - grayB);
                gImage.setPixel(x, y, qRgb(diff, diff, diff));
            }
        }
    }
    display(gImage, scene2);

    scene3->clear();
    QGraphicsScene* histogram = hist(gImage);
    ui->graphicsView3->setScene(histogram);
    ui->graphicsView3->setSceneRect(histogram->sceneRect());
}

void MainWindow::applyThreshold(int threshold){
    if (gImage.isNull()) return;

    QImage binaryImage(gImage.size(), QImage::Format_Mono);
    for (int y = 0; y < gImage.height(); ++y) {
        for (int x = 0; x < gImage.width(); ++x) {
            int gray = qGray(gImage.pixel(x, y));
            binaryImage.setPixel(x, y, gray < threshold ? 0 : 1);
        }
    }
    ui->label3->setText(QString("Binary Image -> Threshold : %1").arg(threshold));
    display(binaryImage, scene5);

    scene6->clear();
    QGraphicsScene* histogram = hist(binaryImage);
    ui->graphicsView6->setScene(histogram);
    ui->graphicsView6->setSceneRect(histogram->sceneRect());
}

void MainWindow::adjustResolution(int value){
    int scaleFactor = ui->horizontalSlider2->value();
    int newWidth = originImage.width() * scaleFactor / 100;
    int newHeight = originImage.height() * scaleFactor / 100;

    QImage resizedImage = resizeImage(gImage, newWidth, newHeight);
    display(resizedImage, scene7);
    ui->label4->setText(QString("Resized Image (%1%)").arg(scaleFactor));

    scene8->clear();
    QGraphicsScene* histogram = hist(resizedImage);
    ui->graphicsView8->setScene(histogram);
    ui->graphicsView8->setSceneRect(histogram->sceneRect());
}

void MainWindow::grayScale(int value){
    int levels = ui->horizontalSlider3->value();
    QImage adjustedImage = grayScale(gImage, levels);
    display(adjustedImage, scene7);
    ui->label4->setText(QString("Gray Levels -> %1").arg(levels));

    scene8->clear();
    QGraphicsScene* histogram = hist(adjustedImage);
    ui->graphicsView8->setScene(histogram);
    ui->graphicsView8->setSceneRect(histogram->sceneRect());
}

QImage MainWindow::resizeImage(const QImage& image, int newWidth, int newHeight){
    QImage result(newWidth, newHeight, QImage::Format_Grayscale8);
    double scaleX = static_cast<double>(image.width()) / newWidth;
    double scaleY = static_cast<double>(image.height()) / newHeight;

    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            double srcX = x * scaleX;
            double srcY = y * scaleY;

            int x1 = static_cast<int>(srcX);
            int y1 = static_cast<int>(srcY);
            int x2 = std::min(x1 + 1, image.width() - 1);
            int y2 = std::min(y1 + 1, image.height() - 1);
            double fx = srcX - x1;
            double fy = srcY - y1;

            int q11 = qGray(image.pixel(x1, y1));
            int q12 = qGray(image.pixel(x1, y2));
            int q21 = qGray(image.pixel(x2, y1));
            int q22 = qGray(image.pixel(x2, y2));
            int gray = static_cast<int>( (1-fx)*(1-fy)*q11 + (1-fx)*fy*q12 + fx*(1-fy)*q21 + fx*fy*q22 );

            result.setPixel(x, y, qRgb(gray, gray, gray));
        }
    }
    return result;
}

QImage MainWindow::grayScale(const QImage& image, int levels){
    QImage result(image.size(), QImage::Format_Grayscale8);
    int factor = 256 / levels;

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            int gray = qGray(image.pixel(x, y));
            gray = (gray / factor) * factor;
            result.setPixel(x, y, qRgb(gray, gray, gray));
        }
    }
    return result;
}
void MainWindow::bright_contrast(int value){
    int brightness = ui->horizontalSlider4->value() ;
    int contrast = ui->horizontalSlider5->value();

    QImage adjustedImage = bright_contrast(gImage, brightness, contrast);
    display(adjustedImage, scene9);
    ui->label5->setText(QString("Brightness : %1 & Contrast : %2").arg(brightness).arg(contrast));

    scene10->clear();
    QGraphicsScene* histogram = hist(adjustedImage);
    ui->graphicsView10->setScene(histogram);
    ui->graphicsView10->setSceneRect(histogram->sceneRect());
}

QImage MainWindow::bright_contrast(const QImage& image, int brightness, double contrast){
    QImage result = image.copy();
    contrast = (contrast + 100) / 100.0;

    for (int y = 0; y < result.height(); ++y) {
        for (int x = 0; x < result.width(); ++x) {
            int gray = qGray(image.pixel(x, y));

            gray = static_cast<int>((gray - 128) * contrast + 128);
            gray += brightness;
            gray = std::max(0, std::min(gray, 255));

            result.setPixel(x, y, qRgb(gray, gray, gray));
        }
    }
    return result;
}

void MainWindow::equalization(){
    QImage adjustedImage = equalization(gImage);
    display(adjustedImage, scene11);

    scene12->clear();
    QGraphicsScene* histogram = hist(adjustedImage);
    ui->graphicsView12->setScene(histogram);
    ui->graphicsView12->setSceneRect(histogram->sceneRect());
}

QImage MainWindow::equalization(const QImage &image){
    QImage result = image.copy();
    int width = image.width();
    int height = image.height();
    int totalPixels = width * height;

    QVector<int> histogram(256, 0);
    for (int y = 0; y < height; ++y) {
        const uchar* line = result.constScanLine(y);
        for (int x = 0; x < width; ++x) {
            histogram[line[x]]++;
        }
    }

    // CDF
    QVector<int> cdf(256);
    cdf[0] = histogram[0];
    for (int i = 1; i < 256; ++i) {
        cdf[i] = cdf[i-1] + histogram[i];
    }

    // look at table LUT
    QVector<uchar> lut(256);
    for (int i = 0; i < 256; ++i) {
        lut[i] = qBound(0, (cdf[i] * 255) / totalPixels, 255);
    }

    // equalization histogram
    for (int y = 0; y < height; ++y) {
        uchar* line = result.scanLine(y);
        for (int x = 0; x < width; ++x) {
            line[x] = lut[line[x]];
        }
    }

    return result;
}

void MainWindow::display(const QImage& image, QGraphicsScene* scene){
    scene->clear();
    QPixmap pixmap = QPixmap::fromImage(image);
    QGraphicsPixmapItem* pixmapItem = scene->addPixmap(pixmap);

    scene->setSceneRect(pixmap.rect());
    QGraphicsView* view = qobject_cast<QGraphicsView*>(scene->views().first());
    view->setSceneRect(scene->sceneRect());
}


QGraphicsScene* MainWindow::hist(const QImage &image){
    int width = 300;
    int height = 200;
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width, height);
    scene->addRect(scene->sceneRect(), QPen(Qt::NoPen), QBrush(Qt::white));

    // Draw grid
    QPen gridPen(Qt::lightGray, 1, Qt::DotLine);
    for (int i = 0; i<5; ++i) {
        int y = 140 - i * 160/6;
        scene->addLine(40, y, width - 20, y, gridPen);
    }
    for (int i = 0; i < 256; i += 32) {
        int x = 40 + i * 240/256;
        scene->addLine(x, 30, x, height - 30, gridPen);
    }

    // Draw axes
    QPen axisPen(Qt::black, 1);
    scene->addLine(40, height - 30, 270, height - 30, axisPen);
    scene->addLine(40, 30, 40, height - 30, axisPen);

    // Draw histogram bars
    QVector<int> histogram(256, 0);
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            int gray = qGray(image.pixel(x, y));
            histogram[gray]++;
        }
    }
    int maxCount = *std::max_element(histogram.begin(), histogram.end());
    double scale = (height - 40.0) / maxCount;

    QPen barPen(Qt::blue);
    for (int i = 0; i < 256; ++i) {
        int barHeight = static_cast<int>(histogram[i] * scale);
        int x = 40 + i * (width - 60) / 256;
        scene->addRect(x, height - 30 - barHeight, 1, barHeight, barPen);
    }

    QFont labelFont("Courier", 8);

    // X-axis labels
    for (int i = 0; i < 256; i += 32) {
        int x = 40 + i * (width - 60) / 256;
        QGraphicsTextItem* label = scene->addText(QString::number(i), labelFont);
        label->setPos(x - 5, height-30);
    }
    QGraphicsTextItem* xAxisLabel = scene->addText("Gray values", labelFont);
    xAxisLabel->setPos(width / 2 - 30, height-20);

    // Y-axis labels
    for (int i = 0; i < 6; ++i) {
        int labelValue = (maxCount / 6) * i;
        int y = height - 20 - i * (height - 40) / 6;
        QGraphicsTextItem* label = scene->addText(QString::number(labelValue), labelFont);
        label->setPos(5, y-20);
    }
    QGraphicsTextItem* yAxisLabel = scene->addText("Frequency", labelFont);
    yAxisLabel->setPos(0, 5);

    return scene;
}
