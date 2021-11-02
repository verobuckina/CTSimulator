//
// Created by Veronica Buckina on 05.09.21.
//

#ifndef CTSIMULATOR_IMAGETRANSFORMATIONUTILITY_H
#define CTSIMULATOR_IMAGETRANSFORMATIONUTILITY_H

#include <QImage>
#include <opencv2/opencv.hpp>

using namespace cv;

class ImageTransformationUtility {
public:
//    QImage static matToQImage(Mat &matrix);

    void static padMat(Mat &src, Mat &dst, int padHeight, int padWidth);

    void static cropMat(Mat &src, Mat &dst, int cropHeight, int cropWidth);
};


#endif //CTSIMULATOR_IMAGETRANSFORMATIONUTILITY_H
