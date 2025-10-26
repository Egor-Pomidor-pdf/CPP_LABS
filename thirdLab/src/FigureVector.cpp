#include "FigureVector.h"
#include "Figure.h"

FigureVector::FigureVector() : size(0), capacity(1), figures(new Figure *[capacity]) {}

FigureVector::FigureVector(const FigureVector &other)
    : size(other.size), capacity(other.capacity),
      figures(new Figure *[capacity])
{
    std::copy(other.figures, other.figures + size, figures);
}

FigureVector::FigureVector(FigureVector &&other) noexcept : size(other.size), capacity(other.capacity), figures(other.figures)
{
    other.clear();
}

FigureVector::~FigureVector() { delete[] figures; }

void FigureVector::resize(size_t newsize)
{
    capacity = newsize;
    Figure **t = new Figure *[capacity];
    std::copy(figures, figures + size, t);
    delete[] figures;
    figures = t;
}

void FigureVector::delIndex(size_t ind)
{
    for (size_t i = ind; i < size; ++i)
    {
        figures[i] = figures[i + 1];
    }
    --size;
}

void FigureVector::push(Figure *c)
{
    if (size >= capacity)
    {
        resize(2 * capacity);
    }
    figures[size++] = c;
}

void FigureVector::pop()
{
    if (size == 0)
    {
        throw std::out_of_range("Cannot pop");
    }
    --size;
}

Figure *FigureVector::operator[](size_t index) const { return figures[index]; }

size_t FigureVector::len() const { return size; }

void FigureVector::clear()
{
    size = 0;
    capacity = 1;
    delete[] figures;
    figures = new Figure *[capacity];
}