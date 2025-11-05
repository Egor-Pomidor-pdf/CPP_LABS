#pragma once

#include <iostream>

#include "Point.h"
#include "PointVector.h"

class Figure
{
public:
    Figure();
    virtual ~Figure();
    void ReadPoints(std::istream &);
    void PrintPoints(std::ostream &);
    virtual long double Area();
    operator double();
    friend bool operator==(Figure, Figure);
    friend bool operator!=(Figure, Figure);

protected:
    PointVector v;
    long double AreaF(const PointVector &) const;
    Point Center() const;
};

std::istream &operator>>(std::istream &, Figure &);
std::ostream &operator<<(std::ostream &, Figure &);


class Multipier:
{
    public:
    operator() 
}