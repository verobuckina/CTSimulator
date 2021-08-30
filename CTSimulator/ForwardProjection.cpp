//
// Created by Veronica Buckina on 26.08.21.
//

#include "ForwardProjection.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void ForwardProjection::forwardProjection(Mat image, Mat projection) {
    int numAngles = 180;

    double dtheta = 180.0 / numAngles;
    double theta0 = 0.0;

    for (int i = 0; i < numAngles; i++) {
        double theta = theta0 + i * dtheta;
        // Rotate phantom
        Mat rotatedImage = Mat(image.rows, image.cols, CV_8U);
        rotateImage(image, rotatedImage, theta);
        for (int j = 0; j < image.rows; j++) {
            double sum = 0.0;
            for (int k = image.cols - 1; k >= 0; k--) {
                sum += rotatedImage.at<unsigned char>(j, k) / 255.0;
            }
            projection.at<unsigned char>(j, i)= sum;
        }
    }
}

void ForwardProjection::rotateImage(Mat image, Mat rotatedImage, double angle) {
    Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);

    Mat rotationMatrix = getRotationMatrix2D(center, angle=angle, 1.0);

    warpAffine(image, rotatedImage, rotationMatrix, image.size());
}