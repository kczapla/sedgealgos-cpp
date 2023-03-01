#include "sedgealgos/algorithms/two_sum/are_equal.hpp"

#include <gtest/gtest.h>

TEST(AreEqualTest, ThereIsNoPairWithTheSameValue) {
    sedgealgos::algorithms::two_sum::AreEqual are_equal{};

    EXPECT_EQ(0, are_equal.count({1,2,3,4}));
}

TEST(AreEqualTest, NoPairWhenArrayIsEmpty) {
    sedgealgos::algorithms::two_sum::AreEqual are_equal{};

    EXPECT_EQ(0, are_equal.count({}));
}

TEST(AreEqualTest, ThereIsOnePair) {
    sedgealgos::algorithms::two_sum::AreEqual are_equal{};

    EXPECT_EQ(1, are_equal.count({1, 2, 3, 1}));
}

TEST(AreEqualTest, NoPairWhenArrayHasOneElement) {
    sedgealgos::algorithms::two_sum::AreEqual are_equal{};

    EXPECT_EQ(0, are_equal.count({1}));
}
