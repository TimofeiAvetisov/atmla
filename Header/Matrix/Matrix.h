#include <bits/stdc++.h>
#include <valarray>
#include "../Supporting/Fraction.h"
#include "../Supporting/Vector_operations.h"

namespace atmla
{
    template<typename T>
    class Matrix
    {
        public:
            int height;
            int width;
            std::pair<int, int> sizes;
            std::vector<std::vector<T>> data;
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
            template<typename U>
            Matrix(std::vector<std::vector<U>>& values);
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
            Matrix(int n, std::string special, T lambda = T());

            /**
             * @brief Sets the matrix values from a 2D vector.
             * 
             * @param values Input vector of values to set the matrix elements.
             * @throw std::invalid_argument If the size of the input vector does not match the matrix dimensions.
             */
            void Set_values_from_vector(std::vector<std::vector<T>>& values);
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
            template<typename U>
            void print_system(std::vector<U>& values);

            /**
             * @brief Prints two matrices side by side as a system of equations.
             * 
             * This function prints the current matrix and the provided matrix `matrix` side by side. 
             * It assumes that both matrices have the same number of rows.
             * 
             * @param matrix The matrix to be printed alongside the current matrix.
             * @throw std::invalid_argument If the heights of the matrices are not equal.
             */
            template<typename U>
            void print_matrix_system(Matrix<U>& matrix);

            // Matrix operations with other matrix
            void operator=(Matrix<T>& other_matrix);
            Matrix<T>& operator+(Matrix<T>& other_matrix);
            Matrix<T>& operator-(Matrix<T>& other_matrix);
            Matrix<T>& operator*(Matrix<T>& other_matrix);
            void operator*=(Matrix<T>& other_matrix);
            void operator+=(Matrix<T>& other_matrix);
            void operator-=(Matrix<T>& other_matrix);
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
            T Determinant();
            /**
             * @brief Computes the trace of the matrix.
             * 
             * Calculates the sum of the diagonal elements of a square matrix.
             * 
             * @return double The trace of the matrix.
             * @throw std::invalid_argument If the matrix is not square.
             */
            T Trace();
            /**
             * @brief Solves a system of linear equations using Gaussian elimination.
             * 
             * Transforms the matrix to upper triangular form and solves the system of equations with the right-hand side represented by the vector `values`.
             * 
             * @param values Vector of right-hand sides of the equations.
             * @throw std::invalid_argument If the size of the vector does not match the number of rows in the matrix.
             */
            void Gauss(std::vector<T>& values);
            /**
             * @brief Computes the inverse of the matrix.
             * 
             * This function returns the inverse of the current matrix if it is square and invertible.
             * 
             * @return atmla::Matrix The inverse matrix.
             * @throw std::invalid_argument If the matrix is not square.
             * @throw std::runtime_error If the matrix is not invertible.
             */
            Matrix<T> Inverse();

            // Matrix operations with scalar
            Matrix<T> operator+(T scalar);
            Matrix<T> operator-(T scalar);
            Matrix<T> operator*(T scalar);
            Matrix<T> operator/(T scalar);

            // output
            friend std::ostream& operator<<(std::ostream& os, const atmla::Matrix<T>& matrix) {
                for (int i = 0; i < matrix.height; ++i) {
                    for (int j = 0; j < matrix.width; ++j) {
                        os << matrix.data[i][j] << '\t';
                    }
                    os << '\n';
                }
                return os;
            }
    };
}

#include "../../Source/Matrix/Constructor.h"
#include "../../Source/Matrix/Operations.h"
#include "../../Source/Matrix/Scalar_operations.h"
#include "../../Source/Matrix/output.h"
#include "../../Source/Matrix/Functions.h"
template class atmla::Matrix<int>;
template class atmla::Matrix<double>;
template class atmla::Matrix<atmla::Fraction>;
