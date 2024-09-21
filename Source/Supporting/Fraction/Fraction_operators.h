atmla::Fraction atmla::Fraction::operator*(const Fraction& other) const{
    Fraction new_fraction = Fraction(numerator * other.numerator, denominator * other.denominator);
    new_fraction.simplify();
    return new_fraction;
}

atmla::Fraction atmla::Fraction::operator/(const Fraction& other) const{
    Fraction new_fraction = Fraction(numerator * other.denominator, denominator * other.numerator);
    new_fraction.simplify();
    return new_fraction;
}

atmla::Fraction atmla::Fraction::operator+(const Fraction& other) const{
    int new_denominator = denominator * other.denominator;
    int new_numerator = numerator * other.denominator + denominator * other.numerator;
    Fraction new_fraction = Fraction(new_numerator, new_denominator);
    new_fraction.simplify();
    return new_fraction;
}

atmla::Fraction atmla::Fraction::operator-(const Fraction& other) const{
    int new_denominator = denominator * other.denominator;
    int new_numerator = numerator * other.denominator - denominator * other.numerator;
    Fraction new_fraction = Fraction(new_numerator, new_denominator);
    new_fraction.simplify();
    return new_fraction;
}

void atmla::Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    simplify();
}

void atmla::Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    simplify();
}

void atmla::Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    simplify();
}

void atmla::Fraction::operator/=(const Fraction& other) {
    *this = *this / other;
    simplify();
}

bool atmla::Fraction::operator==(const Fraction& other) const{
    return numerator == other.numerator && denominator == other.denominator;
}

bool atmla::Fraction::operator!=(const Fraction& other) const{
    return !(*this == other);
}

bool atmla::Fraction::operator<(const Fraction& other) const{
    return numerator * other.denominator < denominator * other.numerator;
}

bool atmla::Fraction::operator>(const Fraction& other) const{
    return numerator * other.denominator > denominator * other.numerator;
}

bool atmla::Fraction::operator<=(const Fraction& other) const{
    return numerator * other.denominator <= denominator * other.numerator;
}

bool atmla::Fraction::operator>=(const Fraction& other) const{
    return numerator * other.denominator >= denominator * other.numerator;
}