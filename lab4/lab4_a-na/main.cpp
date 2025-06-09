#include <iostream>
#include <vector>
#include <clocale>

#include "name.h"
#include "house.h"
#include "employee.h"
#include "department.h"
#include "fraction.h"
#include "utils.h"

int main() {
    setlocale(LC_ALL, "Russian");
    using namespace std;

    std::cout << "=== Лабораторная работа №3. Вариант 8 ===\n";

    std::vector<Employee*> employees;
    std::vector<Department*> departments;

    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Задание 1.3: ФИО\n";
        std::cout << "2. Задание 1.5: Дом\n";
        std::cout << "3. Задание 2.4: Сотрудники и отдел\n";
        std::cout << "4. Задание 3.4: Сотрудники и отдел (наследование)\n";
        std::cout << "5. Задание 4.5: Полное имя\n";
        std::cout << "6. Задание 5.5: Дробь\n";
        std::cout << "0. Выход\n";

        int _choice;
        while (true) {
            _choice = input_int("Введите команду (0-6): ");
            if (_choice >= 0 && _choice <= 6) break;
            std::cout << "Ошибка ввода. Пожалуйста, введите число от 0 до 6.\n";
        }

        switch (_choice) {
        case 1: {
            std::cout << "\n=== Задание 1.3: ФИО ===\n";
            Name _name = Name::input_from_keyboard();
            _name.print();
            break;
        }
        case 2: {
            std::cout << "\n=== Задание 1.5: Дом ===\n";
            House _house = House::input_from_keyboard();
            _house.print();
            break;
        }
        case 3: {
            std::cout << "\n=== Задание 2.4: Сотрудники и отдел ===\n";
            std::cout << "1. Добавить сотрудника\n";
            std::cout << "2. Создать отдел\n";
            std::cout << "3. Показать всех сотрудников\n";
            std::cout << "4. Показать все отделы\n";
            int _sub_choice;
            while (true) {
                _sub_choice = input_int("Введите действие (1-4): ");
                if (_sub_choice >= 1 && _sub_choice <= 4) break;
                std::cout << "Ошибка ввода. Пожалуйста, введите число от 1 до 4.\n";
            }

            if (_sub_choice == 1) {
                Employee* _emp = new Employee(Employee::input_from_keyboard());
                employees.push_back(_emp);
                std::cout << "Сотрудник добавлен.\n";
                _emp->print();
            }
            else if (_sub_choice == 2) {
                if (employees.empty()) {
                    std::cout << "Нет сотрудников для создания отдела. Пожалуйста, сначала добавьте сотрудников.\n";
                }
                else {
                    Department* _dept = new Department(Department::input_from_keyboard(employees));
                    departments.push_back(_dept);
                    std::cout << "Отдел создан.\n";
                    _dept->print();
                }
            }
            else if (_sub_choice == 3) {
                if (employees.empty()) {
                    std::cout << "Нет сотрудников для отображения.\n";
                }
                else {
                    std::cout << "Список сотрудников:\n";
                    for (const auto& _emp : employees) {
                        _emp->print();
                    }
                }
            }
            else if (_sub_choice == 4) {
                if (departments.empty()) {
                    std::cout << "Нет отделов для отображения.\n";
                }
                else {
                    std::cout << "Список отделов:\n";
                    for (const auto& _dept : departments) {
                        _dept->print();
                    }
                }
            }
            break;
        }
        case 4: {
            std::cout << "\n=== Задание 3.4: Сотрудники и отдел (наследование) ===\n";
            if (employees.empty()) {
                std::cout << "Нет сотрудников для создания отдела. Пожалуйста, сначала добавьте сотрудников.\n";
            }
            else {
                DepartmentEx* _dept = new DepartmentEx(DepartmentEx::input_from_keyboard(employees));
                departments.push_back(_dept);
                std::cout << "Наследованный отдел создан.\n";
                _dept->print();
            }
            break;
        }
        case 5: {
            std::cout << "\n=== Задание 4.5: Полное имя ===\n";
            Name _name = Name::input_from_keyboard();
            _name.print();
            break;
        }
        case 6: {
            std::cout << "\n=== Задание 5.5: Дробь ===\n";
            Fraction _f1 = Fraction::input_from_keyboard();
            Fraction _f2 = Fraction::input_from_keyboard();

            _f1.print();
            _f2.print();

            std::cout << "\nАрифметические операции:\n";
            std::cout << _f1.to_string() << " + " << _f2.to_string() << " = " << _f1.add(_f2).to_string() << std::endl;
            std::cout << _f1.to_string() << " - " << _f2.to_string() << " = " << _f1.subtract(_f2).to_string() << std::endl;
            std::cout << _f1.to_string() << " * " << _f2.to_string() << " = " << _f1.multiply(_f2).to_string() << std::endl;

            try {
                std::cout << _f1.to_string() << " / " << _f2.to_string() << " = " << _f1.divide(_f2).to_string() << std::endl;
            }
            catch (const std::invalid_argument& _e) {
                std::cout << "Ошибка: " << _e.what() << std::endl;
            }

            try {
                Fraction _result = _f1.add(_f2).divide(Fraction::input_from_keyboard()).subtract(5);
                std::cout << "\nРезультат сложной операции: " << _result.to_string() << std::endl;
            }
            catch (const std::invalid_argument& _e) {
                std::cout << "Ошибка при вычислении операции: " << _e.what() << std::endl;
            }
            break;
        }
        case 0: {
            // Очистка памяти
            for (auto _dept : departments) delete _dept;
            for (auto _emp : employees) delete _emp;
            return 0;
        }
        }
    }
}
