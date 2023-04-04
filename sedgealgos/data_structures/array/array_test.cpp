#include "sedgealgos/data_structures/array/array.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::data_structures::array;

TEST(ArrayTest, PushesBackOneElement) {
    Array<int> arr;
    arr.push_back(1);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 1);
}

TEST(ArrayTest, PushesBackTwoElements) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
}

TEST(ArrayTest, PushesBackThreeElements) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(ArrayTest, PopsBackElements) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    EXPECT_EQ(arr.pop_back(), 3);
    EXPECT_EQ(arr.size(), 2);

    EXPECT_EQ(arr.pop_back(), 2);
    EXPECT_EQ(arr.size(), 1);

    EXPECT_EQ(arr.pop_back(), 1);
    EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, IteratesOverElementsWithPostfixIncrement) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    auto iter{arr.begin()};
    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 2);
    EXPECT_EQ(*(iter++), 3);
    EXPECT_EQ(iter, arr.end());

    iter = arr.begin();
    EXPECT_EQ(*iter, 1);
    EXPECT_EQ(*(++iter), 2);
    EXPECT_EQ(*(++iter), 3);
    EXPECT_EQ(++iter, arr.end());

    auto const_iter{arr.cbegin()};
    EXPECT_EQ(*(const_iter++), 1);
    EXPECT_EQ(*(const_iter++), 2);
    EXPECT_EQ(*(const_iter++), 3);
    EXPECT_EQ(const_iter, arr.cend());

    const_iter = arr.cbegin();
    EXPECT_EQ(*const_iter, 1);
    EXPECT_EQ(*(++const_iter), 2);
    EXPECT_EQ(*(++const_iter), 3);
    EXPECT_EQ(++const_iter, arr.cend());
}

TEST(ArrayTest, PerformsForRangeLoop) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    for ([[maybe_unused]] auto const& a : arr) {}
}
}

