#include "Matrix.cpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    atmla::Matrix matrix1(n, m);
    std::vector<std::vector<double>> data1(n, std::vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> data1[i][j];
        }
    }
    matrix1.Set_values_from_vector(data1);
    std::cin >> n >> m;
    atmla::Matrix matrix2(n, m);
    std::vector<std::vector<double>> data2(n, std::vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> data2[i][j];
        }
    }
    matrix2.Set_values_from_vector(data2);
    atmla::Matrix result = matrix1 * matrix2;
    std::cout << "result\n";
    for (auto q : result.data) {
        for (auto p : q) {
            std::cout << p << ' ';
        }
        std::cout << '\n';
    }
    system("pause");
}
