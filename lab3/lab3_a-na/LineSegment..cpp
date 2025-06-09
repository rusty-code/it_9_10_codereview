#include "LineSegment.h"

LineSegment::LineSegment(double _start, double _end) {
    if (_start > _end) {
        throw std::invalid_argument("Start cannot be greater than end");
    }
    _x1 = _start;
    _x2 = _end;
}

LineSegment::LineSegment(double _point) : _x1(_point), _x2(_point) {}

LineSegment::LineSegment(const LineSegment& _other) : _x1(_other._x1), _x2(_other._x2) {}

double LineSegment::start() const {
    return _x1;
}

double LineSegment::end() const {
    return _x2;
}

LineSegment* LineSegment::intersect(const LineSegment& _other) const {
    double max_start = std::max(this->start(), _other.start());
    double min_end = std::min(this->end(), _other.end());

    if (max_start <= min_end) {
        return new LineSegment(max_start, min_end);
    }
    return nullptr;
}

LineSegment LineSegment::operator!() const {
    return LineSegment(0, std::max(_x1, _x2));
}

LineSegment LineSegment::operator+(int _offset) const {
    return LineSegment(_x1 + _offset, _x2 + _offset);
}

bool LineSegment::operator>(const LineSegment& _other) const {
    return (_x1 <= _other._x1 && _x2 >= _other._x2);
}

LineSegment::operator int() const {
    return static_cast<int>(_x1);
}

LineSegment::operator double() const {
    return _x1;
}

void LineSegment::display() const {
    std::cout << "Segment from " << _x1 << " to " << _x2 << std::endl;
}

std::ostream& operator<<(std::ostream& _os, const LineSegment& _segment) {
    _os << "Segment from " << _segment._x1 << " to " << _segment._x2;
    return _os;
}

double get_user_input(const std::string& _prompt) {
    double value;

    while (true) {
        std::cout << _prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: please enter a number." << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}
