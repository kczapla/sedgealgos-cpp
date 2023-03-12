#include "sedgealgos/algorithms/two_sum/closest_pair/closest_pair.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::algorithms::two_sum::closest_pair;

TEST(ClosestPairTest, FindsPair1) {
    ClosestPair::Array arr{-5, -3, -1, 2, 4, 6, 9};
    auto const current_pair{ClosestPair::find(arr)};
    ClosestPair::Pair const expected_pair{-5, -3};
    EXPECT_EQ(current_pair, expected_pair);
}

TEST(ClosestPairTest, FindsPair2) {
    ClosestPair::Array arr{-5, -3, -1, 0, 5.1, 7.2, 9};
    auto const current_pair{ClosestPair::find(arr)};
    ClosestPair::Pair const expected_pair{-1, 0};
    EXPECT_EQ(current_pair, expected_pair);
}
}

