#pragma once

#include <memory>
#include <iostream>

#include "Figure.hpp"
#include "Point.hpp"

template <scalar T>
class Rectangle : public Figure<T>
{
private:
    std::unique_ptr<Point<T>> p1, p2, p3, p4;

public:
    Rectangle(Point<T> _p1, Point<T> _p2, Point<T> _p3, Point<T> _p4);
    
    double area() const override;
    Point<T> center() const override;
    void printVertices() const override;
    bool operator==(const Figure<T> &other) const override;
};

#include "Rectangle.ipp"
