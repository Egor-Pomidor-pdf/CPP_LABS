#include "../include/PointVector.h"
#include "../include/Point.h"

PointVector::PointVector() : size(0), capacity(1), v(new Point[capacity]) {}

PointVector::PointVector(size_t n) : size(n), capacity(2 * n), v(new Point[capacity]) {}

PointVector::PointVector(const PointVector &other)
    : size(other.size), capacity(other.capacity),
      v(new Point[capacity])
{
    std::copy(other.v, other.v + size, v);
}

PointVector::PointVector(PointVector &&other) noexcept
    : size(other.size), capacity(other.capacity), v(other.v)
{
    other.clear();
}

PointVector::~PointVector() { delete[] v; }

void PointVector::resize(size_t newsize)
{
    capacity = newsize;
    Point *t = new Point[capacity];
    std::copy(v, v + size, t);
    delete[] v;
    v = t;
    size = newsize;
}

void PointVector::push(Point c)
{
    if (size >= capacity)
    {
        resize(2 * capacity);
    }
    v[size++] = c;
}

void PointVector::pop()
{
    if (size)
    {
        --size;
    }
}

void PointVector::set(size_t i, Point p) { v[i] = p; }

Point PointVector::get(size_t i) const { return v[i]; }

size_t PointVector::len() const { return size; }

void PointVector::clear()
{
    size = 0;
    capacity = 1;
    delete[] v;
    v = new Point[capacity];
}