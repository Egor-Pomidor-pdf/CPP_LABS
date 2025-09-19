cmake_minimum_required(VERSION 3.14)
project(sec_lab)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)



add_executable(FiveTest
    test/FiveTest
    test/MainTest
    src/Five.cpp
)


target_link_libraries(FiveTest GTest::GTest GTest::Main)
target_include_directories(FiveTest PRIVATE include)




# cmake_minimum_required(VERSION 3.14)
# project(sec_lab)

# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_subdirectory(googletest)
# enable_testing()

# add_executable(FiveTest Five.cpp FiveTest.cpp)
# target_link_libraries(FiveTest gtest)

# add_test(NAME FiveTest COMMAND FiveTest)


