#include "sedgealgos/data_structures/bag/random_bag.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace {
using namespace sedgealgos::data_structures::bag;

MATCHER_P2(IsBetween, a, b, "") { return a <= arg && arg <= b; }

TEST(RandomBagTest, IsEmptyReturnsTrueWhenRandomBagIsEmpty) {
    RandomBag<int> bag;

    EXPECT_TRUE(bag.is_empty());
}

TEST(RandomBagTest, IsEmptyReturnsFalseWhenRandomBagIsNotEmpty) {
    RandomBag<int> bag;

    bag.add(1);

    EXPECT_FALSE(bag.is_empty());
}

TEST(RandomBagTest, SizeReturnZeroWhenRandomBagIsEmpty) {
    RandomBag<int> bag;

    EXPECT_EQ(bag.size(), 0);
}

TEST(RandomBagTest, AddItemIncreasesSizeOfBag) {
    RandomBag<int> bag;

    bag.add(1);

    EXPECT_EQ(bag.size(), 1);
}

TEST(RandomBagTest, BeginIteratorIsEqualEndIteratorWhenBagIsEmpty) {
    RandomBag<int> bag;

    EXPECT_TRUE(bag.begin() == bag.end());
    EXPECT_FALSE(bag.begin() != bag.end());
}

TEST(RandomBagTest, BeginIteratorIsNotEqualEndIteratorWhenBagIsEmpty) {
    RandomBag<int> bag;

    bag.add(1);

    EXPECT_TRUE(bag.begin() != bag.end());
    EXPECT_FALSE(bag.begin() == bag.end());
}

TEST(RandomBagTest, IteratorsAreEqualWhenBagIsEmpty) {
    RandomBag<int> bag;

    EXPECT_TRUE(bag.begin() == bag.begin());
    EXPECT_FALSE(bag.begin() != bag.begin());
}

TEST(RandomBagTest, IteratorAreNotEqualWhenBagIsNotEmpty) {
    RandomBag<int> bag;

    bag.add(1);

    EXPECT_TRUE(bag.begin() != bag.begin());
    EXPECT_FALSE(bag.begin() == bag.begin());
}

TEST(RandomBagTest, IterateOverSingleElementAlwaysReturnsTheSameValue) {
    RandomBag<int> bag;

    bag.add(1);

    auto iter{bag.begin()};
    EXPECT_EQ(*(++iter), 1);
    EXPECT_EQ(*(++iter), 1);
    EXPECT_EQ(*(++iter), 1);
}

TEST(RandomBagTest, IterateOverArrayWithMoreThanOneElementReturnsRandomeItem) {
    RandomBag<int> bag;

    bag.add(1);
    bag.add(2);
    bag.add(3);
    bag.add(4);

    auto iter{bag.begin()};
    EXPECT_THAT(*(++iter), IsBetween(1, 4));
    EXPECT_THAT(*(++iter), IsBetween(1, 4));
    EXPECT_THAT(*(++iter), IsBetween(1, 4));
    EXPECT_THAT(*(++iter), IsBetween(1, 4));
}
}

