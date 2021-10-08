//
// Created by Veronica Buckina on 31.08.21.
//

#ifndef CTSIMULATOR_BACKPROJECTION_H
#define CTSIMULATOR_BACKPROJECTION_H

#include <opencv2/opencv.hpp>

using namespace cv;


class BackProjection {
public:
    static void filterSinogram(Mat &sinogram, Mat &kernel, Mat &filteredSinogram);

    static void backProjection(Mat &sinogram, Mat &backProjection);

    static void backProjection(Mat &sinogram, Mat &backProjection, int numOfAngles);
};


#endif //CTSIMULATOR_BACKPROJECTION_H
