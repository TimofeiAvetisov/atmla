template<typename T>
std::vector<T> operator+(const std::vector<T>& v, const std::vector<T>& u) {
    if (v.size() != u.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    std::vector<T> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] + u[i];
    }
    return result;
}

template<typename T>
std::vector<T> operator-(const std::vector<T>& v, const std::vector<T>& u) {
    if (v.size()!= u.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    std::vector<T> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] - u[i];
    }
    return result;
}

template<typename T>
std::vector<T> operator*(std::vector<T>& v, T scalar) {
    std::vector<T> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = scalar * v[i];
    }
    return result;
}

template<typename T>
std::vector<T> operator/(std::vector<T>& v, T scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    std::vector<T> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] / scalar;
    }
    return result;
}