cmake_minimum_required(VERSION 3.5)

project(Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(infixeval SHARED infix.cpp)

add_executable(Calculator
    infix_test.cpp
    infix_test_main.cpp
    )

target_link_libraries(Calculator infixeval)
