#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort.hpp"
#include "sedgealgos/data_structures/array/array.hpp"

#include <gtest/gtest.h>

using namespace sedgealgos::algorithms::sort::insertion_sort;
using namespace sedgealgos::data_structures::array;

namespace {

TEST(InsertionSortTest, DoNothingForEmptyArray) {
    Array<int> arr;

    sort(arr);

    EXPECT_TRUE(arr.is_empty());
}

TEST(InsertionSortTest, DoNothingArrayWithOneElement) {
    Array<int> arr;
    arr.push_back(1);

    sort(arr);

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr.size(), 1);
}

TEST(InsertionSortTest, DoNothingForSortedArrayOfTwo) {
    Array<int> arr;
    arr.push_back(1);
    arr.push_back(2);

    sort(arr);

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr.size(), 2);
}

}
