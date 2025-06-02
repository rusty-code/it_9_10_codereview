#include "../header/task2.hpp"
#include <string>
#include <vector>


Line<int>* task2::create_line()
{

    std::cout << "    Введите целочисленные координаты точки:\n";

    return new Line<int>(
               checkcin<int>("        (ВВОД) X точки-1: "),
               checkcin<int>("        (ВВОД) Y точки-1: "),
               checkcin<int>("        (ВВОД) X точки-2: "),
               checkcin<int>("        (ВВОД) Y точки-2: ")
           );
}


void task2::print_lines(std::vector<Line<int>*>* _lines)
{
    for(size_t line = 0; line < _lines->size(); ++line) {
        std::cout << "    Линия " << std::to_string(line + 1) << " " << _lines->at(line)->print() << std::endl;
    }
}


void task2::sample1(size_t _lines_num)
{
    std::vector<Line<int>*>* lines = new std::vector<Line<int>*>;

    for(size_t line = 0; line < _lines_num; ++line) {
        std::cout << "Введите координаты линии " << std::to_string(line) << ":" << std::endl;
        lines->push_back(create_line());
    }

    std::cout << "Соединени линиии с началом в начальной точке линии 1 и окончанием в конце линии 2...\n";
    lines->push_back(
        new Line<int>(
            lines->at(0)->get_ptr_begin_dot(),
            lines->at(1)->get_ptr_end_dot()
        )
    );

    print_lines(lines);

    std::cout << "\nИзменение координат\n";
    lines->at(0)->set_begin_xy(
        checkcin<int>("        (ВВОД) X точки-1: "),
        checkcin<int>("        (ВВОД) y точки-1: ")
    );

    print_lines(lines);

    std::cout << "\nОтвязка координат третьей линии от первой...\n";

    lines->at(2)->__change_dependent_begin_dot(false);

    std::cout << "\nИзменение координат первой линии\n";
    lines->at(0)->set_begin_xy(
        checkcin<int>("        (ВВОД) X точки-1: "),
        checkcin<int>("        (ВВОД) y точки-1: ")
    );

    print_lines(lines);

    for(size_t line = 0; line < lines->size(); ++line) {
        delete lines->at(line);
    }

    delete lines;
}
