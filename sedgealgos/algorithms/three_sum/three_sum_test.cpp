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

TEST(TreeSumTest, DetectesThreeSumOnTheVergeOfOverflowing) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::max() / 2, std::numeric_limits<int>::max() / 2, 0};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, DoesntDetectThreeSumWhenSumOfTwoConsecutiveElementsOverflow) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::max(), 2, std::numeric_limits<int>::max()};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, DoesntDetectThreeSumWhenSumOfTwoScatteredElementsOverflow) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), 2};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, DoesntDetectThreeSumWhenSumOverflowsOnlyAfterThirdElement) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::max() / 2, std::numeric_limits<int>::max() / 2, 2};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, DoesntDetectThreeSumWhenSumOfTwoConsecutiveElementsOverflowNegatively) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min(), 0, std::numeric_limits<int>::min()};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, DoesntDetectThreeSumWhenSumOfTwoScatteredElementsOverflowNegatively) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min(), std::numeric_limits<int>::min(), 0};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, DoesntDetectThreeSumWhenSumOfTwoLastElemsOverflowNegatively) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{0, std::numeric_limits<int>::min(), std::numeric_limits<int>::min()};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, DoesntDetectZeroSumWhenSumWillOverflowNegativelyOnAddingLastElement) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min() / 2, std::numeric_limits<int>::min() / 2, -1};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, DoesntDetectZeroSumWhenSumWillOverflowNegativelyOnAddingLastElementWhichNegativeMaxInt) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min() / 2, std::numeric_limits<int>::min() / 2, -std::numeric_limits<int>::max()};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(TreeSumTest, Test1) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min(), std::numeric_limits<int>::min() + 1, -1};
  ASSERT_EQ(0, three_sum.count(a));
}
}
