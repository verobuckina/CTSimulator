# CTSimulator

This is a small program to simulate the forward and filtered-backprojection of a parallel beam computed tomography. The simulator has a simple UI to visualize the reconstruction pipeline.

---

## How to use

### Requirements

OpenCV 4 and Qt5 must be installed.

### Build

You can find a CMakeList.txt in the project. Build the application with cmake. An executable file will be created.

### How to use the CTSimulator

Start the executable file on your PC. A simple UI with 4 image slots will open.

1. Click on "Load Phantom" to load a phantom. The phantom can have a maximum resolution of 255 x 255 pixels.

2. Click on "Forward Projection" to generate the sinogram of your phantom

3. Select a filter from the drop-down menu. You can choose not to filter the sinogram. For this, select "Not Selected". Nevertheless you should click on "Filter" to be able to backproject your sinogram.

4. Click on "Backward Projection" to generate the backprojected Phantom.

![image](https://user-images.githubusercontent.com/43641879/136431131-baf393ea-e861-4828-9790-8eb3a4b48980.png)

---

## Executables

Executables yet to come.

---
