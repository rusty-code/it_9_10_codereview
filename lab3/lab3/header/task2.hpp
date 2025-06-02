#ifndef TASK2EXEC
#define TASK2EXEC

#include "includes.h"
#include "Line.h"
#include "Dot.h"

namespace task2
{

Line<int>* create_line();

void print_lines(std::vector<Line<int>*>*);

void sample1(size_t);
}

#endif