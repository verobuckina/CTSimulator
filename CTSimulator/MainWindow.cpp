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
#include <QStandardPaths>
#include <QMessageBox>
#include <QImageReader>

#include <thread>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
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

    QLabel *reconstructedDiscLabel = new QLabel("Reconstructed", this);
    reconstructedLabel = new QLabel("", this);
    reconstructedLabel->setMinimumSize(255, 255);
    reconstructedLabel->setStyleSheet("QLabel { background-color : black; }");

    QLabel *selectTextLabel = new QLabel("Select Filter");

    QLabel *copyRightLabel = new QLabel("(c) Veronica Buckina", this);
    copyRightLabel->setStyleSheet("QLabel { color : gray; }");

    angleLabel = new QLabel("", this);

    showLayout->addWidget(phantomDiscLabel, 0, 0);
    showLayout->addWidget(sinogramDiscLabel, 0, 2);
    showLayout->addWidget(fSinogramDiscLabel, 0, 4);
    showLayout->addWidget(reconstructedDiscLabel, 0, 6);

    showLayout->addWidget(phantomLabel, 2, 0);
    showLayout->addWidget(sinogramLabel, 2, 2);
    showLayout->addWidget(fSinogramLabel, 2, 4);
    showLayout->addWidget(reconstructedLabel, 2, 6);

    showLayout->addWidget(selectTextLabel, 4, 4);
    showLayout->addWidget(angleLabel, 4, 6);

    showLayout->addWidget(loadPhantomButton, 6, 0);
    showLayout->addWidget(forwardProjectionButton, 6, 2);
    showLayout->addWidget(backwardProjectionButton, 6, 6);
    showLayout->addWidget(filterComboBox, 6, 4);

    showLayout->addWidget(filterButton, 7, 4);
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
        phantom = ImageTransformationUtility::padMat(phantom, 255, 255);

        showImage(phantom, phantomImg, phantomLabel);
    } else {
        QMessageBox errorMessage;
        errorMessage.critical(0, "Wrong Image Size", "Image size of selected phantom exceeds 255 x 255 pixel.");
        errorMessage.setFixedSize(500, 200);
    }
}

void MainWindow::forwardProjection() {
    if (!phantom.empty()) {
        phantom = ImageTransformationUtility::padMat(phantom, 381, 381);
        sinogram = Mat(381, 181, CV_32FC1);

        ForwardProjection::forwardProjection(phantom, sinogram);

        Mat croppedSinogram = ImageTransformationUtility::cropMat(sinogram, 255, 181);

        croppedSinogram = croppedSinogram * 4;

        showImage(croppedSinogram, sinogramImg, sinogramLabel);
    }
}

void MainWindow::filterSinogram() {
    if (!sinogram.empty()) {
        filteredSinogram = Mat::zeros(381, 181, CV_32FC1);

        QString selectedFilterName = filterComboBox->currentText();

        if (selectedFilterName == QString("Not Selected")) {
            filteredSinogram = sinogram.clone();
        } else if (selectedFilterName == QString("Ram-Lak Filter")) {
            Mat kernel = Kernels::ramLakKernelSD(sinogram.size().height, 0.1);
            filteredSinogram = BackProjection::filterSinogram(sinogram, kernel);
        }

        Mat croppedFilterdSinogram = ImageTransformationUtility::cropMat(filteredSinogram, 255, 181);
        croppedFilterdSinogram = croppedFilterdSinogram * 4;
        showImage(croppedFilterdSinogram, filteredSinogramImg, fSinogramLabel);
    }
}

void MainWindow::backProject() {
    if (!filteredSinogram.empty()) {
        int numOfAngles[] = {1, 2, 4, 6, 10, 18, 36, 60, 90, 180};
        for (int i = 0; i < 10; i++) {
            reconstructed = Mat(381, 381, CV_32FC1);

            angleLabel->setText(QString("Number of angles: %1").arg(numOfAngles[i]));
            angleLabel->update();

            BackProjection::backProjection(filteredSinogram, reconstructed, numOfAngles[i]);

            Mat croppedReconstructed = ImageTransformationUtility::cropMat(reconstructed, 255, 255);

            if (i < 2) {
                croppedReconstructed = croppedReconstructed;
            } else if (i >= 2 && i < 4) {
                croppedReconstructed = croppedReconstructed / 2;
            } else if (i >= 4 && i < 6) {
                croppedReconstructed = croppedReconstructed / 4;
            } else if (i >= 6 && i < 7) {
                croppedReconstructed = croppedReconstructed / 8;
            } else {
                croppedReconstructed = croppedReconstructed / 16;
            }


            showImage(croppedReconstructed, reconstructedImg, reconstructedLabel);

            std::cout << numOfAngles[i] << std::endl;
            reconstructedLabel->repaint();
            std::this_thread::sleep_for(std::chrono::milliseconds(750));
        }
        angleLabel->setText("");
        angleLabel->update();
    }
}

void MainWindow::showImage(Mat imageMat, QImage img, QLabel *imgLabel) {
    img = ImageTransformationUtility::matToQImage(imageMat);
    imgLabel->setPixmap(QPixmap::fromImage(img));
}