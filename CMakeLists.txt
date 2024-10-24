cmake_minimum_required(VERSION 3.10)
project(MatrixProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    Header/Matrix
    Header/Supporting
    Source/Matrix
    Source/Supporting/Vector
    Source/Supporting/Fraction
    Source/Supporting/Polynomial
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(matrix main.cpp)
