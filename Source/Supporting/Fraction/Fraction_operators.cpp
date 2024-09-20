#include "../../../Header/Supporting/Fraction.h"

atmla::Fraction atmla::Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

atmla::Fraction atmla::Fraction::operator/(const Fraction& other) const {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

atmla::Fraction atmla::Fraction::operator+(const Fraction& other) const {
    int new_denominator = denominator * other.denominator;
    int new_numerator = numerator * other.denominator + denominator * other.numerator;
    return Fraction(new_numerator, new_denominator);
}

atmla::Fraction atmla::Fraction::operator-(const Fraction& other) const {
    int new_denominator = denominator * other.denominator;
    int new_numerator = numerator * other.denominator - denominator * other.numerator;
    return Fraction(new_numerator, new_denominator);
}