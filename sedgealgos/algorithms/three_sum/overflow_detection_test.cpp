#include "sedgealgos/algorithms/three_sum/overflow_detection.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <limits>

namespace {

constexpr auto min_int{std::numeric_limits<int>::min()};
constexpr auto max_int{std::numeric_limits<int>::max()};

TEST(SumOfTwoOverflowDetectionTest, Test1) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, min_int));
}

TEST(SumOfTwoOverflowDetectionTest, Test2) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, -1));
}

TEST(SumOfTwoOverflowDetectionTest, Test9) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-1, min_int));
}

TEST(SumOfTwoOverflowDetectionTest, Test3) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, max_int));
}

TEST(SumOfTwoOverflowDetectionTest, Test8) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, min_int));
}

TEST(SumOfTwoOverflowDetectionTest, Test4) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, 1));
}

TEST(SumOfTwoOverflowDetectionTest, Test7) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, min_int));
}

TEST(SumOfTwoOverflowDetectionTest, Test5) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int + 1, -2));
}

TEST(SumOfTwoOverflowDetectionTest, Test6) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-2, min_int + 1));
}

TEST(SumOfTwoOverflowDetectionTest, Test10) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, max_int));
}

TEST(SumOfTwoOverflowDetectionTest, Test11) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, 1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, max_int));
}

TEST(SumOfTwoOverflowDetectionTest, Test12) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, 1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, max_int));
}

TEST(SumOfTwoOverflowDetectionTest, Test13) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, min_int));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, max_int));
}

TEST(SumOfTwoOverflowDetectionTest, Test14) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(0, 0));
}

TEST(SumOfTwoOverflowDetectionTest, Test15) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(0, 1));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, 0));
}

TEST(ThreeSumOverflowDetectionTest, Test1) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, min_int, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test2) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, min_int, -1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-1, min_int, min_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, -1, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test3) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, min_int, 0));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(0, min_int, min_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, 0, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test4) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, -1, -1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-1, -1, min_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-1, min_int, -1));
}

TEST(ThreeSumOverflowDetectionTest, Test6) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, 50, -100));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(50, min_int, -100));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(50, -100, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test7) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(min_int, 1, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, min_int, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, 2, min_int));
}

TEST(ThreeSumOverflowDetectionTest, Test9) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(0, 1, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, 0, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, 2, 0));
}

TEST(SumOfThreeOverflowDetectionTest, Test10) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, max_int, max_int));
}

TEST(SumOfThreeOverflowDetectionTest, Test11) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, max_int, 1));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, max_int, max_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, 1, max_int));
}

TEST(SumOfThreeOverflowDetectionTest, Test12) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, max_int, 0));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(0, max_int, max_int));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, 0, max_int));
}

TEST(SumOfThreeOverflowDetectionTest, Test13) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, -1, -1));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-1, -1, max_int));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-1, max_int, -1));
}

TEST(SumOfThreeOverflowDetectionTest, Test14) {
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, -50, 100));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-50, max_int, 100));
    EXPECT_TRUE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-50, 100, max_int));
}

TEST(SumOfThreeOverflowDetectionTest, Test15) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(max_int, -1, -2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-1, max_int, -2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(-1, -2, max_int));
}

TEST(SumOfThreeOverflowDetectionTest, Test16) {
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(0, 1, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, 0, 2));
    EXPECT_FALSE(sedgealgos::algorithms::three_sum::overflow_detection::will_sum_overflow(1, 2, 0));
}
}
