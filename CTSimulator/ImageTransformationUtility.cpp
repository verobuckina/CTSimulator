//
// Created by Veronica Buckina on 05.09.21.
//

#include "ImageTransformationUtility.h"

QImage ImageTransformationUtility::matToQImage(Mat &matrix) {
    Mat temp = matrix.clone();
    temp.convertTo(temp, CV_8UC1);
    QImage image(temp.data, temp.cols, temp.rows, static_cast<int>(temp.step),
                 QImage::Format_Grayscale8);
    return image;
}

void ImageTransformationUtility::padMat(Mat &src, Mat &dst, int padHeight, int padWidth) {
    int topBottom = (padHeight - src.rows) / 2;
    int leftRight = (padWidth - src.cols) / 2;

    copyMakeBorder(src, dst, topBottom, topBottom, leftRight, leftRight, BORDER_CONSTANT, 0);
}

void ImageTransformationUtility::cropMat(Mat &src, Mat &dst, int cropHeight, int cropWidth) {
    dst = Mat::zeros(cropHeight, cropWidth, CV_32FC1);

    int x = (src.rows - cropHeight) / 2;
    int y = (src.cols - cropWidth) / 2;

    for (int i = 0; i < dst.rows; i++) {
        for (int j = 0; j < dst.cols; j++) {
            dst.at<float>(i, j) = src.at<float>(i + x, j + y);
        }
    }
}
