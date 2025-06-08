

#include "house.h"
#include "utils.h"
#include <iostream>
#include <string>

House::House(int _f) : _floors(_f) {}

std::string House::to_string() const {
    std::string ending;
    if (_floors % 100 >= 11 && _floors % 100 <= 19) {
        ending = "��";
    }
    else {
        switch (_floors % 10) {
        case 1: ending = ""; break;
        case 2:
        case 3:
        case 4: ending = "�"; break;
        default: ending = "��"; break;
        }
    }
    return "��� � " + std::to_string(_floors) + " ����" + ending;
}

void House::print() const {
    std::cout << to_string() << std::endl;
}

House House::input_from_keyboard() {
    int _floors;
    while (true) {
        _floors = input_int("������� ���������� ������: ");
        if (_floors > 0) break;
        std::cout << "���������� ������ ������ ���� ������������� ������!\n";
    }
    return House(_floors);
}