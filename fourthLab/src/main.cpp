#include <iostream>

#include "Point.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"

int main()
{
    // --- Создаём точки ---
    Point<double> a(0, 0), b(0, 2), c(2, 2), d(2, 0);

    // --- Квадрат ---
    Square<double> sq(a, b, c, d);
    std::cout << "=== Квадрат ===\n";
    sq.printVertices();
    std::cout << "Площадь: " << sq.area() << "\n";
    std::cout << "Центр: " << sq.center() << "\n\n";

    // --- Прямоугольник ---
    Rectangle<double> rect(Point<double>(0, 0), Point<double>(0, 3),
                           Point<double>(5, 3), Point<double>(5, 0));
    std::cout << "=== Прямоугольник ===\n";
    rect.printVertices();
    std::cout << "Площадь: " << rect.area() << "\n";
    std::cout << "Центр: " << rect.center() << "\n\n";

    // --- Трапеция ---
    Trapezoid<double> trap(Point<double>(0, 0), Point<double>(2, 3),
                           Point<double>(6, 3), Point<double>(8, 0));
    std::cout << "=== Трапеция ===\n";
    trap.printVertices();
    std::cout << "Площадь: " << trap.area() << "\n";
    std::cout << "Центр: " << trap.center() << "\n\n";

    // --- Проверка сравнения ---

    return 0;
}
