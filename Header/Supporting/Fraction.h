#include <bits/stdc++.h>
#include <valarray>

namespace atmla {
    class Fraction {
        public:
            int numerator;
            int denominator;
            Fraction(int n, int m = 1);
            Fraction();
            Fraction(double n);

            void simplify();

            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;
            void operator+=(const Fraction& other);
            void operator-=(const Fraction& other);
            void operator*=(const Fraction& other);
            void operator/=(const Fraction& other);
            bool operator==(const Fraction& other) const;
            bool operator!=(const Fraction& other) const;
            bool operator<(const Fraction& other) const;
            bool operator>(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;

            friend std::ostream& operator<<(std::ostream& os, const atmla::Fraction& f) {
                if (f.denominator == 1) {
                    os << f.numerator;
                    return os;
                }
                os << f.numerator << "/" << f.denominator;
                return os;
            }

            friend std::istream& operator>>(std::istream& is, atmla::Fraction& f) {
                std::string input;
                is >> input;
                size_t slash_pos = input.find('/');
                if (slash_pos == std::string::npos) {
                    f.numerator = std::stoi(input);
                    f.denominator = 1;
                } else {
                    f.numerator = std::stoi(input.substr(0, slash_pos));
                    f.denominator = std::stoi(input.substr(slash_pos + 1));
                }
                f.simplify();
                return is;
            }
    };
}

atmla::Fraction abs(const atmla::Fraction f) {return atmla::Fraction(abs(f.numerator), abs(f.denominator));};
#include "../../Source/Supporting/Fraction/Fraction_constructors.h"
#include "../../Source/Supporting/Fraction/Fraction_operators.h"