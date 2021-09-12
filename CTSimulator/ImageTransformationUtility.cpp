//
// Created by verobuckina on 05.09.21.
//

#include "ImageTransformationUtility.h"

QImage ImageTransformationUtility::matToQImage(cv::Mat &matrix) {
    Mat temp = matrix.clone();
    temp.convertTo(temp, CV_8UC1);
    QImage image(temp.data, temp.cols, temp.rows, static_cast<int>(temp.step),
                 QImage::Format_Grayscale8);
    return image;
}

Mat ImageTransformationUtility::qImageToMat(QImage &image) {
    return Mat();
}

Mat ImageTransformationUtility::padMat(Mat &imgMat, int padWidth, int padHeight) {
    Mat paddedImage;
    copyMakeBorder(imgMat, paddedImage, padHeight, padHeight, padWidth, padWidth, BORDER_CONSTANT, 0);
    return paddedImage;
}

cv::Mat ImageTransformationUtility::cropMat(Mat &imgMat, int cropWidth, int cropHeight) {
    return Mat();
}
