template <typename T>
std::vector<T> operator+(const std::vector<T>& v, const std::vector<T>& u);

template <typename T>
std::vector<T> operator-(const std::vector<T>& v, const std::vector<T>& u);

template <typename T>
std::vector<T> operator*(std::vector<T>& v, T scalar);

template <typename T>
std::vector<T> operator/(std::vector<T>& v, T scalar);

template <typename T>
bool operator==(const std::vector<T>& v, T scalar);

#include "../../Source/Supporting/Vector/Vector_operations.h"