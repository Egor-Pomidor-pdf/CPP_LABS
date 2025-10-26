#pragma once
#include <iostream>

#include "Figure.h"

class Octagon : public Figure
{
public:
    Octagon();
    ~Octagon() = default;
    Octagon(const Point &, const Point &, const Point &, const Point &, const Point &, const Point &, const Point &, const Point &);
    long double Area();
    Point Center();
};