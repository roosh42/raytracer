#include "Point.hpp"

    Point::Point(double _x, double _y, double _z): x{_x}, y{_y}, z{_z} {};

    Point Point::operator-(const Point& p) const {
        return Point{p.x - x, p.y - y, p.z - z};
    }

    // explicit
    Point::Point(Direction dir): x{dir.x}, y{dir.y}, z{dir.y} {};

    // friend
    Point Point::operator*(double scalar, const Point& point) {
        return Point(scalar * point.c, scalar * point.y, scalar * point.z);
    }

