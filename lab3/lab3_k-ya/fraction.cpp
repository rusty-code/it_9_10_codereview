#include <cmath>
#include <stdexcept>

#include "fraction.h"

int Fraction::_gcd(int a, int b) const {
    return b == 0 ? a : _gcd(b, a % b);
}

void Fraction::_simplify() {
    int common = _gcd(std::abs(_numerator), std::abs(_denominator));
    _numerator /= common;
    _denominator /= common;
    if (_denominator < 0) {
        _numerator *= -1;
        _denominator *= -1;
    }
}

Fraction::Fraction(int num, int denom) : _numerator(num), _denominator(denom) {
    if (denom == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    _simplify();
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(
        _numerator * other._denominator + other._numerator * _denominator,
        _denominator * other._denominator
    );
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(
        _numerator * other._denominator - other._numerator * _denominator,
        _denominator * other._denominator
    );
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(
        _numerator * other._numerator,
        _denominator * other._denominator
    );
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other._numerator == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    return Fraction(
        _numerator * other._denominator,
        _denominator * other._numerator
    );
}

Fraction Fraction::sum(const Fraction& other) const {
    return *this + other;
}

Fraction Fraction::minus(const Fraction& other) const {
    return *this - other;
}

Fraction Fraction::mult(const Fraction& other) const {
    return *this * other;
}

Fraction Fraction::div(const Fraction& other) const {
    return *this / other;
}

Fraction Fraction::minus(int num) const {
    return *this - Fraction(num);
}

std::string Fraction::to_string() const {
    if (_denominator == 1) return std::to_string(_numerator);
    return std::to_string(_numerator) + "/" + std::to_string(_denominator);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.to_string();
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
    char slash;
    is >> f._numerator >> slash >> f._denominator;
    if (slash != '/' || f._denominator == 0) {
        throw std::invalid_argument("Invalid fraction format");
    }
    f._simplify();
    return is;
}