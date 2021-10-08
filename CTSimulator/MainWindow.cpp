//
// Created by Veronica Buckina on 05.09.21.
//

#include "MainWindow.h"
#include "ImageTransformationUtility.h"
#include "ForwardProjection.h"
#include "BackProjection.h"
#include "Kernels.h"

#include <QLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QImageReader>
#include <QSlider>

#include <thread>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    sinogram = Mat(381, 181, CV_32FC1);
    filteredSinogram = Mat(381, 181, CV_32FC1);
    reconstructed = Mat(381, 381, CV_32FC1);

    QGridLayout *showLayout = new QGridLayout(this);

    loadPhantomButton = new QPushButton("Load Phantom", this);
    connect(loadPhantomButton, &QPushButton::clicked, this, &MainWindow::loadImage);

    QLabel *phantomDiscLabel = new QLabel("Phantom", this);
    phantomLabel = new QLabel("", this);
    phantomLabel->setMinimumSize(255, 255);
    phantomLabel->setStyleSheet("QLabel { background-color : black; }");

    forwardProjectionButton = new QPushButton("Forward Projection", this);
    connect(forwardProjectionButton, &QPushButton::clicked, this, &MainWindow::forwardProjection);

    QLabel *sinogramDiscLabel = new QLabel("Sinogram", this);
    sinogramLabel = new QLabel("", this);
    sinogramLabel->setMinimumSize(181, 255);
    sinogramLabel->setStyleSheet("QLabel { background-color : black; }");

    filterComboBox = new QComboBox;
    filterComboBox->addItem(tr("Not Selected"));
    filterComboBox->addItem(tr("Ram-Lak Filter"));

    filterButton = new QPushButton("Filter", this);
    connect(filterButton, &QPushButton::clicked, this, &MainWindow::filterSinogram);

    QLabel *fSinogramDiscLabel = new QLabel("Filtered Sinogram", this);
    fSinogramLabel = new QLabel("", this);
    fSinogramLabel->setMinimumSize(181, 255);
    fSinogramLabel->setStyleSheet("QLabel { background-color : black; }");

    backwardProjectionButton = new QPushButton("Backward Projection", this);
    connect(backwardProjectionButton, &QPushButton::clicked, this, &MainWindow::backProject);

    numOfAnglesSlider = new QSlider(Qt::Horizontal,this);
    numOfAnglesSlider->setSingleStep(1);
    numOfAnglesSlider->setMaximum(180);
    numOfAnglesSlider->setMinimum(1);
    numOfAnglesSlider->setSliderPosition(180);
    connect(numOfAnglesSlider, &QSlider::valueChanged, this, &MainWindow::selectNumOfAngles);

    QLabel *reconstructedDiscLabel = new QLabel("Reconstructed", this);
    reconstructedLabel = new QLabel("", this);
    reconstructedLabel->setMinimumSize(255, 255);
    reconstructedLabel->setStyleSheet("QLabel { background-color : black; }");

    QLabel *selectTextLabel = new QLabel("Select Filter");
    selectAngleTextLabel = new QLabel("Select Number of Angles: 180");

    QLabel *copyRightLabel = new QLabel("(c) Veronica Buckina", this);
    copyRightLabel->setStyleSheet("QLabel { color : gray; }");

    showLayout->addWidget(phantomDiscLabel, 0, 0);
    showLayout->addWidget(sinogramDiscLabel, 0, 2);
    showLayout->addWidget(fSinogramDiscLabel, 0, 4);
    showLayout->addWidget(reconstructedDiscLabel, 0, 6);

    showLayout->addWidget(phantomLabel, 2, 0);
    showLayout->addWidget(sinogramLabel, 2, 2);
    showLayout->addWidget(fSinogramLabel, 2, 4);
    showLayout->addWidget(reconstructedLabel, 2, 6);

    showLayout->addWidget(selectTextLabel, 4, 4);
    showLayout->addWidget(selectAngleTextLabel, 4, 6);

    showLayout->addWidget(loadPhantomButton, 6, 0);
    showLayout->addWidget(forwardProjectionButton, 6, 2);
    showLayout->addWidget(filterComboBox, 6, 4);
    showLayout->addWidget(numOfAnglesSlider, 6, 6);

    showLayout->addWidget(filterButton, 7, 4);
    showLayout->addWidget(backwardProjectionButton, 7, 6);
    showLayout->addWidget(copyRightLabel, 8, 6);

    showLayout->setRowMinimumHeight(1, 10);
    showLayout->setRowMinimumHeight(3, 10);
    showLayout->setColumnMinimumWidth(1, 10);
    showLayout->setColumnMinimumWidth(3, 10);
    showLayout->setColumnMinimumWidth(5, 10);
}

void MainWindow::loadImage() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Image"), "/home/", tr("Image Files (*.jpg)"));

    phantom = cv::imread(fileName.toStdString(), IMREAD_ANYDEPTH);
    if (phantom.rows <= 255 || phantom.cols <= 255) {
        phantom.convertTo(phantom, CV_32FC1);
        ImageTransformationUtility::padMat(phantom, phantom, 255, 255);

        showImage(phantom, phantomLabel);

        ImageTransformationUtility::padMat(phantom, phantom, 381, 381);
    } else {
        QMessageBox errorMessage;
        QMessageBox::critical(0, "Wrong Image Size", "Image size of selected phantom exceeds 255 x 255 pixel.");
        errorMessage.setFixedSize(500, 200);
    }
}

void MainWindow::forwardProjection() {
    if (!phantom.empty()) {

        ForwardProjection::forwardProjection(phantom, sinogram);

        showImage(sinogram, sinogramLabel);
    }
}

void MainWindow::filterSinogram() {
    if (!sinogram.empty()) {
        QString selectedFilterName = filterComboBox->currentText();

        if (selectedFilterName == QString("Not Selected")) {
            filteredSinogram = sinogram.clone();
        } else if (selectedFilterName == QString("Ram-Lak Filter")) {
            Mat kernel = Kernels::ramLakKernelSD(sinogram.size().height, 0.1);
            BackProjection::filterSinogram(sinogram, kernel, filteredSinogram);
        }

        showImage(filteredSinogram, fSinogramLabel);
    }
}

void MainWindow::backProject() {
    if (!filteredSinogram.empty()) {
        BackProjection::backProjection(filteredSinogram, reconstructed, numOfAngles);

        Mat croppedReconstructed;

        ImageTransformationUtility::cropMat(reconstructed, croppedReconstructed, 255, 255);

        showImage(croppedReconstructed, reconstructedLabel);
    }
}

void MainWindow::showImage(Mat &imageMat, QLabel *imgLabel) {
    double min, max;

    Mat copyImgMat = imageMat.clone();

    cv::minMaxLoc(copyImgMat, &min, &max);

    copyImgMat = (copyImgMat - min) / (max - min) * 255;

    QImage img = ImageTransformationUtility::matToQImage(copyImgMat);
    imgLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::selectNumOfAngles() {
    numOfAngles = numOfAnglesSlider->sliderPosition();

    selectAngleTextLabel->setText(QString("Select Number of Angles: %1").arg(numOfAngles));
}
