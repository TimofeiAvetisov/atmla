/*
#include "../../Header/Matrix/Matrix.h"
#include "../../Header/Supporting/Fraction.h"
#include "../../Header/Supporting/Vector_operations.h"
*/
template<typename T>
void atmla::Matrix<T>::operator=(atmla::Matrix<T>& other) {
    if (this == &other) {
        return;
    }
    sizes = other.sizes;
    width = other.width;
    height = other.height;
    data = other.data;
}

template<typename T>
atmla::Matrix<T>& atmla::Matrix<T>::operator+(atmla::Matrix<T>& other) {
    if (sizes != other.sizes) {
        throw std::invalid_argument("Matrices must have the same dimensions to add");
    }
    atmla::Matrix<T> result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    *this = result;
    return *this;
}

template<typename T>
atmla::Matrix<T>& atmla::Matrix<T>::operator-(atmla::Matrix<T>& other) {
    if (sizes != other.sizes) {
        throw std::invalid_argument("Matrices must have the same dimensions to subtract");
    }
    atmla::Matrix<T> result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    *this = result;
    return *this;
}

template<typename T>
atmla::Matrix<T>& atmla::Matrix<T>::operator*(atmla::Matrix<T>& other) {
    if (width != other.height) {
        throw std::invalid_argument("Matrices cannot be multiplied: number of columns in the first matrix must match the number of rows in the second matrix");
    }
    atmla::Matrix<T> result(height, other.width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < other.width; ++j) {
            for (int k = 0; k < width; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    *this = result;
    return *this;
}

template<typename T>
void atmla::Matrix<T>::operator*=(atmla::Matrix<T>& other) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] *= other.data[i][j];
        }
    }
}

template<typename T>
void atmla::Matrix<T>::operator+=(atmla::Matrix<T>& other) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
}

template<typename T>
void atmla::Matrix<T>::operator-=(atmla::Matrix<T>& other) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }
}


