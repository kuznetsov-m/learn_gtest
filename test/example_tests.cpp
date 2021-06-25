#include <gtest/gtest.h>

#include "../example_lib/example.hpp"

struct ExampleTests
    : public ::testing::Test
{
    int *x;

    int GetX() {
        return *x;
    }

    virtual void SetUp() override {
        printf("Starting up!\n");
        x = new int(42);
    }

    virtual void TearDown() override {
        printf("Tearing down!\n");
        delete x;
    }
};

TEST_F(ExampleTests, MAC) {
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    int expectedNewSum = oldSum + GetX() * y;

    EXPECT_EQ(
        expectedNewSum,
        MAC(GetX(), y, sum)
    );

    EXPECT_EQ(
        expectedNewSum,
        sum
    );
}

TEST_F(ExampleTests, f2) {
    EXPECT_EQ(
        GetX(),
        f2(GetX())
    );
}

TEST(ExampleTests2, Square) {
    int x = 5;
    int expectedSquare = x * x;
    EXPECT_EQ(
        expectedSquare,
        Square(x)
    );
}