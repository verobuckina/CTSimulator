cmake_minimum_required(VERSION 3.20)
project(CTSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(CTSimulator main.cpp Kernels.cpp Kernels.h)
