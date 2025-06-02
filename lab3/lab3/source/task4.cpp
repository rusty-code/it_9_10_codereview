#include "../header/task4.hpp"
#include <cmath>


task4::Display::Display(int _width, int _height)
{
    this->_width = _width;
    this->_height = _height;
    this->_display = new std::vector<std::vector<char>*>;

    for(int line = 0; line < this->_height; ++line) {
        this->_display->push_back(new std::vector<char>);
    }
}


task4::Display::~Display()
{
    for(int line = 0; line < this->_height; ++line) {
        delete this->_display->at(line);
    }
    delete this->_display;
}


void task4::Display::init_display(char _base_unit = ' ')
{
    for(int line = 0; line < this->_height; ++line) {
        this->_display->at(line)->assign(this->_width, _base_unit);
    }
}

void task4::Display::set_display_unit(Dot<int>* _dot, char _symbol = 'X')
{
    this->_display->at(_dot->get_dot_y())->at(_dot->get_dot_y()) = _symbol;
}


void task4::Display::set_display_unit(int _x, int _y, char _symbol = 'X')
{
    this->_display->at(_y)->at(_x) = _symbol;
}


void task4::Display::set_display_unit(Line<int>* _line, char _symbol = 'X')
{
    std::vector<std::pair<int, int>*>* dots = task4::normalize_path(
                task4::interpoints_path(_line, this->_width, this->_height)
            );
    for(size_t dot = 0; dot < dots->size(); ++dot) {
        this->set_display_unit(
            dots->at(dot)->first,
            dots->at(dot)->second,
            _symbol
        );
    }

    for (size_t dot = 0; dot < dots->size(); ++dot) {
        delete dots->at(dot);
    }
    delete dots;
}


void task4::Display::set_display_unit(std::vector<std::pair<int, int>*>* _body)
{
    for(size_t dot = 0; dot < _body->size(); ++dot) {
        this->set_display_unit(
            _body->at(dot)->first,
            _body->at(dot)->second
        );
    }
    for (size_t dot = 0; dot < _body->size(); ++dot) {
        delete _body->at(dot);
    }

    delete _body;
}


void task4::Display::print_screen()
{
    for(int line = 0; line < this->_height; ++line) {
        for(int col = 0; col < this->_width; ++col) {
            std::cout << this->_display->at(line)->at(col) << ' ';
        }
        std::cout << '\n';
    }
}


int task4::Display::get_width()
{
    return this->_width;
}


int task4::Display::get_height()
{
    return this->_height;
}


std::vector<std::pair<int, int>*>* normalize_x(
    std::vector<std::pair<int, int> *>* _dots_collect,
    size_t _begin_range,
    size_t _end_range
)
{
    std::cout << "Start normalize_x\n";
    for(size_t coord_x = _end_range; coord_x >= _begin_range; --coord_x) {
        _dots_collect->at(coord_x)->first -= 1;
    }

    return _dots_collect;
}

void normalize_y(
    std::vector<std::pair<int, int> *>* _dots_collect,
    int _begin_range,
    int _end_range
)
{
    for(int coord_y = _end_range; coord_y > _begin_range; --coord_y) {
        _dots_collect->at(coord_y)->second -= 1;
    }
}

std::vector<std::pair<int, int>*>* task4::normalize_path(std::vector<std::pair<int, int> *>* _dots_collect)
{
    std::cout << "\nТочки маршрута:\n";
    for(size_t dot = 0; dot < _dots_collect->size(); ++dot) {
        std::cout << "{" << _dots_collect->at(dot)->first << ", " << _dots_collect->at(dot)->second << "}\n";
    }
    int target_normalize_range_end = 0;

    int repeats = 0;
    for(size_t dot = 0; dot < _dots_collect->size() - 1; ++dot) {
        if (_dots_collect->at(dot)->first == _dots_collect->at(dot+1)->first) {
            ++repeats;
            target_normalize_range_end = dot;
        } else if (
            repeats < 3
        ) {
            target_normalize_range_end = 0;
            repeats = 0;
        }
    }

    if(repeats > 2 && repeats != (int)_dots_collect->size() - 1)
        return task4::normalize_path(
                   normalize_x(
                       _dots_collect,
                       target_normalize_range_end - repeats,
                       target_normalize_range_end - 2
                   )
               );

    return _dots_collect;
}


std::vector<std::pair<int, int>*>* task4::interpoints_path(
    Line<int>* _target,
    int _display_width,
    int _display_height
)
{
    std::vector<std::pair<int, int>*>* interpoints = new std::vector<std::pair<int, int>*>;

    int preload_target_x = _target->get_ptr_end_dot()->get_dot_x();
    int preload_target_y = _target->get_ptr_end_dot()->get_dot_y();

    int candidat_x = _target->get_ptr_begin_dot()->get_dot_x();
    int candidat_y = _target->get_ptr_begin_dot()->get_dot_y();

    int current_x = 0;
    int current_y = 0;

    std::cout << "Поиск маршрута между точками:\n";
    _target->print();

    while(candidat_x != preload_target_x || candidat_y != preload_target_y) {
        for(
            int check_x = ((candidat_x - 1 >= 0) ? candidat_x - 1 : candidat_x);
            check_x <= ((candidat_x+1 < _display_width) ? candidat_x + 1 : candidat_x + 1);
            ++check_x
        ) {
            for(
                int check_y = ((candidat_y - 1 >= 0) ? candidat_y - 1 : candidat_y - 1);
                check_y <= ((candidat_y + 1 < _display_height) ? candidat_y + 1 : candidat_y + 1);
                ++check_y
            ) {
                if(
                    std::abs(preload_target_x - check_x) <= std::abs(preload_target_x - current_x) &&
                    std::abs(preload_target_y - check_y) <= std::abs(preload_target_y - current_y)
                ) {
                    current_x = check_x;
                    current_y = check_y;
                }
            }
        }
        std::cout << "Выбрана координата: {" << current_x << ", " << current_y << "}\n";
        candidat_x = current_x;
        candidat_y = current_y;
        interpoints->push_back(new std::pair<int, int>(current_x, current_y));
    }

    return interpoints;
}


void task4::sample1()
{
    int dots_count = checkcin<int>(
                         "Введите целое количество точек: "
                     );

    std::cout << "Введите целочисленные координаты точек:\n";
    std::vector<Dot<int>*>* dots = new std::vector<Dot<int>*>;
    int coor_x = 0;
    int coor_y = 0;
    for(int out = 0; out < dots_count; ++out) {
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

    int max_x = 0;
    int max_y = 0;
    for(size_t dot = 0; dot < dots->size(); ++dot)
    {
        if(max_x < dots->at(dot)->get_dot_x()) {
            max_x = dots->at(dot)->get_dot_x();
        }
        if(max_y < dots->at(dot)->get_dot_y()) {
            max_y = dots->at(dot)->get_dot_y();
        }
    }

    Display* display = new Display(
        max_x+1, 
        max_y+1
    );

    display->init_display();

    for(size_t dot = 0; dot < dots->size(); ++dot) {
        display->set_display_unit(dots->at(dot));
        delete dots->at(dot);
    }

    display->print_screen();

    delete dots;
    delete display;
}

void task4::sample2()
{
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
    display->init_display();
    display->set_display_unit(line);
    display->print_screen();

    delete line;
    delete display;
}