#pragma once
#include <cstddef>

#include "Figure.h"

class FigureVector
{
public:
    FigureVector();
    FigureVector(const FigureVector &other);
    FigureVector(FigureVector &&other) noexcept;
    ~FigureVector();

    void push(Figure *f);
    void clear();
    void pop();
    void delIndex(size_t index);
    size_t len() const;

    Figure *operator[](size_t index) const;

private:
    size_t size;
    size_t capacity;
    Figure **figures;
    void resize(size_t new_capacity);
};