/*
#include "../../Header/Matrix/Matrix.h"
#include "../../Header/Supporting/Fraction.h"
#include "../../Header/Supporting/Vector_operations.h"
*/

template<typename T>
void atmla::Matrix<T>::Transpose() {
    atmla::Matrix<T> result(width, height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    *this = result;
}

template<typename T>
T atmla::Matrix<T>::Determinant() {
    if (height != width) {
        throw std::invalid_argument("Matrix must be square to calculate the determinant");
    }

    int n = width;
    T det = T(1);

    std::vector<std::vector<T>> mat_copy = data;

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(mat_copy[j][i]) > abs(mat_copy[pivot][i])) {
                pivot = j;
            }
        }
        if (pivot != i) {
            std::swap(mat_copy[i], mat_copy[pivot]);
            det *= T(-1);
        }
        if (mat_copy[i][i] == T(0)) {
            return 0;
        }
        det *= mat_copy[i][i];
        for (int j = i + 1; j < n; j++) {
            T factor = mat_copy[j][i] / mat_copy[i][i];
            for (int k = i + 1; k < n; k++) {
                mat_copy[j][k] -= factor * mat_copy[i][k];
            }
        }
    }
    return det;
}

template<typename T>
T atmla::Matrix<T>::Trace() {
    if (height != width) {
        throw std::invalid_argument("Matrix must be square to calculate the trace");
    }
    T trace = T(0);
    for (int i = 0; i < height; ++i) {
        trace += data[i][i];
    }
    return trace;
}

template<typename T>
void atmla::Matrix<T>::Gauss(std::vector<T>& values) {
    if (values.size() != height) {
        throw std::invalid_argument("Size of input vector does not match the matrix height");
    }
    int step = 0;
    for (int i = 0; i < height; ++i) {
        if (data[i][i + step] == T(0)) {
            for (int k = i + 1; k < height; ++k) {
                if (data[k][i + step] != T(0)) {
                    std::swap(data[i], data[k]);
                    std::swap(values[i], values[k]);
                    break;
                }
            }
        }

        if (data[i][i + step] == T(0)) {
            step++;
            if (i + step >= height) {
                return;
            }
            --i;continue;
        }

        for (int j = i + 1; j < height; ++j) {
            if (data[j][i + step] != T(0)) {
                T factor = data[j][i + step];
                data[j] = (data[j] * data[i][i + step]) - (data[i] * factor);
                values[j] = values[j] * data[i][i + step] - values[i] * factor;
            }
        }
    }
}

template<typename T>
atmla::Matrix<T> atmla::Matrix<T>::Inverse() {
    if (atmla::Matrix<T>::width != atmla::Matrix<T>::height) {
        throw std::invalid_argument("Matrix must be square to calculate its inverse");
    }
    T det = atmla::Matrix<T>::Determinant();
    if (det == T(0)) {
        throw std::runtime_error("Matrix is not invertible");
    }
    atmla::Matrix<T> mat_copy(atmla::Matrix<T>::data);
    atmla::Matrix<T> result(atmla::Matrix<T>::height, static_cast<std::string>("identity"));

    for (int i = 0; i < mat_copy.height; i++) {
        if (mat_copy.data[i][i] == T(0)) {
            for (int k = i + 1; k < mat_copy.height; ++k) {
                if (mat_copy.data[k][i] != T(0)) {
                    std::swap(mat_copy.data[i], mat_copy.data[k]);
                    std::swap(result.data[i], result.data[k]);
                    break;
                }
            }
        }

        for (int j = i + 1; j < mat_copy.height; ++j) {
            if (mat_copy.data[j][i] != T(0)) {
                T factor = mat_copy.data[j][i];
                mat_copy.data[j] = (mat_copy.data[j] * mat_copy.data[i][i]) - (mat_copy.data[i] * factor);
                result.data[j] = (result.data[j] * mat_copy.data[i][i]) - (result.data[i] * factor);
            }
        }
    }

    for (int i = mat_copy.height - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            T factor = mat_copy.data[j][i];
            mat_copy.data[j] = (mat_copy.data[j] * mat_copy.data[i][i]) - (mat_copy.data[i] * factor);
            result.data[j] = (result.data[j] * mat_copy.data[i][i]) - (result.data[i] * factor);
        }
    }
    for (int i = 0; i < mat_copy.height; ++i) {
        result.data[i] = result.data[i] / mat_copy.data[i][i];
    }
    return result;
}
