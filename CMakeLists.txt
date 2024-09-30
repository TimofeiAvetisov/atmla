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

add_executable(matrix
    #Source/Supporting/Vector/Vector_operations.cpp
    #Source/Supporting/Fraction/Fraction_constructors.cpp
    #Source/Supporting/Fraction/Fraction_operators.cpp
    #Source/Matrix/Constructor.cpp
    #Source/Matrix/Operations.cpp
    #Source/Matrix/Output.cpp
    #Source/Matrix/Scalar_operations.cpp
    #Source/Matrix/Functions.cpp
    main.cpp
)