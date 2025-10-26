cmake_minimum_required(VERSION 3.14)
project(thirdLab)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

include_directories(include)

add_executable(figure
    src/main.cpp
    src/Point.cpp
    src/PointVector.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
    src/FigureVector.cpp
)

add_executable(FigureTest
    test/mainTest.cpp
    test/testF.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
    src/Point.cpp
    src/PointVector.cpp
    src/FigureVector.cpp
)

target_link_libraries(FigureTest GTest::GTest GTest::Main)
target_include_directories(FigureTest PRIVATE include)
