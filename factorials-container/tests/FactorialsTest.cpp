#include "Factorials.h"
#include <gtest/gtest.h>

TEST(FactorialsTest, HandlesZeroInput) {
    auto result = Factorials::GenerateFactorials(0);
    EXPECT_TRUE(result.empty());
}

TEST(FactorialsTest, HandlesPositiveInput) {
    auto result = Factorials::GenerateFactorials(5);
    std::vector<unsigned long long> expected = {1, 1, 2, 6, 24};
    EXPECT_EQ(result, expected);
}

TEST(FactorialsTest, ThrowsOnNegativeInput) {
    EXPECT_THROW(Factorials::GenerateFactorials(-1), std::invalid_argument);
}

TEST(FactorialsTest, ThrowsOnOverflow) {
    EXPECT_THROW(Factorials::GenerateFactorials(100), std::overflow_error);
}
