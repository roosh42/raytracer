#include "Direction.hpp"
#include "Point.hpp"

    Direction::Direction(Point source, Point destination) {
        Point diff = destination - source;
        x = diff.x;
        y = diff.y;
        z = diff.z;
    }

