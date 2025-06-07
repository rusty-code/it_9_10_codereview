#include "LineSegment.h"
#include <iostream>
#include <limits>

/*
Функция для безопасного ввода числа
Принимает приглашение для ввода
Возвращает введенное число
*/
double input_number(const std::string& prompt)
{
    double number;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> number)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка. Введите число\n";
    }
    return number;
}


void show_menu()
{
    std::cout << "\nМеню:\n";
    std::cout << "1. Создать отрезок х\n";
    std::cout << "2. Создать отрезок у\n";
    std::cout << "3. Вывести отрезки\n";
    std::cout << "4. Найти пересечение (статический метод)\n";
    std::cout << "5. Найти пересечение (метод объекта)\n";
    std::cout << "6. Применить унарную операцию !\n";
    std::cout << "7. Привести к int\n";
    std::cout << "8. Привести к double\n";
    std::cout << "9. Сложить с целым числом\n";
    std::cout << "10. Проверить включение отрезков\n";
    std::cout << "11. Изменить координаты отрезка\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите номер действия: ";
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    LineSegment segment1;
    LineSegment segment2;
    int choice;

    do
    {
        show_menu();
        choice = static_cast<int>(input_number(""));

        switch (choice)
        {
        case 1:
        {
            double start = input_number("Введите начало первого отрезка: ");
            double end = input_number("Введите конец первого отрезка: ");
            segment1 = LineSegment(start, end);
            break;
        }
        case 2:
        {
            double start = input_number("Введите начало второго отрезка: ");
            double end = input_number("Введите конец второго отрезка: ");
            segment2 = LineSegment(start, end);
            break;
        }
        case 3:
            std::cout << "Первый отрезок: " << segment1 << "\nВторой отрезок: " << segment2 << std::endl;
            break;
        case 4:
        {
            LineSegment* intersection = LineSegment::intersection(segment1, segment2);
            if (intersection)
            {
                std::cout << "Пересечение: " << *intersection << std::endl;
                delete intersection;
            }
            else
            {
                std::cout << "Отрезки не пересекаются" << std::endl;
            }
            break;
        }
        case 5:
        {
            LineSegment* intersection = segment1.intersect(segment2);
            if (intersection)
            {
                std::cout << "Пересечение: " << *intersection << std::endl;
                delete intersection;
            }
            else
            {
                std::cout << "Отрезки не пересекаются" << std::endl;
            }
            break;
        }
        case 6:
        {
            LineSegment result = !segment1;
            std::cout << "Результат применения ! к первому отрезку: " << result << std::endl;
            break;
        }
        case 7:
            std::cout << "Целая часть координаты y второго отрезка: " << static_cast<int>(segment2) << std::endl;
            break;
        case 8:
            std::cout << "Координата x первого отрезка: " << static_cast<double>(segment1) << std::endl;
            break;
        case 9:
        {
            int offset = static_cast<int>(input_number("Введите целое число для сложения: "));
            LineSegment result = segment1 + offset;
            std::cout << "Результат сложения: " << result << std::endl;
            break;
        }
        case 10:
            if (segment1 > segment2)
                std::cout << "Первый отрезок включает второй отрезок" << std::endl;
            else
                std::cout << "Первый отрезок не включает второй отрезок" << std::endl;
            break;
        case 11:
        {
            double start = input_number("Введите новое начало отрезка: ");
            segment1.set_start(start);
            double end = input_number("Введите новый конец отрезка: ");
            segment1.set_end(end);
            std::cout << "Обновленный отрезок: " << segment1 << std::endl;
            break;
        }
        case 0:
            std::cout << "Выход" << std::endl;
            break;
        default:
            std::cout << "Ошибка: введите число от 0 до 11" << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}