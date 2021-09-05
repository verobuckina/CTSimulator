//
// Created by verobuckina on 05.09.21.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    int imageWidth = 255;
    int imageHeight = 255;
    int sinogramWidth = 180;
    int sinogramHeight = imageHeight;

    setFixedSize(1000, 500);

    phantomLabel = new QLabel("", this);
//    phantomLabel->setStyleSheet("QLabel { background-color : red; }");
    phantomLabel->setGeometry(10, 10, imageWidth, imageHeight);

    sinogramLabel = new QLabel("Sinogram", this);
//    sinogramLabel->setStyleSheet("QLabel { background-color : red; }");
    sinogramLabel->setGeometry(10 * 2 + imageWidth, 10, sinogramWidth, sinogramHeight);

    fSinogramLabel = new QLabel("Filtered Sinogram", this);
    fSinogramLabel->setStyleSheet("QLabel { background-color : red; }");
    fSinogramLabel->setGeometry(10 * 3 + imageWidth + sinogramWidth, 10, sinogramWidth, sinogramHeight);

    reconstructedLabel = new QLabel("Reconstructed", this);
    reconstructedLabel->setStyleSheet("QLabel { background-color : red; }");
    reconstructedLabel->setGeometry(10 * 4 + imageWidth + 2 * sinogramWidth, 10, imageWidth, imageHeight);
}

void MainWindow::setPhantom(cv::Mat phantomMat) {
    phantom = new QImage(phantomMat.data, phantomMat.cols, phantomMat.rows, static_cast<float>(phantomMat.step),
                         QImage::Format_RGB888);
    phantomLabel->setPixmap(QPixmap::fromImage(*phantom));
}

void MainWindow::setSinogram(cv::Mat sinogramMat) {
    sinogram = new QImage(sinogramMat.data, sinogramMat.cols, sinogramMat.rows, static_cast<float>(sinogramMat.step),
                          QImage::Format_RGB888);
    sinogramLabel->setPixmap(QPixmap::fromImage(*sinogram));
}

void MainWindow::setFilterdSinogram(cv::Mat filteredSinogramMat) {
    filteredSinogram = new QImage(filteredSinogramMat.data, filteredSinogramMat.cols, filteredSinogramMat.rows,
                                  static_cast<float>(filteredSinogramMat.step),
                                  QImage::Format_RGB888);
    fSinogramLabel->setPixmap(QPixmap::fromImage(*filteredSinogram));
}

void MainWindow::setReconstructed(cv::Mat reconstructedMat) {
    reconstructed = new QImage(reconstructedMat.data, reconstructedMat.cols, reconstructedMat.rows,
                               static_cast<float>(reconstructedMat.step),
                               QImage::Format_RGB888);
    reconstructedLabel->setPixmap(QPixmap::fromImage(*reconstructed));
}