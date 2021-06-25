#include <gtest/gtest.h>

#include "../example_lib/example.hpp"

TEST(ExampleTests0, DemoGTestMacros) {
    const bool result = f();
    EXPECT_EQ(false, result) << "Error description";
}