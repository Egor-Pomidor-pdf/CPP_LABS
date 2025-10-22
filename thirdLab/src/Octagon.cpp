#include <cmath>

#include "Octagon.h"

Octagon::Octagon()
{
    v.resize(8);
}

Octagon::Octagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4,
                 const Point &p5, const Point &p6, const Point &p7, const Point &p8)
{
    v.resize(8);
    v[0] = p1;
    v[1] = p2;
    v[2] = p3;
    v[3] = p4;
    v[4] = p5;
    v[5] = p6;
    v[6] = p7;
    v[7] = p8;
}

long double Octagon::Area()
{
    return AreaF(v);
}

Point Octagon::Center()
{
    return Figure::Center();
}
