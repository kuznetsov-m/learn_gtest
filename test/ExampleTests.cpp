#include <gtest/gtest.h>

#include "../Example.hpp"

// TEST(ExampleTests, DemoGTestMacros) {
//     // EXPECT_TRUE(true);  // success

//     // ASSERT_TRUE(false); // fail and stop test execution
    
//     // EXPECT_TRUE(false); // fail
    
//     EXPECT_EQ(true, true); //

//     const bool result = f();
//     EXPECT_EQ(true, result) << "Error description";
// }

TEST(ExampleTests, MAC) {
    int x = 42;
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    int expectedNewSum = oldSum + x * y;

    EXPECT_EQ(
        expectedNewSum,
        MAC(x, y, sum)
    );

    EXPECT_EQ(
        expectedNewSum,
        sum
    );
}

TEST(ExampleTests, Square) {
    int x = 5;
    int expectedSquare = x * x;
    EXPECT_EQ(
        expectedSquare,
        Square(x)
    );
}