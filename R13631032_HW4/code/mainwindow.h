#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <opencv2/core/core.hpp>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene0, *scene1, *scene2, *scene3, *scene4, *scene5, *scene5_2, *scene6, *scene7, *scene10, *scene11;
    QImage image, image2, sImage, spectrum, phaseAng, rImage, fImag;
    QImage img1, img2, img3, img4, img5;
    QImage lowImage, highImage;
    QPixmap cvMatToQPixmap(const cv::Mat& mat);
    QImage ideal(const QImage &image, int cutoff, bool lowpass);
    QImage butterworth(const QImage &image, int cutoff, int order, bool lowpass);
    QImage gaussian(const QImage &image, int cutoff, bool lowpass);
    void fftShift(cv::Mat& img);
    void filters();
    void images();
    void fourier(const QImage &image);
    void size(int size);
    void homomorphic(cv::Mat &filter, float gammaH, float gammaL, float D0, float c);
    void applyhomomorphic();
    cv::Mat apply(const QImage &image, int cutoff, const QString &filterType, bool lowpass);
    cv::Mat filterMat(cv::Size size, int cutoff, const QString &filterType, bool lowpass, int order);
    void display(const QImage& image, QGraphicsScene* scene);
};
#endif // MAINWINDOW_H
