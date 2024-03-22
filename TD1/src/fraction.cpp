#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>
#include <algorithm>

// Ex 1 (J'ai commenté pour la nouvelle version des opérateurs à la question 5)

// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }


// Ex 2

std::ostream& operator<<(std::ostream &out, Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}

// Ex 3

bool operator==(Fraction const& f1, Fraction const& f2) {
    Fraction simplifiedF1 = simplify(f1);
    Fraction simplifiedF2 = simplify(f2);

    return simplifiedF1.numerator == simplifiedF2.numerator
        && simplifiedF1.denominator == simplifiedF2.denominator;
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1==f2);
}

// Ex 4

bool operator<(Fraction const& f1, Fraction const& f2) {
    Fraction frac1{f1.numerator * f2.denominator, f1.denominator * f2.denominator};
    Fraction frac2{f2.numerator * f1.denominator, f2.denominator * f1.denominator};

    return frac1.numerator < frac2.numerator;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return f1 < f2 || f1 == f2;
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return f2 < f1;
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return f2 <= f1;
}

// Ex 5

Fraction Fraction::operator+=(Fraction const& f2) {
    Fraction& f1 = *this;

    f1 = simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });

    return f1;
}

Fraction Fraction::operator-=(Fraction const& f2) {
    Fraction& f1 = *this;

    f1 = simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });

    return f1;
}

Fraction Fraction::operator*=(Fraction const& f2) {
    Fraction& f1 = *this;

    f1 = simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });

    return f1;
}

Fraction Fraction::operator/=(Fraction const& f2) {
    Fraction& f1 = *this;

    f1 = simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });

    return f1;
}

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    Fraction res{f1};
    res += f2;
    return res;
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    Fraction res{f1};
    res -= f2;
    return res;
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    Fraction res{f1};
    res *= f2;
    return res;
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    Fraction res{f1};
    res /= f2;
    return res;
}

// Ex 6

float Fraction::to_float()
{
    return static_cast<float>(numerator)/static_cast<float>(denominator);
}

Fraction::operator float()
{
    return to_float();
}