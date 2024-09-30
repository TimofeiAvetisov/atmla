template<typename T>
atmla::Polynomial<T> atmla::Polynomial<T>::operator+(const atmla::Polynomial<T>& other) const {
    if (this->variable_name != other.variable_name) {
        throw std::invalid_argument("Cannot add polynomials with different variables");
    }
    atmla::Polynomial<T> result(std::max(this->degree, other.degree), this->variable_name);
    
    for (int i = 0; i < std::min(this->degree, other.degree); ++i) {
        result.coefficients[i] = this->coefficients[i] + other.coefficients[i];
    }
    
    if (this->degree > other.degree) {
        for (int i = other.degree; i < this->degree; ++i) {
            result.coefficients[i] = this->coefficients[i];
        }
    } else {
        for (int i = this->degree; i < other.degree; ++i) {
            result.coefficients[i] = other.coefficients[i];
        }
    }

    return result;
}

template<typename T>
atmla::Polynomial<T> atmla::Polynomial<T>::operator-(const atmla::Polynomial<T>& other) const {
    if (this->variable_name != other.variable_name) {
        throw std::invalid_argument("Cannot subtract polynomials with different variables");
    }
    atmla::Polynomial<T> result(std::max(this->degree, other.degree), this->variable_name);
    
    for (int i = 0; i < std::min(this->degree, other.degree); ++i) {
        result.coefficients[i] = this->coefficients[i] - other.coefficients[i];
    }
    
    if (this->degree > other.degree) {
        for (int i = other.degree; i < this->degree; ++i) {
            result.coefficients[i] = this->coefficients[i];
        }
    } else {
        for (int i = this->degree; i < other.degree; ++i) {
            result.coefficients[i] = abs(other.coefficients[i]);
        }
    }

    return result;
}

template<typename T>
atmla::Polynomial<T> atmla::Polynomial<T>::operator*(const atmla::Polynomial<T>& other) const {
    if (this->variable_name != other.variable_name) {
        throw std::invalid_argument("Cannot multiply polynomials with different variables");
    }
    atmla::Polynomial<T> result(this->degree + other.degree - 1, this->variable_name);
    for (int i = 0; i < this->degree; ++i) {
        for (int j = 0; j < other.degree; ++j) {
            result.coefficients[i + j] += this->coefficients[i] * other.coefficients[j];
        }
    }
    return result;
}

template<typename T>
bool atmla::Polynomial<T>::operator==(const atmla::Polynomial<T>& other) const {
    if (this->variable_name!= other.variable_name || this->degree!= other.degree) {
        return false;
    }
    for (int i = 0; i < this->degree; ++i) {
        if (this->coefficients[i]!= other.coefficients[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool atmla::Polynomial<T>::operator!=(const atmla::Polynomial<T>& other) const {
    return !(*this == other);
}

template<typename T>
void atmla::Polynomial<T>::operator=(const atmla::Polynomial<T>& other) {
    if (*this == other) {
        return;
    }
    this->variable_name = other.variable_name;
    this->degree = other.degree;
    this->coefficients = other.coefficients;
}

template<typename T>
bool atmla::Polynomial<T>::operator==(const T value) const {
    for (int i = 0; i < degree; ++i) {
        if (coefficients[i] != value) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool atmla::Polynomial<T>::operator!=(const T value) const {
    return !(*this == value);
}