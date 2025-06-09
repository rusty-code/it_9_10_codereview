#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <string>

class Fraction {
private:
    int _numerator;
    int _denominator;
    void simplify();

public:
    Fraction(int _num, int _denom);
    std::string to_string() const;
    void print() const;
    Fraction add(const Fraction& _other) const;
    Fraction subtract(const Fraction& _other) const;
    Fraction multiply(const Fraction& _other) const;
    Fraction divide(const Fraction& _other) const;
    Fraction add(int _number) const;
    Fraction subtract(int _number) const;
    Fraction multiply(int _number) const;
    Fraction divide(int _number) const;
    
    static Fraction input_from_keyboard();
};

#endif // FRACTION_H
