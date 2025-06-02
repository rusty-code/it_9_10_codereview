#ifndef PRNTCPP
#define PRNTCPP

#ifndef PRNT
#include "../header/print.h"
#endif


template <typename _T>
void print_collection(
    std::string _name_unit,
    std::initializer_list<_T> _collect)
{
    for(auto iter = _collect.begin(); iter != _collect.end(); ++iter) {
        std::cout << _name_unit << ": " << (*iter)->print() << std::endl;
    }
}


#endif