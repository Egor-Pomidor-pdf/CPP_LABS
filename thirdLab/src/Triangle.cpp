#include <cmath>
#include "../include/Triangle.h"

Triangle::Triangle()
{
    v.resize(3);
}

Triangle::~Triangle() {}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
    v.resize(3);
    v.set(0, p1);
    v.set(1, p2);
    v.set(2, p3);
}

long double Triangle::Area()
{
    long double res = 0.0;
    size_t n = v.len();
    std::cout << "n = " << n << std::endl;
    for (size_t i = 0; i < n; ++i)
    {
        Point p1 = v.get(i);
        Point p2 = v.get((i + 1) % n);
        res += p1.x * p2.y - p2.x * p1.y;
    }
    return std::abs(res) / 2.0;
}

Point Triangle::Center()
{
    return Figure::Center();
}
