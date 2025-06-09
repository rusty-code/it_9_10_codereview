#include "department.h"
#include "employee.h"
#include "utils.h"
#include <iostream>

Department::Department(const std::string& _n, Employee* _h) : _name(_n), _head(_h) {}

void Department::set_head(Employee* _h) {
    _head = _h;
    if (_h) {
        _h->set_department(this);
    }
}

void Department::add_employee(Employee* _emp) {
    _employees.push_back(_emp);
    _emp->set_department(this);
}

std::string Department::get_name() const {
    return _name;
}

Employee* Department::get_head() const {
    return _head;
}

const std::vector<Employee*>& Department::get_employees() const {
    return _employees;
}

void Department::print() const {
    std::cout << "Отдел: " << _name << std::endl;
    if (_head) {
        std::cout << "Начальник: " << _head->get_name() << std::endl;
    }
    std::cout << "Сотрудники (" << _employees.size() << "):\n";
    for (const auto& _emp : _employees) {
        std::cout << "- " << _emp->get_name() << std::endl;
    }
}

Department Department::input_from_keyboard(std::vector<Employee*>& _all_employees) {
    std::string _name;
    while (true) {
        _name = input_string("Введите название отдела: ");
        if (!_name.empty()) break;
        std::cout << "Название отдела не может быть пустым!\n";
    }

    Department _dept(_name);

    if (!_all_employees.empty()) {
        std::cout << "Выберите начальника отдела:\n";
        for (size_t _i = 0; _i < _all_employees.size(); ++_i) {
            std::cout << _i + 1 << ". " << _all_employees[_i]->get_name() << std::endl;
        }
        int _choice;
        while (true) {
            _choice = input_int("Номер начальника (0 - без начальника): ");
            if (_choice >= 0 && _choice <= static_cast<int>(_all_employees.size())) break;
            std::cout << "Неверный номер сотрудника!\n";
        }
        if (_choice > 0 && _choice <= static_cast<int>(_all_employees.size())) {
            _dept.set_head(_all_employees[_choice - 1]);
        }
    }

    return _dept;
}

void DepartmentEx::print() const {
    Department::print();
    std::cout << "(Расширенная версия отдела)\n";
}

DepartmentEx DepartmentEx::input_from_keyboard(std::vector<Employee*>& _all_employees) {
    Department _base_dept = Department::input_from_keyboard(_all_employees);
    return DepartmentEx(_base_dept.get_name(), _base_dept.get_head());
}
