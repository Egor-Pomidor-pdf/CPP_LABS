#pragma once
#include <iostream>

#include "Figure.h"

class Triangle : public Figure
{
public:
    Triangle();
    ~Triangle() = default;
    Triangle(Point, Point, Point);
    long double Area();
    Point Center();
};