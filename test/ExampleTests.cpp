#include <gtest/gtest.h>

#include "../Example.hpp"

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

// TEST(ExampleTests, DemoGTestMacros) {
//     // EXPECT_TRUE(true);  // success

//     // ASSERT_TRUE(false); // fail and stop test execution
    
//     // EXPECT_TRUE(false); // fail
    
//     EXPECT_EQ(true, true); //

//     const bool result = f();
//     EXPECT_EQ(true, result) << "Error description";
// }

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

TEST(ExampleTests2, Square) {
    int x = 5;
    int expectedSquare = x * x;
    EXPECT_EQ(
        expectedSquare,
        Square(x)
    );
}