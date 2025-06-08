#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "departament.h"
#include "employee.h"

// FIXME: параметр
Department::Department(const std::string& name)
    : _name(name), _head(nullptr) {
}

// FIXME: параметр
void Department::set_head(Employee* new_head) {
    if (new_head) {
        if (_head) {
            auto it = std::find(_employees.begin(), _employees.end(), _head);
            if (it != _employees.end()) {
                _employees.erase(it);
            }
        }
        _head = new_head;
        add_employee(new_head);
    }
}

// FIXME: параметр
void Department::add_employee(Employee* employee) {
    if (std::find(_employees.begin(), _employees.end(), employee) == _employees.end()) {
        _employees.push_back(employee);
        employee->set_department(this);
    }
}

Employee* Department::get_head() const {
    return _head;
}

std::string Department::get_name() const {
    return _name;
}

const std::vector<Employee*>& Department::get_employees() const {
    return _employees;
}

void Department::print_employees() const {
    std::cout << "\n      " << _name << ":\n";
    if (_head) {
        std::cout << "         : " << _head->get_name() << "\n";
    }
    std::cout << "           (" << _employees.size() << "):\n";
    for (const auto& emp : _employees) {
        if (emp != _head) {
            std::cout << " - " << emp->get_name() << "\n";
        }
    }
}