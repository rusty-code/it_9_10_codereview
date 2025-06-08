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
// FIXME: параметр
    LineSegment(double start, double end);
    LineSegment(double point);
    LineSegment(const LineSegment& other);

    double start() const;
    double end() const;

    LineSegment* intersect(const LineSegment& other) const;
    LineSegment operator!() const;
    LineSegment operator+(int offset) const;
    bool operator>(const LineSegment& other) const;

    operator int() const;
    explicit operator double() const;

    void display() const;
    friend std::ostream& operator<<(std::ostream& os, const LineSegment& segment);
};

double get_user_input(const std::string& prompt);

#endif