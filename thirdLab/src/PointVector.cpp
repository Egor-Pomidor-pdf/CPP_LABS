#include "PointVector.h"
#include "Point.h"

PointVector::PointVector() : size(0), capacity(1), points(new Point[capacity]) {}

PointVector::PointVector(size_t n) : size(n), capacity(2 * n), points(new Point[capacity]) {}

PointVector::PointVector(const PointVector &other)
    : size(other.size), capacity(other.capacity),
      points(new Point[capacity])
{
    std::copy(other.points, other.points + size, points);
}

PointVector::PointVector(PointVector &&other) noexcept
    : size(other.size), capacity(other.capacity), points(other.points)
{
    other.clear();
}

PointVector::~PointVector() { delete[] points; }

void PointVector::resize(size_t newsize)
{
    capacity = newsize;
    Point *t = new Point[capacity];
    std::copy(points, points + size, t);
    delete[] points;
    points = t;
    size = newsize;
}

void PointVector::push(Point c)
{
    if (size >= capacity)
    {
        resize(2 * capacity);
    }
    points[size++] = c;
}

void PointVector::pop()
{

    if (size)
    {
        --size;
    }
}

Point &PointVector::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("PointVector::operator[] - index out of range");
    }
    return points[index];
}

const Point &PointVector::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("PointVector::operator[] const - index out of range");
    }
    return points[index];
}

size_t PointVector::len() const { return size; }

void PointVector::clear()
{
    size = 0;
    capacity = 1;
    delete[] points;
    points = new Point[capacity];
}