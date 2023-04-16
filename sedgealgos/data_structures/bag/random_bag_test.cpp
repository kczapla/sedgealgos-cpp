#include "sedgealgos/data_structures/bag/random_bag.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace {
using namespace sedgealgos::data_structures::bag;
using namespace sedgealgos::data_structures::array;

template<typename T>
class RandomGeneratorMock {
public:
    void add(T t) {
        data.push_back(t);
    }

    int uniform(int) {
        return data.pop_back();
    }

private:
    Array<T> data;
};

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

TEST(RandomBagTest, BeginIteratorsAreEqualWhenBagHasSingleElement) {
    RandomBag<int> bag;

    bag.add(1);

    EXPECT_TRUE(bag.begin() == bag.begin());
    EXPECT_FALSE(bag.begin() != bag.begin());
}

TEST(RandomBagTest, IterateOverSingleItemBag) {
    RandomBag<int> bag;

    bag.add(1);

    auto iter{bag.begin()};
    EXPECT_EQ(*iter, 1);
    EXPECT_TRUE(++iter == bag.end());
}

TEST(RandomBagTest, IterateOverArrayWithMoreThanOneElementReturnsRandomItem) {
    RandomBag<int> bag;

    bag.add(1);
    bag.add(2);
    bag.add(3);
    bag.add(4);

    auto iter{bag.begin()};
    EXPECT_THAT(*iter, IsBetween(1, 4));
    EXPECT_THAT(*(++iter), IsBetween(1, 4));
    EXPECT_THAT(*(++iter), IsBetween(1, 4));
    EXPECT_THAT(*(++iter), IsBetween(1, 4));
    EXPECT_TRUE(++iter == bag.end());
}

TEST(RandomBagTest, IterateOverWithManyElements) {
    ::RandomGeneratorMock<int> random_generator;

    random_generator.add(0);
    random_generator.add(1);
    random_generator.add(2);
    random_generator.add(3);
    random_generator.add(4);
    random_generator.add(5);
    random_generator.add(6);
    random_generator.add(6);
    random_generator.add(7);
    random_generator.add(8);
    random_generator.add(9);

    Array<int> arr;

    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);

    RandomBag<int>::Iterator<int, RandomGeneratorMock<int>> iter{&arr, arr.size(), random_generator};
    RandomBag<int>::Iterator<int, RandomGeneratorMock<int>> end{&arr, 0, random_generator};

    EXPECT_THAT(*iter, 0);
    EXPECT_THAT(*(++iter), 1);
    EXPECT_THAT(*(++iter), 2);
    EXPECT_THAT(*(++iter), 3);
    EXPECT_THAT(*(++iter), 4);
    EXPECT_THAT(*(++iter), 5);
    EXPECT_THAT(*(++iter), 6);
    EXPECT_THAT(*(++iter), 7);
    EXPECT_THAT(*(++iter), 8);
    EXPECT_THAT(*(++iter), 9);
    EXPECT_TRUE(++iter == end);
}
}
