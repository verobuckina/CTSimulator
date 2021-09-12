//
// Created by Veronica Buckina on 05.09.21.
//

#include "MainWindow.h"
#include "ImageTransformationUtility.h"
#include "ForwardProjection.h"
#include "BackProjection.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QGridLayout *showLayout = new QGridLayout(this);

    loadPhantomButton = new QPushButton("Load Phantom", this);
    connect(loadPhantomButton, &QPushButton::clicked, this, &MainWindow::loadImage);

    QLabel *phantomDiscLabel = new QLabel("Phantom", this);
    phantomLabel = new QLabel("", this);

    phantomLabel->setPixmap(QPixmap::fromImage(phantomImg));

    forwardProjectionButton = new QPushButton("Forward Projection", this);
    connect(forwardProjectionButton, &QPushButton::clicked, this, &MainWindow::forwardProjection);

    QLabel *sinogramDiscLabel = new QLabel("Sinogram", this);
    sinogramLabel = new QLabel("", this);

    filterComboBox = new QComboBox;
    filterComboBox->addItem(tr("Not Selected"));
    filterComboBox->addItem(tr("Ram-Lak Filter"));

    filterButton = new QPushButton("Filter", this);
    connect(filterButton, &QPushButton::clicked, this, &MainWindow::filterSinogram);

    QLabel *fSinogramDiscLabel = new QLabel("Filtered Sinogram", this);
    fSinogramLabel = new QLabel("", this);

    backwardProjectionButton = new QPushButton("Backward Projection", this);
    connect(backwardProjectionButton, &QPushButton::clicked, this, &MainWindow::backProject);

    QLabel *reconstructedDiscLabel = new QLabel("Reconstructed", this);
    reconstructedLabel = new QLabel("", this);

    QLabel *selectTextLabel = new QLabel("Select Filter");

    showLayout->addWidget(phantomDiscLabel, 0, 0);
    showLayout->addWidget(sinogramDiscLabel, 0, 2);
    showLayout->addWidget(fSinogramDiscLabel, 0, 4);
    showLayout->addWidget(reconstructedDiscLabel, 0, 6);

    showLayout->addWidget(phantomLabel, 2, 0);
    showLayout->addWidget(sinogramLabel, 2, 2);
    showLayout->addWidget(fSinogramLabel, 2, 4);
    showLayout->addWidget(reconstructedLabel, 2, 6);

    showLayout->addWidget(selectTextLabel, 4, 4);

    showLayout->addWidget(loadPhantomButton, 6, 0);
    showLayout->addWidget(forwardProjectionButton, 6, 2);
    showLayout->addWidget(backwardProjectionButton, 6, 6);
    showLayout->addWidget(filterComboBox, 6, 4);

    showLayout->addWidget(filterButton, 7, 4);

    showLayout->setRowMinimumHeight(1, 10);
    showLayout->setRowMinimumHeight(3, 10);
    showLayout->setColumnMinimumWidth(1, 10);
    showLayout->setColumnMinimumWidth(3, 10);
    showLayout->setColumnMinimumWidth(5, 10);

    setDefaultImages();
}

void MainWindow::loadImage() {
    circle(phantom, Point(100, 100), 40, Scalar(255, 255, 255), FILLED, 8);
    circle(phantom, Point(100, 80), 10, Scalar(0, 0, 0), FILLED, 8);

    showImage(phantom, phantomImg, phantomLabel);
}

void MainWindow::forwardProjection() {
//    phantom = ImageTransformationUtility::padMat(phantom, 380, 380);

    ForwardProjection::forwardProjection(phantom, sinogram);

    // Crop

    showImage(sinogram, sinogramImg, sinogramLabel);
}

void MainWindow::filterSinogram() {
    QString selectedFilterName = filterComboBox->currentText();

    if (selectedFilterName == QString("Ram-Lak Filter")) {
        filteredSinogram = BackProjection::filterSinogram(sinogram);
    }

    showImage(filteredSinogram, filteredSinogramImg, fSinogramLabel);
}

void MainWindow::backProject() {
    BackProjection::backProjection(filteredSinogram, reconstructed);

    reconstructed = reconstructed / 16;
    showImage(reconstructed, reconstructedImg, reconstructedLabel);
}

void MainWindow::setDefaultImages() {
    phantom = Mat::zeros(255, 255, CV_32FC1);
    showImage(phantom, phantomImg, phantomLabel);

    sinogram = Mat::zeros(255, 181, CV_32FC1);
    showImage(sinogram, sinogramImg, sinogramLabel);

    filteredSinogram = Mat::zeros(255, 181, CV_32FC1);
    showImage(filteredSinogram, filteredSinogramImg, fSinogramLabel);

    reconstructed = Mat::zeros(255, 255, CV_32FC1);
    showImage(reconstructed, reconstructedImg, reconstructedLabel);
}

void MainWindow::showImage(Mat imageMat, QImage img, QLabel *imgLabel) {
    img = ImageTransformationUtility::matToQImage(imageMat);
    imgLabel->setPixmap(QPixmap::fromImage(img));
}