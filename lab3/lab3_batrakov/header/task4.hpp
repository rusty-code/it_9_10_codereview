#ifndef TASK4EXEC
#define TASK4EXEC

#include "includes.h"
#include "task2.hpp"
#include "Dot.h"
#include "Line.h"


namespace task4
{

enum class DIRECTIONS {
    UP_RIGHT,
    UP_LEFT,
    DOWN_RIGHT,
    DOWN_LEFT,
    LEFT_DIAGONAL,
    UNKNOWN_VERTICAL,
    UNKNOWN_HORIZONTAL,
    UNKNOWN
};

class Display
{
private:
    std::vector<std::vector<char>*>* _display;
    int _width, _height;

public:
    Display(int, int);
    ~Display();

    void init_display(char);

public:
    void set_display_unit(Dot<int>*, char);
    void set_display_unit(Line<int>*, char);
    void set_display_unit(int, int, char);
    void set_display_unit(std::vector<std::pair<int, int>*>*);

    void print_screen();
    void clear_screen();

    int get_width();
    int get_height();
};

std::vector<std::pair<int, int>*>* normalize_path(std::vector<std::pair<int, int>*>*);

std::vector<std::pair<int, int>*>* interpoints_path(Line<int>*, int, int);

void sample1();
void sample2();

};

#endif