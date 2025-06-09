#include <iostream>
#include <numeric>
#include <stdexcept>
#include "fraction.h"
#include "utils.h"

void Fraction::simplify() {
    int _gcd = std::gcd(abs(_numerator), abs(_denominator));
    _numerator /= _gcd;
    _denominator /= _gcd;
    if (_denominator < 0) {
        _numerator = -_numerator;
        _denominator = -_denominator;
    }
}

Fraction::Fraction(int _num, int _denom) : _numerator(_num), _denominator(_denom) {
    if (_denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    simplify();
}

std::string Fraction::to_string() const {
    return std::to_string(_numerator) + "/" + std::to_string(_denominator);
}

void Fraction::print() const {
    std::cout << "Дробь: " << to_string() << std::endl;
}

Fraction Fraction::add(const Fraction& _other) const {
    int _new_num = _numerator * _other._denominator + _other._numerator * _denominator;
    int _new_den = _denominator * _other._denominator;
    return Fraction(_new_num, _new_den);
}

Fraction Fraction::subtract(const Fraction& _other) const {
    int _new_num = _numerator * _other._denominator - _other._numerator * _denominator;
    int _new_den = _denominator * _other._denominator;
    return Fraction(_new_num, _new_den);
}

Fraction Fraction::multiply(const Fraction& _other) const {
    int _new_num = _numerator * _other._numerator;
    int _new_den = _denominator * _other._denominator;
    return Fraction(_new_num, _new_den);
}

Fraction Fraction::divide(const Fraction& _other) const {
    if (_other._numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    int _new_num = _numerator * _other._denominator;
    int _new_den = _denominator * _other._numerator;
    return Fraction(_new_num, _new_den);
}

Fraction Fraction::add(int _number) const {
    return add(Fraction(_number, 1));
}

Fraction Fraction::subtract(int _number) const {
    return subtract(Fraction(_number, 1));
}

Fraction Fraction::multiply(int _number) const {
    return multiply(Fraction(_number, 1));
}

Fraction Fraction::divide(int _number) const {
    return divide(Fraction(_number, 1));
}

Fraction Fraction::input_from_keyboard() {
    int _num = input_int("Введите числитель: ");
    int _denom;
    while (true) {
        _denom = input_int("Введите знаменатель (не 0): ");
        if (_denom != 0) break;
        std::cout << "Знаменатель не может быть нулём!\n";
    }
    return Fraction(_num, _denom);
}
