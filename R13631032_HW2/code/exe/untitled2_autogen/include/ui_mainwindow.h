/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPage1;
    QAction *actionPage2;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Page_1;
    QSlider *horizontalSlider;
    QLabel *label1;
    QGraphicsView *graphicsView6;
    QGraphicsView *graphicsView3;
    QLabel *label3;
    QGraphicsView *graphicsView5;
    QLabel *label2;
    QGraphicsView *graphicsView4;
    QGraphicsView *graphicsView2;
    QGraphicsView *graphicsView;
    QPushButton *pushButton3;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *Button1;
    QLabel *label_3;
    QWidget *page_2;
    QPushButton *pushButton4;
    QGraphicsView *graphicsView12;
    QGraphicsView *graphicsView11;
    QGraphicsView *graphicsView9;
    QLabel *label6;
    QGraphicsView *graphicsView10;
    QSlider *horizontalSlider3;
    QSlider *horizontalSlider4;
    QLabel *label5;
    QLabel *label4;
    QGraphicsView *graphicsView7;
    QSlider *horizontalSlider5;
    QGraphicsView *graphicsView8;
    QSlider *horizontalSlider2;
    QPushButton *Button2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1800, 900);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setDocumentMode(false);
        actionPage1 = new QAction(MainWindow);
        actionPage1->setObjectName("actionPage1");
        actionPage2 = new QAction(MainWindow);
        actionPage2->setObjectName("actionPage2");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(20, 140, 1441, 671));
        stackedWidget->setFrameShape(QFrame::Shape::StyledPanel);
        Page_1 = new QWidget();
        Page_1->setObjectName("Page_1");
        horizontalSlider = new QSlider(Page_1);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(1370, 270, 22, 160));
        horizontalSlider->setMaximum(256);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(16);
        horizontalSlider->setOrientation(Qt::Orientation::Vertical);
        label1 = new QLabel(Page_1);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(60, 80, 311, 19));
        label1->setAutoFillBackground(true);
        label1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graphicsView6 = new QGraphicsView(Page_1);
        graphicsView6->setObjectName("graphicsView6");
        graphicsView6->setGeometry(QRect(950, 230, 380, 220));
        graphicsView6->setFrameShape(QFrame::Shape::Panel);
        graphicsView6->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView3 = new QGraphicsView(Page_1);
        graphicsView3->setObjectName("graphicsView3");
        graphicsView3->setGeometry(QRect(490, 230, 380, 220));
        graphicsView3->setFrameShape(QFrame::Shape::Panel);
        graphicsView3->setFrameShadow(QFrame::Shadow::Raised);
        label3 = new QLabel(Page_1);
        label3->setObjectName("label3");
        label3->setGeometry(QRect(990, 80, 311, 19));
        label3->setFrameShape(QFrame::Shape::StyledPanel);
        label3->setFrameShadow(QFrame::Shadow::Sunken);
        label3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graphicsView5 = new QGraphicsView(Page_1);
        graphicsView5->setObjectName("graphicsView5");
        graphicsView5->setGeometry(QRect(950, 50, 380, 120));
        graphicsView5->setFrameShape(QFrame::Shape::Panel);
        graphicsView5->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView5->setLineWidth(1);
        label2 = new QLabel(Page_1);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(530, 80, 311, 19));
        label2->setFrameShape(QFrame::Shape::StyledPanel);
        label2->setFrameShadow(QFrame::Shadow::Sunken);
        label2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graphicsView4 = new QGraphicsView(Page_1);
        graphicsView4->setObjectName("graphicsView4");
        graphicsView4->setGeometry(QRect(30, 231, 380, 220));
        graphicsView4->setFrameShape(QFrame::Shape::Panel);
        graphicsView4->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView2 = new QGraphicsView(Page_1);
        graphicsView2->setObjectName("graphicsView2");
        graphicsView2->setGeometry(QRect(490, 50, 380, 120));
        graphicsView2->setFrameShape(QFrame::Shape::Panel);
        graphicsView2->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView2->setLineWidth(1);
        graphicsView = new QGraphicsView(Page_1);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(30, 50, 380, 120));
        graphicsView->setFrameShape(QFrame::Shape::Panel);
        graphicsView->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        graphicsView->setInteractive(false);
        pushButton3 = new QPushButton(Page_1);
        pushButton3->setObjectName("pushButton3");
        pushButton3->setGeometry(QRect(630, 510, 93, 28));
        pushButton1 = new QPushButton(Page_1);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(580, 480, 93, 28));
        pushButton2 = new QPushButton(Page_1);
        pushButton2->setObjectName("pushButton2");
        pushButton2->setGeometry(QRect(680, 480, 93, 28));
        Button1 = new QPushButton(Page_1);
        Button1->setObjectName("Button1");
        Button1->setGeometry(QRect(1300, 560, 100, 80));
        QFont font;
        font.setPointSize(12);
        Button1->setFont(font);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoNext));
        Button1->setIcon(icon);
        label_3 = new QLabel(Page_1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1340, 230, 81, 19));
        label_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(Page_1);
        horizontalSlider->raise();
        graphicsView5->raise();
        graphicsView2->raise();
        graphicsView->raise();
        pushButton3->raise();
        pushButton1->raise();
        pushButton2->raise();
        Button1->raise();
        label2->raise();
        label3->raise();
        label1->raise();
        graphicsView3->raise();
        graphicsView6->raise();
        label_3->raise();
        graphicsView4->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton4 = new QPushButton(page_2);
        pushButton4->setObjectName("pushButton4");
        pushButton4->setGeometry(QRect(1030, 500, 221, 28));
        pushButton4->setAutoFillBackground(true);
        graphicsView12 = new QGraphicsView(page_2);
        graphicsView12->setObjectName("graphicsView12");
        graphicsView12->setGeometry(QRect(950, 240, 380, 220));
        graphicsView12->setFrameShape(QFrame::Shape::Panel);
        graphicsView12->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView11 = new QGraphicsView(page_2);
        graphicsView11->setObjectName("graphicsView11");
        graphicsView11->setGeometry(QRect(950, 60, 380, 120));
        graphicsView11->setFrameShape(QFrame::Shape::Panel);
        graphicsView11->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView11->setLineWidth(1);
        graphicsView9 = new QGraphicsView(page_2);
        graphicsView9->setObjectName("graphicsView9");
        graphicsView9->setGeometry(QRect(30, 60, 380, 120));
        graphicsView9->setFrameShape(QFrame::Shape::Panel);
        graphicsView9->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView9->setLineWidth(1);
        label6 = new QLabel(page_2);
        label6->setObjectName("label6");
        label6->setGeometry(QRect(990, 90, 311, 19));
        label6->setFrameShape(QFrame::Shape::StyledPanel);
        label6->setFrameShadow(QFrame::Shadow::Sunken);
        label6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graphicsView10 = new QGraphicsView(page_2);
        graphicsView10->setObjectName("graphicsView10");
        graphicsView10->setGeometry(QRect(30, 240, 380, 220));
        graphicsView10->setFrameShape(QFrame::Shape::Panel);
        graphicsView10->setFrameShadow(QFrame::Shadow::Raised);
        horizontalSlider3 = new QSlider(page_2);
        horizontalSlider3->setObjectName("horizontalSlider3");
        horizontalSlider3->setGeometry(QRect(690, 520, 160, 22));
        horizontalSlider3->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider4 = new QSlider(page_2);
        horizontalSlider4->setObjectName("horizontalSlider4");
        horizontalSlider4->setGeometry(QRect(50, 520, 160, 22));
        horizontalSlider4->setMinimum(-100);
        horizontalSlider4->setMaximum(100);
        horizontalSlider4->setOrientation(Qt::Orientation::Horizontal);
        label5 = new QLabel(page_2);
        label5->setObjectName("label5");
        label5->setGeometry(QRect(60, 90, 311, 19));
        label5->setFrameShape(QFrame::Shape::StyledPanel);
        label5->setFrameShadow(QFrame::Shadow::Sunken);
        label5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label4 = new QLabel(page_2);
        label4->setObjectName("label4");
        label4->setGeometry(QRect(530, 90, 311, 19));
        label4->setFrameShape(QFrame::Shape::StyledPanel);
        label4->setFrameShadow(QFrame::Shadow::Sunken);
        label4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graphicsView7 = new QGraphicsView(page_2);
        graphicsView7->setObjectName("graphicsView7");
        graphicsView7->setGeometry(QRect(490, 60, 380, 120));
        graphicsView7->setFrameShape(QFrame::Shape::Panel);
        graphicsView7->setFrameShadow(QFrame::Shadow::Raised);
        graphicsView7->setLineWidth(1);
        horizontalSlider5 = new QSlider(page_2);
        horizontalSlider5->setObjectName("horizontalSlider5");
        horizontalSlider5->setGeometry(QRect(240, 520, 160, 22));
        horizontalSlider5->setMinimum(-100);
        horizontalSlider5->setMaximum(100);
        horizontalSlider5->setOrientation(Qt::Orientation::Horizontal);
        graphicsView8 = new QGraphicsView(page_2);
        graphicsView8->setObjectName("graphicsView8");
        graphicsView8->setGeometry(QRect(490, 240, 380, 220));
        graphicsView8->setFrameShape(QFrame::Shape::Panel);
        graphicsView8->setFrameShadow(QFrame::Shadow::Raised);
        horizontalSlider2 = new QSlider(page_2);
        horizontalSlider2->setObjectName("horizontalSlider2");
        horizontalSlider2->setGeometry(QRect(510, 520, 160, 22));
        horizontalSlider2->setMinimum(0);
        horizontalSlider2->setMaximum(200);
        horizontalSlider2->setOrientation(Qt::Orientation::Horizontal);
        Button2 = new QPushButton(page_2);
        Button2->setObjectName("Button2");
        Button2->setGeometry(QRect(20, 560, 100, 80));
        QFont font1;
        font1.setBold(false);
        Button2->setFont(font1);
        Button2->setAutoFillBackground(true);
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoPrevious));
        Button2->setIcon(icon1);
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 490, 131, 19));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 490, 121, 20));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(540, 490, 121, 20));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(710, 490, 121, 20));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page_2);
        pushButton4->raise();
        graphicsView11->raise();
        graphicsView9->raise();
        graphicsView10->raise();
        horizontalSlider3->raise();
        horizontalSlider4->raise();
        label5->raise();
        graphicsView7->raise();
        horizontalSlider5->raise();
        graphicsView8->raise();
        horizontalSlider2->raise();
        Button2->raise();
        label4->raise();
        label6->raise();
        label->raise();
        label_2->raise();
        label_4->raise();
        label_5->raise();
        graphicsView12->raise();
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPage1->setText(QCoreApplication::translate("MainWindow", "actionPage1", nullptr));
        actionPage2->setText(QCoreApplication::translate("MainWindow", "actonPage2", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        label3->setText(QString());
        label2->setText(QString());
        pushButton3->setText(QCoreApplication::translate("MainWindow", "Compare", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        pushButton2->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        Button1->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Threshold", nullptr));
        pushButton4->setText(QCoreApplication::translate("MainWindow", "Histogram Equalization", nullptr));
        label6->setText(QString());
        label5->setText(QString());
        label4->setText(QString());
        Button2->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "GrayScale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
