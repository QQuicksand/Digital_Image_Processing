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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_8;
    QGraphicsView *graphic4;
    QLabel *label2_3;
    QPushButton *b1_3;
    QLabel *label3_4;
    QGraphicsView *graphic5;
    QLabel *label4_5;
    QGraphicsView *graphic2;
    QPushButton *Button1;
    QLabel *label4_6;
    QGraphicsView *graphic1;
    QGraphicsView *graphic3;
    QGraphicsView *graphic6;
    QLabel *label3_5;
    QLabel *label4_7;
    QWidget *page_9;
    QPushButton *b2_3;
    QPushButton *b2_4;
    QGraphicsView *graphic11;
    QGraphicsView *graphic10;
    QLabel *label_25;
    QLabel *label_32;
    QPushButton *Button3;
    QGraphicsView *graphic10_2;
    QPushButton *Button3_2;
    QWidget *page_10;
    QLabel *label_27;
    QPushButton *b3_2;
    QLabel *label_28;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_31;
    QGraphicsView *graphic8;
    QGraphicsView *graphic7;
    QPushButton *Button1_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1474, 839);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 1431, 771));
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
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        graphic4 = new QGraphicsView(page_8);
        graphic4->setObjectName("graphic4");
        graphic4->setGeometry(QRect(60, 440, 384, 258));
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
        graphic4->setPalette(palette1);
        graphic4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label2_3 = new QLabel(page_8);
        label2_3->setObjectName("label2_3");
        label2_3->setGeometry(QRect(60, 380, 384, 41));
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
        label2_3->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Code")});
        font1.setPointSize(12);
        label2_3->setFont(font1);
        label2_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label2_3->setFrameShape(QFrame::Shape::StyledPanel);
        label2_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        b1_3 = new QPushButton(page_8);
        b1_3->setObjectName("b1_3");
        b1_3->setGeometry(QRect(1270, 720, 131, 31));
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
        b1_3->setPalette(palette3);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Cascadia Code")});
        font2.setPointSize(12);
        font2.setWeight(QFont::Medium);
        b1_3->setFont(font2);
        b1_3->setAutoFillBackground(false);
        b1_3->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 173, 148);\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"alternate-background-color: rgb(116, 139, 117);\n"
"color: rgb(80, 61, 66);"));
        b1_3->setAutoRepeatDelay(100);
        b1_3->setAutoDefault(false);
        b1_3->setFlat(false);
        label3_4 = new QLabel(page_8);
        label3_4->setObjectName("label3_4");
        label3_4->setGeometry(QRect(520, 380, 384, 41));
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
        label3_4->setPalette(palette4);
        label3_4->setFont(font1);
        label3_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label3_4->setFrameShape(QFrame::Shape::StyledPanel);
        label3_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graphic5 = new QGraphicsView(page_8);
        graphic5->setObjectName("graphic5");
        graphic5->setGeometry(QRect(520, 440, 384, 258));
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
        graphic5->setPalette(palette5);
        graphic5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label4_5 = new QLabel(page_8);
        label4_5->setObjectName("label4_5");
        label4_5->setGeometry(QRect(520, 20, 384, 41));
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
        label4_5->setPalette(palette6);
        label4_5->setFont(font1);
        label4_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label4_5->setFrameShape(QFrame::Shape::StyledPanel);
        label4_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graphic2 = new QGraphicsView(page_8);
        graphic2->setObjectName("graphic2");
        graphic2->setGeometry(QRect(520, 80, 384, 258));
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
        graphic2->setPalette(palette7);
        graphic2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Button1 = new QPushButton(page_8);
        Button1->setObjectName("Button1");
        Button1->setGeometry(QRect(200, 720, 95, 30));
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
        Button1->setPalette(palette8);
        Button1->setFont(font1);
        Button1->setAutoDefault(true);
        label4_6 = new QLabel(page_8);
        label4_6->setObjectName("label4_6");
        label4_6->setGeometry(QRect(60, 20, 384, 41));
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
        label4_6->setPalette(palette9);
        label4_6->setFont(font1);
        label4_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label4_6->setFrameShape(QFrame::Shape::StyledPanel);
        label4_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graphic1 = new QGraphicsView(page_8);
        graphic1->setObjectName("graphic1");
        graphic1->setGeometry(QRect(60, 80, 384, 258));
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
        graphic1->setPalette(palette10);
        graphic1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphic3 = new QGraphicsView(page_8);
        graphic3->setObjectName("graphic3");
        graphic3->setGeometry(QRect(980, 80, 384, 258));
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
        graphic3->setPalette(palette11);
        graphic3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphic6 = new QGraphicsView(page_8);
        graphic6->setObjectName("graphic6");
        graphic6->setGeometry(QRect(980, 440, 384, 258));
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
        graphic6->setPalette(palette12);
        graphic6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label3_5 = new QLabel(page_8);
        label3_5->setObjectName("label3_5");
        label3_5->setGeometry(QRect(980, 380, 384, 41));
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
        label3_5->setPalette(palette13);
        label3_5->setFont(font1);
        label3_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label3_5->setFrameShape(QFrame::Shape::StyledPanel);
        label3_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label4_7 = new QLabel(page_8);
        label4_7->setObjectName("label4_7");
        label4_7->setGeometry(QRect(980, 20, 384, 41));
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
        label4_7->setPalette(palette14);
        label4_7->setFont(font1);
        label4_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label4_7->setFrameShape(QFrame::Shape::StyledPanel);
        label4_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        b2_3 = new QPushButton(page_9);
        b2_3->setObjectName("b2_3");
        b2_3->setGeometry(QRect(40, 720, 131, 31));
        b2_3->setFont(font2);
        b2_3->setAutoFillBackground(false);
        b2_3->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 173, 148);\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"alternate-background-color: rgb(116, 139, 117);\n"
"color: rgb(80, 61, 66);"));
        b2_3->setAutoRepeatDelay(100);
        b2_3->setAutoDefault(false);
        b2_3->setFlat(false);
        b2_4 = new QPushButton(page_9);
        b2_4->setObjectName("b2_4");
        b2_4->setGeometry(QRect(1270, 720, 131, 31));
        b2_4->setFont(font2);
        b2_4->setAutoFillBackground(false);
        b2_4->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 173, 148);\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"alternate-background-color: rgb(116, 139, 117);\n"
"color: rgb(80, 61, 66);"));
        b2_4->setAutoRepeatDelay(100);
        b2_4->setAutoDefault(false);
        b2_4->setFlat(false);
        graphic11 = new QGraphicsView(page_9);
        graphic11->setObjectName("graphic11");
        graphic11->setGeometry(QRect(720, 180, 576, 387));
        graphic11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphic10 = new QGraphicsView(page_9);
        graphic10->setObjectName("graphic10");
        graphic10->setGeometry(QRect(140, 110, 384, 258));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette15.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette15.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        graphic10->setPalette(palette15);
        graphic10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_25 = new QLabel(page_9);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(140, 50, 384, 41));
        label_25->setFont(font1);
        label_25->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_25->setFrameShape(QFrame::Shape::StyledPanel);
        label_25->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_32 = new QLabel(page_9);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(720, 120, 576, 41));
        label_32->setFont(font1);
        label_32->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_32->setFrameShape(QFrame::Shape::StyledPanel);
        label_32->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Button3 = new QPushButton(page_9);
        Button3->setObjectName("Button3");
        Button3->setGeometry(QRect(280, 660, 95, 30));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette16.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        Button3->setPalette(palette16);
        Button3->setFont(font1);
        Button3->setAutoDefault(true);
        graphic10_2 = new QGraphicsView(page_9);
        graphic10_2->setObjectName("graphic10_2");
        graphic10_2->setGeometry(QRect(140, 380, 384, 258));
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
        graphic10_2->setPalette(palette17);
        graphic10_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Button3_2 = new QPushButton(page_9);
        Button3_2->setObjectName("Button3_2");
        Button3_2->setGeometry(QRect(590, 330, 80, 80));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette18.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette18.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette18.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette18.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette18.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette18.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette18.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        Button3_2->setPalette(palette18);
        Button3_2->setFont(font1);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
        Button3_2->setIcon(icon);
        Button3_2->setAutoDefault(true);
        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        label_27 = new QLabel(page_10);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(660, 140, 567, 41));
        label_27->setFont(font1);
        label_27->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_27->setFrameShape(QFrame::Shape::StyledPanel);
        label_27->setAlignment(Qt::AlignmentFlag::AlignCenter);
        b3_2 = new QPushButton(page_10);
        b3_2->setObjectName("b3_2");
        b3_2->setGeometry(QRect(40, 720, 131, 31));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette19.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette19.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette19.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette19.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette19.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette19.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette19.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        b3_2->setPalette(palette19);
        b3_2->setFont(font2);
        b3_2->setAutoFillBackground(false);
        b3_2->setStyleSheet(QString::fromUtf8("background-color: rgb(146, 173, 148);\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"alternate-background-color: rgb(116, 139, 117);\n"
"color: rgb(80, 61, 66);"));
        b3_2->setAutoRepeatDelay(100);
        b3_2->setAutoDefault(false);
        b3_2->setFlat(false);
        label_28 = new QLabel(page_10);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(190, 600, 311, 21));
        label_28->setFont(font1);
        label_28->setAlignment(Qt::AlignmentFlag::AlignCenter);
        doubleSpinBox_8 = new QDoubleSpinBox(page_10);
        doubleSpinBox_8->setObjectName("doubleSpinBox_8");
        doubleSpinBox_8->setGeometry(QRect(280, 630, 110, 25));
        QPalette palette20;
        QBrush brush8(QColor(80, 61, 66, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette20.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette20.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette20.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette20.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush9(QColor(80, 61, 66, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette20.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette20.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette20.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette20.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette20.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        doubleSpinBox_8->setPalette(palette20);
        doubleSpinBox_8->setFont(font1);
        doubleSpinBox_8->setStyleSheet(QString::fromUtf8("\n"
"\n"
"selection-background-color: rgb(116, 139, 117);\n"
"selection-color: rgb(132, 195, 24);\n"
"border-left-color: rgb(116, 139, 117);\n"
"border-color: rgb(245, 251, 239);\n"
"\n"
""));
        doubleSpinBox_8->setDecimals(1);
        doubleSpinBox_8->setMinimum(50.000000000000000);
        doubleSpinBox_8->setMaximum(500.000000000000000);
        doubleSpinBox_8->setSingleStep(50.000000000000000);
        doubleSpinBox_8->setValue(50.000000000000000);
        label_31 = new QLabel(page_10);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(140, 160, 384, 41));
        label_31->setFont(font1);
        label_31->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_31->setFrameShape(QFrame::Shape::StyledPanel);
        label_31->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graphic8 = new QGraphicsView(page_10);
        graphic8->setObjectName("graphic8");
        graphic8->setGeometry(QRect(660, 220, 576, 387));
        graphic8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        graphic7 = new QGraphicsView(page_10);
        graphic7->setObjectName("graphic7");
        graphic7->setGeometry(QRect(140, 220, 384, 258));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette21.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette21.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette21.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette21.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette21.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette21.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette21.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette21.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette21.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        graphic7->setPalette(palette21);
        graphic7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Button1_3 = new QPushButton(page_10);
        Button1_3->setObjectName("Button1_3");
        Button1_3->setGeometry(QRect(290, 500, 95, 30));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette22.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette22.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette22.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette22.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette22.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette22.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette22.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette22.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette22.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette22.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette22.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette22.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette22.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        Button1_3->setPalette(palette22);
        Button1_3->setFont(font1);
        Button1_3->setAutoDefault(true);
        stackedWidget->addWidget(page_10);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1474, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        b1_3->setDefault(false);
        b2_3->setDefault(false);
        b2_4->setDefault(false);
        b3_2->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label2_3->setText(QCoreApplication::translate("MainWindow", "Wavy", nullptr));
        b1_3->setText(QCoreApplication::translate("MainWindow", "PAGE 1 >>", nullptr));
        label3_4->setText(QCoreApplication::translate("MainWindow", "Spiral", nullptr));
        label4_5->setText(QCoreApplication::translate("MainWindow", "Fisheye", nullptr));
        Button1->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        label4_6->setText(QCoreApplication::translate("MainWindow", "Original", nullptr));
        label3_5->setText(QCoreApplication::translate("MainWindow", "Ripple", nullptr));
        label4_7->setText(QCoreApplication::translate("MainWindow", "Kaleidoscope", nullptr));
        b2_3->setText(QCoreApplication::translate("MainWindow", "<< PAGE 2 ", nullptr));
        b2_4->setText(QCoreApplication::translate("MainWindow", " PAGE 2 >>", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Discrete Wavelet Transform", nullptr));
        Button3->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        Button3_2->setText(QCoreApplication::translate("MainWindow", "DWT", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Superpixels", nullptr));
        b3_2->setText(QCoreApplication::translate("MainWindow", "<< PAGE 3 ", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Number of Superpixels", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        Button1_3->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
