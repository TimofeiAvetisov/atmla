namespace atmla
{
    template<typename T>
    class Polynomial {
        public:
            std::vector<T> coefficients;
            std::string variable_name;
            size_t degree;

            Polynomial(std::vector<T> values, std::string var_name = "x");
            Polynomial(size_t degree, std::string variable_name = "x");
            Polynomial() : coefficients({}), variable_name("x"), degree(0) {};

            Polynomial<T> operator+(const Polynomial<T>& other) const;
            Polynomial<T> operator-(const Polynomial<T>& other) const;
            Polynomial<T> operator*(const Polynomial<T>& other) const;
            bool operator==(const Polynomial<T>& other) const;
            bool operator!=(const Polynomial<T>& other) const;
            void operator=(const Polynomial<T>& other);
            bool operator==(const T value) const;
            bool operator!=(const T value) const;


            friend std::ostream& operator<<(std::ostream& os, const Polynomial<T>& poly) {
                bool first_term = true;
                
                for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
                    T current_coeff = poly.coefficients[i];
                    if (current_coeff == T(0)) {
                        continue;
                    }

                    if (!first_term) {
                        if (current_coeff > T(0)) {
                            os << " + ";
                        } else {
                            os << " - ";
                            current_coeff = abs(current_coeff);
                        }
                    } else if (current_coeff < T(0)) {
                        os << "-";
                        current_coeff = abs(current_coeff);
                    }

                    if (i == 0 || current_coeff != T(1)) {
                        os << current_coeff;
                    }

                    if (i > 0) {
                        os << poly.variable_name;
                        if (i > 1) {
                            os << "^" << i;
                        }
                    }

                    first_term = false;
                }

                return os;
            }


    };
}

#include "../../Source/Supporting/Polynomial/Constructor.h"
#include "../../Source/Supporting/Polynomial/Operations.h"

