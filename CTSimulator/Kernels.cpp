//
// Created by Veronica Buckina on 31.07.21.
//

#include "Kernels.h"
#include "math.h"

double* Kernels::ramLakKernelSD(int kernelSize, int tau) {
    double kernel[kernelSize - 1];
    int halfKernelSize = (int) kernelSize / 2;

    for(int n = -halfKernelSize; n <= halfKernelSize; n++) {
        double kernelValue = 0;
        if (n == 0) {
            kernelValue = 1.0 / (4.0 * tau * tau);
        } else if ((n % 2) == 0) {
            kernelValue = 0;
        } else {
            kernelValue = - 1.0 / (M_PI * M_PI * n * n * tau * tau);
        }
        kernel[n + halfKernelSize] = kernelValue;
    }

    return kernel;
}