#pragma once
#include <iostream>

#include "Point.h"

class PointVector
{
public:
    void push(Point v);
    void pop();
    void clear();
    void resize(size_t sz);
    size_t len() const;

    Point &operator[](size_t index);
    const Point &operator[](size_t index) const;

    PointVector(const PointVector &other);
    PointVector(size_t n);
    PointVector(PointVector &&other) noexcept;
    PointVector();
    ~PointVector();

private:
    size_t capacity;
    size_t size;
    Point *points;
};