#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void images();
    void updateImage(int method);
    void applyThreshold(int threshold);
    void adjustResolution(int value);
    void grayScale(int value);
    void bright_contrast(int value);
    void equalization();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene1, *scene2, *scene3, *scene4, *scene5, *scene6, *scene7, *scene8, *scene9, *scene10, *scene11, *scene12;
    QImage originImage;
    QImage gImage;
    QImage grayImageA;
    QImage grayImageB;

    QImage bright_contrast(const QImage& image, int brightness, double contrast);
    void display(const QImage& image, QGraphicsScene* scene);
    QGraphicsScene* hist(const QImage &image);
    QImage resizeImage(const QImage& image, int newWidth, int newHeight);
    QImage grayScale(const QImage& image, int levels);
    QImage equalization(const QImage &image);
};

#endif // MAINWINDOW_H
