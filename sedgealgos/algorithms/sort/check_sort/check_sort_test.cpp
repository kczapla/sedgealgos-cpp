#include "sedgealgos/algorithms/sort/check_sort/check_sort.hpp"
#include "sedgealgos/data_structures/array/array.hpp"

#include <gtest/gtest.h>

TEST(TestCheckSort, CheckSort) {
    sedgealgos::data_structures::array::Array<int> arr{2, 3, 2, 0, -1, -10};
    EXPECT_TRUE(sedgealgos::algorithms::sort::check_sort::check_sort(arr));
}