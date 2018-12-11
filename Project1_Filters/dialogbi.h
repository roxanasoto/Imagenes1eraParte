#ifndef DIALOGBI_H
#define DIALOGBI_H


#include <QMainWindow>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
//#include "constants.h"
//#include "processing.h"
 #include <QKeyEvent>
#include<vector>
#include<iostream>

using namespace cv;
using namespace std;

namespace Ui {
class DialogBi;
}

class DialogBi : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogBi(QWidget *parent = nullptr);
    ~DialogBi();
    void setImgSrc(Mat);
    void setImgRpta1(Mat);
    void setImgRpta2(Mat);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_btn_operation_clicked();

private:
    Ui::DialogBi *ui;
    Mat img_rpta1;
    Mat img_rpta2;
    Mat img_src;

};

#endif // DIALOGBI_H
