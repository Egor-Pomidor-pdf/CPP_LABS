#include "../include/FigureVector.h"
#include "../include/Figure.h"

FigureVector::FigureVector() : size(0), capacity(1), v(new Figure *[capacity]) {}

FigureVector::FigureVector(const FigureVector &other)
    : size(other.size), capacity(other.capacity),
      v(new Figure *[capacity])
{
    std::copy(other.v, other.v + size, v);
}

FigureVector::FigureVector(FigureVector &&other) noexcept : size(other.size), capacity(other.capacity), v(other.v)
{
    other.clear();
}

FigureVector::~FigureVector() { delete[] v; }

void FigureVector::resize(size_t newsize)
{
    capacity = newsize;
    Figure **t = new Figure *[capacity];
    std::copy(v, v + size, t);
    delete[] v;
    v = t;
}

void FigureVector::delIndex(size_t ind)
{
    for (size_t i = ind; i < size; ++i)
    {
        v[i] = v[i + 1];
    }
    --size;
}

void FigureVector::push(Figure *c)
{
    if (size >= capacity)
    {
        resize(2 * capacity);
    }
    v[size++] = c;
}

void FigureVector::pop()
{
    if (size)
    {
        --size;
    }
}

Figure *FigureVector::get(size_t i) const { return v[i]; }

size_t FigureVector::len() const { return size; }

void FigureVector::clear()
{
    size = 0;
    capacity = 1;
    delete[] v;
    v = new Figure *[capacity];
}