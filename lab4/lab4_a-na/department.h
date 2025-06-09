#pragma once
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include "employee.h"

class Department {
private:
    std::string _name;
    Employee* _head;
    std::vector<Employee*> _employees{};

public:
    Department(const std::string& _n, Employee* _h = nullptr);
    void set_head(Employee* _h);
    void add_employee(Employee* _emp);
    std::string get_name() const;
    Employee* get_head() const;
    const std::vector<Employee*>& get_employees() const;
    void print() const;
    static Department input_from_keyboard(std::vector<Employee*>& _all_employees);
};

class DepartmentEx : public Department {
public:
    using Department::Department;
    void print() const;
    static DepartmentEx input_from_keyboard(std::vector<Employee*>& _all_employees);
};

#endif
