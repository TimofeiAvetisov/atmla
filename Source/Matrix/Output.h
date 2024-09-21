/*#include "../../Header/Matrix/Matrix.h"
#include "../../Header/Supporting/Fraction.h"
#include "../../Header/Supporting/Vector_operations.h"
*/

template<typename T>
void atmla::Matrix<T>::print() {
    for (auto q : data) {
        for (auto p : q) {
            std::cout << p << ' ';
        }
        std::cout << '\n';
    }
}

template<typename T>
template<typename U>
void atmla::Matrix<T>::print_system(std::vector<U>& values) {
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

template<typename T>
template<typename U>
void atmla::Matrix<T>::print_matrix_system(atmla::Matrix<U>& matrix) {
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
