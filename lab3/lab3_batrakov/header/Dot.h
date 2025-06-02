#ifndef DOT
#define DOT

#include "includes.h"

template <typename _T>
class Dot {
private:
    // simple control block of dependents
    // if coordinate coonect to other instance.coordinate
    bool _flag_p_x_is_dependent;
    bool _flag_p_y_is_dependent;

    _T* _p_x;
    _T* _p_y;

public:

    Dot(_T, _T);
    Dot(_T*, _T); // p_x is dependent
    Dot(_T, _T*); // p_y is dependent
    Dot(_T*, _T*); // p_x and p_y is dependent
    Dot(Dot<_T>*);

    void __release_x(); // clear memory for p_x
    void __release_y(); // clear memory for p_y

    ~Dot();

public:

    _T get_dot_x();
    _T get_dot_y();

    _T* get_dot_x_for_connect();
    _T* get_dot_y_for_connect();

    void set_x_independent(_T);
    void set_y_independent(_T);

    void set_dot_x(_T);
    void set_dot_y(_T);

    void connect_dot_x_to(_T* _x);
    void connect_dot_y_to(_T* _y);
    void connect_to_Dot(Dot<_T>*);

    void __change_dependent_for_x(bool);
    void __change_dependent_for_y(bool);

public:
    void printls();
    std::string print();

};

// declataions methods
#include "../source/Dot.cpp"

#endif