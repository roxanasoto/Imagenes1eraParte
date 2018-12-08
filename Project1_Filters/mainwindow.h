#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include<iostream>
#include <QFileDialog>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
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
    cv::Mat histogramEcualization(cv::Mat*,int);
    cv::Mat calculateHistogram(cv::Mat*);

private:
    Ui::MainWindow *ui;
    cv::Mat image;
    cv::String name_image;

private slots:
    void on_b_openPhoto_clicked();
    void on_b_opencv_clicked();
    void on_b_histograma_clicked();
};

#endif // MAINWINDOW_H



