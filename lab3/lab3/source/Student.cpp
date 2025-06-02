#ifndef STDNTCPP
#define STDNTCPP


#include "../header/Student.h"


Student::Student() {
    this->_name_is_dependent = false;
    this->_marks_is_dependent = false;

    this->_name = new std::string;
    this->_marks = new std::vector<int>;
}


Student::Student(std::string _name) {
    this->_name_is_dependent = false;
    this->_marks_is_dependent = false;

    this->_name = new std::string(_name);
    this->_marks = new std::vector<int>;
}


Student::Student(std::string _name, std::initializer_list<int> _marks) {
    this->_name_is_dependent = false;
    this->_marks_is_dependent = false;

    this->_name = new std::string(_name);
    this->_marks = new std::vector<int>(_marks);
}


void Student::__release_name() {
    if(this->_name_is_dependent) {
        this->_name = nullptr;
        delete this->_name;
    } else
        delete this->_name;
}


void Student::__release_marks() {
    if(this->_marks_is_dependent) {
        this->_marks = nullptr;
        delete this->_marks;
    } else
        delete this->_marks;
}

Student::~Student() {
    this->__release_name();
    this->__release_marks();
}


void Student::set_marks_ptr(std::vector<int>* _marks) {
    this->_marks_is_dependent = true;
    this->_marks = _marks;
}


void Student::set_marks(
    std::vector<int>::iterator begin,
    std::vector<int>::iterator end) {
    for(auto iter = begin; iter != end; ++iter) {
        this->_marks->push_back(*iter);
    }
}


std::vector<int>* Student::get_marks_ptr() {
    return this->_marks;
}


std::vector<int>::iterator Student::get_marks_begin() {
    return this->_marks->begin();
}


std::vector<int>::iterator Student::get_marks_end() {
    return this->_marks->end();
}


std::string Student::print() {
    std::string res = "";
    res.append(*(this->_name)+": ");

    for(auto iter = this->_marks->begin(); iter != this->_marks->end(); ++iter) {
        res.append(std::to_string(*iter)+", ");
    }

    return res;
}

int& Student::operator[](size_t _index) {
    if(_index < 0 || _index >= this->_marks->size()) {
        std::cerr << "Student::operator[index] -> index out of range" << std::endl;
        exit(1);
    }
    return this->_marks->operator[](_index);
}


#endif