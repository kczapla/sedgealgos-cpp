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

TEST(AccumulatorTest, ReturnsVariance) {
  Accumulator acc{};
  acc.add_data_value(3);
  acc.add_data_value(4);
  acc.add_data_value(6);
  acc.add_data_value(2);
  acc.add_data_value(6);
  acc.add_data_value(8);

  EXPECT_NEAR(acc.var(), 4.1388888, 0.00001);
}

TEST(Accumulator, ReturnsZeroVarianceIfZeroElements) {
  Accumulator acc{};
  EXPECT_EQ(acc.var(), 0.0);
}

TEST(AccumulatorTest, ReturnZeroStddevIfZeroElements) {
  Accumulator acc{};
  EXPECT_EQ(acc.stddev(), 0.0);
}

TEST(AccumulatorTest, ReaturnStandardDeviation) {
  Accumulator acc{};
  acc.add_data_value(3);
  acc.add_data_value(4);
  acc.add_data_value(6);
  acc.add_data_value(2);
  acc.add_data_value(6);
  acc.add_data_value(8);

  EXPECT_NEAR(acc.stddev(), 2.0344, 0.0001);

}
}
