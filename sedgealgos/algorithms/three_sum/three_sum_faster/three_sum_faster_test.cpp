#include "sedgealgos/algorithms/three_sum/three_sum_faster/three_sum_faster.hpp"

#include <gtest/gtest.h>

#include "sedgealgos/array/array.hpp"

namespace {
using namespace sedgealgos::algorithms::three_sum::three_sum_faster;

TEST(ThreeSumFasterTest, OneTripleSumsToZero) {
    EXPECT_EQ(1, ThreeSumFaster::count({-3, -1, 0, 4}));
    EXPECT_EQ(1, ThreeSumFaster::count({-3, 0, 1, 3, 4}));
    EXPECT_EQ(1, ThreeSumFaster::count({-1, 0, 1}));
}

TEST(ThreeSumFasterTest, ZeroTriplesSumToZero) {
    EXPECT_EQ(0, ThreeSumFaster::count({-3, -1, 0, 2, 5}));
    EXPECT_EQ(0, ThreeSumFaster::count({-1, 0}));
}
}

