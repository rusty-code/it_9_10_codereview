#ifndef GEOMETRY_STUDENT_H
#define GEOMETRY_STUDENT_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <regex>
#include <sstream>
#include <algorithm>
#include <string>

class Point {
private:
    double _x;
    double _y;

public:
    Point(double x, double y);
    std::string print() const;
    double get_x() const;
    double get_y() const;
};

class Line {
private:
    Point _start;
    Point _end;

public:
    Line(const Point& start, const Point& end);
    std::string print() const;
    void set_start(const Point& new_start);
    void set_end(const Point& new_end);
    Point get_start() const;
    Point get_end() const;
};

class Student {
private:
    std::string _name;
    std::vector<int> _grades;

public:
    Student(const std::string& name, const std::vector<int>& grades = {});
    std::string print() const;
    double average() const;
    bool is_excellence() const;
    void set_grades(const std::vector<int>& new_grades);
    std::vector<int> get_grades() const;
};

int input_integer();
Point input_point(const std::string& prompt);
bool is_valid_grade(int grade);
bool is_valid_grades_input(const std::string& input);
std::vector<int> input_grades(const std::string& prompt);
bool is_valid_name(const std::string& name);
std::string input_student_name(const std::string& prompt, const std::vector<std::string>& used_names);

void show_menu();
int main();

#endif
