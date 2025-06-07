#include "LineSegment.h"
#include <limits>

LineSegment::LineSegment() :
    _x1(0),
    _x2(0)
{
}

/*
Конструктор с параметрами
Принимает начало и конец отрезка
Автоматически упорядочивает координаты
*/
LineSegment::LineSegment(double start, double end)
{
    if (start <= end)
    {
        _x1 = start;
        _x2 = end;
    }
    else
    {
        _x1 = end;
        _x2 = start;
    }
}

LineSegment::LineSegment(const LineSegment& other) :
    _x1(other._x1),
    _x2(other._x2)
{
}

double LineSegment::get_start() const
{
    return _x1;
}

double LineSegment::get_end() const
{
    return _x2;
}

void LineSegment::set_start(double start)
{
    if (start <= _x2)
    {
        _x1 = start;
    }
    else
    {
        _x2 = start;
        _x1 = _x2;
    }
}

void LineSegment::set_end(double end)
{
    if (end >= _x1)
    {
        _x2 = end;
    }
    else
    {
        _x1 = end;
        _x2 = _x1;
    }
}

/*
Статический метод для нахождения пересечения отрезков
Возвращает новый отрезок или nullptr если нет пересечения
*/
LineSegment* LineSegment::intersection(const LineSegment& seg1, const LineSegment& seg2)
{
    if (seg1._x2 < seg2._x1 || seg2._x2 < seg1._x1)
    {
        return nullptr;
    }
    double start = std::max(seg1._x1, seg2._x1);
    double end = std::min(seg1._x2, seg2._x2);
    return new LineSegment(start, end);
}

/*
Метод объекта для нахождения пересечения с другим отрезком
Возвращает новый отрезок или nullptr если нет пересечения
*/
LineSegment* LineSegment::intersect(const LineSegment& other) const
{
    double max_start = std::max(_x1, other._x1);
    double min_end = std::min(_x2, other._x2);

    if (max_start <= min_end)
    {
        return new LineSegment(max_start, min_end);
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const LineSegment& seg)
{
    os << "[" << seg._x1 << ", " << seg._x2 << "]";
    return os;
}

LineSegment LineSegment::operator!() const
{
    return LineSegment(0, (_x2 - _x1));
}

LineSegment::operator int() const
{
    return static_cast<int>(_x2);
}

LineSegment::operator double() const
{
    return _x1;
}

LineSegment LineSegment::operator+(int offset) const
{
    return LineSegment(_x1 + offset, _x2 + offset);
}

bool LineSegment::operator>(const LineSegment& other) const
{
    return (_x1 <= other._x1 && _x2 >= other._x2);
}