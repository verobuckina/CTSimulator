#include "ForwardProjection.h"
#include "BackProjection.h"
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
    int dim = 250;

    float phantom[dim][dim];

    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            if((i >= 60 && i <= 120 && j >= 60 && j <= 120)) {
                phantom[i][j] = 1.0;
            } else {
                phantom[i][j] = 0.0;
            }
            if((i >= 80 && i <= 100 && j >= 80 && j <= 100)) {
                phantom[i][j] *= 0.5;
            }

            if((i >= 200 && i <= 220 && j >= 200 && j <= 220)) {
                phantom[i][j] = 1.0;
            }
        }
    }
    Mat p = Mat(dim, dim, CV_32FC1, &phantom);
    imshow("Phantom", p);
    waitKey(0);

    // Perform forward projection
    Mat sinogram(dim, 181, CV_32FC1);
    ForwardProjection::forwardProjection(p, sinogram);

    // Show sinogram
    imshow("Sinogram", sinogram);
    waitKey(0);

    // Perform backprojection
    Mat reconstruction = Mat::zeros(dim, dim, CV_32FC1);
    BackProjection::backProjection(sinogram, reconstruction);
    imshow("Reconstructed", reconstruction);
    waitKey(0);

    return 0;
}
