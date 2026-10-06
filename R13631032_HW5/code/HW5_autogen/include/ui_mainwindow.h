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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QGraphicsView *graph2;
    QLabel *label2_2;
    QPushButton *b1_2;
    QLabel *label3_2;
    QGraphicsView *graph4;
    QLabel *label4_2;
    QGraphicsView *graph3;
    QPushButton *button;
    QLabel *label4_3;
    QGraphicsView *graph1;
    QGraphicsView *graph5;
    QGraphicsView *graph6;
    QLabel *label3_3;
    QLabel *label4_4;
    QWidget *page_6;
    QPushButton *b2_1;
    QGraphicsView *graph2_2;
    QLabel *label_14;
    QPushButton *b2_2;
    QGraphicsView *graph2_3;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_29;
    QGraphicsView *graph2_1;
    QComboBox *comboBox;
    QGraphicsView *graphicsView11_2;
    QComboBox *comboBox_2;
    QGraphicsView *graphicsView22;
    QGraphicsView *graphicsView33;
    QComboBox *comboBox_3;
    QWidget *page_7;
    QGraphicsView *graph3_2;
    QLabel *label_23;
    QPushButton *b3_1;
    QLabel *label_26;
    QDoubleSpinBox *doubleSpinBox_7;
    QGraphicsView *graph3_1;
    QLabel *label_24;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1529, 866);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(30, 40, 1431, 771));
        QPalette palette;
        QBrush brush(QColor(136, 13, 30, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(146, 173, 148, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(116, 139, 117, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        QBrush brush3(QColor(132, 195, 24, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush4(QColor(136, 13, 30, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        stackedWidget->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code")});
        font.setPointSize(10);
        stackedWidget->setFont(font);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 173, 148);\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"alternate-background-color: rgb(116, 139, 117);\n"
"color: rgb(80, 61, 66);"));
        stackedWidget->setFrameShape(QFrame::Shape::StyledPanel);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        graph2 = new QGraphicsView(page_5);
        graph2->setObjectName("graph2");
        graph2->setGeometry(QRect(60, 440, 384, 258));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        graph2->setPalette(palette1);
        graph2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label2_2 = new QLabel(page_5);
        label2_2->setObjectName("label2_2");
        label2_2->setGeometry(QRect(60, 380, 384, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label2_2->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Code")});
        font1.setPointSize(12);
        label2_2->setFont(font1);
        label2_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label2_2->setFrameShape(QFrame::Shape::StyledPanel);
        label2_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        b1_2 = new QPushButton(page_5);
        b1_2->setObjectName("b1_2");
        b1_2->setGeometry(QRect(1270, 720, 131, 31));
        QPalette palette3;
        QBrush brush6(QColor(221, 45, 74, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(221, 45, 74, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        b1_2->setPalette(palette3);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cascadia Code")});
        font2.setPointSize(12);
        font2.setWeight(QFont::Medium);
        b1_2->setFont(font2);
        b1_2->setAutoFillBackground(false);
        b1_2->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 173, 148);\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"alternate-background-color: rgb(116, 139, 117);\n"
"color: rgb(80, 61, 66);"));
        b1_2->setAutoRepeatDelay(100);
        b1_2->setAutoDefault(false);
        b1_2->setFlat(false);
        label3_2 = new QLabel(page_5);
        label3_2->setObjectName("label3_2");
        label3_2->setGeometry(QRect(520, 380, 384, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette4.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label3_2->setPalette(palette4);
        label3_2->setFont(font1);
        label3_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label3_2->setFrameShape(QFrame::Shape::StyledPanel);
        label3_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graph4 = new QGraphicsView(page_5);
        graph4->setObjectName("graph4");
        graph4->setGeometry(QRect(520, 440, 384, 258));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette5.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        graph4->setPalette(palette5);
        graph4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label4_2 = new QLabel(page_5);
        label4_2->setObjectName("label4_2");
        label4_2->setGeometry(QRect(520, 20, 384, 41));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette6.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label4_2->setPalette(palette6);
        label4_2->setFont(font1);
        label4_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label4_2->setFrameShape(QFrame::Shape::StyledPanel);
        label4_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graph3 = new QGraphicsView(page_5);
        graph3->setObjectName("graph3");
        graph3->setGeometry(QRect(520, 80, 384, 258));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette7.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        graph3->setPalette(palette7);
        graph3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        button = new QPushButton(page_5);
        button->setObjectName("button");
        button->setGeometry(QRect(200, 720, 95, 30));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        button->setPalette(palette8);
        button->setFont(font1);
        button->setAutoDefault(true);
        label4_3 = new QLabel(page_5);
        label4_3->setObjectName("label4_3");
        label4_3->setGeometry(QRect(60, 20, 384, 41));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette9.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label4_3->setPalette(palette9);
        label4_3->setFont(font1);
        label4_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label4_3->setFrameShape(QFrame::Shape::StyledPanel);
        label4_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graph1 = new QGraphicsView(page_5);
        graph1->setObjectName("graph1");
        graph1->setGeometry(QRect(60, 80, 384, 258));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette10.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        graph1->setPalette(palette10);
        graph1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graph5 = new QGraphicsView(page_5);
        graph5->setObjectName("graph5");
        graph5->setGeometry(QRect(980, 80, 384, 258));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette11.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        graph5->setPalette(palette11);
        graph5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graph6 = new QGraphicsView(page_5);
        graph6->setObjectName("graph6");
        graph6->setGeometry(QRect(980, 440, 384, 258));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette12.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        graph6->setPalette(palette12);
        graph6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label3_3 = new QLabel(page_5);
        label3_3->setObjectName("label3_3");
        label3_3->setGeometry(QRect(980, 380, 384, 41));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette13.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label3_3->setPalette(palette13);
        label3_3->setFont(font1);
        label3_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label3_3->setFrameShape(QFrame::Shape::StyledPanel);
        label3_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label4_4 = new QLabel(page_5);
        label4_4->setObjectName("label4_4");
        label4_4->setGeometry(QRect(980, 20, 384, 41));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette14.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label4_4->setPalette(palette14);
        label4_4->setFont(font1);
        label4_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label4_4->setFrameShape(QFrame::Shape::StyledPanel);
        label4_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        b2_1 = new QPushButton(page_6);
        b2_1->setObjectName("b2_1");
        b2_1->setGeometry(QRect(40, 720, 131, 31));
        b2_1->setFont(font2);
        b2_1->setAutoFillBackground(false);
        b2_1->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 173, 148);\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"alternate-background-color: rgb(116, 139, 117);\n"
"color: rgb(80, 61, 66);"));
        b2_1->setAutoRepeatDelay(100);
        b2_1->setAutoDefault(false);
        b2_1->setFlat(false);
        graph2_2 = new QGraphicsView(page_6);
        graph2_2->setObjectName("graph2_2");
        graph2_2->setGeometry(QRect(520, 230, 384, 258));
        graph2_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_14 = new QLabel(page_6);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(520, 150, 384, 41));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_14->setFrameShape(QFrame::Shape::StyledPanel);
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);
        b2_2 = new QPushButton(page_6);
        b2_2->setObjectName("b2_2");
        b2_2->setGeometry(QRect(1270, 720, 131, 31));
        b2_2->setFont(font2);
        b2_2->setAutoFillBackground(false);
        b2_2->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 173, 148);\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"alternate-background-color: rgb(116, 139, 117);\n"
"color: rgb(80, 61, 66);"));
        b2_2->setAutoRepeatDelay(100);
        b2_2->setAutoDefault(false);
        b2_2->setFlat(false);
        graph2_3 = new QGraphicsView(page_6);
        graph2_3->setObjectName("graph2_3");
        graph2_3->setGeometry(QRect(980, 230, 384, 258));
        graph2_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_20 = new QLabel(page_6);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(980, 150, 384, 41));
        label_20->setFont(font1);
        label_20->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_20->setFrameShape(QFrame::Shape::StyledPanel);
        label_20->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_21 = new QLabel(page_6);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(290, 60, 800, 41));
        label_21->setFont(font1);
        label_21->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_21->setFrameShape(QFrame::Shape::StyledPanel);
        label_21->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_29 = new QLabel(page_6);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(60, 150, 384, 41));
        label_29->setFont(font1);
        label_29->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_29->setFrameShape(QFrame::Shape::StyledPanel);
        label_29->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graph2_1 = new QGraphicsView(page_6);
        graph2_1->setObjectName("graph2_1");
        graph2_1->setGeometry(QRect(60, 230, 384, 258));
        graph2_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(page_6);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(60, 540, 121, 31));
        graphicsView11_2 = new QGraphicsView(page_6);
        graphicsView11_2->setObjectName("graphicsView11_2");
        graphicsView11_2->setGeometry(QRect(190, 540, 251, 31));
        comboBox_2 = new QComboBox(page_6);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(520, 540, 121, 31));
        graphicsView22 = new QGraphicsView(page_6);
        graphicsView22->setObjectName("graphicsView22");
        graphicsView22->setGeometry(QRect(650, 540, 251, 31));
        graphicsView33 = new QGraphicsView(page_6);
        graphicsView33->setObjectName("graphicsView33");
        graphicsView33->setGeometry(QRect(1110, 540, 251, 31));
        comboBox_3 = new QComboBox(page_6);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(980, 540, 121, 31));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        graph3_2 = new QGraphicsView(page_7);
        graph3_2->setObjectName("graph3_2");
        graph3_2->setGeometry(QRect(510, 110, 768, 576));
        graph3_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_23 = new QLabel(page_7);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(510, 40, 761, 41));
        label_23->setFont(font1);
        label_23->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_23->setFrameShape(QFrame::Shape::StyledPanel);
        label_23->setAlignment(Qt::AlignmentFlag::AlignCenter);
        b3_1 = new QPushButton(page_7);
        b3_1->setObjectName("b3_1");
        b3_1->setGeometry(QRect(40, 720, 131, 31));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette15.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        b3_1->setPalette(palette15);
        b3_1->setFont(font2);
        b3_1->setAutoFillBackground(false);
        b3_1->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 173, 148);\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"alternate-background-color: rgb(116, 139, 117);\n"
"color: rgb(80, 61, 66);"));
        b3_1->setAutoRepeatDelay(100);
        b3_1->setAutoDefault(false);
        b3_1->setFlat(false);
        label_26 = new QLabel(page_7);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(120, 570, 100, 21));
        label_26->setFont(font1);
        label_26->setAlignment(Qt::AlignmentFlag::AlignCenter);
        doubleSpinBox_7 = new QDoubleSpinBox(page_7);
        doubleSpinBox_7->setObjectName("doubleSpinBox_7");
        doubleSpinBox_7->setGeometry(QRect(200, 610, 110, 25));
        QPalette palette16;
        QBrush brush8(QColor(80, 61, 66, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette16.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush9(QColor(80, 61, 66, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        doubleSpinBox_7->setPalette(palette16);
        doubleSpinBox_7->setFont(font1);
        doubleSpinBox_7->setStyleSheet(QString::fromUtf8("\n"
"\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"\n"
""));
        doubleSpinBox_7->setDecimals(1);
        doubleSpinBox_7->setMinimum(0.000000000000000);
        doubleSpinBox_7->setSingleStep(1.000000000000000);
        doubleSpinBox_7->setValue(2.000000000000000);
        graph3_1 = new QGraphicsView(page_7);
        graph3_1->setObjectName("graph3_1");
        graph3_1->setGeometry(QRect(60, 180, 384, 258));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette17.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette17.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette17.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        graph3_1->setPalette(palette17);
        graph3_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_24 = new QLabel(page_7);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(60, 110, 384, 41));
        label_24->setFont(font1);
        label_24->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_24->setFrameShape(QFrame::Shape::StyledPanel);
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);
        radioButton_6 = new QRadioButton(page_7);
        radioButton_6->setObjectName("radioButton_6");
        radioButton_6->setGeometry(QRect(100, 490, 71, 23));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Cascadia Code")});
        font3.setPointSize(11);
        radioButton_6->setFont(font3);
        radioButton_7 = new QRadioButton(page_7);
        radioButton_7->setObjectName("radioButton_7");
        radioButton_7->setGeometry(QRect(330, 490, 91, 23));
        radioButton_7->setFont(font3);
        radioButton_8 = new QRadioButton(page_7);
        radioButton_8->setObjectName("radioButton_8");
        radioButton_8->setGeometry(QRect(210, 490, 91, 23));
        radioButton_8->setFont(font3);
        stackedWidget->addWidget(page_7);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1529, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        b1_2->setDefault(false);
        b2_1->setDefault(false);
        b2_2->setDefault(false);
        b3_1->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label2_2->setText(QCoreApplication::translate("MainWindow", "CMY", nullptr));
        b1_2->setText(QCoreApplication::translate("MainWindow", "PAGE 1 >>", nullptr));
        label3_2->setText(QCoreApplication::translate("MainWindow", "XYZ", nullptr));
        label4_2->setText(QCoreApplication::translate("MainWindow", "HSI", nullptr));
        button->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        label4_3->setText(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        label3_3->setText(QCoreApplication::translate("MainWindow", "YUV", nullptr));
        label4_4->setText(QCoreApplication::translate("MainWindow", "L*a*b", nullptr));
        b2_1->setText(QCoreApplication::translate("MainWindow", "<< PAGE 2 ", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        b2_2->setText(QCoreApplication::translate("MainWindow", " PAGE 2 >>", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Pseudo Color", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        label_23->setText(QString());
        b3_1->setText(QCoreApplication::translate("MainWindow", "<< PAGE 3 ", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "K-means", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        radioButton_6->setText(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        radioButton_7->setText(QCoreApplication::translate("MainWindow", "HSI", nullptr));
        radioButton_8->setText(QCoreApplication::translate("MainWindow", "L*a*b", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
