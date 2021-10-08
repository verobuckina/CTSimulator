//
// Created by Veronica Buckina on 05.09.21.
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

    void selectNumOfAngles();

private:
    int numOfAngles = 180;

    Mat phantom;
    Mat sinogram;
    Mat filteredSinogram;
    Mat reconstructed;

    QLabel *phantomLabel;
    QLabel *sinogramLabel;
    QLabel *fSinogramLabel;
    QLabel *reconstructedLabel;
    QPushButton *loadPhantomButton;
    QPushButton *forwardProjectionButton;
    QComboBox *filterComboBox;
    QPushButton *filterButton;
    QPushButton *backwardProjectionButton;
    QLabel *selectAngleTextLabel;
    QSlider *numOfAnglesSlider;

    static void showImage(Mat &imageMat, QLabel *imgLabel);
};

#endif //CTSIMULATOR_MAINACTIVITY_H
