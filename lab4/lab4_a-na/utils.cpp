#include <iostream>
#include <limits>
#include <cctype>
#include <algorithm>
#include "utils.h"

int input_int(const std::string& _prompt, int _min, int _max) {
    int value;
    while (true) {
        std::cout << _prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
        }
        else if (value < _min || value > _max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Число должно быть в диапазоне от " << _min << " до " << _max << ". Попробуйте снова.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

std::string input_string(const std::string& _prompt, bool _allow_empty) {
    std::string value;
    while (true) {
        std::cout << _prompt;
        std::getline(std::cin, value);

        value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](int ch) {
            return !std::isspace(ch);
            }));
        value.erase(std::find_if(value.rbegin(), value.rend(), [](int ch) {
            return !std::isspace(ch);
            }).base(), value.end());

        if (!_allow_empty && value.empty()) {
            std::cout << "Ввод не может быть пустым. Пожалуйста, попробуйте снова.\n";
        }
        else {
            return value;
        }
    }
}

std::string input_name(const std::string& _prompt) {
    while (true) {
        std::string name = input_string(_prompt);
        bool valid = true;

        for (char c : name) {
            if (!std::isalpha(c) && c != '-' && c != ' ' && c != '\'') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            std::cout << "Имя может содержать только буквы, дефисы, апострофы и пробелы. Попробуйте снова.\n";
        }
        else {
            return name;
        }
    }
}