/*#include "../../Header/Matrix/Matrix.h"
#include "../../Header/Supporting/Fraction.h"
#include "../../Header/Supporting/Vector_operations.h"*/

template<typename T>
atmla::Matrix<T> atmla::Matrix<T>::operator+(T scalar) {
    atmla::Matrix<T> result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] + scalar;
        }
    }
    return result;
}

template<typename T>
atmla::Matrix<T> atmla::Matrix<T>::operator-(T scalar) {
    atmla::Matrix<T> result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] - scalar;
        }
    }
    return result;
}

template<typename T>
atmla::Matrix<T> atmla::Matrix<T>::operator*(T scalar) {
    atmla::Matrix<T> result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

template<typename T>
atmla::Matrix<T> atmla::Matrix<T>::operator/(T scalar) {
    if (scalar == T(0)) {
        throw std::runtime_error("Division by zero is not allowed");
    }
    atmla::Matrix<T> result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}
