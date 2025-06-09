#include <iostream>
#include <limits>
#include <cctype>
#include <algorithm>
#include "utils.h"

int input_int(const std::string& _prompt, int _min, int _max) {
    int _value;
    while (true) {
        std::cout << _prompt;
        std::cin >> _value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
        }
        else if (_value < _min || _value > _max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Число должно быть в диапазоне от " << _min << " до " << _max << ". Попробуйте снова.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return _value;
        }
    }
}

std::string input_string(const std::string& _prompt, bool _allow_empty) {
    std::string _value;
    while (true) {
        std::cout << _prompt;
        std::getline(std::cin, _value);

        // Удаление начальных и конечных пробелов
        _value.erase(_value.begin(), std::find_if(_value.begin(), _value.end(), [](int ch) {
            return !std::isspace(ch);
            }));
        _value.erase(std::find_if(_value.rbegin(), _value.rend(), [](int ch) {
            return !std::isspace(ch);
            }).base(), _value.end());

        if (!_allow_empty && _value.empty()) {
            std::cout << "Поле не может быть пустым. Пожалуйста, введите текст.\n";
        }
        else {
            return _value;
        }
    }
}

std::string input_name(const std::string& _prompt) {
    while (true) {
        std::string _name = input_string(_prompt, false);
        bool _valid = true;

        for (char _c : _name) {
            if (!std::isalpha(_c) && _c != '-' && _c != ' ' && _c != '\'') {
                _valid = false;
                break;
            }
        }

        if (!_valid) {
            std::cout << "Имя может содержать только буквы, дефисы, пробелы и апострофы. Попробуйте снова.\n";
        }
        else {
            return _name;
        }
    }
}
