#include "Matrix.cpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<double>> values(n, std::vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> values[i][j];
        }
    }
    atmla::Matrix matrix1(values);
    //std::vector<double> values1 = {0, 0};
    //matrix1.Gauss(values1);
    //matrix1.print();
    atmla::Matrix result = matrix1.Inverse();

    matrix1.print_matrix_system(result);
}
