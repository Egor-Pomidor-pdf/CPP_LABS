#pragma once
#include <cstddef>
#include "../include/Figure.h"

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
    Figure *get(size_t index) const;
    size_t len() const;

    void delIndex(size_t index);

private:
    size_t size;
    size_t capacity;
    Figure **v;
    void resize(size_t new_capacity);
};