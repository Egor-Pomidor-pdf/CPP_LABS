#pragma once
#include <iostream>
#include "../include/Figure.h"

class Hexagon : public Figure
{
public:
    Hexagon();
    ~Hexagon();
    Hexagon(const Point &, const Point &, const Point &, const Point &, const Point &, const Point &);
    long double Area();
    Point Center();
};
