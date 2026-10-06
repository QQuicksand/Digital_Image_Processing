#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <array>
#include <limits>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Add PixelFeature struct definition
struct PixelFeature {
    std::array<double, 3> labValue;
    cv::Point xy;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene1, *scene2, *scene3, *scene4, *scene5;
    QGraphicsScene *scene6, *scene7, *scene8, *scene10;
    QGraphicsScene *scene10_2, *scene11;

    QImage image, image2, image2_1, image3;

    void images();
    void fisheye();
    void kaleidoscope();
    void wavy();
    void spiral();
    void ripple();
    void dwt();
    void superpixel();
    void display(const QImage &image, QGraphicsScene *scene);
    void SLIC(const cv::Mat &src_image, cv::Mat &trans_image,
              int numOfSuperpixels, const int compactness, const double threshold);
    void fusing(const cv::Mat& input, cv::Mat& LL, cv::Mat& LH, cv::Mat& HL, cv::Mat& HH);

    // Add helper functions for SLIC
    double distance(PixelFeature f1, PixelFeature f2, const int compactness, const int S);
    cv::Point getLocalMinimum(cv::Mat input, const int x, const int y, const int n);
    cv::Mat enforceConnectivity(cv::Mat labels, const int numOfSuperpixels);

    std::vector<std::vector<int>> clusters;
    std::vector<std::vector<float>> distances;
};

#endif // MAINWINDOW_H
