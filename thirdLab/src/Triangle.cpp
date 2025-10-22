#include <cmath>

#include "Triangle.h"

Triangle::Triangle()
{
    v.resize(3);
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
    v.resize(3);
    v[0] = p1;
    v[1] = p2;
    v[2] = p3;
}

long double Triangle::Area()
{
    return AreaF(v);
}

Point Triangle::Center()
{
    return Figure::Center();
}
