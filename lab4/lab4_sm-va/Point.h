#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <limits>
#include <sstream>
#include <cctype>
#include <iostream>
#include <string>

class Point {
private:
	double _x;
	double _y;

public:
	Point() : _x(0), _y(0) {}

	Point(double x, double y) : _x(x), _y(y) {}

	Point(const Point& other) : _x(other._x), _y(other._y) {}

	double get_x_pos() const { return _x; }
	double get_y_pos() const { return _y; }

	Point& operator--() {
		--_x;
		--_y;
		return *this;
	}

	Point operator&() const {
		return Point(_y, _x);
	}

	operator double() const { return static_cast<double>(_y); }
	operator int() const { return _x; }

	Point operator-(unsigned int number) const {
		return Point(_x - number, _y);
	}

	double operator+(Point p) const {
		return std::sqrt(std::pow(p._x - _x, 2) + std::pow(p._y - _y, 2));
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& p) {
		os << "Точка: (" << p._x << ", " << p._y << ")";
		return os;
	}
};

bool is_number(const std::string& s);
double get_valid_coordinate(const std::string& prompt);
void calculate_distance(Point p1, Point p2);
void task_1();
void task_2();

#endif // POINT_H
