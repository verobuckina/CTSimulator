cmake_minimum_required(VERSION 3.20)
project(CTSimulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(OpenCV_DIR C:/opencv-build/install/x64/mingw/lib)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

set(Qt5_DIR C:/Qt/Qt5.12.11/5.12.11/mingw73_64/lib/cmake/Qt5)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(CTSimulator main.cpp Kernels.cpp Kernels.h ForwardProjection.cpp ForwardProjection.h BackProjection.cpp BackProjection.h MainWindow.cpp MainWindow.h ImageTransformationUtility.cpp ImageTransformationUtility.h)

target_link_libraries(CTSimulator ${OpenCV_LIBS} Qt5::Core
        Qt5::Gui
        Qt5::Widgets)



