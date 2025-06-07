#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <iostream>
#include <algorithm>

class LineSegment {
private:
    double _x1;
    double _x2;

public:
    LineSegment();
    LineSegment(double start, double end);
    LineSegment(const LineSegment& other);

    double get_start() const;
    double get_end() const;

    void set_start(double start);
    void set_end(double end);

    static LineSegment* intersection(const LineSegment& seg1, const LineSegment& seg2);
    LineSegment* intersect(const LineSegment& other) const;

    friend std::ostream& operator<<(std::ostream& os, const LineSegment& seg);
    LineSegment operator!() const;
    operator int() const;
    explicit operator double() const;
    LineSegment operator+(int offset) const;
    bool operator>(const LineSegment& other) const;
};

#endif // LINESEGMENT_H