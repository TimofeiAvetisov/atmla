#include <bits/stdc++.h>
#include "Matrix.h"

//Matrix declaration


atmla::Matrix::Matrix(int n, int m) {
    if (n <= 0 || m <= 0) {
        throw std::invalid_argument("Size of matrix must be positive");
    }
    atmla::Matrix::size = {n, m};
    atmla::Matrix::width = m;
    atmla::Matrix::height = n;
    data.resize(n);
    for (int i = 0; i < n; ++i) {
        data[i].resize(m);
    }
}

void atmla::Matrix::Set_values_from_vector(std::vector<std::vector<double>>& values) {
    if (values.size()!= height || values[0].size()!= width) {
        throw std::invalid_argument("Size of input vector does not match the matrix dimensions");
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] = values[i][j];
        }
    }
}

void atmla::Matrix::Set_values_manually() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cin >> data[i][j];
        }
    }
}


// Matrix operations with other matrix


void atmla::Matrix::operator=(atmla::Matrix& other) {
    if (this == &other) {
        return;
    }
    size = other.size;
    width = other.width;
    height = other.height;
    data = other.data;
}

atmla::Matrix& atmla::Matrix::operator+(atmla::Matrix& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same dimensions to add");
    }
    atmla::Matrix result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    *this = result;
    return *this;
}

atmla::Matrix& atmla::Matrix::operator-(atmla::Matrix& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must have the same dimensions to subtract");
    }
    atmla::Matrix result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    *this = result;
    return *this;
}

atmla::Matrix& atmla::Matrix::operator*(atmla::Matrix& other) {
    if (width != other.height) {
        throw std::invalid_argument("Matrices cannot be multiplied: number of columns in the first matrix must match the number of rows in the second matrix");
    }
    atmla::Matrix result(height, other.width);
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

void atmla::Matrix::operator*=(atmla::Matrix& other) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] *= other.data[i][j];
        }
    }
}

void atmla::Matrix::operator+=(atmla::Matrix& other) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
}

void atmla::Matrix::operator-=(atmla::Matrix& other) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }
}

void atmla::Matrix::Transpose() {
    atmla::Matrix result(width, height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    *this = result;
}

double atmla::Matrix::Determinant() {
    if (height != width) {
        throw std::invalid_argument("Matrix must be square to calculate the determinant");
    }
    int n = width;
    double det = 1.0;
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(data[j][i]) > abs(data[pivot][i])) {
                pivot = j;
            }
        }
        if (pivot != i) {
            std::swap(data[i], data[pivot]);
            det *= -1;
        }
        if (data[i][i] == 0) {
            return 0;
        }
        det *= data[i][i];
        for (int j = i + 1; j < n; j++) {
            double factor = data[j][i] / data[i][i];
            for (int k = i + 1; k < n; k++) {
                data[j][k] -= factor * data[i][k];
            }
        }
    }
    return det;
}

double atmla::Matrix::Trace() {
    if (height != width) {
        throw std::invalid_argument("Matrix must be square to calculate the trace");
    }
    double trace = 0;
    for (int i = 0; i < height; ++i) {
        trace += data[i][i];
    }
}


// Matrix operations with scalar


atmla::Matrix atmla::Matrix::operator+(double scalar) {
    atmla::Matrix result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] + scalar;
        }
    }
    return result;
}

atmla::Matrix atmla::Matrix::operator-(double scalar) {
    atmla::Matrix result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] - scalar;
        }
    }
    return result;
}

atmla::Matrix atmla::Matrix::operator*(double scalar) {
    atmla::Matrix result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}
