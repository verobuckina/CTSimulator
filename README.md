# CTSimulator

This is a small program to simulate the forward and filtered-backprojection of a parallel beam computed tomography. The simulator has a simple UI to visualize the reconstruction pipeline.

## How to use

### How to use the CTSimulator

Start the executable file on your PC. A simple UI with 4 image slots will open.

1. Click on "Load Phantom" to load a phantom. The phantom can have a maximum resolution of 255 x 255 pixels.

2. Click on "Forward Projection" to generate the sinogram of your phantom

3. Select a filter from the drop-down menu. You can choose not to filter the sinogram. For this, select "Not Selected". Nevertheless you should click on "Filter" to be able to backproject your sinogram.

4. Select the number of angles. Default is 180. This means, that the phantom is reconstructed with all acquired angles. Click on "Backward Projection" to generate the backprojected phantom.

![CTSim](https://user-images.githubusercontent.com/43641879/136768402-92e842c0-6a0b-4d7a-8ba9-6f484ede068d.png)

### Requirements

OpenCV 4 and Qt5 must be installed. An installation instruction is given below.

Binaries for OpenCV can be found [here](https://opencv.org/releases/). (Binaries used in the project: OpenCV - 4.5.4)

Binaries for Qt5 can be found [here](https://www.qt.io/offline-installers). (Binaries used in this project: Qt 5.15.x)

### Build

You can find a CMakeList.txt in the project. Build the application with cmake. An executable file will be created.

## Executables

You can find the executables in the folder Executable. Download the .zip-file and extract it. To start the application, double click on the .exe. How to use the CTSimulator is described above.

## Installation Instruction

### Prerequisites

Will follow soon.

### Installing Qt5

Will be updated soon.

<!-- 1. Download the "5.12.x Offline Installer" from https://www.qt.io/offline-installers

2. Create an Qt Account and click "Next".

3. Confirm the "Qt Open Source Usage Obligations".

4. Select the directory to install Qt 5.12.11.

5. Under "Developer and Deigner Tools" select "MinGW 7.3.0 64-bit", under "Qt 5.12.11" select "MinGW 7.3.0 64-bit"

6. Agree to the License Agreement.

7. Install Qt.

8. After Installing add following directories to your path variables: ./Qt5.12.11/Tools/mingw73_64/bin and ./Qt/Qt5.12.11/5.12.11/mingw73_64/bin -->

### Installing OpenCV with Qt support

Will be updated soon.

## License 

CT Simulator is under Lesser GNU General Public License v3. The full license copy is given in LICENSE.md.

The software is build using the Qt Open Source Version and OpenCV. The Qt modules used in this project are under Lesser GNU General Public License v3. Some Qt modules are not available for LGPLv3 license and are under GNU General public License v3.
