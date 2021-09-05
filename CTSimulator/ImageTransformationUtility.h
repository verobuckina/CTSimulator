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

    Mat static padMat(Mat &phantom, int padWidth, int padHeight);

    Mat static cropMat(Mat &phantom, int cropWidth, int cropHeight);
};


#endif //CTSIMULATOR_IMAGETRANSFORMATIONUTILITY_H
