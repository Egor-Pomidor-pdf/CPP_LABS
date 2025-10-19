#pragma once
#include <iostream>
#include "../include/Figure.h"

class Octagon : public Figure
{
public:
    Octagon();
    ~Octagon();
    Octagon(const Point &, const Point &, const Point &, const Point &, const Point &, const Point &, const Point &, const Point &);
    long double Area();
    Point Center();
};