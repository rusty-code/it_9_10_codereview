/* ЕСЛИ БЕЗ DOTCPP, то g++ вываливает:

source/classDot.cpp:11:1: ошибка: переопределение «Dot<_T>::"methode_name"
      | Dot<_T>::"methode_name"
      | ^~~~~~~
In file included from source/../headers/classDot.h:"line_num",
                 from source/classDot.cpp:"line_num":
source/../headers/../source/classDot.cpp:11:1: замечание: «Dot<_T>::"methode_name"»
    ранее декларировано здесь
      | Dot<_T>::"methode_name"
      | ^~~~~~~
*/

// метод разделения шаблона-определения от шаблона-реализации

#ifndef DOTCPP
#define DOTCPP


#ifndef DOT
#include "../header/Dot.h"
#endif



// Constructors

template <typename _T>
Dot<_T>::Dot(_T _x, _T _y) {
    this->_flag_p_x_is_dependent = false;
    this->_flag_p_y_is_dependent = false;

    this->_p_x = new _T(_x);
    this->_p_y = new _T(_y);
}


template <typename _T>
Dot<_T>::Dot(_T* _x, _T* _y) {
    this->_flag_p_x_is_dependent = true;
    this->_flag_p_y_is_dependent = true;

    this->_p_x = _x;
    this->_p_y = _y;
}


template <typename _T>
Dot<_T>::Dot(Dot<_T>* _p_instance) {
    this->_flag_p_x_is_dependent = true;
    this->_flag_p_y_is_dependent = true;

    this->_p_x = _p_instance->p_x;
    this->_p_y = _p_instance->p_y;
}


template <typename _T>
Dot<_T>::Dot(_T* _x, _T _y) {
    this->_flag_p_x_is_dependent = true;
    this->_flag_p_y_is_dependent = false;

    this->_p_x = _x;
    this->_p_y = new _T(_y);
}


template <typename _T>
Dot<_T>::Dot(_T _x, _T* _y) {
    this->_flag_p_x_is_dependent = false;
    this->_flag_p_y_is_dependent = true;

    this->_p_x = new _T(_x);
    this->_p_y = _y;
}


// Destructions

template <typename _T>
void Dot<_T>::__release_x() {
    if(this->_flag_p_x_is_dependent) {
        this->_p_x = nullptr; // protect original
        delete this->_p_x;
    } else delete this->_p_x;
}


template <typename _T>
void Dot<_T>::__release_y() {
    if(this->_flag_p_y_is_dependent) {
        this->_p_y = nullptr; // protect original
        delete this->_p_y;
    } else delete this->_p_y;
}


template <typename _T>
Dot<_T>::~Dot() {
    this->__release_x();
    this->__release_y();
}

// Getters

template <typename _T>
_T Dot<_T>::get_dot_x() {
    return *(this->_p_x);
}


template <typename _T>
_T Dot<_T>::get_dot_y() {
    return *(this->_p_y);
}

template <typename _T>
_T *Dot<_T>::get_dot_x_for_connect() {
    return this->_p_x;
}

template <typename _T>
_T* Dot<_T>::get_dot_y_for_connect() {
    return this->_p_y;
}


// Setters

template <typename _T>
void Dot<_T>::set_x_independent(_T _x) {
    this->_flag_p_x_is_dependent = false;
    this->_p_x = nullptr;
    this->_p_x = new _T(_x);
}


template <typename _T>
void Dot<_T>::set_y_independent(_T _y) {
    this->_flag_p_y_is_dependent = false;
    this->_p_y = nullptr;
    this->_p_y = new _T(_y);
}


template <typename _T>
void Dot<_T>::set_dot_x(_T _x) {
    *(this->_p_x) = _x;
}


template <typename _T>
void Dot<_T>::set_dot_y(_T _y) {
    *(this->_p_y) = _y;
}


template <typename _T>
void Dot<_T>::connect_dot_x_to(_T* _x_of_other_instance) {
    this->release_x();

    this->_flag_p_x_is_dependent = true;
    this->_p_x = _x_of_other_instance;
}


template <typename _T>
void Dot<_T>::connect_dot_y_to(_T* _y_of_other_instance) {
    this->release_y();

    this->_flag_p_y_is_dependent = true;
    this->_p_y = _y_of_other_instance;
}


template <typename _T>
void Dot<_T>::connect_to_Dot(Dot<_T>* _p_instance) {
    this->connect_dot_x_to(_p_instance->get_dot_x_for_connect());
    this->connect_dot_y_to(_p_instance->get_dot_y_for_connect());
}


// For agregator realizations setters

template <typename _T>
void Dot<_T>::__change_dependent_for_x(bool flag) {
    this->_flag_p_x_is_dependent = flag;
}


template <typename _T>
void Dot<_T>::__change_dependent_for_y(bool flag) {
    this->_flag_p_y_is_dependent = flag;
}


// Other methods

template <typename _T>
void Dot<_T>::printls() {
    std::cout << "Dot x: " << this->get_dot_x() << '\n'
              << "Dot y: " << this->get_dot_y() << std::endl;
}

template <typename _T>
std::string Dot<_T>::print() {
    return std::format(
               "({};{})",
               this->get_dot_x(),
               this->get_dot_y());
}

#endif