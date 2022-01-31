#include "sedgealgos/analysis/accumulator.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::analysis;

TEST(AccumulatorTest, ReturnsMeanEqualToZeroWhenNoData) {
    Accumulator acc{};
    EXPECT_EQ(acc.mean(), 0);
}
}
