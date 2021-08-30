#include "ForwardProjection.h"
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
    int dim = 255;

    uint8_t phantom[255][255];

    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            if((i >= 20 && i <= 100 && j >= 20 && j <= 100)) {
                phantom[i][j] = 255;
            } else if (i >= 120 && i <= 200 && j >= 120 && j <= 200) {
                phantom[i][j] = 125;
            } else {
                phantom[i][j] = 0;
            }
        }
    }
    Mat p = Mat(dim, dim, CV_8U, &phantom);
    imshow("Phantom", p);
    waitKey(0);

    // Perform forward projection
    Mat s = Mat(dim, 180, CV_8U);
    ForwardProjection::forwardProjection(p, s);

    // Show sinogram
    imshow("Sinogram", s);
    waitKey(0);
    return 0;
}
