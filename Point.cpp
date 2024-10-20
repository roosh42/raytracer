#include "Point.hpp"
#include "Direction.hpp"

    Point::Point(double _x, double _y, double _z): x{_x}, y{_y}, z{_z} {};

    Point Point::operator-(const Point& p) const {
        return Point{x - p.x, y - p.y, z - p.z};
    }

    Point Point::operator+(const Point& p) const {
        return Point{x + p.x, y + p.y, z + p.z};
    }

    double Point::operator*(const Point& p) const {
        return x * p.x + y * p.y + z * p.z;
    }


    // explicit
Point::Point(Direction dir): x{dir.x}, y{dir.y}, z{dir.z} {};

    // friend
    Point operator*(double scalar, const Point& point) {
        return Point(scalar * point.x, scalar * point.y, scalar * point.z);
    }

