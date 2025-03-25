#include "DuplicatesRemover.h"
#include <gtest/gtest.h>

TEST(DuplicatesRemoverTest, HandlesEmptyInput) {
    std::vector<int> input;
    auto result = DuplicatesRemover::RemoveDuplicates(input);
    EXPECT_TRUE(result.empty());
}

TEST(DuplicatesRemoverTest, RemovesDuplicates) {
    std::vector<int> input = {1, 2, 2, 3, 3, 3};
    std::vector<int> expected = {1, 2, 3};
    auto result = DuplicatesRemover::RemoveDuplicates(input);
    EXPECT_EQ(result, expected);
}
