#include "sedgealgos/algorithms/four_sum/four_sum.hpp"
#include "sedgealgos/array/array.hpp"

#include <gtest/gtest.h>

using FourSum = sedgealgos::algorithms::four_sum::FourSum;
using Array = sedgealgos::array::Array<int>;

namespace {
TEST(FourSumTest, FindsOneSumOfFours) {
    Array array{3, 1, 0, 2, 0, 0, -6};
    EXPECT_EQ(1, sedgealgos::algorithms::four_sum::FourSum::count(array));
}

TEST(FourSumTest, FindsZeroSumsOfFour) {
    Array array{1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(0, sedgealgos::algorithms::four_sum::FourSum::count(array));
}

TEST(FourSumTest, FindsZeroSumsOfFourInEmptyArray) {
    Array array{};
    EXPECT_EQ(0, sedgealgos::algorithms::four_sum::FourSum::count(array));
}
}

