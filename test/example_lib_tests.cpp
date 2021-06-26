#include <gtest/gtest.h>

#include <example.hpp>

#include <math.h>

// for windows build
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

TEST(example_lib, circleSquare) {
    double radius = 10.;
    double expectedSquare = radius * M_PI;
    EXPECT_DOUBLE_EQ(
        expectedSquare,
        circleSquare(radius)
    );
}
