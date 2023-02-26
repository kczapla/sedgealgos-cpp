#include "sedgealgos/algorithms/three_sum/overflow_detection.hpp"

#include <gtest/gtest.h>

#include <limits>

namespace {

constexpr auto min_int{std::numeric_limits<int>::min()};
constexpr auto max_int{std::numeric_limits<int>::max()};

TEST(OverflowDetectionTest, Test1) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, min_int));
}

TEST(OverflowDetectionTest, Test2) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, -1));
}

TEST(OverflowDetectionTest, Test9) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(-1, min_int));
}

TEST(OverflowDetectionTest, Test3) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, max_int));
}

TEST(OverflowDetectionTest, Test8) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(max_int, min_int));
}

TEST(OverflowDetectionTest, Test4) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, 1));
}

TEST(OverflowDetectionTest, Test7) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(1, min_int));
}

TEST(OverflowDetectionTest, Test5) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int + 1, -2));
}

TEST(OverflowDetectionTest, Test6) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(-2, min_int + 1));
}
}
