#ifndef STDNT
#define STDNT

#include "includes.h"


class Student
{
private:
    bool _name_is_dependent;
    bool _marks_is_dependent;

    std::string* _name;
    std::vector<int>* _marks;

public:
    // Constrs
    Student(std::string, std::initializer_list<int>);
    Student(std::string);
    Student();

    // Destrs
    void __release_name();
    void __release_marks();
    ~Student();

public:

    void set_marks_ptr(std::vector<int>*);
    void set_marks(
        std::vector<int>::iterator,
        std::vector<int>::iterator);

    std::vector<int>* get_marks_ptr();
    std::vector<int>::iterator get_marks_begin();
    std::vector<int>::iterator get_marks_end();

    std::string print();

    int& operator[](size_t);
};


#endif