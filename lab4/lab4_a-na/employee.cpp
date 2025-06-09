#include <iostream>
#include "employee.h"
#include "department.h"
#include "utils.h"

Employee::Employee(const std::string& _n) : _name(_n), _department(nullptr) {}

std::string Employee::to_string() const {
    if (_department && _department->get_head() == this) {
        return _name + " (начальник отдела " + _department->get_name() + ")";
    }
    else if (_department) {
        return _name + " (работает в отделе " + _department->get_name() + 
               ", начальник " + _department->get_head()->get_name() + ")";
    }
    return _name + " (без отдела)";
}

void Employee::set_department(Department* _dept) {
    _department = _dept;
}

std::string Employee::get_name() const {
    return _name;
}

Department* Employee::get_department() const {
    return _department;
}

void Employee::print() const {
    std::cout << to_string() << std::endl;
}

Employee Employee::input_from_keyboard() {
    std::string _name;
    while (true) {
        _name = input_string("Введите имя сотрудника: ");
        if (!_name.empty()) break;
        std::cout << "Имя сотрудника не может быть пустым!\n";
    }
    return Employee(_name);
}
