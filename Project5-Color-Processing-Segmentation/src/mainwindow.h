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

private slots:
    void applySegmentation();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene1, *scene2, *scene3, *scene4, *scene5, *scene6, *scene2_1, *scene2_2, *scene2_3, *scene3_1, *scene3_2, *scene11_2, *scene22, *scene33;
    QImage image, image_2, image_3, image1, image2, image3, image4, image5;
    cv::Mat grayscale_image;

    void images();
    void colors();

    void colorMap(int colormapType, QGraphicsScene* imageScene, QGraphicsScene* colorBarScene);
    void colorBar(int colormapType, QGraphicsScene* scene, QGraphicsView* view);

    cv::Mat QImageToCvMat(const QImage &inImage);
    void segmentImageByKMeans(int k, const QString &colorSpace, QGraphicsScene *scene);

    void segmentImageByHSIKMeans(int k, QGraphicsScene *scene);
    void applyHSISegmentation();

    void cmy();
    void hsi();
    void xyz();
    void yuv();
    void display(const QImage& image, QGraphicsScene* scene);
};
#endif // MAINWINDOW_H
