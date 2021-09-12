//
// Created by verobuckina on 05.09.21.
//

#ifndef CTSIMULATOR_MAINACTIVITY_H
#define CTSIMULATOR_MAINACTIVITY_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <opencv2/opencv.hpp>

using namespace cv;

class MainWindow : public QWidget {
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private slots:

    void loadImage();

    void forwardProjection();

    void filterSinogram();

    void backProject();

private:
    Mat phantom;
    Mat sinogram;
    Mat filteredSinogram;
    Mat reconstructed;

    QLabel *phantomLabel;
    QImage phantomImg;
    QLabel *sinogramLabel;
    QImage sinogramImg;
    QLabel *fSinogramLabel;
    QImage filteredSinogramImg;
    QLabel *reconstructedLabel;
    QImage reconstructedImg;
    QPushButton *loadPhantomButton;
    QPushButton *forwardProjectionButton;
    QComboBox *filterComboBox;
    QPushButton *filterButton;
    QPushButton *backwardProjectionButton;

    void setDefaultImages();

    void showImage(Mat imageMat, QImage img, QLabel *imgLabel);
};

#endif //CTSIMULATOR_MAINACTIVITY_H
