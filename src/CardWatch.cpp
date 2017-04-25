//
// Created by ikononenko on 25.04.17.
//

#include <opencv2/core.hpp>
#include <iostream>
#include "CardWatch.h"

LinearLayer::LinearLayer(int32 size_i, int32 size_w) {
//    uchar * data;
//    theta = new cv::Mat(size_i+1, size_w,CV_32FC1);
    theta = new cv::Mat1f(size_i+1, size_w);
    cv::randn(*theta,  cv::Scalar(0), cv::Scalar(0.09));
    std::cout << std::endl << "M = " << *theta << std::endl;
}

void *LinearLayer::backward(void *pVoid) {
    return (void*) theta;
}

void *LinearLayer::forward(void *matx) {
    cv::Mat1b * vec = (cv::Mat1b*)matx ;
    cv::Mat1b bais(1,1);
//    vec->push_back(cv::Mat1b(1,1,CV_32FC1));
//    cv::Mat1b *result = new cv::Mat1b((*vec*(*theta)));
    return (void *)(new cv::Mat1b(bais + *vec));
}

//void *SigmoidLayer::forward(cv::Matx *matx) {
//    //todo
////    cv::Mat1b* vec = (cv::Mat1b*)pVoid;
////    cv::exp((vec->reshape(1,1)));
////    std:: cout << vec;
//    return NULL;
//}
//
//void *SigmoidLayer::backward(void *pVoid) {
//    return NULL;
//}
