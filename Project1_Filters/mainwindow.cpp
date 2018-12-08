#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //cv::Mat inputImage = cv::imread("/home/uburoxana/Documentos/Imagenes/JuanCarlos_guittierez/Project1_Filters/gru.jpg");
    ////cv::cvtColor(inputImage, inputImage, CV_BGR2RGB);
    /*if(!inputImage.empty())
        cv::imshow("Display Image", inputImage);*/
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//void on_btn_openImage_clicked();
//void on_btn_load_clicked();
//void on_btn_showHistogram_clicked();
void MainWindow::on_b_openPhoto_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(filename,QString())!=0){
        QImage image;
        bool valid = image.load(filename);
        if(valid){
            image = image.scaledToWidth(ui->l_photo->width(),Qt::SmoothTransformation);
            ui->l_photo->setPixmap(QPixmap::fromImage(image));
        }
    }
}
void MainWindow::printProperties(Mat* img){
    cout<<"size: "<<img->size()<<"\n channels: "<<img->channels()
       <<"\n type: "<<img->type()<<endl;

    if (img->depth() == CV_8U)
          cout << "CV_8U" << endl;
}

void MainWindow::on_b_opencv_clicked()
{
    name_image = "face_girl.jpg";
    String path = "/home/uburoxana/Documentos/Imagenes/JuanCarlos_guittierez/Project1_Filters/Images/";
    cv::Mat inputImage = imread(path+name_image,1);
    printProperties(&inputImage);
    cv::cvtColor(inputImage,inputImage,CV_BGR2RGB); //Qt reads in RGB whereas CV in BGR
    image = inputImage;

    if (!inputImage.empty()) {
        QImage imdisplay((uchar*)inputImage.data, inputImage.cols, inputImage.rows,inputImage.step, QImage::Format_RGB888);
        imdisplay = imdisplay.scaledToWidth(ui->l_photo->width(),Qt::SmoothTransformation);
        ui->l_photo->setPixmap(QPixmap::fromImage(imdisplay));
     }
     else{
        cout<<"Error! Cant open photo"<<endl;
     }
}
void print_histogram(cv::Mat mat)
{
    cout<<"size: "<<mat.size()<<endl;
    for(int i=0; i<mat.size().height; i++)
    {
        cout << "i: "<<i<<"->[";
        for(int j=0; j<mat.size().width; j++)
        {
            cout << mat.at<double>(i,j);
            if(j != mat.size().width-1)
                cout << ", ";
            else
                cout << "]" << endl;
        }
    }
}
cv::Mat MainWindow::histogramEcualization(cv::Mat* p_histogram, int total_pixels){
    int f[256];
    f[0]=0;
//    int acumulado = (*p_histogram)[0];
//    for(int i=1;i<254;i++){

//    }
}

cv::Mat MainWindow::calculateHistogram(cv::Mat* img){
    // Separate the image in 3 places ( B, G and R )
    vector<cv::Mat> bgr_planes;
    split(*(img), bgr_planes );
    // Establish the number of bins
    int histSize = 256;

     // Set the ranges ( for B,G,R) )
     float range[] = { 0, 256 } ;
     const float* histRange = { range };

     bool uniform = true; bool accumulate = false;

     cv::Mat b_hist, g_hist, r_hist;

     // Compute the histograms:
     cv::calcHist( &bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
     cv::calcHist( &bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
     cv::calcHist( &bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );

     // Draw the histograms for B, G and R
     int hist_w = 512; int hist_h = 400;
     int bin_w = cvRound((double) hist_w/histSize );

     cv::Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 255,255,255) );
     /// Normalize the result to [ 0, histImage.rows ]
     normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
     normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
     normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

     print_histogram(r_hist);
//          cout<<"hist 1: "<<r_hist.size()<<endl;
          /// Draw for each channel
          for( int i = 1; i < histSize; i++ )
          {
              line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                               Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                               Scalar( 255, 0, 0), 2, 8, 0  );
              line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                               Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                               Scalar( 0, 255, 0), 2, 8, 0  );
              line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                               Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                               Scalar( 0, 0, 255), 2, 8, 0  );
          }

          double res = r_hist.at<double>(244,0)+r_hist.at<double>(252,0);
          cout<<"size: "<<r_hist.size()<<", rrrr: "<<res<<endl;
          return histImage;

}

void MainWindow::on_b_histograma_clicked()
{
    cv::Mat histogram = calculateHistogram(&image);

    QImage imdisplay((uchar*)histogram.data, histogram.cols, histogram.rows, histogram.step, QImage::Format_RGB888);
    imdisplay = imdisplay.scaledToWidth(ui->l_histogram->width(),Qt::SmoothTransformation);
    ui->l_histogram->setPixmap(QPixmap::fromImage(imdisplay));

}



