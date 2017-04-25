//
// Created by ikononenko on 11.04.17.
//
#include <cstdlib>
#include <cstdio>
#include <iostream>


#include "opencv2/highgui/highgui.hpp"
#include "CardWatch.h"

using namespace cv;
using namespace std;

Mat src, tmp;

IplImage* image = 0;
IplImage* gray = 0;
IplImage* bin = 0;
IplImage* dst = 0;
const char * win_name = "Pyramids image";

//source: http://robocraft.ru/blog/computervision/640.html
int main(int argc, char *argv[])
{
    printf("Starting phw-bot service...");
    LinearLayer l(5,5);
    uchar data[5] = {2,3,4,5,0};
    void * L2 = new cv::Mat1b(1,5,data);
    l.forward(L2);
//    cv::Mat1b * tmp = new cv::Mat1b(5,1);
//    l.forward((void *)tmp);
//    std::cout << l.forward((void *)tmp);
    /*image = cvLoadImage( "../../assets/tbs_1.png",1 ); // Loads the test image

    assert( image != 0 );

    // создаём одноканальные картинки
    gray = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
    bin = cvCreateImage( cvGetSize(image), IPL_DEPTH_8U, 1 );
    // клонируем
    dst = cvCloneImage(image);
    // окно для отображения картинки
    cvNamedWindow("original",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("binary",CV_WINDOW_AUTOSIZE);
    cvNamedWindow("contours",CV_WINDOW_AUTOSIZE);

    // преобразуем в градации серого
    cvCvtColor(image, gray, CV_RGB2GRAY);

    // преобразуем в двоичное
    cvInRangeS(gray, cvScalar(40), cvScalar(150), bin); // atoi(argv[2])

    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* contours=0;

    // находим контуры
    int contoursCont = cvFindContours( bin, storage,&contours,sizeof(CvContour),CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));

    // нарисуем контуры
    for(CvSeq* seq0 = contours;seq0!=0;seq0 = seq0->h_next){
        cvDrawContours(dst, seq0, CV_RGB(255,216,0), CV_RGB(0,0,250), 0, 1, 8); // рисуем контур
    }

    // показываем картинки
    cvShowImage("original",image);
    cvShowImage("binary", bin);
    cvShowImage("contours", dst);

    // ждём нажатия клавиши
    cvWaitKey(0);

    // освобождаем ресурсы
    cvReleaseImage(&image);
    cvReleaseImage(&gray);
    cvReleaseImage(&bin);
    cvReleaseImage(&dst);
    // удаляем окна
    cvDestroyAllWindows();*/
    return EXIT_SUCCESS;
}
