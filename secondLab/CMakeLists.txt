cmake_minimum_required(VERSION 3.14)
project(sec_lab)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)

add_executable(FiveTest
    test/FiveTest
    test/MainTest
    src/Five.cpp
    src/customVector.cpp
)

add_executable(five
    src/Five.cpp
    src/customVector.cpp
    src/main.cpp
)

target_link_libraries(FiveTest GTest::GTest GTest::Main)
target_include_directories(FiveTest PRIVATE include)
target_include_directories(five PRIVATE include)


