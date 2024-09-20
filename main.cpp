#include "Source/Matrix/Constructor.cpp"
#include "Header/Supporting/Vector_operations.h"


int main() {
    int n;
    std::cin >> n;
    std::string line;
    std::getline(std::cin, line);
    std::cout << "\'" << line << "\'";
    atmla::Matrix<atmla::Fraction> matrix(n, n);
    matrix.Set_values_manually();
    std::cout << matrix;
}
