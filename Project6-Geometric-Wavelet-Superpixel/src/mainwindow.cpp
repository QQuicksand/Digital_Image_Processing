#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <opencv2/imgproc.hpp>
#include <QMessageBox>
#include <float.h>


using namespace std;

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
    scene7 = new QGraphicsScene(this);
    scene8 = new QGraphicsScene(this);
    scene10 = new QGraphicsScene(this);
    scene10_2 = new QGraphicsScene(this);
    scene11 = new QGraphicsScene(this);

    ui->graphic1->setScene(scene1);
    ui->graphic2->setScene(scene2);
    ui->graphic3->setScene(scene3);
    ui->graphic4->setScene(scene4);
    ui->graphic5->setScene(scene5);
    ui->graphic6->setScene(scene6);
    ui->graphic7->setScene(scene7);
    ui->graphic8->setScene(scene8);
    ui->graphic10->setScene(scene10);
    ui->graphic10_2->setScene(scene10_2);
    ui->graphic11->setScene(scene11);

    images();
    connect(ui->doubleSpinBox_8, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::superpixel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::images(){
    image = QImage("IP_dog.bmp");
    image2 = QImage("MRI1.jpg");
    image2_1 = QImage("MRI2.jpg");
    image3 = QImage("totem-poles.jpg");

    connect(ui->Button1, &QPushButton::clicked, [this](){
        display(image, scene1);

        fisheye();
        kaleidoscope();
        wavy();
        spiral();
        ripple();
    });

    connect(ui->Button3, &QPushButton::clicked, [this](){
        display(image2, scene10);
        display(image2_1, scene10_2);
    });

    connect(ui->Button3_2, &QPushButton::clicked, [this](){
        dwt();
    });

    connect(ui->Button1_3, &QPushButton::clicked, [this](){
        display(image3, scene7);

        superpixel();
    });

    connect(ui->b1_3, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->b2_3, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->b2_4, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->b3_2, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->doubleSpinBox_8, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::superpixel);
}

void MainWindow::fisheye()
{
    QImage transformed = image;
    float centerX = image.width() / 2.0f;
    float centerY = image.height() / 2.0f;
    float intensity = 3.0;

    for(int y = 0; y < image.height(); y++) {
        for(int x = 0; x < image.width(); x++) {
            QPointF centered(x - centerX, y - centerY);
            float distance = sqrt(centered.x() * centered.x() + centered.y() * centered.y());
            float angle = atan2(centered.y(), centered.x());

            float radius = min(centerX, centerY);
            float normalized = distance / radius;
            float fisheye = atan(normalized * intensity) / (M_PI / 2);
            distance = fisheye * radius;

            int newX = qRound(centerX + distance * cos(angle));
            int newY = qRound(centerY + distance * sin(angle));

            if(newX >= 0 && newX < image.width() && newY >= 0 && newY < image.height()) {
                transformed.setPixel(x, y, image.pixel(newX, newY));
            }
        }
    }
    display(transformed, scene2);
}

void MainWindow::kaleidoscope()
{
    QImage transformed = image;
    float centerX = image.width() / 2.0f;
    float centerY = image.height() / 2.0f;
    float intensity = 1.0;

    for(int y = 0; y < image.height(); y++) {
        for(int x = 0; x < image.width(); x++) {
            QPointF centered(x - centerX, y - centerY);
            float distance = sqrt(centered.x() * centered.x() + centered.y() * centered.y());
            float angle = atan2(centered.y(), centered.x());

            int segments = 6 + intensity * 10;
            float segmentAngle = 2 * M_PI / segments;
            angle = fmod(angle + 2 * M_PI, segmentAngle);
            if (angle > segmentAngle / 2) {
                angle = segmentAngle - angle;
            }

            int newX = qRound(centerX + distance * cos(angle));
            int newY = qRound(centerY + distance * sin(angle));

            if(newX >= 0 && newX < image.width() && newY >= 0 && newY < image.height()) {
                transformed.setPixel(x, y, image.pixel(newX, newY));
            }
        }
    }
    display(transformed, scene3);
}

void MainWindow::wavy()
{
    QImage transformed = image;
    float intensity = 20.0;
    float frequency = 0.1;

    for(int y = 0; y < image.height(); y++) {
        for(int x = 0; x < image.width(); x++) {
            int newX = x + intensity * sin(frequency * y);
            int newY = y + intensity * sin(frequency * x);

            if(newX >= 0 && newX < image.width() && newY >= 0 && newY < image.height()) {
                transformed.setPixel(x, y, image.pixel(newX, newY));
            }
        }
    }
    display(transformed, scene4);
}

void MainWindow::spiral()
{
    QImage transformed = image;
    float centerX = image.width() / 2.0f;
    float centerY = image.height() / 2.0f;
    float intensity = 0.01;

    for(int y = 0; y < image.height(); y++) {
        for(int x = 0; x < image.width(); x++) {
            QPointF centered(x - centerX, y - centerY);
            float distance = sqrt(centered.x() * centered.x() + centered.y() * centered.y());
            float angle = atan2(centered.y(), centered.x());

            angle += distance * intensity;

            int newX = qRound(centerX + distance * cos(angle));
            int newY = qRound(centerY + distance * sin(angle));

            if(newX >= 0 && newX < image.width() && newY >= 0 && newY < image.height()) {
                transformed.setPixel(x, y, image.pixel(newX, newY));
            }
        }
    }
    display(transformed, scene5);
}

void MainWindow::ripple()
{
    QImage transformed = image;
    float centerX = image.width() / 2.0f;
    float centerY = image.height() / 2.0f;
    float intensity = 20.0;

    for(int y = 0; y < image.height(); y++) {
        for(int x = 0; x < image.width(); x++) {
            QPointF centered(x - centerX, y - centerY);
            float distance = sqrt(centered.x() * centered.x() + centered.y() * centered.y());
            float angle = atan2(centered.y(), centered.x());

            float ripple = sin(distance * 0.1) * intensity;
            distance += ripple;

            int newX = qRound(centerX + distance * cos(angle));
            int newY = qRound(centerY + distance * sin(angle));

            if(newX >= 0 && newX < image.width() && newY >= 0 && newY < image.height()) {
                transformed.setPixel(x, y, image.pixel(newX, newY));
            }
        }
    }
    display(transformed, scene6);
}

void MainWindow::fusing(const cv::Mat& input, cv::Mat& LL, cv::Mat& LH, cv::Mat& HL, cv::Mat& HH) {
    cv::Mat m;
    cv::pyrDown(input, m);
    cv::pyrUp(m, LL, input.size());
    LH = input - LL;
    cv::transpose(input, m);
    cv::pyrDown(m, m);
    cv::pyrUp(m, m, input.size());
    HL = m - LL.t();
    HH = input - LL - LH - HL;
}

void MainWindow::dwt() {
    cv::Mat mat1 = cv::Mat(image2.height(), image2.width(), CV_8UC1,
                                const_cast<uchar*>(image2.bits()), image2.bytesPerLine()).clone();
    cv::Mat mat2 = cv::Mat(image2_1.height(), image2_1.width(), CV_8UC1,
                                  const_cast<uchar*>(image2_1.bits()), image2_1.bytesPerLine()).clone();

    cv::Mat LL1, LH1, HL1, HH1;
    cv::Mat LL2, LH2, HL2, HH2;
    fusing(mat1, LL1, LH1, HL1, HH1);
    fusing(mat2, LL2, LH2, HL2, HH2);

    cv::Mat LL = (LL1 + LL2) / 2.0;
    cv::Mat LH = cv::max(LH1, LH2);
    cv::Mat HL = cv::max(HL1, HL2);
    cv::Mat HH = cv::max(HH1, HH2);

    cv::Mat fuseMat = LL + LH + HL + HH;

    cv::normalize(fuseMat, fuseMat, 0, 255, cv::NORM_MINMAX);
    fuseMat.convertTo(fuseMat, CV_8U);

    QImage fusedImage(fuseMat.data, fuseMat.cols, fuseMat.rows, fuseMat.step, QImage::Format_Grayscale8);
    fusedImage.bits();

    display(fusedImage, scene11);
}


void MainWindow::superpixel() {

    cv::Mat inputImage = cv::Mat(image3.height(), image3.width(), CV_8UC3);
    for(int y = 0; y < image3.height(); y++) {
        for(int x = 0; x < image3.width(); x++) {
            QColor color(image3.pixel(x, y));
            inputImage.at<cv::Vec3b>(y, x)[0] = color.red();
            inputImage.at<cv::Vec3b>(y, x)[1] = color.green();
            inputImage.at<cv::Vec3b>(y, x)[2] = color.blue();
        }
    }

    cv::Mat outputImage;
    int numSuperpixels = ui->doubleSpinBox_8->value();
    SLIC(inputImage, outputImage, numSuperpixels, 20, 10.0);

    // Convert cv::Mat back to QImage
    QImage result(outputImage.data, outputImage.cols, outputImage.rows,
                  outputImage.step, QImage::Format_RGB888);
    display(result, scene8);
}

void MainWindow::SLIC(const cv::Mat &src_image, cv::Mat &trans_image,
                      int numOfSuperpixels, const int compactness, const double threshold) {
    qDebug() << "START SLIC";
    try {
        cv::Mat labSpaceInput;
        if (src_image.channels() == 3) {
            cv::cvtColor(src_image, labSpaceInput, cv::COLOR_RGB2Lab);
        }

        const int S = static_cast<int>(
            floor(sqrt((labSpaceInput.rows * labSpaceInput.cols) / numOfSuperpixels)));
        std::vector<PixelFeature> clusterCenters(numOfSuperpixels);
        int x = 0;
        int y = 0;
        const int n = 3;

        // Init clusters
        for (size_t i = 0; i < clusterCenters.size(); ++i) {
            cv::Point bestPoint = getLocalMinimum(labSpaceInput, x * S, y * S, n);
            PixelFeature temp;
            if (labSpaceInput.channels() == 3) {
                temp.labValue[0] = static_cast<double>(
                    labSpaceInput.at<cv::Vec3b>(bestPoint.y, bestPoint.x)[0]);
                temp.labValue[1] = static_cast<double>(
                    labSpaceInput.at<cv::Vec3b>(bestPoint.y, bestPoint.x)[1]);
                temp.labValue[2] = static_cast<double>(
                    labSpaceInput.at<cv::Vec3b>(bestPoint.y, bestPoint.x)[2]);
            } else {
                temp.labValue[0] = static_cast<double>(
                    labSpaceInput.at<uchar>(bestPoint.y, bestPoint.x));
                temp.labValue[1] = 0.0;
                temp.labValue[2] = 0.0;
            }
            temp.xy = bestPoint;
            clusterCenters[i] = temp;
            x += 1;
            if ((x * S) >= labSpaceInput.cols) {
                x = 0;
                y += 1;
            }
        }

        double error;
        cv::Mat labels;
        do {
            error = 0.0;
            cv::Mat distances(labSpaceInput.size(), CV_64FC1, std::numeric_limits<double>::max());
            labels = cv::Mat(labSpaceInput.size(), CV_32SC1);

            for (size_t itr = 0; itr < clusterCenters.size(); ++itr) {
                cv::Point roiCenter = clusterCenters[itr].xy;
                for (y = roiCenter.y - S; y < roiCenter.y + S; ++y) {
                    for (x = roiCenter.x - S; x < roiCenter.x + S; ++x) {
                        if ((x < 0) || (x >= labSpaceInput.cols) || (y < 0)
                            || (y >= labSpaceInput.rows))
                            continue;

                        PixelFeature tempPoint;
                        tempPoint.xy = cv::Point(x, y);
                        if (labSpaceInput.channels() == 3) {
                            tempPoint.labValue[0] = static_cast<double>(
                                labSpaceInput.at<cv::Vec3b>(y, x)[0]);
                            tempPoint.labValue[1] = static_cast<double>(
                                labSpaceInput.at<cv::Vec3b>(y, x)[1]);
                            tempPoint.labValue[2] = static_cast<double>(
                                labSpaceInput.at<cv::Vec3b>(y, x)[2]);
                        } else {
                            tempPoint.labValue[0] = static_cast<double>(
                                labSpaceInput.at<uchar>(y, x));
                            tempPoint.labValue[1] = 0.0;
                            tempPoint.labValue[2] = 0.0;
                        }

                        const double dis = distance(clusterCenters[itr], tempPoint, compactness, S);
                        if (dis < distances.at<double>(y, x)) {
                            distances.at<double>(y, x) = dis;
                            labels.at<int>(y, x) = static_cast<int>(itr);
                        }
                    }
                }
            }

            std::vector<PixelFeature> newClusterCenters(clusterCenters.size());
            std::vector<int> numOfPixels(clusterCenters.size(), 0);

            for (y = 0; y < labels.rows; ++y) {
                for (x = 0; x < labels.cols; ++x) {
                    if (labSpaceInput.channels() == 3) {
                        newClusterCenters[labels.at<int>(y, x)].labValue[0] += static_cast<double>(
                            labSpaceInput.at<cv::Vec3b>(y, x)[0]);
                        newClusterCenters[labels.at<int>(y, x)].labValue[1] += static_cast<double>(
                            labSpaceInput.at<cv::Vec3b>(y, x)[1]);
                        newClusterCenters[labels.at<int>(y, x)].labValue[2] += static_cast<double>(
                            labSpaceInput.at<cv::Vec3b>(y, x)[2]);
                    } else {
                        newClusterCenters[labels.at<int>(y, x)].labValue[0] += static_cast<double>(
                            labSpaceInput.at<uchar>(y, x));
                        newClusterCenters[labels.at<int>(y, x)].labValue[1] += 0.0;
                        newClusterCenters[labels.at<int>(y, x)].labValue[2] += 0.0;
                    }
                    newClusterCenters[labels.at<int>(y, x)].xy.x += x;
                    newClusterCenters[labels.at<int>(y, x)].xy.y += y;
                    numOfPixels[labels.at<int>(y, x)] += 1;
                }
            }

            // Normalize
            for (size_t itr = 0; itr < newClusterCenters.size(); ++itr) {
                if (numOfPixels[itr] == 0) {
                    continue;
                }
                newClusterCenters[itr].labValue[0] /= numOfPixels[itr];
                newClusterCenters[itr].labValue[1] /= numOfPixels[itr];
                newClusterCenters[itr].labValue[2] /= numOfPixels[itr];
                newClusterCenters[itr].xy.x /= numOfPixels[itr];
                newClusterCenters[itr].xy.y /= numOfPixels[itr];
            }

            // Calculate convergence
            for (size_t itr = 0; itr < newClusterCenters.size(); ++itr) {
                error += distance(clusterCenters[itr], newClusterCenters[itr], compactness, S);
            }
            clusterCenters = newClusterCenters;
        } while (error > threshold);

        cv::Mat enforcedConnectivityLabels = enforceConnectivity(labels, numOfSuperpixels);

        // Display the image
        for (y = 0; y < labSpaceInput.rows; ++y) {
            for (x = 0; x < labSpaceInput.cols; ++x) {
                const int clusIndx = enforcedConnectivityLabels.at<int>(y, x);
                if (labSpaceInput.channels() == 3) {
                    labSpaceInput.at<cv::Vec3b>(y, x)[0] = clusterCenters[clusIndx].labValue[0];
                    labSpaceInput.at<cv::Vec3b>(y, x)[1] = clusterCenters[clusIndx].labValue[1];
                    labSpaceInput.at<cv::Vec3b>(y, x)[2] = clusterCenters[clusIndx].labValue[2];
                } else {
                    labSpaceInput.at<uchar>(y, x) = clusterCenters[clusIndx].labValue[0];
                }
            }
        }

        if (labSpaceInput.channels() == 3) {
            cv::cvtColor(labSpaceInput, trans_image, cv::COLOR_Lab2RGB);
        } else {
            trans_image = labSpaceInput;
        }
    } catch (std::exception &e) {
        qDebug() << e.what();
    }
    qDebug() << "END SLIC";
}

double MainWindow::distance(PixelFeature f1, PixelFeature f2,
                            const int compactness, const int S) {
    double dlab = sqrt(pow(f1.labValue[0] - f2.labValue[0], 2)
                       + pow(f1.labValue[1] - f2.labValue[1], 2)
                       + pow(f1.labValue[2] - f2.labValue[2], 2));
    double dxy = sqrt(pow(f1.xy.x - f2.xy.x, 2) + pow(f1.xy.y - f2.xy.y, 2));
    return dlab + (static_cast<double>(compactness) / static_cast<double>(S)) * dxy;
}

cv::Point MainWindow::getLocalMinimum(cv::Mat input, const int x, const int y, const int n) {
    auto lambdaGrad = [](cv::Mat input, int x, int y) {
        // Calculate differences for each channel separately
        double xSum = 0;
        double ySum = 0;

        for(int c = 0; c < 3; c++) {
            int xDiff = static_cast<int>(input.at<cv::Vec3b>(y, x + 1)[c]) -
                        static_cast<int>(input.at<cv::Vec3b>(y, x - 1)[c]);
            int yDiff = static_cast<int>(input.at<cv::Vec3b>(y + 1, x)[c]) -
                        static_cast<int>(input.at<cv::Vec3b>(y - 1, x)[c]);

            xSum += xDiff * xDiff;
            ySum += yDiff * yDiff;
        }

        return xSum + ySum;
    };

    double minGradient = std::numeric_limits<double>::max();
    int min_x = x;
    int min_y = y;

    for (int itrY = y - static_cast<int>(static_cast<double>(n) / 2.0);
         itrY < y + static_cast<int>(static_cast<double>(n) / 2.0);
         ++itrY) {
        for (int itrX = x - static_cast<int>(static_cast<double>(n) / 2.0);
             itrX < x + static_cast<int>(static_cast<double>(n) / 2.0);
             ++itrX) {
            if (itrY < 1 || itrX < 1 || itrY >= input.rows - 1 || itrX >= input.cols - 1)
                continue;

            const double gradient = lambdaGrad(input, itrX, itrY);
            if (gradient < minGradient) {
                minGradient = gradient;
                min_x = itrX;
                min_y = itrY;
            }
        }
    }

    return cv::Point(min_x, min_y);
}

cv::Mat MainWindow::enforceConnectivity(cv::Mat labels, const int numOfSuperpixels) {
    const std::array<int, 4> dx4 = {-1, 0, 1, 0};
    const std::array<int, 4> dy4 = {0, -1, 0, 1};
    const int SuperSize = (labels.rows * labels.cols) / numOfSuperpixels;
    int adjcLabel = 0;
    std::vector<int> xvec((labels.rows * labels.cols));
    std::vector<int> yvec((labels.rows * labels.cols));
    cv::Mat newLabels(labels.size(), CV_32S, -1);

    for (int y = 0; y < labels.rows; ++y) {
        for (int x = 0; x < labels.cols; ++x) {
            if (newLabels.at<int>(y, x) < 0) {
                newLabels.at<int>(y, x) = labels.at<int>(y, x);

                // Start new segment
                xvec[0] = x;
                yvec[0] = y;

                // Search neighbours for adjacent labels
                for (size_t i = 0; i < dx4.size(); ++i) {
                    int nX = xvec[0] + dx4[i];
                    int nY = yvec[0] + dy4[i];
                    if (nX < labels.cols && nX >= 0 && nY < labels.rows && nY >= 0) {
                        if (newLabels.at<int>(nY, nX) >= 0) {
                            adjcLabel = newLabels.at<int>(nY, nX);
                        }
                    }
                }

                int count = 1;
                for (int c = 0; c < count; ++c) {
                    for (size_t i = 0; i < dx4.size(); ++i) {
                        int nX = xvec[c] + dx4[i];
                        int nY = yvec[c] + dy4[i];
                        if (nX < labels.cols && nX >= 0 && nY < labels.rows && nY >= 0) {
                            if (0 > newLabels.at<int>(nY, nX)
                                && labels.at<int>(y, x) == labels.at<int>(nY, nX)) {
                                xvec[count] = nX;
                                yvec[count] = nY;
                                newLabels.at<int>(nY, nX) = newLabels.at<int>(y, x);
                                count++;
                            }
                        }
                    }
                }

                if (count <= SuperSize >> 2) {
                    for (int c = 0; c < count; ++c) {
                        newLabels.at<int>(yvec[c], xvec[c]) = adjcLabel;
                    }
                }
            }
        }
    }

    return newLabels.clone();
}

void MainWindow::display(const QImage& image, QGraphicsScene* scene) {
    scene->clear();
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    scene->setSceneRect(pixmap.rect());
    scene->update();

    if(scene == scene1) {
        ui->graphic1->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene2) {
        ui->graphic2->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene3) {
        ui->graphic3->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene4) {
        ui->graphic4->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene5) {
        ui->graphic5->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene6) {
        ui->graphic6->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene7) {
        ui->graphic7->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene8) {
        ui->graphic8->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    } else if(scene == scene11) {
        ui->graphic11->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}

