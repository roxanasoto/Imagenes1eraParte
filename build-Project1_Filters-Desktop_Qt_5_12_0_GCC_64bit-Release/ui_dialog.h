/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *centralwidget;
    QPushButton *btn_operation;
    QLabel *lbl_img_raw;
    QLabel *lbl_img_rpta1;
    QLabel *lbl_img_rpta2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(956, 557);
        centralwidget = new QWidget(Dialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_operation = new QPushButton(centralwidget);
        btn_operation->setObjectName(QString::fromUtf8("btn_operation"));
        btn_operation->setGeometry(QRect(780, 20, 114, 32));
        lbl_img_raw = new QLabel(centralwidget);
        lbl_img_raw->setObjectName(QString::fromUtf8("lbl_img_raw"));
        lbl_img_raw->setGeometry(QRect(70, 20, 361, 191));
        lbl_img_rpta1 = new QLabel(centralwidget);
        lbl_img_rpta1->setObjectName(QString::fromUtf8("lbl_img_rpta1"));
        lbl_img_rpta1->setGeometry(QRect(60, 240, 401, 241));
        lbl_img_rpta2 = new QLabel(centralwidget);
        lbl_img_rpta2->setObjectName(QString::fromUtf8("lbl_img_rpta2"));
        lbl_img_rpta2->setGeometry(QRect(500, 240, 401, 241));
        Dialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 956, 22));
        Dialog->setMenuBar(menubar);
        statusbar = new QStatusBar(Dialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Dialog->setStatusBar(statusbar);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QMainWindow *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "MainWindow", nullptr));
        btn_operation->setText(QApplication::translate("Dialog", "Operation", nullptr));
        lbl_img_raw->setText(QString());
        lbl_img_rpta1->setText(QString());
        lbl_img_rpta2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
