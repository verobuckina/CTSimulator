//
// Created by Veronica Buckina on 31.08.21.
//

#include "BackProjection.h"
#include "Kernels.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

void BackProjection::backProjection(Mat sinogram, Mat reconstruction) {
    for (int x = 0; x < reconstruction.size().height; x++) {
        double delta_t = M_PI / 180;
        for (int y = 0; y < reconstruction.size().width; y++) {
            reconstruction.at<float>(x, y) = 0.0;
            for (int theta = 0; theta < sinogram.size().width; theta += 1) {
                int s = (x - 0.5 * sinogram.size().height) * sin(theta * delta_t) +
                        (y - 0.5 * sinogram.size().height) * cos(theta * delta_t) + 0.5 * sinogram.size().height;
                if (s > 0 && s < sinogram.size().height) {
                    reconstruction.at<float>(x, y) += sinogram.at<float>(s, theta);
                }
            }
            if (reconstruction.at<float>(x, y) < 0)reconstruction.at<float>(x, y) = 0;
        }
    }
    rotate(reconstruction, reconstruction, ROTATE_90_CLOCKWISE);
}

void BackProjection::backProjection(Mat sinogram, Mat reconstruction, int numOfAngles) {
    int dtheta = 180/numOfAngles;
    for (int x = 0; x < reconstruction.size().height; x++) {
        double delta_t = M_PI / 180;
        for (int y = 0; y < reconstruction.size().width; y++) {
            reconstruction.at<float>(x, y) = 0.0;
            for (int theta = 0; theta < sinogram.size().width; theta += dtheta) {
                int s = (x - 0.5 * sinogram.size().height) * sin(theta * delta_t) +
                        (y - 0.5 * sinogram.size().height) * cos(theta * delta_t) + 0.5 * sinogram.size().height;
                if (s > 0 && s < sinogram.size().height) {
                    reconstruction.at<float>(x, y) += sinogram.at<float>(s, theta);
                }
            }
            if (reconstruction.at<float>(x, y) < 0)reconstruction.at<float>(x, y) = 0;
        }
    }
    rotate(reconstruction, reconstruction, ROTATE_90_CLOCKWISE);
}

Mat BackProjection::filterSinogram(Mat sinogram, Mat kernel) {
    Mat padded = Mat::zeros(sinogram.rows * 2 - 1, sinogram.cols, CV_32FC1);

    for (int proj = 0; proj < sinogram.rows; proj++) {
        for (int j = 0; j < sinogram.cols; j++) {
            padded.at<float>(proj + sinogram.rows / 2, j) = sinogram.at<float>(proj, j);
        }
    }


    Mat padded2 = padded.clone();

    for (int projection = 0; projection < sinogram.cols; projection++) {
        for (int i = 0; i < padded.rows; i++) {
            padded2.at<float>(i, projection) = 0;
            for (int j = 0; j < kernel.rows; ++j) {
                padded2.at<float>(i, projection) +=
                        padded.at<float>(i - j, projection) * kernel.at<float>(j, 0);
            }
        }
    }

    Mat filterSinogram(sinogram.rows, sinogram.cols, CV_32FC1);

    for (int proj = 0; proj < filterSinogram.rows; proj++) {
        for (int j = 0; j < filterSinogram.cols; j++) {
            filterSinogram.at<float>(proj, j) = padded2.at<float>(proj + sinogram.rows - 1, j);
        }
    }

    return filterSinogram;
}