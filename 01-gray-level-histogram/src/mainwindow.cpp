#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QDebug>
#include <QPixmap>
#include <QFile>
#include <QVector>
#include <QTextStream>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <algorithm>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setImage();
}

MainWindow::~MainWindow() {
    delete ui;
}

//convert ascii code to grayvalues
bool MainWindow::readFile(const QString &filePath, QImage &image, QVector<int> &histogram) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    QVector<QVector<int>> matrix;
    histogram = QVector<int>(32, 0);

    int maxWidth = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QVector<int> row;

        for (const QChar &c : line) {
            int val;
            if (c >= 'A' && c <= 'V')
                val = c.unicode() - 'A' + 10;   //A~V for 10~31
            else if (c >= '0' && c <= '9')
                val = c.unicode() - '0';    //0~9 for 0~9
            else
                continue;

            row.push_back(val);
            histogram[val]++;
        }

        if (!row.isEmpty()) {
            matrix.push_back(row);
            maxWidth = qMax(maxWidth, row.size());
        }
    }
    file.close();

    image = QImage(maxWidth, matrix.size(), QImage::Format_Grayscale8);

    //convert 0~31 to 0~255 grayvalues
    for (int y = 0; y < matrix.size(); ++y) {
        for (int x = 0; x < matrix[y].size(); ++x) {
            int grayValue = matrix[y][x] * (255 / 31);
            image.setPixel(x, y, qRgb(grayValue, grayValue, grayValue));
        }
    }
    return true;
}

//draw histogram
void MainWindow::histo(QGraphicsView *view, const QVector<int> &histogram) {
    QGraphicsScene *scene = new QGraphicsScene(view);
    view->setScene(scene);

    const int width = 300;    //histogram width
    const int height = 200;    //histogram height
    const int barWidth = 8;    //bar width
    const int space = 2;    //space between bars
    int maxValue = *std::max_element(histogram.begin(), histogram.end());
    double scale = static_cast<double>(height - 60) / maxValue;    //scaling for bar height

    scene->setSceneRect(0, 0, width, height);

    //set grids
    QPen gridPen(QColor(225, 225, 225));
    for (int i = 0; i <= 10; ++i) {
        int y = (height - 50) - (i * (height - 60) / 10);
        scene->addLine(0, y, width, y, gridPen);
    }

    //use histogram values to draw bars
    for (int i = 0; i < histogram.size(); ++i) {
        int barHeight = static_cast<int>(histogram[i] * scale);
        QGraphicsRectItem *bar = new QGraphicsRectItem(i * (barWidth + space), (height - barHeight) - 50, barWidth, barHeight);
        bar->setBrush(QBrush(QColor(100, 150, 250)));
        bar->setPen(QPen(Qt::gray, 1));
        scene->addItem(bar);
    }

    //set axes
    QPen axisPen(Qt::gray);
    scene->addLine(0, height - 50, width, height - 50, axisPen);    //X-axis
    scene->addLine(0, height - 50, 0, 0, axisPen);    //Y-axis

    //Y-axis labels
    QFont labelFont("Courier", 6);
    for (int i = 0; i <= 10; ++i) {
        int freq = static_cast<int>(maxValue * i / 10);
        QGraphicsTextItem *yLabel = new QGraphicsTextItem(QString::number(freq));
        yLabel->setFont(labelFont);
        yLabel->setPos(-30, height - 50 - (i * (height - 60) / 10) - 5);
        scene->addItem(yLabel);
    }

    //X-axis labels
    for (int i = 0; i < 32; ++i) {
        QGraphicsTextItem *item = new QGraphicsTextItem(QString::number(i));
        item->setFont(labelFont);
        item->setPos(i * (barWidth + space) + (barWidth / 2) - 5, 150);
        scene->addItem(item);
    }

    //label for Y
    QGraphicsTextItem *labelY = new QGraphicsTextItem("Frequency");
    labelY->setFont(labelFont);
    labelY->setPos(-30, -10);
    scene->addItem(labelY);

    //label for X
    QGraphicsTextItem *labelX = new QGraphicsTextItem("Gray Values");
    labelX->setFont(labelFont);
    labelX->setPos(width / 2 - 20, 160);
    scene->addItem(labelX);

    view->setSceneRect(0, -10, width, height);
    view->show();
}

void MainWindow::setImage() {
    //read&show image
    QString lisaPath = "images/LISA.64";
    QVector<int> lisaHistogram;
    if (readFile(lisaPath, image, lisaHistogram)) {
        ui->Label->setPixmap(QPixmap::fromImage(image.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
        histo(ui->Histogram, lisaHistogram);
    }

    QString lincolnPath = "images/LINCOLN.64";
    QVector<int> lincolnHistogram;
    QImage lincolnImage;
    if (readFile(lincolnPath, lincolnImage, lincolnHistogram)) {
        QImage averagedImage = avg(image, lincolnImage);
        ui->avgLabel->setPixmap(QPixmap::fromImage(averagedImage.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
        QVector<int> averageHistogram;
        histoo(averagedImage, averageHistogram);
        histo(ui->avgHistogram, averageHistogram);
    }

    //gradient image&histogram
    QImage gImage = grad(image);
    ui->gLabel->setPixmap(QPixmap::fromImage(gImage.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    QVector<int> gHistogram;
    histoo(gImage, gHistogram);
    histo(ui->gHistogram, gHistogram);
}

void MainWindow::on_aSlider_valueChanged(int value) {
    ui->avLabel->setText(QString::number(value));
    QImage aImage;
    if (value >= 0) {
        aImage = addConstant(image, value*10);  //slider add value ++
    } else {
        aImage = subtractConstant(image, -value*10);    //slider subtract value--
    }
    ui->aLabel->setPixmap(QPixmap::fromImage(aImage.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation)));

    QVector<int> histogram;
    histoo(aImage, histogram);
    histo(ui->aHistogram, histogram);
}

void MainWindow::on_mSlider_valueChanged(int value) {
    ui->mvLabel->setText(QString::number(value));
    QImage mImage = multiplyConstant(image, value);     //give multiplication
    ui->mLabel->setPixmap(QPixmap::fromImage(mImage.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation)));

    QVector<int> histogram;
    histoo(mImage, histogram);
    histo(ui->mHistogram, histogram);
}

void MainWindow::histoo(const QImage &image, QVector<int> &histogram) {
    histogram.fill(0, 32);
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            int grayValue = qGray(image.pixel(x, y)) / (255 / 31);
            histogram[grayValue]++;
        }
    }
}

//add to all grayvalues
QImage MainWindow::addConstant(const QImage &image, int constant) {
    QImage aImage = image.copy();
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            int newVal = qGray(image.pixel(x, y)) + constant;
            newVal = qBound(0, newVal, 255);
            aImage.setPixel(x, y, qRgb(newVal, newVal, newVal));
        }
    }
    return aImage;
}

//subbtract to all grayvalues
QImage MainWindow::subtractConstant(const QImage &image, int constant) {
    return addConstant(image, -constant);
}

//multiply to all grayvalues
QImage MainWindow::multiplyConstant(const QImage &image, double constant) {
    QImage mImage = image.copy();
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            int newVal = qGray(image.pixel(x, y)) * constant;
            newVal = qBound(0, newVal, 255);
            mImage.setPixel(x, y, qRgb(newVal, newVal, newVal));
        }
    }
    return mImage;
}

//average 2 images of LISA.64 and LINCOLN.64
QImage MainWindow::avg(const QImage &image1, const QImage &image2) {
    QImage avgImage = image1.copy();
    for (int y = 0; y < image1.height(); ++y) {
        for (int x = 0; x < image1.width(); ++x) {
            int avgVal = (qGray(image1.pixel(x, y)) + qGray(image2.pixel(x, y))) / 2;
            avgImage.setPixel(x, y, qRgb(avgVal, avgVal, avgVal));
        }
    }
    return avgImage;
}

//from equation g(x,y) = f(x,y) - f(x-1,y)
QImage MainWindow::grad(const QImage &image) {
    QImage gImage = image.copy();
    for (int y = 1; y < image.height() - 1; ++y) {
        for (int x = 1; x < image.width() - 1; ++x) {
            int gx = qGray(image.pixel(x + 1, y)) - qGray(image.pixel(x - 1, y));
            gx = qBound(0, gx, 255);
            gImage.setPixel(x, y, qRgb(gx, gx, gx));
        }
    }
    return gImage;
}
