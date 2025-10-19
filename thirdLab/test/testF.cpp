#include <gtest/gtest.h>
#include "../include/Triangle.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"

// ---- Тесты для треугольника ----
TEST(TriangleTest, AreaCalculation)
{
    Triangle t({0, 0}, {3, 0}, {0, 4});
    EXPECT_NEAR(static_cast<double>(t.Area()), 6.0, 1e-9);
}

TEST(TriangleTest, CenterCalculation)
{
    Triangle t({0, 0}, {3, 0}, {0, 4});
    Point c = t.Center();
    EXPECT_NEAR(c.x, 1.0, 1e-9);
    EXPECT_NEAR(c.y, 1.333333, 1e-6);
}

// ---- Тесты для шестиугольника ----
TEST(HexagonTest, AreaCalculation)
{
    Hexagon h({0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1});
    EXPECT_NEAR(static_cast<double>(h.Area()), 6.0, 1e-9);
}

TEST(HexagonTest, CenterCalculation)
{
    Hexagon h({0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1});
    Point c = h.Center();
    EXPECT_NEAR(c.x, 1.0, 1e-6);
    EXPECT_NEAR(c.y, 1.0, 1e-6);
}

// ---- Тесты для восьмиугольника ----

TEST(OctagonTest, CenterCalculation)
{
    Octagon o({1, 0}, {2, 0}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}, {0, 1});
    Point c = o.Center();
    EXPECT_NEAR(c.x, 1.5, 1e-6);
    EXPECT_NEAR(c.y, 1.5, 1e-6);
}

// ---- Проверка оператора приведения к double ----
TEST(FigureTest, OperatorDouble)
{
    Triangle t({0, 0}, {3, 0}, {0, 4});
    EXPECT_NEAR(static_cast<double>(t), 6.0, 1e-9);
}
