#include <cmath>

#include "Hexagon.h"
#include "Figure.h"

Hexagon::Hexagon()
{
    v.resize(6);
}

Hexagon::Hexagon(const Point &p1, const Point &p2, const Point &p3,
                 const Point &p4, const Point &p5, const Point &p6)
{
    v.resize(6);
    v[0] = p1;
    v[1] = p2;
    v[2] = p3;
    v[3] = p4;
    v[4] = p5;
    v[5] = p6;
}

long double Hexagon::Area()
{
    return AreaF(v);
}

Point Hexagon::Center()
{
    return Figure::Center();
}
