//
// Created by verobuckina on 31.08.21.
//

#ifndef CTSIMULATOR_BACKPROJECTION_H
#define CTSIMULATOR_BACKPROJECTION_H

#include <opencv2/opencv.hpp>

using namespace cv;


class BackProjection {
private:
    static Mat filterSinogram(Mat sinogram);
public:
    static void backProjection(Mat sinogram, Mat backProjection);
};


#endif //CTSIMULATOR_BACKPROJECTION_H
