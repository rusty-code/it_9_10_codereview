#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
#include <string>

class Fraction {
private:
    int _numerator;
    int _denominator;

    int _gcd(int a, int b) const;
    void _simplify();

public:
    Fraction(int num = 0, int denom = 1);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    Fraction sum(const Fraction& other) const;
    Fraction minus(const Fraction& other) const;
    Fraction mult(const Fraction& other) const;
    Fraction div(const Fraction& other) const;
    Fraction minus(int num) const;

    std::string to_string() const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);
};

#endif