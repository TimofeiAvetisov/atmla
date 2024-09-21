#define cycles 10
#define precision 5e-4

atmla::Fraction::Fraction(int n, int m) {
    if (m == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    numerator = n;
    denominator = m;
    simplify();
}

atmla::Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

atmla::Fraction::Fraction(double number) {
    int sign = number < 0 ? -1 : 1;
    number = number * sign;
    double new_number, whole_part;
    double decimal_part = number - static_cast<int>(number);
    int counter = 0;

    std::valarray<double> vec_1{double((int) number), 1}, vec_2{1,0}, temporary;

    while(decimal_part > precision & counter < cycles){
        new_number = 1 / decimal_part;
        whole_part = (int) new_number;
        
        temporary = vec_1;
        vec_1 = whole_part * vec_1 + vec_2;
        vec_2 = temporary;
        
        decimal_part = new_number - whole_part;
        counter += 1;
    }
    atmla::Fraction::numerator = sign * vec_1[0];
    atmla::Fraction::denominator = vec_1[1];
    simplify();
}

void atmla::Fraction::simplify() {
    int gcd = std::__gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}