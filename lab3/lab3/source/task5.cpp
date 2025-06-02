#include "../header/task5.hpp"



void task5::sample1()
{
    std::cout << "Создайте линию:\n";

    Line<int>* line = task2::create_line();

    task4::Display* display = new task4::Display(
        std::max(
            line->get_ptr_begin_dot()->get_dot_x(),
            line->get_ptr_end_dot()->get_dot_x()
        ) + 1,
        std::max(
            line->get_ptr_begin_dot()->get_dot_y(),
            line->get_ptr_end_dot()->get_dot_y()
        ) + 1
    );
    display->init_display(' ');
    display->set_display_unit(line, '*');
    display->print_screen();

    std::cout << "\n Длина лини: " << line->get_distance() << std::endl;

    delete display;
    delete line;
}