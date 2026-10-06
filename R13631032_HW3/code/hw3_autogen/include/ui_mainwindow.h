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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGraphicsView *graphicsView_2;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *radioButton1;
    QRadioButton *radioButton3;
    QRadioButton *radioButton2;
    QRadioButton *radioButton4;
    QSlider *verticalSlider;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *label_3;
    QPushButton *Button1;
    QGroupBox *groupBox_2;
    QGraphicsView *graphicsView;
    QLabel *label;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton4;
    QProgressBar *progressBar;
    QWidget *page_2;
    QPushButton *Button2;
    QGroupBox *groupBox_3;
    QGraphicsView *graphicsView_4;
    QLabel *label_6;
    QPushButton *pushButton5;
    QPushButton *pushButton7;
    QPushButton *pushButton6;
    QPushButton *pushButton8;
    QGraphicsView *graphicsView_5;
    QLabel *label_7;
    QPushButton *Button3;
    QProgressBar *progressBar3;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_16;
    QLabel *label_17;
    QSpinBox *spinBox2;
    QWidget *page_3;
    QGroupBox *groupBox_4;
    QGraphicsView *graphicsView_6;
    QLabel *label_8;
    QPushButton *pushButton9;
    QPushButton *pushButton10;
    QGraphicsView *graphicsView_7;
    QLabel *label_9;
    QPushButton *Button4;
    QRadioButton *radioButton5;
    QRadioButton *radioButton6;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QProgressBar *progressBar2;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1456, 901);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(20, 70, 1421, 741));
        stackedWidget->setStyleSheet(QString::fromUtf8("color: rgb(60, 110, 113);\n"
"selection-color: rgb(254, 250, 224);\n"
"background-color: rgb(217, 217, 217);"));
        stackedWidget->setFrameShape(QFrame::Shape::Box);
        page = new QWidget();
        page->setObjectName("page");
        graphicsView_2 = new QGraphicsView(page);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(400, 90, 768, 576));
        graphicsView_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1200, 170, 111, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code SemiLight")});
        font.setPointSize(12);
        label_2->setFont(font);
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(60, 410, 301, 251));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Code Light")});
        font1.setPointSize(14);
        groupBox->setFont(font1);
        radioButton1 = new QRadioButton(groupBox);
        radioButton1->setObjectName("radioButton1");
        radioButton1->setGeometry(QRect(30, 60, 150, 23));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cascadia Code")});
        font2.setPointSize(12);
        radioButton1->setFont(font2);
        radioButton3 = new QRadioButton(groupBox);
        radioButton3->setObjectName("radioButton3");
        radioButton3->setGeometry(QRect(30, 140, 250, 23));
        radioButton3->setFont(font2);
        radioButton2 = new QRadioButton(groupBox);
        radioButton2->setObjectName("radioButton2");
        radioButton2->setGeometry(QRect(30, 100, 150, 23));
        radioButton2->setFont(font2);
        radioButton4 = new QRadioButton(groupBox);
        radioButton4->setObjectName("radioButton4");
        radioButton4->setGeometry(QRect(30, 180, 150, 23));
        radioButton4->setFont(font2);
        verticalSlider = new QSlider(page);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(1240, 400, 30, 200));
        verticalSlider->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(60, 110, 113);\n"
"border-color: rgb(60, 110, 113);\n"
""));
        verticalSlider->setMaximum(10);
        verticalSlider->setOrientation(Qt::Orientation::Vertical);
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(400, 30, 761, 41));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_4->setFrameShape(QFrame::Shape::StyledPanel);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox = new QSpinBox(page);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(1220, 220, 71, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cascadia Code")});
        font3.setPointSize(11);
        spinBox->setFont(font3);
        spinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBox->setMinimum(3);
        spinBox->setSingleStep(2);
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1190, 330, 131, 41));
        label_3->setFont(font);
        Button1 = new QPushButton(page);
        Button1->setObjectName("Button1");
        Button1->setGeometry(QRect(1180, 690, 131, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Cascadia Code")});
        font4.setPointSize(12);
        font4.setWeight(QFont::Medium);
        Button1->setFont(font4);
        Button1->setAutoFillBackground(false);
        Button1->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 75, 99);\n"
"color: rgb(255, 255, 255);\n"
""));
        Button1->setAutoRepeatDelay(100);
        Button1->setAutoDefault(false);
        Button1->setFlat(false);
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(50, 30, 321, 351));
        QPalette palette;
        QBrush brush(QColor(60, 110, 113, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(217, 217, 217, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(254, 250, 224, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        QBrush brush3(QColor(60, 110, 113, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        groupBox_2->setPalette(palette);
        QFont font5;
        font5.setWeight(QFont::Thin);
        font5.setKerning(false);
        groupBox_2->setFont(font5);
#if QT_CONFIG(statustip)
        groupBox_2->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        groupBox_2->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        groupBox_2->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        groupBox_2->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        groupBox_2->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        graphicsView = new QGraphicsView(groupBox_2);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(30, 60, 256, 192));
        graphicsView->setAutoFillBackground(false);
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphicsView->setLineWidth(2);
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 191, 31));
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton1 = new QPushButton(groupBox_2);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(40, 260, 95, 30));
        pushButton1->setFont(font2);
        pushButton2 = new QPushButton(groupBox_2);
        pushButton2->setObjectName("pushButton2");
        pushButton2->setGeometry(QRect(40, 300, 95, 30));
        pushButton2->setFont(font2);
        pushButton3 = new QPushButton(groupBox_2);
        pushButton3->setObjectName("pushButton3");
        pushButton3->setGeometry(QRect(170, 260, 95, 30));
        pushButton3->setFont(font2);
        pushButton4 = new QPushButton(groupBox_2);
        pushButton4->setObjectName("pushButton4");
        pushButton4->setGeometry(QRect(170, 300, 95, 30));
        pushButton4->setFont(font2);
        progressBar = new QProgressBar(page);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(110, 660, 211, 51));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Link, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        progressBar->setPalette(palette1);
        progressBar->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 110, 113);"));
        progressBar->setValue(0);
        stackedWidget->addWidget(page);
        groupBox_2->raise();
        graphicsView_2->raise();
        label_2->raise();
        groupBox->raise();
        verticalSlider->raise();
        label_4->raise();
        spinBox->raise();
        label_3->raise();
        Button1->raise();
        progressBar->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        Button2 = new QPushButton(page_2);
        Button2->setObjectName("Button2");
        Button2->setGeometry(QRect(40, 690, 131, 31));
        Button2->setFont(font4);
        Button2->setAutoFillBackground(false);
        Button2->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 75, 99);\n"
"color: rgb(255, 255, 255);\n"
""));
        Button2->setAutoRepeatDelay(100);
        Button2->setAutoDefault(false);
        Button2->setFlat(false);
        groupBox_3 = new QGroupBox(page_2);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(50, 30, 321, 351));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        groupBox_3->setPalette(palette2);
        groupBox_3->setFont(font5);
#if QT_CONFIG(statustip)
        groupBox_3->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        groupBox_3->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        groupBox_3->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        groupBox_3->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        groupBox_3->setStyleSheet(QString::fromUtf8(""));
        groupBox_3->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        graphicsView_4 = new QGraphicsView(groupBox_3);
        graphicsView_4->setObjectName("graphicsView_4");
        graphicsView_4->setGeometry(QRect(30, 60, 256, 192));
        graphicsView_4->setAutoFillBackground(false);
        graphicsView_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphicsView_4->setLineWidth(2);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 20, 191, 31));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton5 = new QPushButton(groupBox_3);
        pushButton5->setObjectName("pushButton5");
        pushButton5->setGeometry(QRect(40, 260, 95, 30));
        pushButton5->setFont(font2);
        pushButton7 = new QPushButton(groupBox_3);
        pushButton7->setObjectName("pushButton7");
        pushButton7->setGeometry(QRect(40, 300, 95, 30));
        pushButton7->setFont(font2);
        pushButton6 = new QPushButton(groupBox_3);
        pushButton6->setObjectName("pushButton6");
        pushButton6->setGeometry(QRect(170, 260, 95, 30));
        pushButton6->setFont(font2);
        pushButton8 = new QPushButton(groupBox_3);
        pushButton8->setObjectName("pushButton8");
        pushButton8->setGeometry(QRect(170, 300, 95, 30));
        pushButton8->setFont(font2);
        label_6->raise();
        pushButton5->raise();
        pushButton7->raise();
        pushButton6->raise();
        pushButton8->raise();
        graphicsView_4->raise();
        graphicsView_5 = new QGraphicsView(page_2);
        graphicsView_5->setObjectName("graphicsView_5");
        graphicsView_5->setGeometry(QRect(400, 90, 768, 576));
        graphicsView_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(400, 30, 761, 41));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7->setFrameShape(QFrame::Shape::StyledPanel);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Button3 = new QPushButton(page_2);
        Button3->setObjectName("Button3");
        Button3->setGeometry(QRect(1160, 690, 131, 31));
        Button3->setFont(font4);
        Button3->setAutoFillBackground(false);
        Button3->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 75, 99);\n"
"color: rgb(255, 255, 255);\n"
""));
        Button3->setAutoRepeatDelay(100);
        Button3->setAutoDefault(false);
        Button3->setFlat(false);
        progressBar3 = new QProgressBar(page_2);
        progressBar3->setObjectName("progressBar3");
        progressBar3->setGeometry(QRect(110, 570, 211, 51));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Link, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette3.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        progressBar3->setPalette(palette3);
        progressBar3->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 110, 113);"));
        progressBar3->setValue(0);
        doubleSpinBox_8 = new QDoubleSpinBox(page_2);
        doubleSpinBox_8->setObjectName("doubleSpinBox_8");
        doubleSpinBox_8->setGeometry(QRect(220, 420, 101, 25));
        doubleSpinBox_8->setFont(font2);
        doubleSpinBox_8->setDecimals(0);
        doubleSpinBox_8->setMinimum(1.000000000000000);
        doubleSpinBox_8->setMaximum(81.000000000000000);
        doubleSpinBox_8->setSingleStep(2.000000000000000);
        doubleSpinBox_8->setValue(1.000000000000000);
        label_16 = new QLabel(page_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(110, 420, 91, 21));
        label_16->setFont(font2);
        label_16->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_17 = new QLabel(page_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(60, 460, 141, 21));
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        spinBox2 = new QSpinBox(page_2);
        spinBox2->setObjectName("spinBox2");
        spinBox2->setGeometry(QRect(220, 460, 101, 31));
        spinBox2->setFont(font3);
        spinBox2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        spinBox2->setMinimum(1);
        spinBox2->setSingleStep(2);
        spinBox2->setValue(15);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        groupBox_4 = new QGroupBox(page_3);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(50, 30, 321, 311));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        groupBox_4->setPalette(palette4);
        groupBox_4->setFont(font5);
#if QT_CONFIG(statustip)
        groupBox_4->setStatusTip(QString::fromUtf8(""));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        groupBox_4->setWhatsThis(QString::fromUtf8(""));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        groupBox_4->setAccessibleName(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        groupBox_4->setAccessibleDescription(QString::fromUtf8(""));
#endif // QT_CONFIG(accessibility)
        groupBox_4->setStyleSheet(QString::fromUtf8(""));
        groupBox_4->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        graphicsView_6 = new QGraphicsView(groupBox_4);
        graphicsView_6->setObjectName("graphicsView_6");
        graphicsView_6->setGeometry(QRect(30, 60, 256, 192));
        graphicsView_6->setAutoFillBackground(false);
        graphicsView_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphicsView_6->setLineWidth(2);
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(60, 20, 191, 31));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton9 = new QPushButton(groupBox_4);
        pushButton9->setObjectName("pushButton9");
        pushButton9->setGeometry(QRect(50, 260, 95, 30));
        pushButton9->setFont(font2);
        pushButton10 = new QPushButton(groupBox_4);
        pushButton10->setObjectName("pushButton10");
        pushButton10->setGeometry(QRect(170, 260, 95, 30));
        pushButton10->setFont(font2);
        graphicsView_7 = new QGraphicsView(page_3);
        graphicsView_7->setObjectName("graphicsView_7");
        graphicsView_7->setGeometry(QRect(400, 90, 768, 576));
        graphicsView_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(page_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(400, 30, 761, 41));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_9->setFrameShape(QFrame::Shape::StyledPanel);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Button4 = new QPushButton(page_3);
        Button4->setObjectName("Button4");
        Button4->setGeometry(QRect(40, 690, 131, 31));
        Button4->setFont(font4);
        Button4->setAutoFillBackground(false);
        Button4->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 75, 99);\n"
"color: rgb(255, 255, 255);\n"
""));
        Button4->setAutoRepeatDelay(100);
        Button4->setAutoDefault(false);
        Button4->setFlat(false);
        radioButton5 = new QRadioButton(page_3);
        radioButton5->setObjectName("radioButton5");
        radioButton5->setGeometry(QRect(70, 360, 231, 41));
        radioButton5->setFont(font2);
        radioButton6 = new QRadioButton(page_3);
        radioButton6->setObjectName("radioButton6");
        radioButton6->setGeometry(QRect(70, 635, 301, 41));
        radioButton6->setFont(font2);
        label_10 = new QLabel(page_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(120, 450, 31, 21));
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_11 = new QLabel(page_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(120, 490, 31, 21));
        label_11->setFont(font2);
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_12 = new QLabel(page_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(120, 530, 31, 21));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_13 = new QLabel(page_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(120, 570, 31, 21));
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_14 = new QLabel(page_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(120, 610, 31, 21));
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_15 = new QLabel(page_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(115, 410, 51, 21));
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        doubleSpinBox_2 = new QDoubleSpinBox(page_3);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setGeometry(QRect(200, 410, 101, 25));
        doubleSpinBox_2->setFont(font2);
        doubleSpinBox_2->setDecimals(0);
        doubleSpinBox_2->setMinimum(1.000000000000000);
        doubleSpinBox_2->setMaximum(81.000000000000000);
        doubleSpinBox_2->setSingleStep(2.000000000000000);
        doubleSpinBox_3 = new QDoubleSpinBox(page_3);
        doubleSpinBox_3->setObjectName("doubleSpinBox_3");
        doubleSpinBox_3->setGeometry(QRect(200, 450, 101, 25));
        doubleSpinBox_3->setFont(font2);
        doubleSpinBox_3->setDecimals(1);
        doubleSpinBox_3->setMinimum(0.000000000000000);
        doubleSpinBox_3->setSingleStep(0.100000000000000);
        doubleSpinBox_3->setValue(0.000000000000000);
        doubleSpinBox_4 = new QDoubleSpinBox(page_3);
        doubleSpinBox_4->setObjectName("doubleSpinBox_4");
        doubleSpinBox_4->setGeometry(QRect(200, 490, 101, 25));
        doubleSpinBox_4->setFont(font2);
        doubleSpinBox_4->setDecimals(1);
        doubleSpinBox_4->setMinimum(0.000000000000000);
        doubleSpinBox_4->setSingleStep(0.100000000000000);
        doubleSpinBox_4->setValue(0.300000000000000);
        doubleSpinBox_5 = new QDoubleSpinBox(page_3);
        doubleSpinBox_5->setObjectName("doubleSpinBox_5");
        doubleSpinBox_5->setGeometry(QRect(200, 530, 101, 25));
        doubleSpinBox_5->setFont(font2);
        doubleSpinBox_5->setDecimals(1);
        doubleSpinBox_5->setMinimum(0.000000000000000);
        doubleSpinBox_5->setSingleStep(0.100000000000000);
        doubleSpinBox_5->setValue(0.000000000000000);
        doubleSpinBox_6 = new QDoubleSpinBox(page_3);
        doubleSpinBox_6->setObjectName("doubleSpinBox_6");
        doubleSpinBox_6->setGeometry(QRect(200, 570, 101, 25));
        doubleSpinBox_6->setFont(font2);
        doubleSpinBox_6->setDecimals(1);
        doubleSpinBox_6->setMinimum(0.000000000000000);
        doubleSpinBox_6->setSingleStep(0.100000000000000);
        doubleSpinBox_7 = new QDoubleSpinBox(page_3);
        doubleSpinBox_7->setObjectName("doubleSpinBox_7");
        doubleSpinBox_7->setGeometry(QRect(200, 610, 101, 25));
        doubleSpinBox_7->setFont(font2);
        doubleSpinBox_7->setDecimals(1);
        doubleSpinBox_7->setMinimum(0.000000000000000);
        doubleSpinBox_7->setSingleStep(0.200000000000000);
        doubleSpinBox_7->setValue(22.800000000000001);
        progressBar2 = new QProgressBar(page_3);
        progressBar2->setObjectName("progressBar2");
        progressBar2->setGeometry(QRect(1200, 650, 211, 51));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette5.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Link, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette5.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        progressBar2->setPalette(palette5);
        progressBar2->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 110, 113);"));
        progressBar2->setValue(0);
        textBrowser = new QTextBrowser(page_3);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(1190, 100, 221, 541));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Cascadia Code")});
        font6.setPointSize(10);
        textBrowser->setFont(font6);
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1456, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        Button1->setDefault(false);
        Button2->setDefault(false);
        Button3->setDefault(false);
        Button4->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "mask size", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Mask Types", nullptr));
        radioButton1->setText(QCoreApplication::translate("MainWindow", "Smoothing", nullptr));
        radioButton3->setText(QCoreApplication::translate("MainWindow", "Order Statistics", nullptr));
        radioButton2->setText(QCoreApplication::translate("MainWindow", "Sharpening", nullptr));
        radioButton4->setText(QCoreApplication::translate("MainWindow", "Sobel", nullptr));
        label_4->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "coefficient", nullptr));
        Button1->setText(QCoreApplication::translate("MainWindow", "PAGE 1 >>", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "Image1", nullptr));
        pushButton2->setText(QCoreApplication::translate("MainWindow", "Image2", nullptr));
        pushButton3->setText(QCoreApplication::translate("MainWindow", "Image3", nullptr));
        pushButton4->setText(QCoreApplication::translate("MainWindow", "Image4", nullptr));
        Button2->setText(QCoreApplication::translate("MainWindow", "<< PAGE 2 ", nullptr));
        groupBox_3->setTitle(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        pushButton5->setText(QCoreApplication::translate("MainWindow", "Image1", nullptr));
        pushButton7->setText(QCoreApplication::translate("MainWindow", "Image2", nullptr));
        pushButton6->setText(QCoreApplication::translate("MainWindow", "Image3", nullptr));
        pushButton8->setText(QCoreApplication::translate("MainWindow", "Image4", nullptr));
        label_7->setText(QString());
        Button3->setText(QCoreApplication::translate("MainWindow", " PAGE 2 >>", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Sigma", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Kernel Size", nullptr));
        groupBox_4->setTitle(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        pushButton9->setText(QCoreApplication::translate("MainWindow", "Image1", nullptr));
        pushButton10->setText(QCoreApplication::translate("MainWindow", "Image2", nullptr));
        label_9->setText(QString());
        Button4->setText(QCoreApplication::translate("MainWindow", "<< PAGE 3 ", nullptr));
        radioButton5->setText(QCoreApplication::translate("MainWindow", "Local Enhancement", nullptr));
        radioButton6->setText(QCoreApplication::translate("MainWindow", "Histogram Equalization", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "K0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "K1", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "K2", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "K3", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Cascadia Code'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">Local Enhancement Parameters: </span><span style=\" font-size:9pt; font-weight:700;\">   </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:700;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; "
                        "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#bc6c25;\">Local mean intensity m</span><span style=\" font-size:9pt; color:#bc6c25; vertical-align:sub;\">Sxy</span><span style=\" font-size:9pt; color:#bc6c25;\">:    </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:700; color:#bc6c25;\"> k\342\202\200\302\267m</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25; vertical-align:sub;\">G</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25;\"> \342\211\244 m</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25; vertical-align:sub;\">Sxy</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25;\"> \342\211\244 k\342\202\201\302\267m</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25; vertical-align:sub;\">G</span><span style=\" font-size:9pt; color:#bc6c2"
                        "5;\">    </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#bc6c25;\">(m</span><span style=\" font-size:9pt; color:#bc6c25; vertical-align:sub;\">G</span><span style=\" font-size:9pt; color:#bc6c25;\">: global mean)<br />(k\342\202\200, k\342\202\201: constants)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; color:#bc6c25;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#bc6c25;\">Local standard deviation s</span><span style=\" font-size:9pt; color:#bc6c25; vertical-align:sub;\">Sxy</span><span style=\" font-size:9pt; color:#bc6c25;\">:    </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:700; color:#bc6c25;\"> k\342\202\202\302\267s</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25; vertical-align:sub;\">G</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25;\"> \342\211\244 s</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25; vertical-align:sub;\">Sxy</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25;\"> \342\211\244 k\342\202\203\302\267s</span><span style=\" font-size:9pt; font-weight:700; color:#bc6c25; vertical-align:sub;\">G</span><span style=\" font-size:9pt; color:#bc6c25;\">    </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#bc6c25;\">(s</span><span style=\" font-size:9pt; color:#bc6c25; vertical-align:sub;\">G</span><span style=\" font-size:9pt; color:#bc6c25;\""
                        ">: global standard deviation)<br />(k\342\202\202, k\342\202\203: constants)   </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#3c6e71;\">1. If both conditions are met, enhance the pixel intensity:        </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:700; color:#3c6e71;\">  g(x, y) = C\302\267f(x, y)</span><span style=\" font-size:9pt; color:#3c6e71;\">        </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#3c"
                        "6e71;\">(C: intensity)<br />(f(x, y): original pixel value)     </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; color:#3c6e71;\">2. If the conditions are not met, leave the pixel unchanged:        </span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:700; color:#3c6e71;\">  g(x, y) = f(x, y)</span><span style=\" font-size:9pt; color:#3c6e71;\"> </span><span style=\" font-size:9pt; color:#bc6c25;\">      </span><span style=\" font-size:9pt;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:700;\">Example Parameters:</span><span style=\" font-size:9pt;\"> k\342\202\200 = 0, k\342\202\201 = 0.1, k\342\202\202 = 0, k\342\202"
                        "\203 = 0.1, C = 22.8    </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
