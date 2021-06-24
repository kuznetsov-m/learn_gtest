cmake_minimum_required(VERSION 3.20)

set(This ExampleTests)

set(
    Sources
    ExampleTests.cpp
)

add_executable(${This} ${Sources})

# for #include <gtest/gtest.h>
target_link_libraries(${This} PUBLIC
    gtest_main
    Example
)

add_test(
    NAME ${This}
    COMMAND ${This}
)