#ifndef LINE
#define LINE

#include "includes.h"
#include "Dot.h"


template <typename _T>
class Line
{
private:
    // simple control block of dependents
    // if Dot coonect to other instance.Dot
    bool _begin_dot_is_dependent;
    bool _end_dot_is_dependent;

    Dot<_T>* _begin_dot;
    Dot<_T>* _end_dot;

public:
    // Constructors
    Line(Dot<_T>, Dot<_T>);
    Line(Dot<_T>*, Dot<_T>*);
    Line(coordinate<_T>, coordinate<_T>);
    Line(Dot<_T>*, Dot<_T>);
    Line(Dot<_T>, Dot<_T>*);
    Line(_T, _T, _T, _T);
    Line(_T*, _T*, _T*, _T*);
    // Line();

    // Destructors
    void __release_begin_dot();
    void __release_end_dot();

    ~Line();

public:
    // Getters
    Dot<_T>* get_ptr_begin_dot();
    Dot<_T>* get_ptr_end_dot();
    _T get_distance();

    // Setters
    void __change_dependent_begin_dot(bool);
    void __change_dependent_end_dot(bool);

    void set_begin_x(_T);
    void set_begin_y(_T);

    void set_end_x(_T);
    void set_end_y(_T);

    void set_begin_xy(_T, _T);
    void set_end_xy(_T, _T);

    void set_begin_indenpendent_dot(_T, _T);
    void set_end_indenpendent_dot(_T, _T);

public:
    // Other methods
    void printls();
    std::string print();
};


/* 
    may take two Dot/Dot* instance
    two coordinate<coordinate> ...
    delegates creation to constructors
*/
template <typename _INSTANCES_TYPE, typename _COORDS_TYPE>
Line<_COORDS_TYPE>* makeline(coordinate<_INSTANCES_TYPE>);

#include "../source/Line.cpp"


#endif