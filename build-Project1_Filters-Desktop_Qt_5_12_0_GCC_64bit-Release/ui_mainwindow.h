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
    QLabel *l_histogram;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1096, 741);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        b_openPhoto = new QPushButton(centralWidget);
        b_openPhoto->setObjectName(QString::fromUtf8("b_openPhoto"));
        b_openPhoto->setGeometry(QRect(160, 610, 89, 25));
        b_histograma = new QPushButton(centralWidget);
        b_histograma->setObjectName(QString::fromUtf8("b_histograma"));
        b_histograma->setGeometry(QRect(430, 610, 89, 25));
        b_opencv = new QPushButton(centralWidget);
        b_opencv->setObjectName(QString::fromUtf8("b_opencv"));
        b_opencv->setGeometry(QRect(660, 610, 89, 25));
        l_photo = new QLabel(centralWidget);
        l_photo->setObjectName(QString::fromUtf8("l_photo"));
        l_photo->setGeometry(QRect(60, 80, 461, 261));
        l_histogram = new QLabel(centralWidget);
        l_histogram->setObjectName(QString::fromUtf8("l_histogram"));
        l_histogram->setGeometry(QRect(610, 60, 361, 291));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1096, 22));
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
        b_openPhoto->setText(QApplication::translate("MainWindow", "Photo", nullptr));
        b_histograma->setText(QApplication::translate("MainWindow", "Histogram", nullptr));
        b_opencv->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        l_photo->setText(QString());
        l_histogram->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
