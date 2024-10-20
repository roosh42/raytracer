#pragma once

class Direction;

class Point {
public:
    double x;
    double y;
    double z;

    Point(double _x, double _y, double _z);
    Point operator-(const Point& p) const;
    Point operator+(const Point& p) const;
    double operator*(const Point& p) const;


    explicit Point(Direction dir);

    friend Point operator*(double scalar, const Point& point);
};

