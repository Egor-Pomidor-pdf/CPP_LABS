cmake_minimum_required(VERSION 3.10)
project(BalagurDungeonEditor)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

include_directories(include)

add_executable(balagur
src/main.cpp
src/npc.cpp
src/npc_factory.cpp
src/fight_visitor.cpp
src/observer.cpp
src/knight.cpp
src/squirrel.cpp
src/pegasus.cpp
src/fight_thread.cpp
src/game_state.cpp
src/movement_thread.cpp
)


add_executable(Test
test/mainTest.cpp
test/testF.cpp
src/npc.cpp
src/npc_factory.cpp
src/fight_visitor.cpp
src/observer.cpp
src/knight.cpp
src/squirrel.cpp
src/pegasus.cpp
src/fight_thread.cpp
src/game_state.cpp
src/movement_thread.cpp
)

target_link_libraries(Test GTest::GTest GTest::Main)
target_include_directories(Test PRIVATE include)



