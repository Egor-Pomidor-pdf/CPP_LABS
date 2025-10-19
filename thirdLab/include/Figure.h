#pragma once
#include <iostream>
#include "../include/Point.h"
#include "../include/PointVector.h"

class Figure
{
public:
    PointVector v;
    Figure();
    virtual ~Figure();
    void ReadPoints(std::istream &);
    void PrintPoints(std::ostream &);
    virtual long double Area();
    operator double();
    friend bool operator==(Figure, Figure);
    friend bool operator!=(Figure, Figure);

protected:
    Point Center() const;
};

std::istream &operator>>(std::istream &, Figure &);
std::ostream &operator<<(std::ostream &, Figure &);
