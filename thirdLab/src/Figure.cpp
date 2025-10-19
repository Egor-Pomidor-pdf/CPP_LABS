#include "../include/Figure.h"
#include "../include/PointVector.h"
#include "../include/Point.h"

Figure::Figure() {}

long double Figure::Area()
{
}

Point Figure::Center() const
{
    Point c{0, 0};
    for (size_t i = 0; i < v.len(); ++i)
    {
        c.x += v.get(i).x;
        c.y += v.get(i).y;
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
        v.set(i, p);
    }
}

void Figure::PrintPoints(std::ostream &os)
{
    for (size_t i = 0; i < v.len(); ++i)
    {
        Point p = v.get(i);
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
        if (a.v.get(i) != b.v.get(i))
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