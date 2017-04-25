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

void *LinearLayer::forward(void *pVec1r32f) {
    cv::Mat1f * vec1r32f = (cv::Mat1f *)pVec1r32f;
    float * bays_data = (float *)vec1r32f->data;
    bays_data = bays_data - sizeof(float);
    bays_data[0]= 1.0;
    cv::Mat1f* staff = new cv::Mat1f(6,1,bays_data);
    staff->mul(*vec1r32f);
    cv::MatExpr * ex = new cv::MatExpr(staff->mul(*vec1r32f));
    return (void *)(ex);
}

void *LinearLayer::backward(void *) {
    return (void*) theta;
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

void *SigmoidLayer::forward(void *) {
    return NULL;
}

void *SigmoidLayer::backward(void *) {
    return NULL;
}