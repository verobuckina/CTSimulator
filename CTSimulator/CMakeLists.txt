cmake_minimum_required(VERSION 3.5)
project(CTSimulator)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)

#set(Qt5_DIR C:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5)
set(QT_PLUGIN_PATH "C:/Qt/Qt-5.15.2/plugins")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(OpenCV_DIR C:/opencv/release)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set (SRCS
    BackProjection.cpp
    BackProjection.h
    ForwardProjection.cpp
    ForwardProjection.h
    ImageTransformationUtility.cpp
    ImageTransformationUtility.h
    Kernels.cpp
    Kernels.h
    main.cpp
    MainWindow.cpp
    MainWindow.h
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})

add_library(Qt5Core STATIC IMPORTED)

target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS} Qt5::Core Qt5::Gui Qt5::Widgets)
