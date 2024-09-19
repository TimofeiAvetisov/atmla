namespace atmla
{
    class Matrix
    {
        public:
            int height;
            int width;
            std::pair<int, int> sizes;
            std::vector<std::vector<double>> data;
            /**
             * @brief Matrix constructor with given dimensions.
             * 
             * Creates a matrix with dimensions n by m.
             * 
             * @param n Number of rows.
             * @param m Number of columns.
             * @throw std::invalid_argument If matrix dimensions are negative or zero.
             */
            Matrix(int n, int m);
            /**
             * @brief Matrix constructor based on a 2D vector.
             * 
             * Creates a matrix based on the values from a 2D vector.
             * 
             * @param values Vector of values to initialize the matrix.
             */
            Matrix(std::vector<std::vector<double>>& values);
            /**
             * @brief Constructor for special types of matrices.
             * 
             * Creates a special matrix such as identity, zero, diagonal, or Jordan block matrix.
             * 
             * @param n Matrix size (the matrix will be square).
             * @param special The type of special matrix ("identity", "zero", "jordan cell", "diagonal").
             * @param lambda Parameter for certain types of special matrices (e.g., diagonal and Jordan block).
             * @throw std::invalid_argument If the special matrix type is invalid or the size is non-positive.
             */
            Matrix(int n, std::string special, double lambda);

            /**
             * @brief Sets the matrix values from a 2D vector.
             * 
             * @param values Input vector of values to set the matrix elements.
             * @throw std::invalid_argument If the size of the input vector does not match the matrix dimensions.
             */
            void Set_values_from_vector(std::vector<std::vector<double>>& values);
            /**
             * @brief Manually set matrix values.
             * 
             * Prompts the user to input values for each matrix element via standard input.
             */
            void Set_values_manually();

            /**
             * @brief Prints the matrix to the standard output.
             * 
             * Outputs all elements of the matrix in tabular form.
             */
            void print();
            /**
             * @brief Prints the matrix as a system of equations with right-hand sides.
             * 
             * Outputs the matrix along with a vector of values representing the right-hand side of the system of linear equations.
             * 
             * @param values Vector of right-hand sides.
             * @throw std::invalid_argument If the size of the vector does not match the number of rows in the matrix.
             */
            void print_system(std::vector<double>& values);

            /**
             * @brief Prints two matrices side by side as a system of equations.
             * 
             * This function prints the current matrix and the provided matrix `matrix` side by side. 
             * It assumes that both matrices have the same number of rows.
             * 
             * @param matrix The matrix to be printed alongside the current matrix.
             * @throw std::invalid_argument If the heights of the matrices are not equal.
             */
            void print_matrix_system(Matrix& matrix);

            // Matrix operations with other matrix
            void operator=(Matrix& other_matrix);
            Matrix& operator+(Matrix& other_matrix);
            Matrix& operator-(Matrix& other_matrix);
            Matrix& operator*(Matrix& other_matrix);
            void operator*=(Matrix& other_matrix);
            void operator+=(Matrix& other_matrix);
            void operator-=(Matrix& other_matrix);
            /**
             * @brief Transposes the current matrix.
             * 
             * Swaps the rows and columns of the matrix and returns the result.
             */
            void Transpose();
            /**
             * @brief Computes the determinant of the matrix.
             * 
             * Calculates the determinant of a square matrix using Gaussian elimination.
             * 
             * @return double The determinant of the matrix.
             * @throw std::invalid_argument If the matrix is not square.
             */
            double Determinant();
            /**
             * @brief Computes the trace of the matrix.
             * 
             * Calculates the sum of the diagonal elements of a square matrix.
             * 
             * @return double The trace of the matrix.
             * @throw std::invalid_argument If the matrix is not square.
             */
            double Trace();
            /**
             * @brief Solves a system of linear equations using Gaussian elimination.
             * 
             * Transforms the matrix to upper triangular form and solves the system of equations with the right-hand side represented by the vector `values`.
             * 
             * @param values Vector of right-hand sides of the equations.
             * @throw std::invalid_argument If the size of the vector does not match the number of rows in the matrix.
             */
            void Gauss(std::vector<double>& values);
            /**
             * @brief Computes the inverse of the matrix.
             * 
             * This function returns the inverse of the current matrix if it is square and invertible.
             * 
             * @return atmla::Matrix The inverse matrix.
             * @throw std::invalid_argument If the matrix is not square.
             * @throw std::runtime_error If the matrix is not invertible.
             */
            Matrix Inverse();

            // Matrix operations with scalar
            Matrix operator+(double scalar);
            Matrix operator-(double scalar);
            Matrix operator*(double scalar);
            Matrix operator/(double scalar);
    };
}