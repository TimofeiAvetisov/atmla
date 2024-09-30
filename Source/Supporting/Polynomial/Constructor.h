template<typename T>
atmla::Polynomial<T>::Polynomial(std::vector<T> values,  std::string var_name) {
    this->coefficients = values;
    this->variable_name = var_name;
    this->degree = values.size();
}

template<typename T>
atmla::Polynomial<T>::Polynomial(size_t degree, std::string var_name) {
    this->coefficients.resize(degree);
    for (int i = 0; i < degree; ++i) {
        this->coefficients[i] = T(0);
    }
    this->variable_name = var_name;
    this->degree = degree;
}


