#include "../include/Point.h"
#include <iostream>

bool operator==(const Point &a, const Point &b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point &a, const Point &b)
{
    return !(a == b);
}

Point::Point() : x(0), y(0) {}

Point::Point(int x_, int y_) : x(x_), y(y_) {}