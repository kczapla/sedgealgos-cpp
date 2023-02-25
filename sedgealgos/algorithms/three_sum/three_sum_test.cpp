#include "sedgealgos/algorithms/three_sum/three_sum.hpp"

#include <gtest/gtest.h>

#include <limits>

namespace {
TEST(TreeSumTest, DetectsZeroZeroSums) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, DetectsOneZeroSum) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{1, 2, -3, 4, 5, 6};
  ASSERT_EQ(1, three_sum.count(a));
}

TEST(TreeSumTest, DetectsZeroSumsScatterInArray) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{1, 2, 3, 4, 5, -6};
  ASSERT_EQ(2, three_sum.count(a));
}

TEST(TreeSumTest, DetectThreeSumsWhenSumOverflows) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::max(), 2, std::numeric_limits<int>::max()};
  ASSERT_EQ(0, three_sum.count(a));
}
}
