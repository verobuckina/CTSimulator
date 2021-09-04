//
// Created by Veronica Buckina on 31.07.21.
//

#include "Kernels.h"
#include "math.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat Kernels::ramLakKernelSD(int kernelSize, float tau) {
    Mat kernel(1, kernelSize, CV_32FC1);
    int halfKernelSize = (int) kernelSize / 2;

    for(int n = -halfKernelSize; n < halfKernelSize; n++) {
        float kernelValue = 0.0;
        if (n == 0) {
            kernelValue = 1.0 / (4.0 * tau * tau);
        } else if ((n % 2) == 0) {
            kernelValue = 0;
        } else {
            kernelValue = - 1.0 / (M_PI * M_PI * n * n * tau * tau);
        }
        kernel.at<float>(0, n + halfKernelSize) = kernelValue;
    }
    return kernel;
}