cmake_minimum_required(VERSION 2.8)
project(CTSimulator)

find_package(OpenCV REQUIRED)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

add_executable(CTSimulator main.cpp Kernels.cpp Kernels.h ForwardProjection.cpp ForwardProjection.h BackProjection.cpp BackProjection.h MainWindow.cpp MainWindow.h ImageTransformationUtility.cpp ImageTransformationUtility.h)
target_link_libraries(CTSimulator ${OpenCV_LIBS} Qt5::Core
        Qt5::Gui
        Qt5::Widgets)
