#include "sedgealgos/algorithms/two_sum/farthest_pair/farthest_pair.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::algorithms::two_sum::farthest_pair;

TEST(FarthestPairTest, Test1) {
    auto const current_pair{FarthestPair::find({-5, -1, 0, 1, 3, 6})};
    FarthestPair::Pair const expected_pair{-5, 6};
    EXPECT_EQ(current_pair, expected_pair);
}

TEST(FarthestPairTest, Test2) {
    auto const current_pair{FarthestPair::find({6, -5, 3, -1, 0, 1})};
    FarthestPair::Pair const expected_pair{6, -5};
    EXPECT_EQ(current_pair, expected_pair);
}

TEST(FarthestPairTest, Test3) {
    auto const current_pair{FarthestPair::find({0, 0})};
    FarthestPair::Pair const expected_pair{0, 0};
    EXPECT_EQ(current_pair, expected_pair);
}
}

