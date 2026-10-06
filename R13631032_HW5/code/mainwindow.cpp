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

    scene1 = new QGraphicsScene(this);
    scene2 = new QGraphicsScene(this);
    scene3 = new QGraphicsScene(this);
    scene4 = new QGraphicsScene(this);
    scene5 = new QGraphicsScene(this);
    scene6 = new QGraphicsScene(this);
    scene2_1 = new QGraphicsScene(this);
    scene2_2 = new QGraphicsScene(this);
    scene2_3 = new QGraphicsScene(this);
    scene3_1 = new QGraphicsScene(this);
    scene3_2 = new QGraphicsScene(this);
    scene11_2 = new QGraphicsScene(this);
    scene22 = new QGraphicsScene(this);
    scene33 = new QGraphicsScene(this);

    ui->graph1->setScene(scene1);
    ui->graph2->setScene(scene2);
    ui->graph3->setScene(scene3);
    ui->graph4->setScene(scene4);
    ui->graph5->setScene(scene5);
    ui->graph6->setScene(scene6);
    ui->graph2_1->setScene(scene2_1);
    ui->graph2_2->setScene(scene2_2);
    ui->graph2_3->setScene(scene2_3);
    ui->graph3_1->setScene(scene3_1);
    ui->graph3_2->setScene(scene3_2);
    ui->graphicsView11_2->setScene(scene11_2);
    ui->graphicsView22->setScene(scene22);
    ui->graphicsView33->setScene(scene33);


    images();

    QStringList colormaps = {
        "AUTUMN", "BONE", "JET", "WINTER", "RAINBOW", "HOT"
    };
    QList<int> colormapValues = {
        cv::COLORMAP_AUTUMN, cv::COLORMAP_BONE, cv::COLORMAP_JET,
        cv::COLORMAP_WINTER, cv::COLORMAP_RAINBOW, cv::COLORMAP_HOT
    };

    for (int i = 0; i < colormaps.size(); ++i) {
        ui->comboBox->addItem(colormaps[i], colormapValues[i]);
        ui->comboBox_2->addItem(colormaps[i], colormapValues[i]);
        ui->comboBox_3->addItem(colormaps[i], colormapValues[i]);
    }

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [this](int index) {
                int colormapType = ui->comboBox->currentData().toInt();
                colorMap(colormapType, scene2_1, scene11_2);
                colorBar(colormapType, scene11_2, ui->graphicsView11_2);
                ui->label_29->setText(ui->comboBox->currentText());  // ADD

            });

    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [this](int index) {
                int colormapType = ui->comboBox_2->currentData().toInt();
                colorMap(colormapType, scene2_2, scene22);
                colorBar(colormapType, scene22, ui->graphicsView22);
                ui->label_14->setText(ui->comboBox_2->currentText());

            });

    connect(ui->comboBox_3, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [this](int index) {
                int colormapType = ui->comboBox_3->currentData().toInt();
                colorMap(colormapType, scene2_3, scene33);
                colorBar(colormapType, scene33, ui->graphicsView33);
                ui->label_20->setText(ui->comboBox_3->currentText());  // ADD

            });

    connect(ui->doubleSpinBox_7, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::applySegmentation);
    connect(ui->radioButton_6, &QRadioButton::toggled, this, &MainWindow::applySegmentation);
    connect(ui->radioButton_7, &QRadioButton::toggled, this, &MainWindow::applySegmentation);
    connect(ui->radioButton_8, &QRadioButton::toggled, this, &MainWindow::applySegmentation);
}

void MainWindow::applySegmentation() {
    int k = static_cast<int>(ui->doubleSpinBox_7->value());

    QString colorSpace;
    if (ui->radioButton_6->isChecked()) {
        colorSpace = "RGB";
    } else if (ui->radioButton_7->isChecked()) {
        colorSpace = "HSI";
    } else if (ui->radioButton_8->isChecked()) {
        colorSpace = "Lab";
    }
    ui->label_23->setText(QString("k: %1, Method: %2").arg(k).arg(colorSpace));

    segmentImageByKMeans(k, colorSpace, scene3_2);
    ui->graph3_2->fitInView(scene3_2->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::segmentImageByKMeans(int k, const QString &colorSpace, QGraphicsScene *scene) {
    cv::Mat mat = QImageToCvMat(image_3);
    cv::Mat img, samples, labels, centers;

    if (colorSpace == "RGB") {
        img = mat.clone();
    } else if (colorSpace == "HSI") {
        cv::cvtColor(mat, img, cv::COLOR_BGR2HSV);
    } else if (colorSpace == "Lab") {
        cv::cvtColor(mat, img, cv::COLOR_BGR2Lab);
    }
    img.convertTo(samples, CV_32F);
    samples = samples.reshape(1, img.rows * img.cols);

    cv::kmeans(samples, k, labels,
               cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 10, 1.0),
               3, cv::KMEANS_PP_CENTERS, centers);

    cv::Mat clustered(img.size(), img.type());
    for (int i = 0; i < samples.rows; ++i) {
        clustered.at<cv::Vec3b>(i / img.cols, i % img.cols) = centers.at<cv::Vec3f>(labels.at<int>(i), 0);
    }

    if (colorSpace == "HSI") {
        cv::cvtColor(clustered, clustered, cv::COLOR_HSV2BGR);
    } else if (colorSpace == "Lab") {
        cv::cvtColor(clustered, clustered, cv::COLOR_Lab2BGR);
    }

    QImage qImageSegmented(clustered.data, clustered.cols, clustered.rows, clustered.step, QImage::Format_RGB888);
    display(qImageSegmented, scene);
}


void MainWindow::colorMap(int colormapType, QGraphicsScene* imageScene, QGraphicsScene* colorBarScene)
{
    cv::Mat pseudo_color_image;
    cv::applyColorMap(grayscale_image, pseudo_color_image, colormapType);

    cv::Mat rgb_image;
    cv::cvtColor(pseudo_color_image, rgb_image, cv::COLOR_BGR2RGB);

    QImage qImagePseudo(rgb_image.data, rgb_image.cols, rgb_image.rows,
                        rgb_image.step, QImage::Format_RGB888);

    imageScene->clear();
    QPixmap pixmap = QPixmap::fromImage(qImagePseudo);
    imageScene->addPixmap(pixmap);
}

void MainWindow::colorBar(int colormapType, QGraphicsScene* scene, QGraphicsView* view)
{
    cv::Mat colorBar(30, 256, CV_8UC1);
    for (int i = 0; i < 256; i++) {
        colorBar.col(i).setTo(i);
    }

    cv::Mat pseudo_color_bar;
    cv::applyColorMap(colorBar, pseudo_color_bar, colormapType);

    cv::Mat rgb_color_bar;
    cv::cvtColor(pseudo_color_bar, rgb_color_bar, cv::COLOR_BGR2RGB);

    QImage qImageColorBar(rgb_color_bar.data, rgb_color_bar.cols, rgb_color_bar.rows,
                          rgb_color_bar.step, QImage::Format_RGB888);

    scene->clear();
    QPixmap pixmap = QPixmap::fromImage(qImageColorBar);
    scene->addPixmap(pixmap);
    scene->setSceneRect(pixmap.rect());
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);  // ADD

}

cv::Mat MainWindow::QImageToCvMat(const QImage &inImage)
{
    switch (inImage.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    {
        cv::Mat mat(inImage.height(), inImage.width(),
                    CV_8UC4, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine());
        return mat.clone();
    }
    case QImage::Format_RGB888:
    {
        cv::Mat mat(inImage.height(), inImage.width(),
                    CV_8UC3, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine());
        return mat.clone();
    }
    case QImage::Format_Grayscale8:
    case QImage::Format_Indexed8:
    {
        cv::Mat mat(inImage.height(), inImage.width(),
                    CV_8UC1, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine());
        return mat.clone();
    }
    default:
        break;
    }
    return cv::Mat();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::images(){
    image_2 = QImage("HW05-Part 2-01.bmp");
    image = QImage("images.jpg");
    image_3 = QImage("HW05-Part 3-04.bmp");

    connect(ui->button, &QPushButton::clicked, [this](){

        display(image, scene1);
        display(image_3, scene3_1);

        cmy();
        hsi();
        xyz();
        yuv();
    });

    connect(ui->b1_2, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->b2_1, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->b2_2, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->b3_1, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    cv::Mat mat = QImageToCvMat(image_2);  // Helper function to convert QImage to cv::Mat
    if (mat.channels() == 3) {
        cv::cvtColor(mat, grayscale_image, cv::COLOR_BGR2GRAY);
    } else if (mat.channels() == 4) {
        cv::cvtColor(mat, grayscale_image, cv::COLOR_BGRA2GRAY);
    } else {
        grayscale_image = mat.clone();
    }

    QImage grayscale_qimage((uchar*)grayscale_image.data, grayscale_image.cols, grayscale_image.rows,
                            grayscale_image.step, QImage::Format_Grayscale8);
    scene2_1->clear();
    QPixmap g1 = QPixmap::fromImage(grayscale_qimage);
    scene2_1->addPixmap(g1);
    scene2_1->setSceneRect(g1.rect());
    ui->graph2_1->fitInView(scene2_1->sceneRect(), Qt::KeepAspectRatio);

    scene2_2->clear();
    QPixmap g2 = QPixmap::fromImage(grayscale_qimage);
    scene2_2->addPixmap(g2);
    scene2_2->setSceneRect(g2.rect());
    ui->graph2_2->fitInView(scene2_2->sceneRect(), Qt::KeepAspectRatio);

    scene2_3->clear();
    QPixmap g3 = QPixmap::fromImage(grayscale_qimage);
    scene2_3->addPixmap(g3);
    scene2_3->setSceneRect(g3.rect());
    ui->graph2_3->fitInView(scene2_3->sceneRect(), Qt::KeepAspectRatio);

}

void MainWindow::cmy()
{
    QImage image1 = image.convertToFormat(QImage::Format_RGB32);

    for (int y = 0; y < image1.height(); y++) {
        for (int x = 0; x < image1.width(); x++) {
            QColor color = image1.pixelColor(x, y);

            int C = 255 - color.red();
            int M = 255 - color.green();
            int Y = 255 - color.blue();

            image1.setPixelColor(x, y, QColor(C, M, Y));
        }
    }
    display(image1, scene2);
}

void MainWindow::hsi()
{
    QImage image2 = image.convertToFormat(QImage::Format_RGB32);

    for (int y = 0; y < image2.height(); y++) {
        for (int x = 0; x < image2.width(); x++) {
            QColor color = image2.pixelColor(x, y);

            double r = color.red()/ 255.0;
            double g = color.green()/ 255.0;
            double b = color.blue()/ 255.0;

            double i = (r + g + b) / 3.0;

            double min = qMin(qMin(r, g), b);
            double s = (i > 0.0) ? (1.0 - (min / i)) : 0.0;

            double h = 0.0;
            if (s != 0.0) {
                double n = 0.5 * ((r - g) + (r - b));
                double d = sqrt((r - g) * (r - g) + (r - b) * (g - b));
                h = acos(n / (d + 1e-10));

                if (b > g) {
                    h = 2.0 * M_PI - h;
                }
                h = h * 180.0 / M_PI;
            }

            int H = qBound(0, static_cast<int>(h / 360.0 * 255.0), 255);
            int S = qBound(0, static_cast<int>(s * 255.0), 255);
            int I = qBound(0, static_cast<int>(i * 255.0), 255);

            image2.setPixelColor(x, y, QColor(H, S, I));
        }
    }
    display(image2, scene3);
}

void MainWindow::xyz()
{
    QImage image3 = image.convertToFormat(QImage::Format_RGB32);
    QImage image4(image3.size(), QImage::Format_RGB32);

    for (int y = 0; y < image3.height(); y++) {
        for (int x = 0; x < image3.width(); x++) {
            QColor color = image3.pixelColor(x, y);

            double r = color.red() / 255.0;
            double g = color.green() / 255.0;
            double b = color.blue() / 255.0;

            r = (r > 0.04045) ? pow((r + 0.055) / 1.055, 2.4) : r / 12.92;
            g = (g > 0.04045) ? pow((g + 0.055) / 1.055, 2.4) : g / 12.92;
            b = (b > 0.04045) ? pow((b + 0.055) / 1.055, 2.4) : b / 12.92;

            r *= 100.0;
            g *= 100.0;
            b *= 100.0;

            double X = r * 0.4124564 + g * 0.3575761 + b * 0.1804375;
            double Y = r * 0.2126729 + g * 0.7151522 + b * 0.0721750;
            double Z = r * 0.0193339 + g * 0.1191920 + b * 0.9503041;

            int Xdisplay = qBound(0, static_cast<int>(X * 255.0 / 100.0), 255);
            int Ydisplay = qBound(0, static_cast<int>(Y * 255.0 / 100.0), 255);
            int Zdisplay = qBound(0, static_cast<int>(Z * 255.0 / 100.0), 255);

            double xr = X / 95.047;
            double yr = Y / 100.000;
            double zr = Z / 108.883;

            xr = (xr > 0.008856) ? pow(xr, 1.0/3.0) : (903.3 * xr + 16.0) / 116.0;
            yr = (yr > 0.008856) ? pow(yr, 1.0/3.0) : (903.3 * yr + 16.0) / 116.0;
            zr = (zr > 0.008856) ? pow(zr, 1.0/3.0) : (903.3 * zr + 16.0) / 116.0;

            double L = (116.0 * yr) - 16.0;
            double a = 500.0 * (xr - yr);
            double b_ = 200.0 * (yr - zr);

            int Ldisplay = qBound(0, static_cast<int>((L * 255.0) / 100.0), 255);
            int adisplay = qBound(0, static_cast<int>((a + 128.0)), 255);
            int bdisplay = qBound(0, static_cast<int>((b_ + 128.0)), 255);

            image3.setPixelColor(x, y, QColor(Xdisplay, Ydisplay, Zdisplay));
            image4.setPixelColor(x, y, QColor(Ldisplay, adisplay, bdisplay));
        }
    }
    display(image3, scene4);
    display(image4, scene5);
}

void MainWindow::yuv(){
    QImage image5 = image.convertToFormat(QImage::Format_RGB32);
    for (int y = 0; y < image5.height(); y++) {
        for (int x = 0; x < image5.width(); x++) {
            QColor color = image5.pixelColor(x, y);

            float r = color.red() ;
            float g = color.green() ;
            float b = color.blue() ;

            float Y = r * 0.299f + g * 0.587f + b * 0.114f;
            float U = -r * 0.169f - g * 0.331f + b * 0.500f + 128;
            float V = r * 0.500f - g * 0.419f - b * 0.081f + 128;

            Y = qBound(0.0f, Y, 255.0f);
            U = qBound(0.0f, U, 255.0f);
            V = qBound(0.0f, V, 255.0f);

            image5.setPixelColor(x, y, QColor(Y, U, V));
        }
    }
    display(image5, scene6);
}

void MainWindow::display(const QImage& image, QGraphicsScene* scene) {
    scene->clear();
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    scene->setSceneRect(pixmap.rect());
    scene->update();

    if(scene == scene1) {
        ui->graph1->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene2) {
        ui->graph2->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene3) {
        ui->graph3->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene4) {
        ui->graph4->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene5) {
        ui->graph5->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene6) {
        ui->graph6->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene3_1) {
        ui->graph3_1->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene11_2) {
        ui->graphicsView11_2->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene22) {
        ui->graphicsView22->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene33) {
        ui->graphicsView33->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}
