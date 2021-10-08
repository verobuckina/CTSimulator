//
// Created by Veronica Buckina on 26.08.21.
//

#ifndef CTSIMULATOR_FORWARDPROJECTION_H
#define CTSIMULATOR_FORWARDPROJECTION_H


#include <cstdint>
#include <opencv2/opencv.hpp>

using namespace cv;

class ForwardProjection {
private:
    static void rotateImage(Mat &image, Mat &rotatedImage, double angle);

public:
    static void forwardProjection(Mat &image, Mat &sinogram);
};


#endif //CTSIMULATOR_FORWARDPROJECTION_H
