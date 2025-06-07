#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#include "departament.h"
#include "employee.h"
#include "fraction.h"
#include "house.h"
#include "menu.h"
#include "name.h"

void display_main_menu() {
    std::cout << "\nГЛАВНОЕ МЕНЮ\n"
        << "1. Работа с домами\n"
        << "2. Работа с дробями\n"
        << "3. Управление сотрудниками и отделами\n"
        << "4. Работа с именами\n"
        << "0. Выход\n"
        << "Выберите пункт: ";
}

void manage_houses() {
    std::vector<House> houses;
    int choice;

    do {
        std::cout << "\nРАБОТА С ДОМАМИ\n"
            << "1. Показать все дома\n"
            << "2. Добавить новый дом\n"
            << "0. Назад\n"
            << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "\nСписок домов:\n";
            for (const auto& house : houses) {
                house.print();
            }
            break;
        }
        case 2: {
            int floors;
            std::cout << "Введите количество этажей: ";
            std::cin >> floors;
            houses.emplace_back(floors);
            std::cout << "Дом успешно добавлен!\n";
            break;
        }
        }
    } while (choice != 0);
}

void work_with_fractions() {
    try {
        std::cout << "\nРАБОТА С ДРОБЯМИ\n";

        Fraction f1, f2, f3;
        int whole_number;

        std::cout << "Введите первую дробь (формат a/b): ";
        std::cin >> f1;
        std::cout << "Введите вторую дробь (формат a/b): ";
        std::cin >> f2;
        std::cout << "Введите третью дробь (формат a/b) для комплексной операции: ";
        std::cin >> f3;
        std::cout << "Введите целое число для вычитания: ";
        std::cin >> whole_number;

        Fraction sum_result = f1 + f2;
        Fraction sub_result = f1 - f2;
        Fraction mult_result = f1 * f2;
        Fraction div_result = f1 / f2;
        Fraction complex_result = (f1 + f2) / f3 - whole_number;

        std::cout << "\nРЕЗУЛЬТАТЫ\n";
        std::cout << f1 << " + " << f2 << " = " << sum_result << "\n";
        std::cout << f1 << " - " << f2 << " = " << sub_result << "\n";
        std::cout << f1 << " * " << f2 << " = " << mult_result << "\n";
        std::cout << f1 << " / " << f2 << " = " << div_result << "\n";
        std::cout << "(" << f1 << " + " << f2 << ") / " << f3 << " - "
            << whole_number << " = " << complex_result << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
        std::cin.clear();
    }
}

void print_department_employees(const Employee* emp) {
    if (emp == nullptr) {
        std::cout << "Сотрудник не существует!\n";
        return;
    }

    Department* dept = emp->get_department();
    if (dept == nullptr) {
        std::cout << emp->get_name() << " не принадлежит ни к какому отделу.\n";
        return;
    }

    std::cout << "\nСотрудники отдела " << dept->get_name() << ":\n";
    if (dept->get_head()) {
        std::cout << "Начальник: " << dept->get_head()->get_name() << "\n";
    }

    const auto& employees = dept->get_employees();
    std::cout << "Всего сотрудников: " << employees.size() << "\n";
    for (const auto& e : employees) {
        if (e != dept->get_head()) {
            std::cout << " - " << e->get_name() << "\n";
        }
    }
}

void manage_employees() {
    std::vector<std::unique_ptr<Employee>> employees;
    Department it("IT");

    int choice;
    do {
        std::cout << "\nУПРАВЛЕНИЕ СОТРУДНИКАМИ\n"
            << "1. Добавить нового сотрудника\n"
            << "2. Назначить начальника отдела\n"
            << "3. Добавить сотрудника в отдел\n"
            << "4. Показать всех сотрудников\n"
            << "5. Показать сотрудников отдела\n"
            << "6. Показать сотрудников отдела по ссылке на сотрудника\n"
            << "0. Назад\n"
            << "Выберите пункт: ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        switch (choice) {
        case 1: {
            std::string surname;
            std::cout << "Введите фамилию сотрудника: ";
            std::getline(std::cin, surname);

            if (surname.empty()) {
                std::cout << "Фамилия не может быть пустой!\n";
                break;
            }

            employees.emplace_back(std::make_unique<Employee>(surname));
            std::cout << "Сотрудник " << surname << " создан.\n";
            break;
        }
        case 2: {
            if (employees.empty()) {
                std::cout << "Нет сотрудников для назначения!\n";
                break;
            }

            std::cout << "Список сотрудников:\n";
            for (size_t i = 0; i < employees.size(); ++i) {
                std::cout << i + 1 << ". " << employees[i]->get_name() << "\n";
            }

            int num;
            std::cout << "Выберите номер сотрудника для назначения начальником: ";
            std::cin >> num;

            if (num > 0 && num <= static_cast<int>(employees.size())) {
                it.set_head(employees[num - 1].get());
                std::cout << employees[num - 1]->get_name()
                    << " назначен начальником отдела IT.\n";
            }
            else {
                std::cout << "Неверный номер!\n";
            }
            break;
        }
        case 3: {
            if (employees.empty()) {
                std::cout << "Нет сотрудников для добавления!\n";
                break;
            }

            std::cout << "Список сотрудников:\n";
            for (size_t i = 0; i < employees.size(); ++i) {
                std::cout << i + 1 << ". " << employees[i]->get_name();
                if (employees[i]->get_department()) {
                    std::cout << " (уже в отделе "
                        << employees[i]->get_department()->get_name() << ")";
                }
                std::cout << "\n";
            }

            int num;
            std::cout << "Выберите номер сотрудника для добавления в отдел: ";
            std::cin >> num;

            if (num > 0 && num <= static_cast<int>(employees.size())) {
                it.add_employee(employees[num - 1].get());
                std::cout << employees[num - 1]->get_name()
                    << " добавлен в отдел IT.\n";
            }
            else {
                std::cout << "Неверный номер!\n";
            }
            break;
        }
        case 4:
            std::cout << "\nВсе сотрудники:\n";
            for (const auto& emp : employees) {
                emp->print();
            }
            break;
        case 5:
            it.print_employees();
            break;
        case 6: {
            if (employees.empty()) {
                std::cout << "Нет сотрудников!\n";
                break;
            }

            std::cout << "Список сотрудников:\n";
            for (size_t i = 0; i < employees.size(); ++i) {
                std::cout << i + 1 << ". " << employees[i]->get_name() << "\n";
            }

            int num;
            std::cout << "Выберите номер сотрудника для просмотра его отдела: ";
            std::cin >> num;

            if (num > 0 && num <= static_cast<int>(employees.size())) {
                print_department_employees(employees[num - 1].get());
            }
            else {
                std::cout << "Неверный номер!\n";
            }
            break;
        }
        }
    } while (choice != 0);
}

void work_with_names() {
    std::vector<Name> names;
    int choice;

    do {
        std::cout << "\nРАБОТА С ИМЕНАМИ\n"
            << "1. Показать все имена\n"
            << "2. Добавить новое имя\n"
            << "0. Назад\n"
            << "Выберите пункт: ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        switch (choice) {
        case 1:
            std::cout << "\nСписок имен:\n";
            for (const auto& name : names) {
                std::cout << name.to_string() << "\n";
            }
            break;
        case 2: {
            std::string last, first, middle;
            std::cout << "Введите фамилию (можно пропустить): ";
            std::getline(std::cin, last);
            std::cout << "Введите имя (можно пропустить): ";
            std::getline(std::cin, first);
            std::cout << "Введите отчество (можно пропустить): ";
            std::getline(std::cin, middle);

            if (last.empty() && first.empty() && middle.empty()) {
                std::cout << "Хотя бы одна часть имени должна быть указана!\n";
            }
            else {
                names.emplace_back(last, first, middle);
                std::cout << "Имя успешно добавлено: "
                    << names.back().to_string() << "\n";
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != 0);
}