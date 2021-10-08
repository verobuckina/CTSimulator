//
// Created by Veronica Buckina on 26.08.21.
//

#include "ForwardProjection.h"

using namespace cv;

void ForwardProjection::forwardProjection(Mat &image, Mat &sinogram) {
    int numAngles = 181;

    double dtheta = 181.0 / numAngles;
    double theta0 = 0.0;

    int rows = image.rows;
    int cols = image.cols;

    for (int i = 0; i < numAngles; i++) {
        double theta = theta0 + i * dtheta;
        Mat rotatedImage;
        rotateImage(image, rotatedImage, theta);
        for (int j = 0; j < rows; j++) {
            double sum = 0.0;
            for (int k = cols - 1; k >= 0; k--) {
                sum += rotatedImage.at<float>(j, k);
            }
            sinogram.at<float>(j, i)= sum;
        }
    }
    sinogram /= cols;
}

void ForwardProjection::rotateImage(Mat &image, Mat &rotatedImage, double angle) {
    rotatedImage = Mat(image.rows, image.cols, CV_32FC1);
    Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
    Mat rotationMatrix = getRotationMatrix2D(center, angle=angle, 1.0);
    warpAffine(image, rotatedImage, rotationMatrix, image.size());
}