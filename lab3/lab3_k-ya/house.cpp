#include <iostream>
#include <string>

#include "house.h"

House::House(int f) : _floors(f) {
    if (_floors < 1) {
        throw std::invalid_argument("Number of floors must be positive");
    }
}

std::string House::get_floor_ending() const {
    if (_floors % 100 >= 11 && _floors % 100 <= 14) {
        return "этажей";
    }
    switch (_floors % 10) {
    case 1: return "этаж";
    case 2:
    case 3:
    case 4: return "этажа";
    default: return "этажей";
    }
}

std::string House::to_string() const {
    return "ƒом, в котором " + std::to_string(_floors) + " " + get_floor_ending();
}

void House::print() const {
    std::cout << to_string() << std::endl;
}