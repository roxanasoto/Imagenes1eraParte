#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include<iostream>
#include <QFileDialog>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QKeyEvent>

//#include "dialogbi.h"
using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printProperties(cv::Mat*);
    cv::Mat histogramEcualization(cv::Mat*);
    cv::Mat calculateHistogram(cv::Mat*);
    cv::Mat filter1(cv::Mat*);
    void convolution(cv::Mat ,cv::Mat , cv::Mat );
    cv::Mat convolucion_clicked(Mat );
    inline QImage convertMatToQimage(Mat );
    cv::Mat bordeSovel(Mat);
    vector<Mat> transformationBilineal(Mat);
    void waveletFun(Mat );
    void setImgSrc(Mat);
    void setImgRpta1(Mat);
    void setImgRpta2(Mat);
    //void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    Ui::MainWindow *ui1;


    cv::Mat image;
    cv::Mat imageGray;
    cv::Mat image_clone;
    cv::String name_image;
    cv::Mat imageOriginal;

    //DialogBi *dialogBi;

    Mat img_rpta1;
    Mat img_rpta2;
    Mat img_src;



private slots:
    void on_b_openPhoto_clicked();
    void on_b_opencv_clicked();
    void on_b_histograma_clicked();
    //void on_btn_operation_clicked();


};

#endif // MAINWINDOW_H



