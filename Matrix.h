namespace atmla
{
    class Matrix
    {
        public:
            int height;
            int width;
            std::pair<int, int> size;
            std::vector<std::vector<double>> data;
            // Matrix constructor
            Matrix(int n, int m);
            void Set_values_from_vector(std::vector<std::vector<double>>& values);
            void Set_values_manually();

            // Matrix operations with other matrix
            void operator=(Matrix& other_matrix);
            Matrix& operator+(Matrix& other_matrix);
            Matrix& operator-(Matrix& other_matrix);
            Matrix& operator*(Matrix& other_matrix);
            void operator*=(Matrix& other_matrix);
            void operator+=(Matrix& other_matrix);
            void operator-=(Matrix& other_matrix);
            void Transpose();
            double Determinant();
            double Trace();

            // Matrix operations with scalar
            Matrix operator+(double scalar);
            Matrix operator-(double scalar);
            Matrix operator*(double scalar);
            Matrix operator/(double scalar);
    };
}