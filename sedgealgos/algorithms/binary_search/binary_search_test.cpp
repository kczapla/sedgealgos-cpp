#include "sedgealgos/algorithms/binary_search/binary_search.hpp"
#include "sedgealgos/array/array.hpp"

#include <gtest/gtest.h>

namespace {
using BinarySearch = sedgealgos::algorithms::binary_search::BinarySearch;
using Array = sedgealgos::array::Array<int>;

TEST(BinarySearchTest, FindsElementInSortedArray) {
    Array array{1,2,3,4,5,6,7};

    EXPECT_EQ(3, BinarySearch::rank(4, array));
}

TEST(BinarySearchTest, ReturnsMinusOneWhenKeyIsLargerThanHigherBound) {
    Array array{1,2,3,4,5,6,7};

    EXPECT_EQ(-1, BinarySearch::rank(10, array));
}

TEST(BinarySearchTest, ReturnsMinusOneWhenKeyIsLowerThanLowerBound) {
    Array array{1,2,3,4,5,6,7};

    EXPECT_EQ(-1, BinarySearch::rank(-1, array));
}

TEST(BinarySearchTest, ReturnsMinusOneWhenKeyIsNotInTheArray) {
    Array array{1,2,3,4,6,7,8};

    EXPECT_EQ(-1, BinarySearch::rank(-1, array));
}

TEST(BinarySearchTest, FindKeyWhenAtTheVeryBeginingOfTheArray) {
    Array array{1,2,3,4,5,6,7,8,9,10};

    EXPECT_EQ(0, BinarySearch::rank(1, array));
}

TEST(BinarySearchTest, FindKeyWhenAtTheOneAfterVeryBeginingOfTheArray) {
    Array array{1,2,3,4,5,6,7,8,9,10};

    EXPECT_EQ(0, BinarySearch::rank(1, array));
}

TEST(BinarySearchTest, FindKeyWhenAtTheVeryEndOfTheArray) {
    Array array{1,2,3,4,5,6,7,8,9,10};

    EXPECT_EQ(9, BinarySearch::rank(10, array));
}

TEST(BinarySearchTest, FindKeyWhenAtTheOneBeforeVeryEndOfTheArray) {
    Array array{1,2,3,4,5,6,7,8,9,10};

    EXPECT_EQ(8, BinarySearch::rank(9, array));
}
}

