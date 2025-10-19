#include "../include/Triangle.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include <iostream>

int main()
{
    std::cout << "=== Проверка фигур ===\n\n";
    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);

    Triangle t(p1, p2, p3);
    Hexagon h({0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1});
    Octagon o({1, 0}, {2, 0}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}, {0, 1});

    std::cout << "Треугольник:\nПлощадь: " << t.Area()
              << "\nЦентр: (" << t.Center().x << ", " << t.Center().y << ")\n\n";

    std::cout << "Шестиугольник:\nПлощадь: " << h.Area()
              << "\nЦентр: (" << h.Center().x << ", " << h.Center().y << ")\n\n";

    std::cout << "Восьмиугольник:\nПлощадь: " << o.Area()
              << "\nЦентр: (" << o.Center().x << ", " << o.Center().y << ")\n\n";

    std::cout << "Проверка приведения к double (operator double()):\n";
    std::cout << "double(t) = " << double(t) << "\n";
    std::cout << "double(h) = " << double(h) << "\n";
    std::cout << "double(o) = " << double(o) << "\n";

    std::cout << "\n=== Тест завершён успешно ===\n";
}
