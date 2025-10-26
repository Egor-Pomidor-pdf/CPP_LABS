#pragma once

struct Point
{
    double x;
    double y;
    Point();
    Point(int, int);
};

bool operator==(const Point &a, const Point &b);

bool operator!=(const Point &a, const Point &b);