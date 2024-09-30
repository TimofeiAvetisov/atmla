template<typename T>
atmla::Polynomial<atmla::Fraction> atmla::Matrix<T>::Zonal(/*atmla::Matrix<atmla::Fraction> matrix,*/std::string var_name) {
    if (this->width != this->height) {
        throw std::invalid_argument("Matrix must be square to calculate its zonal polynomial");
    }

    const size_t universal_size = this->width;
    const atmla::Fraction zero(0);
    std::vector<std::vector<atmla::Polynomial<atmla::Fraction>>> poly_matr(universal_size, std::vector<atmla::Polynomial<atmla::Fraction>>(universal_size));

    for (int i = 0; i < universal_size; ++i) {
        for (int j = 0; j < universal_size; ++j) {
            if (i == j) {
                poly_matr[i][j] = typename atmla::Polynomial<atmla::Fraction>::Polynomial({atmla::Fraction(this->data[i][j]), atmla::Fraction(-1)}, var_name);
            } else {
               poly_matr[i][j] = typename atmla::Polynomial<atmla::Fraction>::Polynomial({atmla::Fraction(this->data[i][j])}, var_name);
            }
        }
    }
    
    for (int i = 0; i < universal_size; i++) {
        if (poly_matr[i][i] == zero) {
            for (int k = i + 1; k < universal_size; ++k) {
                if (poly_matr[k][i] != zero) {
                    std::swap(poly_matr[i], poly_matr[k]);
                    break;
                }
            }
        }

        for (int j = i + 1; j < universal_size; ++j) {
            if (poly_matr[j][i] != zero) {
                atmla::Polynomial<atmla::Fraction> factor = poly_matr[j][i];
                poly_matr[j] = (poly_matr[j] * poly_matr[i][i]) - (poly_matr[i] * factor);
            }
        }
        
    }
    

    for (int i = universal_size - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            atmla::Polynomial<atmla::Fraction> factor = poly_matr[j][i];
            poly_matr[j] = (poly_matr[j] * poly_matr[i][i]) - (poly_matr[i] * factor);
        }
    }

    return poly_matr[universal_size - 1][universal_size - 1];
}