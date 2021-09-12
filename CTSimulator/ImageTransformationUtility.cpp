//
// Created by Veronica Buckina on 05.09.21.
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
    cv::Mat mat(image.height(), image.width(), CV_32FC1, const_cast<uchar*>(image.bits()), static_cast<size_t>(image.bytesPerLine()));
}

Mat ImageTransformationUtility::padMat(Mat &imgMat, int padHeight, int padWidth) {
    Mat paddedImage;
    int topBottom = (padHeight - imgMat.rows) / 2;
    int leftRight = (padWidth - imgMat.cols) / 2;

    copyMakeBorder(imgMat, paddedImage, topBottom, topBottom, leftRight, leftRight, BORDER_CONSTANT, 0);
    return paddedImage;
}

cv::Mat ImageTransformationUtility::cropMat(Mat &imgMat, int cropHeight, int cropWidth) {
    Mat croppedImage = Mat::zeros(cropHeight, cropWidth, CV_32FC1);

    int x = (imgMat.rows - cropHeight) / 2;
    int y = (imgMat.cols - cropWidth) / 2;

    for (int i = 0; i < croppedImage.rows; i++) {
        for (int j = 0; j < croppedImage.cols; j++) {
            croppedImage.at<float>(i, j) = imgMat.at<float>(i + x, j + y);
        }
    }

    return croppedImage;
}
