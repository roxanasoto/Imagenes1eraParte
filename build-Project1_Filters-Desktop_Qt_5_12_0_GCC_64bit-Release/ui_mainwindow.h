/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *b_openPhoto;
    QPushButton *b_histograma;
    QPushButton *b_opencv;
    QLabel *l_photo;
    QLabel *subtitle2;
    QLabel *l_histogram_rgb;
    QLabel *label_4;
    QPushButton *btnLoadVideo;
    QLabel *subtitle1;
    QLabel *subtitle6;
    QLabel *l_convolution;
    QLabel *l_bordeSovel;
    QLabel *label_3;
    QLabel *l_gray;
    QLabel *subtitle7;
    QPushButton *btnInitProc;
    QLabel *l_histogram_gray;
    QLabel *subtitle3;
    QLabel *l_1;
    QLabel *subtitle8;
    QLabel *l_equialization;
    QLabel *subtitle4;
    QLabel *l_2;
    QLabel *subtitle9;
    QLabel *l_histogram_equa;
    QLabel *subtitle5;
    QLabel *l_3;
    QLabel *subtitle10;
    QLabel *label_5;
    QLabel *l_video;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1432, 959);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        b_openPhoto = new QPushButton(centralWidget);
        b_openPhoto->setObjectName(QString::fromUtf8("b_openPhoto"));
        b_openPhoto->setEnabled(false);
        b_openPhoto->setGeometry(QRect(230, 100, 89, 25));
        b_histograma = new QPushButton(centralWidget);
        b_histograma->setObjectName(QString::fromUtf8("b_histograma"));
        b_histograma->setEnabled(true);
        b_histograma->setGeometry(QRect(120, 100, 89, 25));
        b_opencv = new QPushButton(centralWidget);
        b_opencv->setObjectName(QString::fromUtf8("b_opencv"));
        b_opencv->setGeometry(QRect(20, 100, 89, 25));
        l_photo = new QLabel(centralWidget);
        l_photo->setObjectName(QString::fromUtf8("l_photo"));
        l_photo->setGeometry(QRect(40, 160, 421, 231));
        subtitle2 = new QLabel(centralWidget);
        subtitle2->setObjectName(QString::fromUtf8("subtitle2"));
        subtitle2->setGeometry(QRect(270, 450, 211, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        subtitle2->setFont(font);
        subtitle2->setAlignment(Qt::AlignCenter);
        l_histogram_rgb = new QLabel(centralWidget);
        l_histogram_rgb->setObjectName(QString::fromUtf8("l_histogram_rgb"));
        l_histogram_rgb->setGeometry(QRect(40, 470, 221, 191));
        l_histogram_rgb->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_histogram_rgb->setScaledContents(true);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 30, 491, 31));
        label_4->setBaseSize(QSize(5, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Loma"));
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        btnLoadVideo = new QPushButton(centralWidget);
        btnLoadVideo->setObjectName(QString::fromUtf8("btnLoadVideo"));
        btnLoadVideo->setEnabled(false);
        btnLoadVideo->setGeometry(QRect(720, 100, 91, 21));
        subtitle1 = new QLabel(centralWidget);
        subtitle1->setObjectName(QString::fromUtf8("subtitle1"));
        subtitle1->setGeometry(QRect(40, 450, 221, 16));
        subtitle1->setFont(font);
        subtitle1->setAlignment(Qt::AlignCenter);
        subtitle6 = new QLabel(centralWidget);
        subtitle6->setObjectName(QString::fromUtf8("subtitle6"));
        subtitle6->setGeometry(QRect(40, 670, 231, 16));
        subtitle6->setFont(font);
        subtitle6->setAlignment(Qt::AlignCenter);
        l_convolution = new QLabel(centralWidget);
        l_convolution->setObjectName(QString::fromUtf8("l_convolution"));
        l_convolution->setGeometry(QRect(30, 690, 231, 191));
        l_convolution->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_convolution->setScaledContents(true);
        l_bordeSovel = new QLabel(centralWidget);
        l_bordeSovel->setObjectName(QString::fromUtf8("l_bordeSovel"));
        l_bordeSovel->setGeometry(QRect(270, 690, 221, 191));
        l_bordeSovel->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_bordeSovel->setScaledContents(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 10, 211, 20));
        label_3->setBaseSize(QSize(5, 0));
        label_3->setFont(font1);
        l_gray = new QLabel(centralWidget);
        l_gray->setObjectName(QString::fromUtf8("l_gray"));
        l_gray->setGeometry(QRect(270, 470, 211, 191));
        l_gray->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_gray->setScaledContents(true);
        subtitle7 = new QLabel(centralWidget);
        subtitle7->setObjectName(QString::fromUtf8("subtitle7"));
        subtitle7->setGeometry(QRect(280, 670, 201, 16));
        subtitle7->setFont(font);
        subtitle7->setAlignment(Qt::AlignCenter);
        btnInitProc = new QPushButton(centralWidget);
        btnInitProc->setObjectName(QString::fromUtf8("btnInitProc"));
        btnInitProc->setEnabled(false);
        btnInitProc->setGeometry(QRect(840, 100, 91, 21));
        l_histogram_gray = new QLabel(centralWidget);
        l_histogram_gray->setObjectName(QString::fromUtf8("l_histogram_gray"));
        l_histogram_gray->setGeometry(QRect(500, 470, 211, 191));
        l_histogram_gray->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_histogram_gray->setScaledContents(true);
        subtitle3 = new QLabel(centralWidget);
        subtitle3->setObjectName(QString::fromUtf8("subtitle3"));
        subtitle3->setGeometry(QRect(500, 450, 221, 16));
        subtitle3->setFont(font);
        subtitle3->setAlignment(Qt::AlignCenter);
        l_1 = new QLabel(centralWidget);
        l_1->setObjectName(QString::fromUtf8("l_1"));
        l_1->setGeometry(QRect(500, 690, 221, 191));
        l_1->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_1->setScaledContents(true);
        subtitle8 = new QLabel(centralWidget);
        subtitle8->setObjectName(QString::fromUtf8("subtitle8"));
        subtitle8->setGeometry(QRect(510, 670, 201, 16));
        subtitle8->setFont(font);
        subtitle8->setAlignment(Qt::AlignCenter);
        l_equialization = new QLabel(centralWidget);
        l_equialization->setObjectName(QString::fromUtf8("l_equialization"));
        l_equialization->setGeometry(QRect(720, 470, 221, 191));
        l_equialization->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_equialization->setScaledContents(true);
        subtitle4 = new QLabel(centralWidget);
        subtitle4->setObjectName(QString::fromUtf8("subtitle4"));
        subtitle4->setGeometry(QRect(730, 450, 201, 16));
        subtitle4->setFont(font);
        subtitle4->setAlignment(Qt::AlignCenter);
        l_2 = new QLabel(centralWidget);
        l_2->setObjectName(QString::fromUtf8("l_2"));
        l_2->setGeometry(QRect(730, 690, 221, 191));
        l_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_2->setScaledContents(true);
        subtitle9 = new QLabel(centralWidget);
        subtitle9->setObjectName(QString::fromUtf8("subtitle9"));
        subtitle9->setGeometry(QRect(740, 670, 201, 16));
        subtitle9->setFont(font);
        subtitle9->setAlignment(Qt::AlignCenter);
        l_histogram_equa = new QLabel(centralWidget);
        l_histogram_equa->setObjectName(QString::fromUtf8("l_histogram_equa"));
        l_histogram_equa->setGeometry(QRect(960, 470, 221, 191));
        l_histogram_equa->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_histogram_equa->setScaledContents(true);
        subtitle5 = new QLabel(centralWidget);
        subtitle5->setObjectName(QString::fromUtf8("subtitle5"));
        subtitle5->setGeometry(QRect(970, 450, 201, 16));
        subtitle5->setFont(font);
        subtitle5->setAlignment(Qt::AlignCenter);
        l_3 = new QLabel(centralWidget);
        l_3->setObjectName(QString::fromUtf8("l_3"));
        l_3->setGeometry(QRect(960, 690, 221, 191));
        l_3->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        l_3->setScaledContents(true);
        subtitle10 = new QLabel(centralWidget);
        subtitle10->setObjectName(QString::fromUtf8("subtitle10"));
        subtitle10->setGeometry(QRect(970, 670, 201, 16));
        subtitle10->setFont(font);
        subtitle10->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 60, 211, 20));
        label_5->setBaseSize(QSize(5, 0));
        label_5->setFont(font1);
        l_video = new QLabel(centralWidget);
        l_video->setObjectName(QString::fromUtf8("l_video"));
        l_video->setGeometry(QRect(690, 150, 501, 271));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1432, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        b_openPhoto->setText(QApplication::translate("MainWindow", "Load Photo", nullptr));
        b_histograma->setText(QApplication::translate("MainWindow", "Run Project", nullptr));
        b_opencv->setText(QApplication::translate("MainWindow", "Load Photo", nullptr));
        l_photo->setText(QString());
        subtitle2->setText(QString());
        l_histogram_rgb->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "COMPUTER SCIENCIE UNIVERSITY CATOLICA SAN PABLO", nullptr));
        btnLoadVideo->setText(QApplication::translate("MainWindow", "Load Video", nullptr));
        subtitle1->setText(QString());
        subtitle6->setText(QString());
        l_convolution->setText(QString());
        l_bordeSovel->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "PHOTOSHOP", nullptr));
        l_gray->setText(QString());
        subtitle7->setText(QString());
        btnInitProc->setText(QApplication::translate("MainWindow", "Run Project", nullptr));
        l_histogram_gray->setText(QString());
        subtitle3->setText(QString());
        l_1->setText(QString());
        subtitle8->setText(QString());
        l_equialization->setText(QString());
        subtitle4->setText(QString());
        l_2->setText(QString());
        subtitle9->setText(QString());
        l_histogram_equa->setText(QString());
        subtitle5->setText(QString());
        l_3->setText(QString());
        subtitle10->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "ROXANA SOTO BARRERA", nullptr));
        l_video->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
