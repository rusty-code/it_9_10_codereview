#include "../header/task1.h"


void task1::sample1(int _dots_count)
{
    std::cout << "Введите целочисленные координаты точек:\n";
    std::vector<Dot<int>*>* dots = new std::vector<Dot<int>*>;
    int coor_x = 0;
    int coor_y = 0;
    for(int out = 0; out < _dots_count; ++out) {
        std::cout << "    ТОЧКА" << std::to_string(out+1) << ": " << std::endl;
        coor_x = checkcin<int>(
                     "          (ВВОД) X: ",
                     "Ошибка ввода. Повторите попытку..."
                 );
        coor_y = checkcin<int>(
                     "          (ВВОД) Y: ",
                     "Ошибка ввода. Повторите попытку..."
                 );
        dots->push_back(new Dot<int>(coor_x, coor_y));
    }
    std::cout << "Созданные точки:\n";
    for(int out = 0; out < _dots_count; ++out) {
        std::cout << "    ТОЧКА\n" << std::to_string(out+1) << ": "  << dots->at(out)->print() << std::endl;
        delete dots->at(out);
    }

    delete dots;
}