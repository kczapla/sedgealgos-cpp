#include "sedgealgos/analysis/accumulator.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::analysis;

TEST(AccumulatorTest, ReturnsMeanEqualToZeroWhenNoData) {
    Accumulator acc{};
    EXPECT_EQ(acc.mean(), 0);
}

TEST(AccumulatorTest, ReturnsMeanFromTwoElements) {
  Accumulator acc{};
  acc.add_data_value(3);
  acc.add_data_value(2);
  EXPECT_EQ(acc.mean(), 2.5);
}
}
