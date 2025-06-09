#include <iostream>
#include "name.h"
#include "utils.h"

Name::Name() : _surname(""), _first_name(""), _patronymic("") {}

Name::Name(std::string _f_name) : _surname(""), _first_name(_f_name), _patronymic("") {}

Name::Name(std::string _f_name, std::string _s_name) :
    _surname(_s_name), _first_name(_f_name), _patronymic("") {
}

Name::Name(std::string _f_name, std::string _s_name, std::string _p_name) :
    _surname(_s_name), _first_name(_f_name), _patronymic(_p_name) {
}

std::string Name::to_string() const {
    std::string _result;
    if (!_surname.empty()) _result += _surname + " ";
    if (!_first_name.empty()) _result += _first_name + " ";
    if (!_patronymic.empty()) _result += _patronymic;

    if (!_result.empty() && _result.back() == ' ') {
        _result.pop_back();
    }
    return _result;
}

void Name::print() const {
    std::cout << "ФИО: " << to_string() << std::endl;
}

Name Name::input_from_keyboard() {
    std::cout << "\nВведите данные имени:\n";
    std::string _f_name = input_name("Введите имя: ");
    std::string _s_name = input_string("Фамилия (если нет - оставьте пустым): ", true);
    std::string _p_name = input_string("Отчество (если нет - оставьте пустым): ", true);

    if (_f_name.empty()) {
        std::cout << "Ошибка: поле имени не может быть пустым. Установлено значение 'Неизвестный'.\n";
        _f_name = "Неизвестный";
    }

    if (_s_name.empty() && _p_name.empty()) {
        return Name(_f_name);
    }
    else if (_p_name.empty()) {
        return Name(_f_name, _s_name);
    }
    else {
        return Name(_f_name, _s_name, _p_name);
    }
}
