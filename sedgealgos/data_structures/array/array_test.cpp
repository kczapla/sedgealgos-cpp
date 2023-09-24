#include "sedgealgos/data_structures/array/array.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace {
using namespace ::testing;
using namespace sedgealgos::data_structures::array;

TEST(ArrayTest, EmptyListInitializerCtor) {
    Array<int> arr{};

    EXPECT_TRUE(arr.is_empty());
}

TEST(ArrayTest, IteratorCtor) {
    Array<int> arr1{1, 2, 3, 4};
    Array<int> arr2{arr1.cbegin(), arr1.cend()};

    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
    EXPECT_EQ(arr2[3], 4);
}

TEST(ArrayTest, ListInitializerCtor) {
    Array<int> arr{1, 2, 3, 4};

    EXPECT_THAT(arr, ElementsAre(1, 2, 3, 4));
}

TEST(ArrayTest, CopyCtor) {
    Array<int> arr{1, 2, 3, 4};

    {
        Array<int> arr1{arr};
        EXPECT_THAT(arr, ElementsAre(1, 2, 3, 4));
    }

    EXPECT_THAT(arr, ElementsAre(1, 2, 3, 4));
}

TEST(ArrayTest, CopyArrayThatIsNotEmpty) {
    Array<int> arr(5, 1);

    auto new_arr{arr};

    EXPECT_EQ(new_arr[0], 1);
    EXPECT_EQ(new_arr[0], 1);
    EXPECT_EQ(new_arr[0], 1);
    EXPECT_EQ(new_arr[0], 1);
    EXPECT_EQ(new_arr[0], 1);
}

TEST(ArrayTest, InitializeArrayWithNZeroValueItemIncreasesSize) {
    Array<int> arr(5);

    EXPECT_EQ(arr.size(), 5);
}

TEST(ArrayTest, InitializeArrayWithNMItemValuesIncreasesSize) {
    Array<int> arr(5);

    EXPECT_EQ(arr.size(), 5);
}

TEST(ArrayTest, InitializeArrayWithNZeroValuesOfItem) {
    Array<int> arr(5);

    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 0);
    EXPECT_EQ(arr[2], 0);
    EXPECT_EQ(arr[3], 0);
    EXPECT_EQ(arr[4], 0);
}

TEST(ArrayTest, InitializeArrayWithNMItemValues) {
    Array<int> arr(5, 1);

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 1);
    EXPECT_EQ(arr[3], 1);
    EXPECT_EQ(arr[4], 1);
}

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

TEST(ArrayTest, PushBackManyElement) {
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
    arr.push_back(10);
    arr.push_back(11);
}

TEST(ArrayTest, RemoveItemFromSingleItemArray) {
    Array<int> arr;
    arr.push_back(0);

    arr.remove(0);

    EXPECT_TRUE(arr.is_empty());
}

TEST(ArrayTest, RemoveLastItemFromArray) {
    Array<int> arr;
    arr.push_back(0);
    arr.push_back(1);

    arr.remove(1);

    EXPECT_THAT(arr, ElementsAre(0));
}

TEST(ArrayTest, RemoveFirstItemFromArray) {
    Array<int> arr;
    arr.push_back(0);
    arr.push_back(1);

    arr.remove(0);

    EXPECT_THAT(arr, ElementsAre(1));
}

TEST(ArrayTest, RemoveItemFromTheMiddle) {
    Array<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    arr.remove(1);

    EXPECT_THAT(arr, ElementsAre(0, 2));
}

TEST(ArrayTest, RemoveItemFromTheMiddleAndAddNewOneAtTheEnd) {
    Array<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    arr.remove(1);

    arr.push_back(3);

    EXPECT_THAT(arr, ElementsAre(0, 2, 3));
}

TEST(ArrayTest, BeginIteratorIsEqualEndIteratorWhenArrayIsEmpty) {
    Array<int> arr;

    EXPECT_TRUE(arr.begin() == arr.end());
}

TEST(ArrayTest, BeginIteratorIsNotEqualEndIteratorWhenArrayIsNotEmpty) {
    Array<int> arr;

    arr.push_back(1);

    EXPECT_FALSE(arr.begin() == arr.end());
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

TEST(ArrayTest, TwoEmptyArraysAreEqual) {
    Array<int> lhs;
    Array<int> rhs;

    EXPECT_EQ(lhs, rhs);
}

TEST(ArrayTest, TwoNonEmptyArraysAreEqual) {
    Array<int> lhs{1, 2, 3, 4};
    Array<int> rhs{1, 2, 3, 4};

    EXPECT_EQ(lhs, rhs);
}

TEST(ArrayTest, TwoNonEmptyArraysAreNotEqual) {
    Array<int> lhs{1, 2, 3, 4};
    Array<int> rhs{1, 2, 3, 5};

    EXPECT_NE(lhs, rhs);
}

TEST(ArrayTest, TwoNonEmptyArraysHaveDifferentLengths) {
    Array<int> lhs{1, 2, 3, 4};
    Array<int> rhs{1, 2, 3, 4, 5};

    EXPECT_NE(lhs, rhs);
}

TEST(ArrayTest, TwoArraysWithSingleDifferentElements) {
    Array<int> lhs{1};
    Array<int> rhs{2};

    EXPECT_NE(lhs, rhs);
}

TEST(ArrayTest, EmptyArrayAndArrayWithOneElementAreNotEqual) {
    Array<int> lhs{1};
    Array<int> rhs{};

    EXPECT_NE(lhs, rhs);
}
}
