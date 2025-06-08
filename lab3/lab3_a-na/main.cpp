#include <iostream>
#include <locale>
#include <clocale>

#include "LineSegment.h"

void print_menu() {
    std::cout << "\nМеню операций с отрезками:\n";
    std::cout << "1. Создать отрезки\n";
    std::cout << "2. Найти пересечение отрезков\n";
    std::cout << "3. Применить унарную операцию (!)\n";
    std::cout << "4. Привести к int (неявное)\n";
    std::cout << "5. Привести к double (явное)\n";
    std::cout << "6. Сложить с целым числом\n";
    std::cout << "7. Сравнить отрезки (оператор >)\n";
    std::cout << "8. Выход\n";
    std::cout << "Выберите операцию: ";
}

int main() {
    // Настройка локализации
    setlocale(LC_ALL, "Russian");


    LineSegment* segment1 = nullptr;
    LineSegment* segment2 = nullptr;
    int choice;

    try {
        do {
            print_menu();
            choice = static_cast<int>(get_user_input(""));

            switch (choice) {
            case 1: {
                double start = get_user_input("Введите начало первого отрезка: ");
                double end = get_user_input("Введите конец первого отрезка: ");
                delete segment1;
                segment1 = new LineSegment(start, end);

                start = get_user_input("Введите начало второго отрезка: ");
                end = get_user_input("Введите конец второго отрезка: ");
                delete segment2;
                segment2 = new LineSegment(start, end);

                std::cout << "Первый отрезок: " << *segment1 << std::endl;
                std::cout << "Второй отрезок: " << *segment2 << std::endl;
                break;
            }

            case 2: {
                if (!segment1 || !segment2) {
                    std::cout << "Сначала создайте отрезки!" << std::endl;
                    break;
                }

                LineSegment* intersection = segment1->intersect(*segment2);
                if (intersection) {
                    std::cout << "Пересечение: " << *intersection << std::endl;
                    delete intersection;
                }
                else {
                    std::cout << "Отрезки не пересекаются." << std::endl;
                }
                break;
            }

            case 3: {
                if (!segment1) {
                    std::cout << "Сначала создайте отрезок!" << std::endl;
                    break;
                }

                LineSegment updated_segment = !(*segment1);
                std::cout << "После унарной операции (!): ";
                updated_segment.display();
                break;
            }

            case 4: {
                if (!segment1) {
                    std::cout << "Сначала создайте отрезок!" << std::endl;
                    break;
                }

                int int_value = *segment1;
                std::cout << "Неявное приведение к int: " << int_value << std::endl;
                break;
            }

            case 5: {
                if (!segment1) {
                    std::cout << "Сначала создайте отрезок!" << std::endl;
                    break;
                }

                double double_value = static_cast<double>(*segment1);
                std::cout << "Явное приведение к double: " << double_value << std::endl;
                break;
            }

            case 6: {
                if (!segment1) {
                    std::cout << "Сначала создайте отрезок!" << std::endl;
                    break;
                }

                int offset = static_cast<int>(get_user_input("Введите целое число для сложения: "));
                LineSegment new_segment = *segment1 + offset;
                std::cout << "После сложения с " << offset << ": ";
                new_segment.display();
                break;
            }

            case 7: {
                if (!segment1 || !segment2) {
                    std::cout << "Сначала создайте два отрезка!" << std::endl;
                    break;
                }

                if (*segment1 > *segment2) {
                    std::cout << "Первый отрезок включает 2." << std::endl;
                }
                else {
                    std::cout << "Первый отрезок не включает 2." << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Выход из программы." << std::endl;
                break;
            }

            default: {
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
                break;
            }
            }
        } while (choice != 8);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    delete segment1;
    delete segment2;

    return 0;
}