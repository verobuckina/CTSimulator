//
// Created by Veronica Buckina on 31.07.21.
//

#ifndef CTSIMULATOR_KERNELS_H
#define CTSIMULATOR_KERNELS_H

#include <opencv2/opencv.hpp>

using namespace cv;

class Kernels {
public:
    static Mat ramLakKernelSD(int kernelSize, float tau);

    static Mat sinusKernel(int kernelSize);
};


#endif //CTSIMULATOR_KERNELS_H
