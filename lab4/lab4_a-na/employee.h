#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Department; // Forward declaration

/* FIXME:
     ласс Employee представл€ет сотрудника с возможностью
    прив€зки к отделу и назначени€ начальником
*/
class Employee {
private:
    std::string _name;
    Department* _department;

public:
    Employee(const std::string& _n);
    std::string to_string() const;
    void set_department(Department* _dept);
    std::string get_name() const;
    Department* get_department() const;
    void print() const;
    static Employee input_from_keyboard();
};

#endif // EMPLOYEE_H