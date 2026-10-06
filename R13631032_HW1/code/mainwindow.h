#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QVector>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_aSlider_valueChanged(int value);
    void on_mSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QImage image;

    bool readFile(const QString &filePath, QImage &image, QVector<int> &histogram);
    void setImage();
    void histo(QGraphicsView *view, const QVector<int> &histogram);
    void histoo(const QImage &image, QVector<int> &histogram);

    QImage addConstant(const QImage &image, int constant);
    QImage subtractConstant(const QImage &image, int constant);
    QImage multiplyConstant(const QImage &image, double constant);
    QImage avg(const QImage &image1, const QImage &image2);
    QImage grad(const QImage &image);
};

#endif // MAINWINDOW_H


