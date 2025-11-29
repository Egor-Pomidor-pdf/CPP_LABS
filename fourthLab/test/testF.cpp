#include <gtest/gtest.h>

#include "Square.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"

// ---- Тесты для квадрата ----
TEST(SquareTest, AreaCalculation)
{
    Square<double> sq(
        Point<double>(0, 0), Point<double>(0, 2),
        Point<double>(2, 2), Point<double>(2, 0));
    EXPECT_NEAR(static_cast<double>(sq), 4.0, 1e-9);
}

TEST(SquareTest, CenterCalculation)
{
    Square<double> sq(
        Point<double>(0, 0), Point<double>(0, 2),
        Point<double>(2, 2), Point<double>(2, 0));
    Point<double> c = sq.center();
    EXPECT_NEAR(c.x(), 1.0, 1e-9);
    EXPECT_NEAR(c.y(), 1.0, 1e-9);
}

// ---- Тесты для прямоугольника ----
TEST(RectangleTest, AreaCalculation)
{
    Rectangle<double> rect(
        Point<double>(0, 0), Point<double>(0, 3),
        Point<double>(5, 3), Point<double>(5, 0));
    EXPECT_NEAR(static_cast<double>(rect), 15.0, 1e-9);
}

TEST(RectangleTest, CenterCalculation)
{
    Rectangle<double> rect(
        Point<double>(0, 0), Point<double>(0, 3),
        Point<double>(5, 3), Point<double>(5, 0));
    Point<double> c = rect.center();
    EXPECT_NEAR(c.x(), 2.5, 1e-9);
    EXPECT_NEAR(c.y(), 1.5, 1e-9);
}

// ---- Тесты для трапеции ----
TEST(TrapezoidTest, AreaCalculation)
{
    Trapezoid<double> trap(
        Point<double>(0, 0), Point<double>(2, 3),
        Point<double>(6, 3), Point<double>(8, 0));
    EXPECT_NEAR(static_cast<double>(trap), 18.0, 1e-9);
}

TEST(TrapezoidTest, CenterCalculation)
{
    Trapezoid<double> trap(
        Point<double>(0, 0), Point<double>(2, 3),
        Point<double>(6, 3), Point<double>(8, 0));
    Point<double> c = trap.center();
    EXPECT_NEAR(c.x(), 4.0, 1e-9);
    EXPECT_NEAR(c.y(), 1.5, 1e-9);
}

// ---- Проверка оператора приведения к double ----
TEST(FigureTest, OperatorDouble)
{
    Square<double> sq(
        Point<double>(0, 0), Point<double>(0, 2),
        Point<double>(2, 2), Point<double>(2, 0));
    EXPECT_NEAR(static_cast<double>(sq), 4.0, 1e-9);
}
