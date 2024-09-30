#include "Header/Matrix/Matrix.h"

int main() {
    int n;
    std::cin >> n;
    atmla::Matrix<atmla::Fraction> matrix(n, n);
    std::cin >> matrix;
    Zonal(matrix, "x"); 
}