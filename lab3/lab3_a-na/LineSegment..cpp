#include "LineSegment.h"

LineSegment::LineSegment(double start, double end) {
    if (start > end) {
        throw std::invalid_argument("Start cannot be greater than end");
    }
    _x1 = start;
    _x2 = end;
}

LineSegment::LineSegment(double point) : _x1(point), _x2(point) {}

LineSegment::LineSegment(const LineSegment& other) : _x1(other._x1), _x2(other._x2) {}

double LineSegment::start() const {
    return _x1;
}

double LineSegment::end() const {
    return _x2;
}

LineSegment* LineSegment::intersect(const LineSegment& other) const {
    double max_start = std::max(this->start(), other.start());
    double min_end = std::min(this->end(), other.end());

    if (max_start <= min_end) {
        return new LineSegment(max_start, min_end);
    }
    return nullptr;
}

LineSegment LineSegment::operator!() const {
    return LineSegment(0, std::max(_x1, _x2));
}

LineSegment LineSegment::operator+(int offset) const {
    return LineSegment(_x1 + offset, _x2 + offset);
}

bool LineSegment::operator>(const LineSegment& other) const {
    return (_x1 <= other._x1 && _x2 >= other._x2);
}

LineSegment::operator int() const {
    return static_cast<int>(_x1);
}

LineSegment::operator double() const {
    return _x1;
}

void LineSegment::display() const {
    std::cout << "Отрезок от " << _x1 << " до " << _x2 << std::endl;
}

std::ostream& operator<<(std::ostream& os, const LineSegment& segment) {
    os << "Отрезок от " << segment._x1 << " до " << segment._x2;
    return os;
}

double get_user_input(const std::string& prompt) {
    double value;

    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите число." << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}