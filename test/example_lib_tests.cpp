#include <gtest/gtest.h>

#include <example.hpp>
#include <functions.h>

#include <math.h>

// for windows build
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

TEST(example_lib, circleSquare) {
    double radius = 12.1050406;
    double expectedSquare = radius * M_PI;
    EXPECT_DOUBLE_EQ(expectedSquare, circleSquare(radius));
}

TEST(example_lib, rectangleSquare) {
    double a = 4.;
    double b = 5.;
    double expectedSquare = a * b;
    EXPECT_DOUBLE_EQ(expectedSquare, rectangleSquare(a, b));
}

TEST(example_lib, triangleSquare) {
    double a = 5.;
    double h = 5.;
    double expectedSquare = a * h / 2.;
    EXPECT_DOUBLE_EQ(expectedSquare, triangleSquare(a, h));
}

// shape=circle
TEST(example_lib, process_circle_1) {
    const int argc = 3;
    const char *args[argc] = { "app_program", "--shape=circle", "10"};

    EXPECT_EQ(process(argc, args), true);
}

TEST(example_lib, process_circle_2) {
    const int argc = 2;
    const char *args[argc] = { "app_program", "--shape=circle"};

    EXPECT_EQ(process(argc, args), false);
}

// shape=rectangle
TEST(example_lib, process_rectangle_1) {
    const int argc = 4;
    const char *args[argc] = { "app_program", "--shape=rectangle", "10", "10"};

    EXPECT_EQ(process(argc, args), true);
}

TEST(example_lib, process_rectangle_2) {
    const int argc = 3;
    const char *args[argc] = { "app_program", "--shape=rectangle", "10"};

    EXPECT_EQ(process(argc, args), false);
}

TEST(example_lib, process_rectangle_3) {
    const int argc = 5;
    const char *args[argc] = { "app_program", "--shape=rectangle", "10", "11", "10"};

    EXPECT_EQ(process(argc, args), true);
}

TEST(example_lib, process_rectangle_4) {
    const int argc = 5;
    const char *args[argc] = { "app_program", "--shape=rectangle", "10", "11", "any_arg"};

    EXPECT_EQ(process(argc, args), false);
}

// shape=triangle
TEST(example_lib, process_triangle_1) {
    const int argc = 4;
    const char *args[argc] = { "app_program", "--shape=triangle", "10", "10"};

    EXPECT_EQ(process(argc, args), true);
}

TEST(example_lib, process_triangle_2) {
    const int argc = 3;
    const char *args[argc] = { "app_program", "--shape=triangle", "10"};

    EXPECT_EQ(process(argc, args), false);
}

TEST(example_lib, process_triangle_3) {
    const int argc = 5;
    const char *args[argc] = { "app_program", "--shape=triangle", "10", "11", "10"};

    EXPECT_EQ(process(argc, args), true);
}

TEST(example_lib, process_triangle_4) {
    const int argc = 5;
    const char *args[argc] = { "app_program", "--shape=triangle", "10", "11", "any_arg"};

    EXPECT_EQ(process(argc, args), false);
}
