//
// Created by ikononenko on 25.04.17.
//

#ifndef PHW_BOT_CARDWATCH_H
#define PHW_BOT_CARDWATCH_H


#include <tiff.h>
#include <cstddef>
#include <opencv2/core/mat.hpp>

class ILayer {

protected:
    virtual void * forward(void * pVec1r32f = NULL) = 0;
    virtual void * backward(void * = NULL) = 0;
};

class LinearLayer : ILayer{
protected:
    cv::Mat1f * theta;
public:
    virtual void *forward(void *pVec1r32f = NULL);

    virtual void *backward(void *vec1r32f = NULL);

    LinearLayer(int32 size_i, int32 size_w);
};

class SigmoidLayer : ILayer {
public:
    virtual void *forward(void * = NULL);

    virtual void *backward(void * vec1r32f = NULL);
};

class CardWatch {

};


#endif //PHW_BOT_CARDWATCH_H
