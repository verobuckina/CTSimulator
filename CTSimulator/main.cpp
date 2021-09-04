#include "ForwardProjection.h"
#include "BackProjection.h"
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
    int dim = 250;

    Mat phantom = Mat::zeros(dim, dim, CV_32FC1);

    circle(phantom, Point(100, 100), 40, Scalar(255, 255, 255), FILLED, 8);

    circle(phantom, Point(100, 80), 10, Scalar(0, 0, 0), FILLED, 8);

    phantom *= 0.5;
    imshow("Phantom", phantom);
    waitKey(0);

    // Perform forward projection
    Mat sinogram(dim, 181, CV_32FC1);
    ForwardProjection::forwardProjection(phantom, sinogram);

    // Show sinogram
    Mat normalizedSino;
    double min, max;
    minMaxLoc(sinogram, &min, &max);
    normalizedSino = sinogram / max;
    imshow("Sinogram", normalizedSino);
    waitKey(0);

    Mat filteredSinogram = BackProjection::filterSinogram(sinogram);

    minMaxLoc(filteredSinogram, &min, &max);
    normalizedSino = filteredSinogram / max;
    imshow("Filtered Sinogram", normalizedSino);
    waitKey(0);

    // Perform backprojection
    Mat reconstruction = Mat::zeros(dim, dim, CV_32FC1);
    BackProjection::backProjection(filteredSinogram, reconstruction);
    imshow("Reconstructed", reconstruction);
    waitKey(0);

    return 0;
}
