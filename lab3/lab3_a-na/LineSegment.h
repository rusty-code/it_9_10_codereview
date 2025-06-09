#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <limits>

class LineSegment {
private:
    double _x1;
    double _x2;

public:
    LineSegment(double _start, double _end);
    LineSegment(double _point);
    LineSegment(const LineSegment& _other);

    double start() const;
    double end() const;

    LineSegment* intersect(const LineSegment& _other) const;
    LineSegment operator!() const;
    LineSegment operator+(int _offset) const;
    bool operator>(const LineSegment& _other) const;

    operator int() const;
    explicit operator double() const;

    void display() const;
    friend std::ostream& operator<<(std::ostream& _os, const LineSegment& _segment);
};

double get_user_input(const std::string& _prompt);

#endif
