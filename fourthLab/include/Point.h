#pragma once
#include <iostream>
#include <type_traits>

template <class T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>

class Point
{
    T x, y;

    Point() : x(0), y(0) {}
    Point(T xValue, T yValue) : x(xValue), y(yValue) {}

    std::istream &operator>>(std::istream &is, Point p)
    {
        is >> p.x >> p.y;
        return is;
    }

    std::ostream &operator<<(std::ostream &os, const Point<T> &p)
    {
        os << '(' << p.x << ' ' << p.y << ')';
        return os;
    }

    bool operator==(const Point<T> &a, const Point<T> &b) { return a.x == b.x && a.y == b.y; }
    bool operator!=(const Point<T> &a, const Point<T> &b) { return !(a == b); }
}