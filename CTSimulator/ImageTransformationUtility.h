//
// Created by verobuckina on 05.09.21.
//

#ifndef CTSIMULATOR_IMAGETRANSFORMATIONUTILITY_H
#define CTSIMULATOR_IMAGETRANSFORMATIONUTILITY_H

#include <QImage>
#include <opencv2/opencv.hpp>

using namespace cv;

class ImageTransformationUtility {
public:
    QImage static matToQImage(cv::Mat &matrix);

    Mat static qImageToMat(QImage &image);

    Mat static padMat(Mat &imgMat, int padHeight, int padWidth);

    Mat static cropMat(Mat &imgMat, int cropHeight, int cropWidth);
};


#endif //CTSIMULATOR_IMAGETRANSFORMATIONUTILITY_H
