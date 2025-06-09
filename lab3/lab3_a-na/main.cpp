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

    LineSegment* _segment1 = nullptr;
    LineSegment* _segment2 = nullptr;
    int _choice;

    try {
        do {
            print_menu();
            _choice = static_cast<int>(get_user_input(""));

            switch (_choice) {
            case 1: {
                double _start = get_user_input("Введите начало первого отрезка: ");
                double _end = get_user_input("Введите конец первого отрезка: ");
                delete _segment1;
                _segment1 = new LineSegment(_start, _end);

                _start = get_user_input("Введите начало второго отрезка: ");
                _end = get_user_input("Введите конец второго отрезка: ");
                delete _segment2;
                _segment2 = new LineSegment(_start, _end);

                std::cout << "Первый отрезок: " << *_segment1 << std::endl;
                std::cout << "Второй отрезок: " << *_segment2 << std::endl;
                break;
            }

            case 2: {
                if (!_segment1 || !_segment2) {
                    std::cout << "Сначала создайте отрезки!" << std::endl;
                    break;
                }

                LineSegment* _intersection = _segment1->intersect(*_segment2);
                if (_intersection) {
                    std::cout << "Пересечение: " << *_intersection << std::endl;
                    delete _intersection;
                }
                else {
                    std::cout << "Отрезки не пересекаются." << std::endl;
                }
                break;
            }

            case 3: {
                if (!_segment1) {
                    std::cout << "Сначала создайте отрезок!" << std::endl;
                    break;
                }

                LineSegment _updated_segment = !(*_segment1);
                std::cout << "После унарной операции (!): ";
                _updated_segment.display();
                break;
            }

            case 4: {
                if (!_segment1) {
                    std::cout << "Сначала создайте отрезок!" << std::endl;
                    break;
                }

                int _int_value = *_segment1;
                std::cout << "Неявное приведение к int: " << _int_value << std::endl;
                break;
            }

            case 5: {
                if (!_segment1) {
                    std::cout << "Сначала создайте отрезок!" << std::endl;
                    break;
                }

                double _double_value = static_cast<double>(*_segment1);
                std::cout << "Явное приведение к double: " << _double_value << std::endl;
                break;
            }

            case 6: {
                if (!_segment1) {
                    std::cout << "Сначала создайте отрезок!" << std::endl;
                    break;
                }

                int _offset = static_cast<int>(get_user_input("Введите целое число для сложения: "));
                LineSegment _new_segment = *_segment1 + _offset;
                std::cout << "После сложения с " << _offset << ": ";
                _new_segment.display();
                break;
            }

            case 7: {
                if (!_segment1 || !_segment2) {
                    std::cout << "Сначала создайте два отрезка!" << std::endl;
                    break;
                }

                if (*_segment1 > *_segment2) {
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
        } while (_choice != 8);

    }
    catch (const std::exception& _e) {
        std::cerr << "Error: " << _e.what() << std::endl;
    }

    delete _segment1;
    delete _segment2;

    return 0;
}
