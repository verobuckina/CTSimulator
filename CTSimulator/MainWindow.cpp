//
// Created by verobuckina on 05.09.21.
//

#include "MainWindow.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QGridLayout *showLayout = new QGridLayout(this);

    QLabel *phantomDiscLabel = new QLabel("Phantom", this);
    phantomLabel = new QLabel("", this);

    QLabel *sinogramDiscLabel = new QLabel("Sinogram", this);
    sinogramLabel = new QLabel("Sinogram", this);

    QLabel *fSinogramDiscLabel = new QLabel("Filtered Sinogram", this);
    fSinogramLabel = new QLabel("Filtered Sinogram", this);

    QLabel *reconstructedDiscLabel = new QLabel("Reconstructed", this);
    reconstructedLabel = new QLabel("Reconstructed", this);

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