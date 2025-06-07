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
    std::cout << "\n������� ����\n"
        << "1. ������ � ������\n"
        << "2. ������ � �������\n"
        << "3. ���������� ������������ � ��������\n"
        << "4. ������ � �������\n"
        << "0. �����\n"
        << "�������� �����: ";
}

void manage_houses() {
    std::vector<House> houses;
    int choice;

    do {
        std::cout << "\n������ � ������\n"
            << "1. �������� ��� ����\n"
            << "2. �������� ����� ���\n"
            << "0. �����\n"
            << "�������� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "\n������ �����:\n";
            for (const auto& house : houses) {
                house.print();
            }
            break;
        }
        case 2: {
            int floors;
            std::cout << "������� ���������� ������: ";
            std::cin >> floors;
            houses.emplace_back(floors);
            std::cout << "��� ������� ��������!\n";
            break;
        }
        }
    } while (choice != 0);
}

void work_with_fractions() {
    try {
        std::cout << "\n������ � �������\n";

        Fraction f1, f2, f3;
        int whole_number;

        std::cout << "������� ������ ����� (������ a/b): ";
        std::cin >> f1;
        std::cout << "������� ������ ����� (������ a/b): ";
        std::cin >> f2;
        std::cout << "������� ������ ����� (������ a/b) ��� ����������� ��������: ";
        std::cin >> f3;
        std::cout << "������� ����� ����� ��� ���������: ";
        std::cin >> whole_number;

        Fraction sum_result = f1 + f2;
        Fraction sub_result = f1 - f2;
        Fraction mult_result = f1 * f2;
        Fraction div_result = f1 / f2;
        Fraction complex_result = (f1 + f2) / f3 - whole_number;

        std::cout << "\n����������\n";
        std::cout << f1 << " + " << f2 << " = " << sum_result << "\n";
        std::cout << f1 << " - " << f2 << " = " << sub_result << "\n";
        std::cout << f1 << " * " << f2 << " = " << mult_result << "\n";
        std::cout << f1 << " / " << f2 << " = " << div_result << "\n";
        std::cout << "(" << f1 << " + " << f2 << ") / " << f3 << " - "
            << whole_number << " = " << complex_result << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << "\n";
        std::cin.clear();
    }
}

void print_department_employees(const Employee* emp) {
    if (emp == nullptr) {
        std::cout << "��������� �� ����������!\n";
        return;
    }

    Department* dept = emp->get_department();
    if (dept == nullptr) {
        std::cout << emp->get_name() << " �� ����������� �� � ������ ������.\n";
        return;
    }

    std::cout << "\n���������� ������ " << dept->get_name() << ":\n";
    if (dept->get_head()) {
        std::cout << "���������: " << dept->get_head()->get_name() << "\n";
    }

    const auto& employees = dept->get_employees();
    std::cout << "����� �����������: " << employees.size() << "\n";
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
        std::cout << "\n���������� ������������\n"
            << "1. �������� ������ ����������\n"
            << "2. ��������� ���������� ������\n"
            << "3. �������� ���������� � �����\n"
            << "4. �������� ���� �����������\n"
            << "5. �������� ����������� ������\n"
            << "6. �������� ����������� ������ �� ������ �� ����������\n"
            << "0. �����\n"
            << "�������� �����: ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        switch (choice) {
        case 1: {
            std::string surname;
            std::cout << "������� ������� ����������: ";
            std::getline(std::cin, surname);

            if (surname.empty()) {
                std::cout << "������� �� ����� ���� ������!\n";
                break;
            }

            employees.emplace_back(std::make_unique<Employee>(surname));
            std::cout << "��������� " << surname << " ������.\n";
            break;
        }
        case 2: {
            if (employees.empty()) {
                std::cout << "��� ����������� ��� ����������!\n";
                break;
            }

            std::cout << "������ �����������:\n";
            for (size_t i = 0; i < employees.size(); ++i) {
                std::cout << i + 1 << ". " << employees[i]->get_name() << "\n";
            }

            int num;
            std::cout << "�������� ����� ���������� ��� ���������� �����������: ";
            std::cin >> num;

            if (num > 0 && num <= static_cast<int>(employees.size())) {
                it.set_head(employees[num - 1].get());
                std::cout << employees[num - 1]->get_name()
                    << " �������� ����������� ������ IT.\n";
            }
            else {
                std::cout << "�������� �����!\n";
            }
            break;
        }
        case 3: {
            if (employees.empty()) {
                std::cout << "��� ����������� ��� ����������!\n";
                break;
            }

            std::cout << "������ �����������:\n";
            for (size_t i = 0; i < employees.size(); ++i) {
                std::cout << i + 1 << ". " << employees[i]->get_name();
                if (employees[i]->get_department()) {
                    std::cout << " (��� � ������ "
                        << employees[i]->get_department()->get_name() << ")";
                }
                std::cout << "\n";
            }

            int num;
            std::cout << "�������� ����� ���������� ��� ���������� � �����: ";
            std::cin >> num;

            if (num > 0 && num <= static_cast<int>(employees.size())) {
                it.add_employee(employees[num - 1].get());
                std::cout << employees[num - 1]->get_name()
                    << " �������� � ����� IT.\n";
            }
            else {
                std::cout << "�������� �����!\n";
            }
            break;
        }
        case 4:
            std::cout << "\n��� ����������:\n";
            for (const auto& emp : employees) {
                emp->print();
            }
            break;
        case 5:
            it.print_employees();
            break;
        case 6: {
            if (employees.empty()) {
                std::cout << "��� �����������!\n";
                break;
            }

            std::cout << "������ �����������:\n";
            for (size_t i = 0; i < employees.size(); ++i) {
                std::cout << i + 1 << ". " << employees[i]->get_name() << "\n";
            }

            int num;
            std::cout << "�������� ����� ���������� ��� ��������� ��� ������: ";
            std::cin >> num;

            if (num > 0 && num <= static_cast<int>(employees.size())) {
                print_department_employees(employees[num - 1].get());
            }
            else {
                std::cout << "�������� �����!\n";
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
        std::cout << "\n������ � �������\n"
            << "1. �������� ��� �����\n"
            << "2. �������� ����� ���\n"
            << "0. �����\n"
            << "�������� �����: ";
        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        switch (choice) {
        case 1:
            std::cout << "\n������ ����:\n";
            for (const auto& name : names) {
                std::cout << name.to_string() << "\n";
            }
            break;
        case 2: {
            std::string last, first, middle;
            std::cout << "������� ������� (����� ����������): ";
            std::getline(std::cin, last);
            std::cout << "������� ��� (����� ����������): ";
            std::getline(std::cin, first);
            std::cout << "������� �������� (����� ����������): ";
            std::getline(std::cin, middle);

            if (last.empty() && first.empty() && middle.empty()) {
                std::cout << "���� �� ���� ����� ����� ������ ���� �������!\n";
            }
            else {
                names.emplace_back(last, first, middle);
                std::cout << "��� ������� ���������: "
                    << names.back().to_string() << "\n";
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "�������� �����!\n";
        }
    } while (choice != 0);
}