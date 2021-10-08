cmake_minimum_required(VERSION 3.20)
project(CTSimulator)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Concurrent
        Test
        REQUIRED)

#set(OpenCV_DIR  C:/opencv/release)
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

target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test Qt5::Concurrent)
