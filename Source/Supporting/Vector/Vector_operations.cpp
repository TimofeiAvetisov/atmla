#include "../../../Header/Supporting/Vector_operations.h"

std::vector<double> operator+(const std::vector<double>& v, const std::vector<double>& u) {
    if (v.size() != u.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    std::vector<double> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] + u[i];
    }
    return result;
}

std::vector<double> operator-(const std::vector<double>& v, const std::vector<double>& u) {
    if (v.size()!= u.size()) {
        throw std::invalid_argument("Vectors must have the same size");
    }

    std::vector<double> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] - u[i];
    }
    return result;
}

std::vector<double> operator*(std::vector<double>& v, double scalar) {
    std::vector<double> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = scalar * v[i];
    }
    return result;
}

std::vector<double> operator/(std::vector<double>& v, double scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    std::vector<double> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] / scalar;
    }
    return result;
}