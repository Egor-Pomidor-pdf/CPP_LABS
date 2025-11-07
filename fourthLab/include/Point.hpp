#pragma once
#include <iostream>
#include <type_traits>

template <typename T>
concept scalar = std::is_arithmetic_v<T>;

template <scalar T>
class Point
{
private:
    T _x, _y;

public:
    Point();
    Point(T xValue, T yValue);

    T x() const;
    T y() const;

    bool operator==(const Point<T> &other) const;
    bool operator!=(const Point<T> &other) const;
};

template <scalar T>
std::ostream &operator<<(std::ostream &os, const Point<T> &p);

#include "Point.ipp"