#ifndef INCLUDES
#define INCLUDES

#include <vector>
#include <utility>
#include <memory>
#include <initializer_list>

#include <iostream>
#include <functional>
#include <format>
#include <cmath>

#include "../checkcin/checkcin.h"

// #include "../../checkcin/checkcin.h"

template <typename _T>
using coordinate = std::initializer_list<_T>;


enum TASKS_CHOOSER {
    STOP,
    TASK_1,
    TASK_2,
    TASK_3,
    TASK_4,
    TASK_5,
    TASK_6
};


int input_chooser(int);


void exec_progs_destrib(int);


template <typename _T>
std::vector<_T>* input_accumulator(std::string _messages)
{
    std::vector<_T>* input_buffer = new std::vector<_T>;

    _T input_unit = NULL;

    for(size_t message = 0; message < _messages.size(); ++message) {
        std::cout << _messages.at(message);

        std::cin >> input_buffer;
        input_buffer->push_back(input_unit);
    }

    return input_buffer;
}


#endif