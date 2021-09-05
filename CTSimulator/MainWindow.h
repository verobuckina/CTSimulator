//
// Created by verobuckina on 05.09.21.
//

#ifndef CTSIMULATOR_MAINACTIVITY_H
#define CTSIMULATOR_MAINACTIVITY_H

#include <QWidget>
#include<QLabel>
#include <opencv2/opencv.hpp>

class MainWindow : public QWidget {
Q_OBJECT
private:
    QLabel *phantomLabel;
    QImage *phantom;
    QLabel *sinogramLabel;
    QImage *sinogram;
    QLabel *fSinogramLabel;
    QImage *filteredSinogram;
    QLabel *reconstructedLabel;
    QImage *reconstructed;

public:
    explicit MainWindow(QWidget *parent = 0);

    void setPhantom(cv::Mat phantomMat);

    void setSinogram(cv::Mat sinogramMat);

    void setFilterdSinogram(cv::Mat filteredSinogramMat);

    void setReconstructed(cv::Mat reconstructedMat);
};

#endif //CTSIMULATOR_MAINACTIVITY_H
