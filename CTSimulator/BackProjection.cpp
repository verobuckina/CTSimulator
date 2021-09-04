//
// Created by Veronica Buckina on 31.08.21.
//

#include "BackProjection.h"
#include "Kernels.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void BackProjection::backProjection(Mat sinogram, Mat reconstruction) {
    for(int x = 0; x < reconstruction.size().height; x++) {
        double delta_t=M_PI/180;
        for(int y = 0; y < reconstruction.size().width; y++) {
            reconstruction.at<float>(x, y) = 0.0;
            for(int theta = 0; theta < sinogram.size().width; theta+=1) {
                int s = (x - 0.5 * sinogram.size().height) * sin(theta * delta_t) + (y - 0.5 * sinogram.size().height) * cos(theta * delta_t) + 0.5 * sinogram.size().height;
                if (s > 0 && s < sinogram.size().height) {
                    reconstruction.at<float>(x,y) += sinogram.at<float>(s, theta);
                }
            }
            if(reconstruction.at<float>(x,y)<0)reconstruction.at<float>(x,y)=0;
        }
    }
    double min, max;
    minMaxLoc(reconstruction, &min, &max);
    reconstruction = reconstruction / max;
    rotate(reconstruction,reconstruction,ROTATE_90_CLOCKWISE);
}






