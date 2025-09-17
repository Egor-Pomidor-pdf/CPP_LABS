cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_app main.cpp gcd.cpp)

add_subdirectory(googletest)
enable_testing()

add_executable(gcd_test gcd.cpp gcd_test.cpp)
target_link_libraries(gcd_test gtest_main)

include(GoogleTest)
gtest_discover_tests(gcd_test)
