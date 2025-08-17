cmake_minimum_required(VERSION 3.28)
project(RubicsCubeSover)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubicsCubeSover main.cpp
        GenericRubiksCube.cpp
        GenericRubiksCube.h)
