#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include <string>

class House {
private:
    const int _floors;

public:
    House(int f);
    std::string to_string() const;
    void print() const;
    static House input_from_keyboard();
};

#endif // HOUSE_H