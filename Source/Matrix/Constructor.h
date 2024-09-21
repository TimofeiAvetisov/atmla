/*
#include "../../Header/Matrix/Matrix.h"
#include "../../Header/Supporting/Fraction.h"
#include "../../Header/Supporting/Vector_operations.h"
*/

template<typename T>
atmla::Matrix<T>::Matrix(int n, int m) {
    if (n <= 0 || m <= 0) {
        throw std::invalid_argument("Size of matrix must be positive");
    }
    sizes = {n, m};
    width = m;
    height = n;
    data.resize(n, std::vector<T>(m));
}


template<typename T>
template<typename U>
atmla::Matrix<T>::Matrix(std::vector<std::vector<U>>& values) {
    width = values.size();
    height = values[0].size();
    if (width == 0 || height == 0) {
        throw std::invalid_argument("Size of input vector must be positive");
    }
    sizes = {width, height};
    data.resize(height, std::vector<T>(width));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] = T(values[i][j]);
        }
    }
}

template<typename T>
atmla::Matrix<T>::Matrix(int n, std::string special, T lambda) {
    if (n <= 0) {
        throw std::invalid_argument("Size of matrix must be positive");
    }
    sizes = {n, n};
    width = n;
    height = n;
    data.resize(n, std::vector<T>(n));
    
    if (special == "identity") {
        for (int i = 0; i < n; ++i) {
            data[i][i] = T(1);
        }
    } else if (special == "zero") {
        for (int i = 0; i < n; ++i) {
            data[i][i] = T(0);
        }
    } else if (special == "jordan cell") {
        for (int i = 0; i < n; ++i) {
            data[i][i] = lambda;
            if (i + 1 < n);
            data[i][i + 1] = T(1);
        }
    } else if (special == "diagonal") {
        for (int i = 0; i < n; ++i) {
            data[i][i] = lambda;
        }
    } else {
        throw std::invalid_argument("Invalid special matrix type");
    }
}

template<typename T>
void atmla::Matrix<T>::Set_values_from_vector(std::vector<std::vector<T>>& values) {
    if (values.size()!= height || values[0].size()!= width) {
        throw std::invalid_argument("Size of input vector does not match the matrix dimensions");
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] = values[i][j];
        }
    }
}

template<typename T>
void atmla::Matrix<T>::Set_values_manually() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cin >> data[i][j];
        }
    }
}
