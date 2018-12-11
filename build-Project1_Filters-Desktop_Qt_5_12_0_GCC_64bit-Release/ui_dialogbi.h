/********************************************************************************
** Form generated from reading UI file 'dialogbi.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBI_H
#define UI_DIALOGBI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogBi
{
public:
    QWidget *centralwidget;
    QPushButton *btn_operation;
    QLabel *lbl_img_raw;
    QLabel *lbl_img_rpta1;
    QLabel *lbl_img_rpta2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DialogBi)
    {
        if (DialogBi->objectName().isEmpty())
            DialogBi->setObjectName(QString::fromUtf8("DialogBi"));
        DialogBi->resize(956, 557);
        centralwidget = new QWidget(DialogBi);
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
        DialogBi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DialogBi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 956, 22));
        DialogBi->setMenuBar(menubar);
        statusbar = new QStatusBar(DialogBi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DialogBi->setStatusBar(statusbar);

        retranslateUi(DialogBi);

        QMetaObject::connectSlotsByName(DialogBi);
    } // setupUi

    void retranslateUi(QMainWindow *DialogBi)
    {
        DialogBi->setWindowTitle(QApplication::translate("DialogBi", "MainWindow", nullptr));
        btn_operation->setText(QApplication::translate("DialogBi", "Operation", nullptr));
        lbl_img_raw->setText(QString());
        lbl_img_rpta1->setText(QString());
        lbl_img_rpta2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogBi: public Ui_DialogBi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBI_H
