//
// Created by verobuckina on 05.09.21.
//

#include "MainWindow.h"
#include "ImageTransformationUtility.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QGridLayout *showLayout = new QGridLayout(this);

    QLabel *phantomDiscLabel = new QLabel("Phantom", this);
    phantomLabel = new QLabel("", this);

    QLabel *sinogramDiscLabel = new QLabel("Sinogram", this);
    sinogramLabel = new QLabel("", this);

    QLabel *fSinogramDiscLabel = new QLabel("Filtered Sinogram", this);
    fSinogramLabel = new QLabel("", this);

    QLabel *reconstructedDiscLabel = new QLabel("Reconstructed", this);
    reconstructedLabel = new QLabel("", this);

    loadPhantomButton = new QPushButton("Load Phantom", this);
    forwardProjectionButton = new QPushButton("Forward Projection", this);

    QLabel *selectTextLabel = new QLabel("Select Filter");

    filterComboBox = new QComboBox;
    filterComboBox->addItem(tr("Not Selected"));
    filterComboBox->addItem(tr("Ram-Lak Filter"));

    backwardProjectionButton = new QPushButton("Backward Projection", this);

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

    showLayout->setRowMinimumHeight(1, 10);
    showLayout->setRowMinimumHeight(3, 10);
    showLayout->setColumnMinimumWidth(1, 10);
    showLayout->setColumnMinimumWidth(3, 10);
    showLayout->setColumnMinimumWidth(5, 10);

}

void MainWindow::setPhantom(cv::Mat phantomMat) {
    phantom = ImageTransformationUtility::matToQImage(phantomMat);
    phantomLabel->setPixmap(QPixmap::fromImage(phantom));
}

void MainWindow::setSinogram(cv::Mat sinogramMat) {
//    sinogram = new QImage(sinogramMat.data, sinogramMat.cols, sinogramMat.rows, static_cast<int>(sinogramMat.step),
//                          QImage::Format_RGB30);
//    sinogram->convertTo(QImage::Format_Grayscale16);
    sinogram = ImageTransformationUtility::matToQImage(sinogramMat);
    sinogramLabel->setPixmap(QPixmap::fromImage(sinogram));
}

void MainWindow::setFilterdSinogram(cv::Mat filteredSinogramMat) {
    filteredSinogram = ImageTransformationUtility::matToQImage(filteredSinogramMat);
    fSinogramLabel->setPixmap(QPixmap::fromImage(filteredSinogram));
}

void MainWindow::setReconstructed(cv::Mat reconstructedMat) {
    reconstructedMat = reconstructedMat / 16;
    reconstructed = ImageTransformationUtility::matToQImage(reconstructedMat);
    reconstructedLabel->setPixmap(QPixmap::fromImage(reconstructed));
}