#pragma once
#include <iostream>
#include "../include/Point.h"

class PointVector
{
public:
    void push(Point v);
    void pop();
    void clear();
    void set(size_t n, Point p);
    void resize(size_t sz);
    Point get(size_t) const;
    size_t len() const;

    PointVector(const PointVector &other);
    PointVector(size_t n);
    PointVector(PointVector &&other) noexcept;
    PointVector();
    ~PointVector();

private:
    size_t capacity;
    size_t size;
    Point *v;
};