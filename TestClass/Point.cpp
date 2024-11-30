#include "Point.h"
#include <iostream>

namespace rut::miit::pentagon
{
    Point::Point(double x, double y) : x{ x }, y{ y } {}

    std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    std::istream& operator>>(std::istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }

    bool Point::operator==(const Point& p2) const {
        return (x == p2.x && y == p2.y);
    }

    bool Point::operator!=(const Point& p2) const {
        return !(*this == p2);
    }
};
