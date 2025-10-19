#include "../include/Hexagon.h"
#include "../include/Figure.h"
#include <cmath>

Hexagon::Hexagon()
{
    v.resize(6);
}

Hexagon::~Hexagon() {}

Hexagon::Hexagon(const Point &p1, const Point &p2, const Point &p3,
                 const Point &p4, const Point &p5, const Point &p6)
{
    v.resize(6);
    v.set(0, p1);
    v.set(1, p2);
    v.set(2, p3);
    v.set(3, p4);
    v.set(4, p5);
    v.set(5, p6);
}

long double Hexagon::Area()
{
    long double res = 0.0;
    size_t n = v.len();
    for (size_t i = 0; i < n; ++i)
    {
        Point p1 = v.get(i);
        Point p2 = v.get((i + 1) % n);
        res += p1.x * p2.y - p2.x * p1.y;
    }
    return std::abs(res) / 2.0;
}

Point Hexagon::Center()
{
    return Figure::Center();
}
