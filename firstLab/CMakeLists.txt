cmake_minimum_required(VERSION 3.14)
project(first_lab)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab main.cpp gcd.cpp)
add_subdirectory(googletest)
enable_testing()

add_executable(gcd_test gcd.cpp gcd_test.cpp)
target_link_libraries(gcd_test gtest)

add_test(NAME gcd_test COMMAND gcd_test)
