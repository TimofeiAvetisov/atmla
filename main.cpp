#include "Header/Matrix/Matrix.h"

int main() {
    int n, m;
    std::cin >> n >> m;
    atmla::Matrix<atmla::Fraction> matrix(n, m);
    matrix.Set_values_manually();
    std::cout << matrix;
    atmla::Matrix<atmla::Fraction> matrix2 = matrix;

    atmla::Matrix<atmla::Fraction> inversed = matrix.Inverse();
    std::cout << inversed;
    std::cout << inversed * matrix2;
}