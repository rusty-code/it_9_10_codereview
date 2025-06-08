#include <iostream>

#include "name.h"
#include "utils.h"

Name::Name() : _surname(""), _first_name(""), _patronymic("") {}

Name::Name(std::string f_name) : _surname(""), _first_name(f_name), _patronymic("") {}

Name::Name(std::string f_name, std::string s_name) :
    _surname(s_name), _first_name(f_name), _patronymic("") {
}

Name::Name(std::string f_name, std::string s_name, std::string p_name) :
    _surname(s_name), _first_name(f_name), _patronymic(p_name) {
}

std::string Name::to_string() const {
    std::string result;
    if (!_surname.empty()) result += _surname + " ";
    if (!_first_name.empty()) result += _first_name + " ";
    if (!_patronymic.empty()) result += _patronymic;

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
}

void Name::print() const {
    std::cout << "Имя: " << to_string() << std::endl;
}

Name Name::input_from_keyboard() {
    std::cout << "\nВведите данные имени:\n";
    std::string f_name = input_name("Личное имя: ");
    std::string s_name = input_string("Фамилия (если нет - оставьте пустым): ", true);
    std::string p_name = input_string("Отчество (если нет - оставьте пустым): ", true);

    if (f_name.empty()) {
        std::cout << "Ошибка: личное имя не может быть пустым. Установлено значение 'Неизвестно'.\n";
        f_name = "Неизвестно";
    }

    if (s_name.empty() && p_name.empty()) {
        return Name(f_name);
    }
    else if (p_name.empty()) {
        return Name(f_name, s_name);
    }
    else {
        return Name(f_name, s_name, p_name);
    }
}