#include "../../Header/Matrix/Matrix.h"
#include "../../Header/Supporting/Vector_operations.h"



void atmla::Matrix::print() {
    for (auto q : data) {
        for (auto p : q) {
            std::cout << p << ' ';
        }
        std::cout << '\n';
    }
}

void atmla::Matrix::print_system(std::vector<double>& values) {
    if (values.size() != height) {
        throw std::invalid_argument("Size of input vector does not match the matrix height");
    }
    for  (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++ j) {
            std::cout << data[i][j] << ' ';
        }
        std::cout << "| " << values[i] << '\n';
    }
}

void atmla::Matrix::print_matrix_system(atmla::Matrix& matrix) {
    if (matrix.height != height) {
        throw std::invalid_argument("Matrices must have the same dimensions to print system");
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << data[i][j] << ' ';
        }
        std::cout << "| ";
        for (int j = 0; j < width; ++j) {
            std::cout << matrix.data[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

// Matrix operations with other matrix

void atmla::Matrix::operator=(atmla::Matrix& other) {
    if (this == &other) {
        return;
    }
    sizes = other.sizes;
    width = other.width;
    height = other.height;
    data = other.data;
}

atmla::Matrix& atmla::Matrix::operator+(atmla::Matrix& other) {
    if (sizes != other.sizes) {
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
    if (sizes != other.sizes) {
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

    // Создаем копию матрицы
    std::vector<std::vector<double>> mat_copy = data;

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(mat_copy[j][i]) > abs(mat_copy[pivot][i])) {
                pivot = j;
            }
        }
        if (pivot != i) {
            std::swap(mat_copy[i], mat_copy[pivot]);
            det *= -1;
        }
        if (mat_copy[i][i] == 0) {
            return 0;
        }
        det *= mat_copy[i][i];
        for (int j = i + 1; j < n; j++) {
            double factor = mat_copy[j][i] / mat_copy[i][i];
            for (int k = i + 1; k < n; k++) {
                mat_copy[j][k] -= factor * mat_copy[i][k];
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

void atmla::Matrix::Gauss(std::vector<double>& values) {
    if (values.size() != height) {
        throw std::invalid_argument("Size of input vector does not match the matrix height");
    }
    int step = 0;
    for (int i = 0; i < atmla::Matrix::height; ++i) {
        if (atmla::Matrix::data[i][i + step] == 0) {
            for (int k = i + 1; k < atmla::Matrix::height; ++k) {
                if (atmla::Matrix::data[k][i + step] != 0) {
                    std::swap(atmla::Matrix::data[i], atmla::Matrix::data[k]);
                    std::swap(values[i], values[k]);
                    break;
                }
            }
        }

        if (atmla::Matrix::data[i][i + step] == 0) {
            step++;
            if (i + step >= atmla::Matrix::height) {
                return;
            }
            --i;continue;
        }

        for (int j = i + 1; j < atmla::Matrix::height; ++j) {
            if (atmla::Matrix::data[j][i + step] != 0) {
                double factor = atmla::Matrix::data[j][i + step];
                atmla::Matrix::data[j] = (atmla::Matrix::data[j] * atmla::Matrix::data[i][i + step]) - (atmla::Matrix::data[i] * factor);
                values[j] = values[j] * atmla::Matrix::data[i][i + step] - values[i] * factor;
            }
        }
    }
}

atmla::Matrix atmla::Matrix::Inverse() {
    if (width != height) {
        throw std::invalid_argument("Matrix must be square to calculate its inverse");
    }
    double det = Determinant();
    if (det == 0) {
        throw std::runtime_error("Matrix is not invertible");
    }
    atmla::Matrix result(height, static_cast<std::string>("identity"));

    //forward
    for (int i = 0; i < atmla::Matrix::height; i++) {
        if (atmla::Matrix::data[i][i] == 0) {
            for (int k = i + 1; k < atmla::Matrix::height; ++k) {
                if (atmla::Matrix::data[k][i] != 0) {
                    std::swap(atmla::Matrix::data[i], atmla::Matrix::data[k]);
                    std::swap(result.data[i], result.data[k]);
                    break;
                }
            }
        }

        for (int j = i + 1; j < atmla::Matrix::height; ++j) {
            if (atmla::Matrix::data[j][i] != 0) {
                double factor = atmla::Matrix::data[j][i];
                atmla::Matrix::data[j] = (atmla::Matrix::data[j] * atmla::Matrix::data[i][i]) - (atmla::Matrix::data[i] * factor);
                result.data[j] = (result.data[j] * atmla::Matrix::data[i][i]) - (result.data[i] * factor);
            }
        }
    }

    //back
    for (int i = height - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            double factor = atmla::Matrix::data[j][i];
            atmla::Matrix::data[j] = (atmla::Matrix::data[j] * atmla::Matrix::data[i][i]) - (atmla::Matrix::data[i] * factor);
            result.data[j] = (result.data[j] * atmla::Matrix::data[i][i]) - (result.data[i] * factor);
        }
    }
    return result;
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

atmla::Matrix atmla::Matrix::operator/(double scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero is not allowed");
    }
    atmla::Matrix result(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}