#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Department;

class Employee {
private:
    std::string _name;
    Department* _department;

public:
// FIXME: параметр
    Employee(const std::string& name);
    // FIXME: параметр
    void set_department(Department* dept);
    std::string get_name() const;
    Department* get_department() const;
    std::string to_string() const;
    void print() const;
};

#endif