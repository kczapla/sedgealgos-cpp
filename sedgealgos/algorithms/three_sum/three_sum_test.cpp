#include "sedgealgos/algorithms/three_sum/three_sum.hpp"

#include <gtest/gtest.h>

#include <limits>

namespace {
TEST(ThreeSumTest, DetectsZeroZeroSums) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, DetectsOneZeroSum) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{1, 2, -3, 4, 5, 6};
  ASSERT_EQ(1, three_sum.count(a));
}

TEST(ThreeSumTest, DetectsZeroSumsScatterInArray) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{1, 2, 3, 4, 5, -6};
  ASSERT_EQ(2, three_sum.count(a));
}

TEST(ThreeSumTest, DetectesThreeSumOnTheVergeOfOverflowing) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::max() / 2, std::numeric_limits<int>::max() / 2, 0};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, DoesntDetectThreeSumWhenSumOfTwoConsecutiveElementsOverflow) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::max(), 2, std::numeric_limits<int>::max()};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, DoesntDetectThreeSumWhenSumOfTwoScatteredElementsOverflow) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), 2};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, DoesntDetectThreeSumWhenSumOverflowsOnlyAfterThirdElement) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::max() / 2, std::numeric_limits<int>::max() / 2, 2};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, DoesntDetectThreeSumWhenSumOfTwoConsecutiveElementsOverflowNegatively) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min(), 0, std::numeric_limits<int>::min()};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, DoesntDetectThreeSumWhenSumOfTwoScatteredElementsOverflowNegatively) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min(), std::numeric_limits<int>::min(), 0};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, DoesntDetectThreeSumWhenSumOfTwoLastElemsOverflowNegatively) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{0, std::numeric_limits<int>::min(), std::numeric_limits<int>::min()};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, DoesntDetectZeroSumWhenSumWillOverflowNegativelyOnAddingLastElement) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min() / 2, std::numeric_limits<int>::min() / 2, -1};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, DoesntDetectZeroSumWhenSumWillOverflowNegativelyOnAddingLastElementWhichNegativeMaxInt) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min() / 2, std::numeric_limits<int>::min() / 2, -std::numeric_limits<int>::max()};
  ASSERT_EQ(0, three_sum.count(a));
}

TEST(ThreeSumTest, Test1) {
  sedgealgos::algorithms::three_sum::ThreeSum three_sum{};
  std::vector<int> a{std::numeric_limits<int>::min(), std::numeric_limits<int>::min() + 1, -1};
  ASSERT_EQ(0, three_sum.count(a));
}
}
