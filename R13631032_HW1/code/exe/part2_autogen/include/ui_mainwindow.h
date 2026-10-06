/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *Histogram;
    QLabel *Label;
    QLabel *aLabel;
    QGraphicsView *aHistogram;
    QLabel *avgLabel;
    QLabel *mLabel;
    QLabel *gLabel;
    QGraphicsView *avgHistogram;
    QGraphicsView *gHistogram;
    QGraphicsView *mHistogram;
    QSlider *aSlider;
    QSlider *mSlider;
    QLabel *mvLabel;
    QLabel *avLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1426, 892);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Histogram = new QGraphicsView(centralwidget);
        Histogram->setObjectName(QStringLiteral("Histogram"));
        Histogram->setGeometry(QRect(300, 60, 400, 200));
        Histogram->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        Label = new QLabel(centralwidget);
        Label->setObjectName(QStringLiteral("Label"));
        Label->setGeometry(QRect(80, 60, 200, 200));
        Label->setFrameShape(QFrame::Shape::Box);
        Label->setFrameShadow(QFrame::Shadow::Raised);
        Label->setScaledContents(false);
        Label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        aLabel = new QLabel(centralwidget);
        aLabel->setObjectName(QStringLiteral("aLabel"));
        aLabel->setGeometry(QRect(80, 320, 200, 200));
        aLabel->setFrameShape(QFrame::Shape::Box);
        aLabel->setFrameShadow(QFrame::Shadow::Raised);
        aLabel->setScaledContents(false);
        aLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        aHistogram = new QGraphicsView(centralwidget);
        aHistogram->setObjectName(QStringLiteral("aHistogram"));
        aHistogram->setGeometry(QRect(300, 320, 400, 200));
        aHistogram->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        avgLabel = new QLabel(centralwidget);
        avgLabel->setObjectName(QStringLiteral("avgLabel"));
        avgLabel->setGeometry(QRect(750, 190, 200, 200));
        avgLabel->setFrameShape(QFrame::Shape::Box);
        avgLabel->setFrameShadow(QFrame::Shadow::Raised);
        avgLabel->setScaledContents(false);
        avgLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        mLabel = new QLabel(centralwidget);
        mLabel->setObjectName(QStringLiteral("mLabel"));
        mLabel->setGeometry(QRect(80, 580, 200, 200));
        mLabel->setFrameShape(QFrame::Shape::Box);
        mLabel->setFrameShadow(QFrame::Shadow::Raised);
        mLabel->setScaledContents(false);
        mLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gLabel = new QLabel(centralwidget);
        gLabel->setObjectName(QStringLiteral("gLabel"));
        gLabel->setGeometry(QRect(750, 450, 200, 200));
        gLabel->setFrameShape(QFrame::Shape::Box);
        gLabel->setFrameShadow(QFrame::Shadow::Raised);
        gLabel->setScaledContents(false);
        gLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        avgHistogram = new QGraphicsView(centralwidget);
        avgHistogram->setObjectName(QStringLiteral("avgHistogram"));
        avgHistogram->setGeometry(QRect(970, 190, 400, 200));
        avgHistogram->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        gHistogram = new QGraphicsView(centralwidget);
        gHistogram->setObjectName(QStringLiteral("gHistogram"));
        gHistogram->setGeometry(QRect(970, 450, 400, 200));
        gHistogram->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        mHistogram = new QGraphicsView(centralwidget);
        mHistogram->setObjectName(QStringLiteral("mHistogram"));
        mHistogram->setGeometry(QRect(300, 580, 400, 200));
        mHistogram->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        aSlider = new QSlider(centralwidget);
        aSlider->setObjectName(QStringLiteral("aSlider"));
        aSlider->setGeometry(QRect(100, 530, 160, 22));
        aSlider->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        aSlider->setMinimum(-31);
        aSlider->setMaximum(31);
        aSlider->setSingleStep(4);
        aSlider->setPageStep(4);
        aSlider->setOrientation(Qt::Orientation::Horizontal);
        mSlider = new QSlider(centralwidget);
        mSlider->setObjectName(QStringLiteral("mSlider"));
        mSlider->setGeometry(QRect(100, 790, 160, 22));
        mSlider->setMaximum(10);
        mSlider->setSingleStep(1);
        mSlider->setPageStep(1);
        mSlider->setOrientation(Qt::Orientation::Horizontal);
        mvLabel = new QLabel(centralwidget);
        mvLabel->setObjectName(QStringLiteral("mvLabel"));
        mvLabel->setGeometry(QRect(60, 790, 63, 19));
        avLabel = new QLabel(centralwidget);
        avLabel->setObjectName(QStringLiteral("avLabel"));
        avLabel->setGeometry(QRect(60, 530, 63, 19));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 63, 19));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 300, 101, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 560, 81, 19));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(820, 170, 63, 19));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(820, 430, 63, 19));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1426, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Label->setText(QApplication::translate("MainWindow", "original", nullptr));
        aLabel->setText(QApplication::translate("MainWindow", "add/subtract", nullptr));
        avgLabel->setText(QApplication::translate("MainWindow", "average", nullptr));
        mLabel->setText(QApplication::translate("MainWindow", "multiply", nullptr));
        gLabel->setText(QApplication::translate("MainWindow", "gradient", nullptr));
        mvLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        avLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        label->setText(QApplication::translate("MainWindow", "Original", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Add/Subtract", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Multiplied", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Average", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Gradient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
