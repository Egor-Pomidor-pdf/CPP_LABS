cmake_minimum_required(VERSION 3.14)
project(first_lab)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)


add_executable(lab
    src/main.cpp
    src/gcd.cpp
)


add_executable(gcd_test 
    test/main_test.cpp 
    test/gcd_test.cpp
    src/gcd.cpp
)


target_link_libraries(gcd_test GTest::GTest GTest::Main)
target_include_directories(lab PRIVATE include)
target_include_directories(gcd_test PRIVATE include)

