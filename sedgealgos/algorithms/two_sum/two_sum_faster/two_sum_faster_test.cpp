#include "sedgealgos/algorithms/two_sum/two_sum_faster/two_sum_faster.hpp"

#include <gtest/gtest.h>

namespace {
using TwoSumFaster = sedgealgos::algorithms::two_sum::two_sum_faster::TwoSumFaster;

TEST(TwoSumFasterTest, TwoPairsSumsToZero) {
    EXPECT_EQ(2, TwoSumFaster::count({-4, -1, 0, 1, 2, 3, 4}));
    EXPECT_EQ(1, TwoSumFaster::count({-4, 4}));
    EXPECT_EQ(4, TwoSumFaster::count({-4, -3, -2, -1, 0, 1, 2, 3, 4}));
}

TEST(TwoSumFasterTest, ZeroParisSumsToZero) {
    EXPECT_EQ(0, TwoSumFaster::count({-6, -5, 0, 1, 2, 3, 4}));
    EXPECT_EQ(0, TwoSumFaster::count({0}));
    EXPECT_EQ(0, TwoSumFaster::count({-1, 0, 2}));
}


}

