#pragma once

#include <cmath>
#include <iostream>
#include <memory>
#include <string>

#include "Point.hpp"

template <scalar T>
class Figure
{
public:
    virtual ~Figure() = default;
    virtual double area() const = 0;
    virtual void printVertices() const = 0;
    virtual Point<T> center() const = 0;
    virtual bool operator==(const Figure<T> &other) const = 0;
    virtual operator double() const;
};

#include "Figure.ipp"
