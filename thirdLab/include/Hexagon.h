#pragma once
#include <iostream>

#include "Figure.h"

class Hexagon : public Figure
{
public:
    Hexagon();
    ~Hexagon() = default;
    Hexagon(const Point &, const Point &, const Point &, const Point &, const Point &, const Point &);
    long double Area();
    Point Center();
};
