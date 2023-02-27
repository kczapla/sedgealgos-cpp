#include "sedgealgos/algorithms/three_sum/overflow_detection.hpp"

#include <gmock/gmock.h>
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

TEST(TwoSumPositiveOverflowDetectionTest, Test1) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, max_int));
}

TEST(TwoSumPositiveOverflowDetectionTest, Test2) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, 1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(1, max_int));
}

TEST(TwoSumPositiveOverflowDetectionTest, Test3) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, 1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(1, max_int));
}

TEST(TwoSumPositiveOverflowDetectionTest, Test4) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, min_int));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(min_int, max_int));
}

TEST(TwoSumPositiveOverflowDetectionTest, Test5) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(0, 0));
}

TEST(TwoSumPositiveOverflowDetectionTest, Test6) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(0, 1));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(1, 0));
}

TEST(ThreeSumOverflowDetectionTest, Test1) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, min_int, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test2) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, min_int, -1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(-1, min_int, min_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, -1, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test3) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, min_int, 0));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(0, min_int, min_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, 0, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test4) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, -1, -1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(-1, -1, min_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(-1, min_int, -1));
}

TEST(ThreeSumOverflowDetectionTest, Test6) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, 50, -100));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(50, min_int, -100));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(50, -100, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test7) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(min_int, 1, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(1, min_int, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(1, 2, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test9) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(0, 1, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(1, 0, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_negatively(1, 2, 0));
}

TEST(ThreeSumPositiveOverflowDetectionTest, Test1) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, max_int, max_int));
}

TEST(ThreeSumPositiveOverflowDetectionTest, Test2) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, max_int, 1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(1, max_int, max_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, 1, max_int));
}

TEST(ThreeSumPositiveOverflowDetectionTest, Test3) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, max_int, 0));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(0, max_int, max_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, 0, max_int));
}

TEST(ThreeSumPositiveOverflowDetectionTest, Test4) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, -1, -1));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(-1, -1, max_int));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(-1, max_int, -1));
}

TEST(ThreeSumPositiveOverflowDetectionTest, Test6) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, -50, 100));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(-50, max_int, 100));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(-50, 100, max_int));
}

TEST(ThreeSumPositiveOverflowDetectionTest, Test7) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(max_int, -1, -2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(-1, max_int, -2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(-1, -2, max_int));
}

TEST(ThreeSumPositiveOverflowDetectionTest, Test9) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(0, 1, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(1, 0, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow_positively(1, 2, 0));
}
}
