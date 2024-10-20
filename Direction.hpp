#pragma once
#include "Point.hpp"

class Direction {
public:
    double x;
    double y;
    double z;

    Direction(Point source, Point destination);
};

