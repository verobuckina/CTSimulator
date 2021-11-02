//
// Created by Veronica Buckina on 31.08.21.
//

#define _USE_MATH_DEFINES
#include "BackProjection.h"
#include "ImageTransformationUtility.h"

using namespace cv;

void BackProjection::backProjection(Mat &sinogram, Mat &reconstruction) {
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

void BackProjection::backProjection(Mat &sinogram, Mat &reconstruction, int numOfAngles) {
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

void BackProjection::filterSinogram(Mat &sinogram, Mat &kernel, Mat &filteredSinogram) {
    Mat dftSinogram, dftKernel, dftFilteredSinogram;
    rotate(sinogram, sinogram, ROTATE_90_CLOCKWISE);
    dft(sinogram, dftSinogram, DFT_ROWS);

    dft(kernel, dftKernel);

    dftFilteredSinogram = dftSinogram.clone();

    for(int i = 0; i < dftSinogram.rows; i++) {
        mulSpectrums(dftKernel, dftSinogram.row(i), dftFilteredSinogram.row(i), DFT_ROWS);
    }

    dft(dftFilteredSinogram, filteredSinogram, DFT_INVERSE|DFT_ROWS);

    rotate(sinogram, sinogram, ROTATE_90_COUNTERCLOCKWISE);
    rotate(filteredSinogram, filteredSinogram, ROTATE_90_COUNTERCLOCKWISE);

    int pivot = ceil(filteredSinogram.rows / 2);
    for (int j = 0; j < filteredSinogram.cols; j++) {
        filteredSinogram.at<float>(pivot, j) = filteredSinogram.at<float>(0, j);
        for (int i = 0; i < pivot; i++) {
            filteredSinogram.at<float>(i, j) = filteredSinogram.at<float>(pivot + i + 1, j);
            filteredSinogram.at<float>(pivot + i + 1, j) = filteredSinogram.at<float>(i + 1, j);
        }
    }
}













