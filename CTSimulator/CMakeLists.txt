cmake_minimum_required(VERSION 2.8)
project(CTSimulator)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(CTSimulator main.cpp Kernels.cpp Kernels.h ForwardProjection.cpp ForwardProjection.h)
target_link_libraries(CTSimulator ${OpenCV_LIBS})
