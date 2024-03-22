#pragma once

#include <iostream>

struct Fraction {
    int numerator;
    int denominator;

    friend std::ostream& operator<<(std::ostream &out, Fraction& f);

    Fraction operator+=(Fraction const&);
    Fraction operator-=(Fraction const&);
    Fraction operator*=(Fraction const&);
    Fraction operator/=(Fraction const&);

    float to_float();
    operator float();
};

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);