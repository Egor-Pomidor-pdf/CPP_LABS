cmake_minimum_required(VERSION 3.14)
project(fourthLab)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

add_executable(figure
    src/main.cpp
)

add_executable(FigureTest
    test/mainTest.cpp
    test/testF.cpp
)

target_include_directories(figure PRIVATE include inline)
target_include_directories(FigureTest PRIVATE include inline)

target_link_libraries(FigureTest GTest::GTest GTest::Main)
target_include_directories(FigureTest PRIVATE include)
