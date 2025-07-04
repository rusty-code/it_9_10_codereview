#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <algorithm>
#include <string>
#include <vector>

class Employee;

class Department {
private:
    std::string _name;
    Employee* _head;
    std::vector<Employee*> _employees;

public:
    // FIXME: параметр
    Department(const std::string& name);
    // FIXME: параметр
    void set_head(Employee* new_head);
    // FIXME: параметр
    void add_employee(Employee* employee);
    // FIXME: параметр
    Employee* get_head() const;
    std::string get_name() const;
    const std::vector<Employee*>& get_employees() const;
    void print_employees() const;
};

#endif