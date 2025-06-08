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
        std::cout << "1. Задание 1.3: Имя\n";
        std::cout << "2. Задание 1.5: Дом\n";
        std::cout << "3. Задание 2.4: Сотрудники и отделы\n";
        std::cout << "4. Задание 3.4: Сотрудники и отделы (расширенная)\n";
        std::cout << "5. Задание 4.5: Создаем Имена\n";
        std::cout << "6. Задание 5.5: Дроби\n";
        std::cout << "0. Выход\n";

        int choice;
        while (true) {
            choice = input_int("Выберите задание (0-6): ");
            if (choice >= 0 && choice <= 6) break;
            std::cout << "Неверный выбор. Введите число от 0 до 6.\n";
        }

        switch (choice) {
        case 1: {
            std::cout << "\n=== Задание 1.3: Имя ===\n";
            Name name = Name::input_from_keyboard();
            name.print();
            break;
        }
        case 2: {
            std::cout << "\n=== Задание 1.5: Дом ===\n";
            House house = House::input_from_keyboard();
            house.print();
            break;
        }
        case 3: {
            std::cout << "\n=== Задание 2.4: Сотрудники и отделы ===\n";
            std::cout << "1. Добавить сотрудника\n";
            std::cout << "2. Создать отдел\n";
            std::cout << "3. Показать всех сотрудников\n";
            std::cout << "4. Показать все отделы\n";
            int sub_choice;
            while (true) {
                sub_choice = input_int("Выберите действие (1-4): ");
                if (sub_choice >= 1 && sub_choice <= 4) break;
                std::cout << "Неверный выбор. Введите число от 1 до 4.\n";
            }

            if (sub_choice == 1) {
                Employee* emp = new Employee(Employee::input_from_keyboard());
                employees.push_back(emp);
                std::cout << "Сотрудник добавлен.\n";
                emp->print();
            }
            else if (sub_choice == 2) {
                if (employees.empty()) {
                    std::cout << "Нет сотрудников для создания отдела. Сначала добавьте сотрудников.\n";
                }
                else {
                    Department* dept = new Department(Department::input_from_keyboard(employees));
                    departments.push_back(dept);
                    std::cout << "Отдел создан.\n";
                    dept->print();
                }
            }
            else if (sub_choice == 3) {
                if (employees.empty()) {
                    std::cout << "Нет сотрудников для отображения.\n";
                }
                else {
                    std::cout << "Список сотрудников:\n";
                    for (const auto& emp : employees) {
                        emp->print();
                    }
                }
            }
            else if (sub_choice == 4) {
                if (departments.empty()) {
                    std::cout << "Нет отделов для отображения.\n";
                }
                else {
                    std::cout << "Список отделов:\n";
                    for (const auto& dept : departments) {
                        dept->print();
                    }
                }
            }
            break;
        }
        case 4: {
            std::cout << "\n=== Задание 3.4: Сотрудники и отделы (расширенная) ===\n";
            if (employees.empty()) {
                std::cout << "Нет сотрудников для создания отдела. Сначала добавьте сотрудников.\n";
            }
            else {
                DepartmentEx* dept = new DepartmentEx(DepartmentEx::input_from_keyboard(employees));
                departments.push_back(dept);
                std::cout << "Расширенный отдел создан.\n";
                dept->print();
            }
            break;
        }
        case 5: {
            std::cout << "\n=== Задание 4.5: Создаем Имена ===\n";
            Name name = Name::input_from_keyboard();
            name.print();
            break;
        }
        case 6: {
            std::cout << "\n=== Задание 5.5: Дроби ===\n";
            Fraction f1 = Fraction::input_from_keyboard();
            Fraction f2 = Fraction::input_from_keyboard();

            f1.print();
            f2.print();

            std::cout << "\nРезультаты операций:\n";
            std::cout << f1.to_string() << " + " << f2.to_string() << " = " << f1.add(f2).to_string() << std::endl;
            std::cout << f1.to_string() << " - " << f2.to_string() << " = " << f1.subtract(f2).to_string() << std::endl;
            std::cout << f1.to_string() << " * " << f2.to_string() << " = " << f1.multiply(f2).to_string() << std::endl;

            try {
                std::cout << f1.to_string() << " / " << f2.to_string() << " = " << f1.divide(f2).to_string() << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }

            try {
                Fraction result = f1.add(f2).divide(Fraction::input_from_keyboard()).subtract(5);
                std::cout << "\nРезультат цепочки операций: " << result.to_string() << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Ошибка при выполнении операций: " << e.what() << std::endl;
            }
            break;
        }
        case 0: {
            // Очистка памяти
            for (auto dept : departments) delete dept;
            for (auto emp : employees) delete emp;
            return 0;
        }
        }
    }
}