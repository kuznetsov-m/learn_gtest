#include <gtest/gtest.h>

#include <example.hpp>

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
