#include <iostream>
#include <string>

#include "departament.h"
#include "employee.h"

Employee::Employee(const std::string& name) : _name(name), _department(nullptr) {}

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
        return _name + " (не назначен в отдел)";
    }

    std::string result = _name + " работает в отделе " + _department->get_name();

    if (_department->get_head() == this) {
        result += " (начальник отдела)";
    }
    else if (_department->get_head()) {
        result += ", начальник которого " + _department->get_head()->get_name();
    }

    return result;
}

void Employee::print() const {
    std::cout << to_string() << std::endl;
}