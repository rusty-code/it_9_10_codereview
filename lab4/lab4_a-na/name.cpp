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
    std::cout << "���: " << to_string() << std::endl;
}

Name Name::input_from_keyboard() {
    std::cout << "\n������� ������ �����:\n";
    std::string f_name = input_name("������ ���: ");
    std::string s_name = input_string("������� (���� ��� - �������� ������): ", true);
    std::string p_name = input_string("�������� (���� ��� - �������� ������): ", true);

    if (f_name.empty()) {
        std::cout << "������: ������ ��� �� ����� ���� ������. ����������� �������� '����������'.\n";
        f_name = "����������";
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