#ifndef LINECPP
#define LINECPP

#ifndef LINE
/*
    Header guard against recursive inclusion.
    This file has already been included in it.
*/
#include "../header/Line.h"
#endif

// Constructors

template <typename _T> 
Line<_T>::Line(Dot<_T> _dot_begin, Dot<_T> _dot_end) {
    this->_begin_dot_is_dependent = false;
    this->_end_dot_is_dependent = false;

    this->_begin_dot = new Dot<_T>(_dot_begin.get_dot_x(), _dot_begin.get_dot_y());
    this->_end_dot = new Dot<_T>(_dot_end.get_dot_x(), _dot_end.get_dot_y());
}

template <typename _T>
Line<_T>::Line(Dot<_T> *_p_dot_begin, Dot<_T> *_p_dot_end) {
    this->_begin_dot_is_dependent = true;
    this->_end_dot_is_dependent = true;

    this->_begin_dot = _p_dot_begin;
    this->_end_dot = _p_dot_end;
}

template <typename _T>
Line<_T>::Line(coordinate<_T> _coords_begin_dot, coordinate<_T> _coords_end_dot) {
    this->_begin_dot_is_dependent = false;
    this->_end_dot_is_dependent = false;

    this->_begin_dot =
        new Dot<_T>(*(_coords_begin_dot.begin()), *(_coords_begin_dot.end()));
    this->_end_dot =
        new Dot<_T>(*(_coords_end_dot.begin()), *(_coords_end_dot.end()));
}

template <typename _T> 
Line<_T>::Line(_T _x1, _T _y1, _T _x2, _T _y2) {
    this->_begin_dot_is_dependent = false;
    this->_end_dot_is_dependent = false;

    this->_begin_dot = new Dot<_T>(_x1, _y1);
    this->_end_dot = new Dot<_T>(_x2, _y2);
}

template <typename _T>
Line<_T>::Line(_T *_x1, _T *_y1, _T *_x2, _T *_y2) {
    this->_begin_dot_is_dependent = true;
    this->_end_dot_is_dependent = true;

    this->_begin_dot = new Dot<_T>(_x1, _y1);
    this->_end_dot = new Dot<_T>(_x2, _y2);
}

// Destructors

template <typename _T> 
void Line<_T>::__release_begin_dot() {
    if(this->_begin_dot_is_dependent)
        this->_begin_dot = nullptr;

    delete this->_begin_dot;

    this->_begin_dot_is_dependent = false;
}

template <typename _T> 
void Line<_T>::__release_end_dot() {
    if(this->_end_dot_is_dependent)
        this->_end_dot = nullptr;

    delete this->_end_dot;

    this->_end_dot_is_dependent = false;
}

template <typename _T> 
Line<_T>::~Line() {
    this->__release_begin_dot();
    this->__release_end_dot();
}

// Setters

template <typename _T> 
void Line<_T>::__change_dependent_begin_dot(bool _flag) {
    this->_begin_dot_is_dependent = _flag;
    if(_flag == false) {
        this->_begin_dot = new Dot<_T>(
            this->_begin_dot->get_dot_x(),
            this->_begin_dot->get_dot_y()
        );
    }
}

template <typename _T>
void Line<_T>::__change_dependent_end_dot(bool _flag) {
    this->_end_dot_is_dependent = _flag;
}

template <typename _T> 
void Line<_T>::set_begin_x(_T _x) {
    this->_begin_dot->set_dot_x(_x);
}

template <typename _T> 
void Line<_T>::set_begin_y(_T _y) {
    this->_begin_dot->set_dot_y(_y);
}

template <typename _T> void Line<_T>::set_end_x(_T _x) {
    this->_end_dot->set_dot_x(_x);
}

template <typename _T> 
void Line<_T>::set_end_y(_T _y) {
    this->_end_dot->set_dot_y(_y);
}

template <typename _T> 
void Line<_T>::set_begin_xy(_T _x, _T _y) {
    this->_begin_dot->set_dot_x(_x);
    this->_begin_dot->set_dot_y(_y);
}

template <typename _T> 
void Line<_T>::set_end_xy(_T _x, _T _y) {
    this->_end_dot->set_dot_x(_x);
    this->_end_dot->set_dot_y(_y);
}


template <typename _T> 
void Line<_T>::set_begin_indenpendent_dot(_T _x, _T _y) {
    this->_begin_dot = nullptr;
    this->_begin_dot = new Dot<_T>(_x, _y);
}


template <typename _T> 
void Line<_T>::set_end_indenpendent_dot(_T _x, _T _y) {
    this->_end_dot = nullptr;
    this->_end_dot = new Dot<_T>(_x, _y);
}

// Getters

template <typename _T> 
Dot<_T> *Line<_T>::get_ptr_begin_dot() {
    return this->_begin_dot;
}

template <typename _T> 
Dot<_T> *Line<_T>::get_ptr_end_dot() {
    return this->_end_dot;
}


template <typename _T> 
void Line<_T>::printls() {

    std::cout   << "Dot begin :\n";
    this->_begin_dot->printls();

    std::cout << "Dot end: \n";
    this->_end_dot->printls();
}

template <typename _T> 
std::string Line<_T>::print() {
    return std::format("Линия от {} до {}", this->_begin_dot->print(),
                       this->_end_dot->print());
}

template <typename _T> 
_T Line<_T>::get_distance() {
    return std::sqrt(std::pow(std::abs(this->_end_dot->get_dot_x() -
                                       this->_begin_dot->get_dot_x()),
                              2) +
                     std::pow(std::abs(this->_end_dot->get_dot_y() -
                                       this->_begin_dot->get_dot_y()),
                              2));
}

// Functions

template <typename _COORDS_TYPE, typename _INSTANCES_TYPE>
Line<_COORDS_TYPE> *makeline(coordinate<_INSTANCES_TYPE> _candidats) {
    return new Line<_COORDS_TYPE>(*(_candidats.begin()), *(_candidats.end()));
}

#endif