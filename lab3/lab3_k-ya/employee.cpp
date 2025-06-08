#include <iostream>
#include <string>

#include "departament.h"
#include "employee.h"
// FIXME: параметр
Employee::Employee(const std::string& name) : _name(name), _department(nullptr) {}
// FIXME: параметр
void Employee::set_department(Department* dept) {
    _department = dept;
}

std::string Employee::get_name() const {
    return _name;
}

Department* Employee::get_department() const {
    return _department;
}

std::string Employee::to_string() const {
    if (_department == nullptr) {
        return _name + " (�� �������� � �����)";
    }

    std::string result = _name + " �������� � ������ " + _department->get_name();

    if (_department->get_head() == this) {
        result += " (��������� ������)";
    }
    else if (_department->get_head()) {
        result += ", ��������� �������� " + _department->get_head()->get_name();
    }

    return result;
}

void Employee::print() const {
    std::cout << to_string() << std::endl;
}