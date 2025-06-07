#ifndef HOUSE_H
#define HOUSE_H

#include <string>
#include <iostream>

class House {
private:
    int _floors;

public:
    House(int f);
    std::string get_floor_ending() const;
    std::string to_string() const;
    void print() const;
};

#endif