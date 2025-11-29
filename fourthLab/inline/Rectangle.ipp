template <scalar T>
Rectangle<T>::Rectangle(Point<T> _p1, Point<T> _p2, Point<T> _p3, Point<T> _p4)
    : p1(std::make_unique<Point<T>>(_p1)),
      p2(std::make_unique<Point<T>>(_p2)),
      p3(std::make_unique<Point<T>>(_p3)),
      p4(std::make_unique<Point<T>>(_p4)) {}

template <scalar T>
double Rectangle<T>::area() const
{
    T x[4] = {p1->x(), p2->x(), p3->x(), p4->x()};
    T y[4] = {p1->y(), p2->y(), p3->y(), p4->y()};

    long double res = 0.0;
    for (int i = 0; i < 4; ++i)
    {
        res += (long long)x[i] * (long long)y[(i + 1) % 4];
        res -= (long long)x[(i + 1) % 4] * (long long)y[i];
    }

    return std::abs(res / 2.0);
}

template <scalar T>
Point<T> Rectangle<T>::center() const
{
    T cx = p1->x() + p2->x() + p3->x() + p4->x();
    T cy = p1->y() + p2->y() + p3->y() + p4->y();
    return Point<T>(cx / 4, cy / 4);
}

template <scalar T>
void Rectangle<T>::printVertices() const
{
    std::cout << *p1 << " " << *p2 << " " << *p3 << " " << *p4 << std::endl;
}

template <scalar T>
bool Rectangle<T>::operator==(const Figure<T> &other) const
{
    return static_cast<double>(*this) == static_cast<double>(other);
}
