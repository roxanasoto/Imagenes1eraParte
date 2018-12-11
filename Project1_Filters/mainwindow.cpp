#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filters.h"
#include "wavelet.h"
//#include "dialogbi.h"
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
    imageOriginal =inputImage;
    cv::Mat imageGrayScale = imread(path+name_image, CV_LOAD_IMAGE_GRAYSCALE);
    imageGray = imageGrayScale;
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


cv::Mat MainWindow::filter1(cv::Mat* img){

}
void MainWindow::convolution(cv::Mat input,cv::Mat mask, cv::Mat output){
    int maskRowsRad = mask.rows /2;
    int  maskColsRad= mask.cols /2;
    Mat aux = Mat:: zeros(input.rows +2* maskRowsRad , input.cols +2* maskColsRad , CV_32FC1);
    Mat ROI = aux(Rect(maskColsRad ,maskRowsRad ,input.cols ,input.rows));
    input.copyTo(ROI);
    for (int r=maskRowsRad; r<aux.rows -maskRowsRad ; r++){
        for (int c=maskColsRad ; c<aux.cols -maskColsRad; c++){
            float  accum= 0.0;
            for(int  m_r =0; m_r <mask.rows; m_r ++){
                for(int  m_c =0; m_c <mask.cols; m_c ++){
                    accum += aux.at <float >(r+m_r -maskRowsRad ,c+m_c -maskColsRad)*mask.at <float >(m_r ,m_c);
                }
            }
            output.at<float >(r-maskRowsRad ,c-maskColsRad) = accum;
        }
    }
}


Mat MainWindow::convolucion_clicked(Mat image)
{

    /*Convolution*/
   /* cv::Mat  original;
    cv::cvtColor(image , original , CV_BGR2GRAY);
    cv::Mat  input;
    original.convertTo(input , CV_32FC1);
    float  maskval [9] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,  1.0};
    Mat mask = Mat(3, 3, CV_32FC1 , maskval)/9.0;
    cv::Mat  output = Mat::zeros(input.rows , input.cols , CV_32FC1);
    convolution(input , mask , output);
    output = abs(output);
    Mat  last;
    output.convertTo(last , CV_8UC1);*/

    //reloadImage();
    Mat src = image.clone();
    //cvtColor(src, src, CV_BGR2GRAY);

    Mat dst;
    Mat kernel;

    dst = src.clone();
    for(int y = 0; y < src.rows; y++)
        for(int x = 0; x < src.cols; x++)
            dst.at<uchar>(y,x) = 0;

    filters::convolute(src,dst,kernel);
    return dst;

    //namedWindow("final");
    // imshow("final", dst);


}

inline QImage MainWindow::convertMatToQimage(Mat input)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(input.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)input.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, input.cols, input.rows, input.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(input.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)input.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, input.cols, input.rows, input.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        cout << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

// Computes the x component of the gradient vector
// at a given point in a image.
// returns gradient in the x direction
int xGradient(Mat image, int x, int y)
{
    return image.at<uchar>(y-1, x-1) +
                2*image.at<uchar>(y, x-1) +
                 image.at<uchar>(y+1, x-1) -
                  image.at<uchar>(y-1, x+1) -
                   2*image.at<uchar>(y, x+1) -
                    image.at<uchar>(y+1, x+1);
}

// Computes the y component of the gradient vector
// at a given point in a image
// returns gradient in the y direction

int yGradient(Mat image, int x, int y)
{
    return image.at<uchar>(y-1, x-1) +
                2*image.at<uchar>(y-1, x) +
                 image.at<uchar>(y-1, x+1) -
                  image.at<uchar>(y+1, x-1) -
                   2*image.at<uchar>(y+1, x) -
                    image.at<uchar>(y+1, x+1);
}
Mat MainWindow::bordeSovel(Mat image)
{
    //reloadImage();
    Mat src = image.clone();
    cvtColor(src, src, CV_BGR2GRAY);

    Mat dst;
    Mat kernel;

    dst = src.clone();
    for(int y = 0; y < src.rows; y++)
        for(int x = 0; x < src.cols; x++)
            dst.at<uchar>(y,x) = 0;
    int gx, gy, sum;

    for(int y = 1; y < src.rows - 1; y++){
                for(int x = 1; x < src.cols - 1; x++){
                    gx = xGradient(src, x, y);
                    gy = yGradient(src, x, y);
                    sum = abs(gx) + abs(gy);
                    sum = sum > 255 ? 255:sum;
                    sum = sum < 0 ? 0 : sum;
                    dst.at<uchar>(y,x) = sum;
                }
    }
    return dst;
    namedWindow("final");
    imshow("final", dst);
}

vector<Point>v_polygon;
vector<Point>quadrilat;
void onmouse(int event, int x, int y, int flags, void* param)
{
    if(event==CV_EVENT_LBUTTONDOWN)
    {
        int n_pts = v_polygon.size();
        if(n_pts<=2){
            Mat &img = *((Mat*)(param)); // 1st cast it back, then deref
            Point2f p = Point2f(x,y);
            circle(img,p,4,Scalar(0,250,0),1);
            v_polygon.push_back(p);
            cout<<"clickeoa aqui: "<<x<<", "<<y<<" poligono: "<<v_polygon.size()<<endl;
        }
    }
}
void onmouse_quad(int event, int x, int y, int flags, void* param)
{
    if(event==CV_EVENT_LBUTTONDOWN)
    {
        int n_pts = quadrilat.size();
        if(n_pts<=4){
            Mat &img = *((Mat*)(param)); // 1st cast it back, then deref
            Point2f p = Point2f(x,y);
            circle(img,p,4,Scalar(0,0,0),1);
            quadrilat.push_back(p);
            cout<<"clickeoa aqui2222: "<<x<<", "<<y<<" quad: "<<quadrilat.size()<<endl;
        }
    }
}

void MainWindow::setImgSrc(Mat img_rpta){
    img_src = img_rpta;
    cv::cvtColor(img_src,img_src,CV_BGR2RGB);
    QImage imdisplay((uchar*)img_src.data, img_src.cols, img_src.rows,
                             img_src.step, QImage::Format_RGB888);
    ui->l_1->setPixmap(QPixmap::fromImage(imdisplay));
    ui->l_1->setScaledContents( true );

}
void MainWindow::setImgRpta1(Mat img_rpta){
    img_rpta1 = img_rpta;
    cv::cvtColor(img_rpta1,img_rpta1,CV_BGR2RGB);
    QImage imdisplay((uchar*)img_rpta1.data, img_rpta1.cols, img_rpta1.rows,
                             img_rpta1.step, QImage::Format_RGB888);
    ui->l_2->setPixmap(QPixmap::fromImage(imdisplay));
    ui->l_2->setScaledContents( true );

}
void MainWindow::setImgRpta2(Mat img_rpta){
    img_rpta2 = img_rpta;
    cv::cvtColor(img_rpta2,img_rpta2,CV_BGR2RGB);
    QImage imdisplay((uchar*)img_rpta2.data, img_rpta2.cols, img_rpta2.rows,
                             img_rpta2.step, QImage::Format_RGB888);
    ui->l_3->setPixmap(QPixmap::fromImage(imdisplay));
    ui->l_3->setScaledContents( true );
}
/*void MainWindow::on_btn_operation_clicked()
{

}*/
/*void MainWindow::keyPressEvent(QKeyEvent *event) // definition
{
}*/

vector<Mat> MainWindow::transformationBilineal(Mat image)
{
    vector<Mat> bilineal;
    // Display dashboard
    int k, size;
    int x1,y1,ancho,alto;
    Mat input_image, img_output,croppedImage;
    Mat img_board;
    Mat inv_img;
//    cvtColor(raw_image, raw_image, CV_BGR2GRAY);
//    raw_image = raw_image;
    Rect Rec;
    namedWindow("Draw rectangule with 2 points and enter");
    setMouseCallback("Draw rectangule with 2 points and enter", onmouse, &image);
    //reloadImage();
    while(1){
        imshow("Draw rectangule with 2 points and enter",image);
        size = v_polygon.size();
        if(size==2){
            x1 = (v_polygon[0].x < v_polygon[1].x)?v_polygon[0].x:v_polygon[1].x;
            y1 = (v_polygon[0].y < v_polygon[1].y)?v_polygon[0].y:v_polygon[1].y;

            ancho = abs(v_polygon[0].x-v_polygon[1].x);
            alto = abs(v_polygon[0].y-v_polygon[1].y);

            Rec =  Rect(x1, y1,ancho , alto);

            rectangle( image, Rec, Scalar( 0, 55, 255 ), +1, 4 );
            cout<<"Draw rectangule with 2 points and enter ";
            Mat ROI(image, Rec);

//            // Copy the data into new matrix
            ROI.copyTo(croppedImage);

        }
        k = waitKey(10);

        if (k== 27 || k==13)
            break;
    }
    size = v_polygon.size();
    if(size == 2 && k==13){
        cout<<"size of image: "<<image.size<<endl;
        Mat img_board(image.rows, image.cols, CV_8UC3, Scalar(255, 255, 255));
        cout<<"size of image cpy: "<<img_board.size<<endl;
        namedWindow("Draw 4 points");
        setMouseCallback("Draw 4 points", onmouse_quad, &img_board);
        while(1){
           imshow("Draw 4 points",img_board);
           k = waitKey(10);

           if (k== 27 || k==13)
               break;
        }
        if(k==13 && quadrilat.size()==4){

            for(int j=0;j<image.rows;j++){
                for (int i=0;i<image.cols;i++){
                    Vec3b pixel = image.at<Vec3b>(i,j);
                            int b, g, r;
                            b = pixel[0];
                            g = pixel[1];
                            r = pixel[2];
                    if(i==100&&j==100){
                         cout<<"leer pixeeeeel main windows...("<<b<<","<<g<<","<<r<<")"<<endl;
                         break;
                    }

                 }
             }

            float u=0, v=0;
//            static void bilinearTransform(Mat image,Mat* respt,Rect, vector <Point>,float*,float*);
            Mat inv_img(image.rows, image.cols, CV_8UC3, Scalar(255, 255, 255));
            filters::bilinearTransform(image,&img_board,&inv_img,Rec,quadrilat,&u, &v);

             cout << "transform222222: " << u<<","<<v<<endl;
            Point2f p = Point2f(u,v);
            circle(img_board,p,10,Scalar(0,0,0),1);
            imshow("Dibuje Cuadrilatero",img_board);

            bilineal.push_back(croppedImage);
            bilineal.push_back(img_board);
            bilineal.push_back(inv_img);

            //new MainWindow();
            //setImgSrc(croppedImage);
            //setImgRpta1(img_board);
            //setImgRpta2(inv_img);
            //show();


    //        printProperties(raw_image);
    //        printProperties(croppedImage);
        }

    }
    //return croppedImage;
    return bilineal;
    v_polygon.clear();
    quadrilat.clear();
}

void MainWindow::waveletFun(Mat image)
{
    images my;
    my.getim(image);
}
void MainWindow::on_b_histograma_clicked()
{
    /*Histogram*/
    cv::Mat histogram = calculateHistogram(&image);

    QImage imdisplay((uchar*)histogram.data, histogram.cols, histogram.rows, histogram.step, QImage::Format_RGB888);
    imdisplay = imdisplay.scaledToWidth(ui->l_histogram_rgb->width(),Qt::SmoothTransformation);
    ui->l_histogram_rgb->setPixmap(QPixmap::fromImage(imdisplay));
    int Sk[256];

    /**/
    vector<Mat> equalization = filters::equalizarHistograma(imageGray);
    cv::Mat imageGray = equalization[0];
    cv::Mat histogramGray = equalization[1];
    cv::Mat imagHistogramEqua = equalization[2];
    cv::Mat histogramEqua = equalization[3];

    /*ImageGray*/
    QImage imdisplay1((uchar*)imageGray.data, imageGray.cols, imageGray.rows, imageGray.step, QImage::Format_Grayscale8);
    imdisplay1 = imdisplay1.scaledToWidth(ui->l_gray->width(),Qt::SmoothTransformation);
    ui->l_gray->setPixmap(QPixmap::fromImage(imdisplay1));
    ui->subtitle2->setText("GRAY SCALE");

    /*Histogram*/
    QImage imdisplay2((uchar*)histogramGray.data, histogramGray.cols, histogramGray.rows, histogramGray.step, QImage::Format_Grayscale8);
    imdisplay2 = imdisplay2.scaledToWidth(ui->l_histogram_gray->width(),Qt::SmoothTransformation);
    ui->l_histogram_gray->setPixmap(QPixmap::fromImage(imdisplay2));
    ui->subtitle3->setText("HISTOGRAM GRAY SCALE");

    /*Image Equalization*/
    QImage imdisplay3((uchar*)imagHistogramEqua.data, imagHistogramEqua.cols, imagHistogramEqua.rows, imagHistogramEqua.step, QImage::Format_Grayscale8);
    imdisplay3 = imdisplay3.scaledToWidth(ui->l_equialization->width(),Qt::SmoothTransformation);
    ui->l_equialization->setPixmap(QPixmap::fromImage(imdisplay3));
    ui->subtitle4->setText("EQUALIZATION");

    /*Histogram Equialization*/
    QImage imdisplay4((uchar*)histogramEqua.data, histogramEqua.cols, histogramEqua.rows, histogramEqua.step, QImage::Format_Grayscale8);
    imdisplay4 = imdisplay4.scaledToWidth(ui->l_histogram_equa->width(),Qt::SmoothTransformation);
    ui->l_histogram_equa->setPixmap(QPixmap::fromImage(imdisplay4));
    ui->subtitle5->setText("HISTOGRAM EQUALIZATION");

    /*Convolution*/
    Mat conv = convolucion_clicked(imageOriginal);//Format_RGB32
    //namedWindow("CONVOLUTION");
    //imshow("convolution", conv);
    QImage convolution = convertMatToQimage(conv);
    //QImage imdisplay5((uchar*)conv.data, conv.cols, conv.rows, conv.step, QImage::Format_RGB444);//7,11,14
    //imdisplay5 = imdisplay5.scaledToWidth(ui->l_convolution->width(),Qt::SmoothTransformation);
    ui->l_convolution->setPixmap(QPixmap::fromImage(convolution));
    ui->subtitle6->setText("CONVOLUTION");

    /*BordeSovel*/
    Mat sovel = bordeSovel(imageOriginal);//Format_RGB32
    //namedWindow("CONVOLUTION");
    //imshow("convolution", conv);
    QImage bordSovel = convertMatToQimage(sovel);
    //QImage imdisplay5((uchar*)conv.data, conv.cols, conv.rows, conv.step, QImage::Format_RGB444);//7,11,14
    //imdisplay5 = imdisplay5.scaledToWidth(ui->l_convolution->width(),Qt::SmoothTransformation);
    ui->l_bordeSovel->setPixmap(QPixmap::fromImage(bordSovel));
    ui->subtitle7->setText("BORDE SOVEL");

    /*Transformacion Bilineal*/
    vector<Mat> bilineal = transformationBilineal(imageOriginal);
    Mat bilineal_original=bilineal[0];
    Mat bilineal_res1=bilineal[1];
    Mat bilineal_res2=bilineal[2];
    QImage qbilineal_ori = convertMatToQimage(bilineal_original);
    ui->l_1->setPixmap(QPixmap::fromImage(qbilineal_ori));
    ui->subtitle8->setText("ORIGINAL BILINEAL");
    ui->l_1->setScaledContents( true );
    QImage qbilineal_res1 = convertMatToQimage(bilineal_res1);
    ui->l_2->setPixmap(QPixmap::fromImage(qbilineal_res1));
    ui->subtitle9->setText(" BILINEAL 1");
    ui->l_2->setScaledContents( true );
    QImage qbilineal_res2 = convertMatToQimage(bilineal_res2);
    ui->l_3->setPixmap(QPixmap::fromImage(qbilineal_res2));
    ui->subtitle10->setText("BILINEAL 2");
    ui->l_3->setScaledContents( true );


    //waveletFun(image);

}
