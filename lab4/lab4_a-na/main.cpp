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

    std::cout << "=== ������������ ������ �3. ������� 8 ===\n";

    std::vector<Employee*> employees;
    std::vector<Department*> departments;

    while (true) {
        std::cout << "\n����:\n";
        std::cout << "1. ������� 1.3: ���\n";
        std::cout << "2. ������� 1.5: ���\n";
        std::cout << "3. ������� 2.4: ���������� � ������\n";
        std::cout << "4. ������� 3.4: ���������� � ������ (�����������)\n";
        std::cout << "5. ������� 4.5: ������� �����\n";
        std::cout << "6. ������� 5.5: �����\n";
        std::cout << "0. �����\n";

        int choice;
        while (true) {
            choice = input_int("�������� ������� (0-6): ");
            if (choice >= 0 && choice <= 6) break;
            std::cout << "�������� �����. ������� ����� �� 0 �� 6.\n";
        }

        switch (choice) {
        case 1: {
            std::cout << "\n=== ������� 1.3: ��� ===\n";
            Name name = Name::input_from_keyboard();
            name.print();
            break;
        }
        case 2: {
            std::cout << "\n=== ������� 1.5: ��� ===\n";
            House house = House::input_from_keyboard();
            house.print();
            break;
        }
        case 3: {
            std::cout << "\n=== ������� 2.4: ���������� � ������ ===\n";
            std::cout << "1. �������� ����������\n";
            std::cout << "2. ������� �����\n";
            std::cout << "3. �������� ���� �����������\n";
            std::cout << "4. �������� ��� ������\n";
            int sub_choice;
            while (true) {
                sub_choice = input_int("�������� �������� (1-4): ");
                if (sub_choice >= 1 && sub_choice <= 4) break;
                std::cout << "�������� �����. ������� ����� �� 1 �� 4.\n";
            }

            if (sub_choice == 1) {
                Employee* emp = new Employee(Employee::input_from_keyboard());
                employees.push_back(emp);
                std::cout << "��������� ��������.\n";
                emp->print();
            }
            else if (sub_choice == 2) {
                if (employees.empty()) {
                    std::cout << "��� ����������� ��� �������� ������. ������� �������� �����������.\n";
                }
                else {
                    Department* dept = new Department(Department::input_from_keyboard(employees));
                    departments.push_back(dept);
                    std::cout << "����� ������.\n";
                    dept->print();
                }
            }
            else if (sub_choice == 3) {
                if (employees.empty()) {
                    std::cout << "��� ����������� ��� �����������.\n";
                }
                else {
                    std::cout << "������ �����������:\n";
                    for (const auto& emp : employees) {
                        emp->print();
                    }
                }
            }
            else if (sub_choice == 4) {
                if (departments.empty()) {
                    std::cout << "��� ������� ��� �����������.\n";
                }
                else {
                    std::cout << "������ �������:\n";
                    for (const auto& dept : departments) {
                        dept->print();
                    }
                }
            }
            break;
        }
        case 4: {
            std::cout << "\n=== ������� 3.4: ���������� � ������ (�����������) ===\n";
            if (employees.empty()) {
                std::cout << "��� ����������� ��� �������� ������. ������� �������� �����������.\n";
            }
            else {
                DepartmentEx* dept = new DepartmentEx(DepartmentEx::input_from_keyboard(employees));
                departments.push_back(dept);
                std::cout << "����������� ����� ������.\n";
                dept->print();
            }
            break;
        }
        case 5: {
            std::cout << "\n=== ������� 4.5: ������� ����� ===\n";
            Name name = Name::input_from_keyboard();
            name.print();
            break;
        }
        case 6: {
            std::cout << "\n=== ������� 5.5: ����� ===\n";
            Fraction f1 = Fraction::input_from_keyboard();
            Fraction f2 = Fraction::input_from_keyboard();

            f1.print();
            f2.print();

            std::cout << "\n���������� ��������:\n";
            std::cout << f1.to_string() << " + " << f2.to_string() << " = " << f1.add(f2).to_string() << std::endl;
            std::cout << f1.to_string() << " - " << f2.to_string() << " = " << f1.subtract(f2).to_string() << std::endl;
            std::cout << f1.to_string() << " * " << f2.to_string() << " = " << f1.multiply(f2).to_string() << std::endl;

            try {
                std::cout << f1.to_string() << " / " << f2.to_string() << " = " << f1.divide(f2).to_string() << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "������: " << e.what() << std::endl;
            }

            try {
                Fraction result = f1.add(f2).divide(Fraction::input_from_keyboard()).subtract(5);
                std::cout << "\n��������� ������� ��������: " << result.to_string() << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "������ ��� ���������� ��������: " << e.what() << std::endl;
            }
            break;
        }
        case 0: {
            // ������� ������
            for (auto dept : departments) delete dept;
            for (auto emp : employees) delete emp;
            return 0;
        }
        }
    }
}