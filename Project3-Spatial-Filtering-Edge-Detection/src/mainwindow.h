#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgraphicsscene.h>

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
    QGraphicsScene *scene1, *scene2, *scene4, *scene5, *scene6, *scene7;
    QImage image1, image2, image3, image4, image5, image6;
    QImage image, fImage, enImage, padImage;

    QImage smooth(const QImage& image, int size);
    QImage sharp(const QImage& image, int size, double coefficient);
    QImage order(const QImage& image, int size);
    QImage sobel(const QImage& image);

    void display(const QImage& image, QGraphicsScene* scene);
    void images() ;
    void filters();
    void neighbor(const QImage& image, int x, int y, int size, std::function<void(QColor, int, int)> func);
    int convolve(const QImage& image, int x, int y, const QVector<QVector<double>>& kernel);
    void local();
    void enhancement();
    void applyMarr();
    QImage apply(const QImage& image, int size, double coefficient);
    QImage localEn(const QImage& image, int size, double k0, double k1, double k2, double k3, double c);
    QImage histEq(const QImage& image);
    QImage pad(const QImage& image, int padding);
    QImage fil(const QImage& image, const QVector<QVector<double>>& kernel) ;
    QImage marr(const QImage& image, int kernelSize, double sigma);
    QImage conv(const QImage &input, const QVector<QVector<double>> &kernel);
    QImage zeroCrossing(const QImage &input);
    QVector<QVector<double>> logKernel(int size, double sigma);
};
#endif // MAINWINDOW_H
