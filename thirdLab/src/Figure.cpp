#include <iostream>

#include "Figure.h"

Figure::Figure() {}

long double Figure::AreaF(const PointVector &t) const
{
    long double res{0.0};
    for (int i = 0; i + 1 < t.len(); ++i)
    {
        res += (long long)t[i].x * (long long)t[i + 1].y;
        res -= (long long)t[i + 1].x * (long long)t[i].y;
    }
    res += (long long)t[t.len() - 1].x * (long long)t[0].y;
    res -= (long long)t[0].x * (long long)t[t.len() - 1].y;
    return std::abs(res / 2.0);
}

long double Figure::Area() { return AreaF(v); }

Point Figure::Center() const
{
    Point c{0, 0};
    for (size_t i = 0; i < v.len(); ++i)
    {
        c.x += v[i].x;
        c.y += v[i].y;
    }
    c.x /= v.len();
    c.y /= v.len();
    return c;
}
void Figure::ReadPoints(std::istream &is)
{
    for (size_t i = 0; i < v.len(); ++i)
    {
        Point p;
        is >> p.x >> p.y;
        v[i] = p;
    }
}

void Figure::PrintPoints(std::ostream &os)
{
    for (size_t i = 0; i < v.len(); ++i)
    {
        Point p = v[i];
        os << "( " << p.x << ", " << p.y << ")";
    }
}

std::istream &operator>>(std::istream &is, Figure &f)
{
    f.ReadPoints(is);
    return is;
}

std::ostream &operator<<(std::ostream &os, Figure &f)
{
    f.PrintPoints(os);
    return os;
}

bool operator==(Figure a, Figure b)
{
    if (a.v.len() != b.v.len())
    {
        return false;
    }
    for (int i = 0; i < a.v.len(); ++i)
    {
        if (a.v[i] != b.v[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!=(Figure a, Figure b) { return !(a == b); }

Figure::operator double()
{
    return Area();
}

Figure::~Figure() {}