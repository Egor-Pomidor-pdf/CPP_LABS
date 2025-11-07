template <scalar T>
Point<T>::Point() : _x(0), _y(0) {}

template <scalar T>
Point<T>::Point(T xValue, T yValue) : _x(xValue), _y(yValue) {}

template <scalar T>
T Point<T>::x() const { return _x; }

template <scalar T>
T Point<T>::y() const { return _y; }

template <scalar T>
std::istream &operator>>(std::istream &is, Point<T> &p)
{
    return is >> p._x >> p._y;
}

template <scalar T>
std::ostream &operator<<(std::ostream &os, const Point<T> &p)
{
    return os << "(" << p._x << ", " << p._y << ")";
}

template <scalar T>
bool Point<T>::operator==(const Point<T> &other) const
{
    return _x == other._x && _y == other._y;
}

template <scalar T>
bool Point<T>::operator!=(const Point<T> &other) const
{
    return !(*this == other);
};
