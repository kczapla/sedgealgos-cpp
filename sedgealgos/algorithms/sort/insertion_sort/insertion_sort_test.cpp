#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort.hpp"
#include "sedgealgos/data_structures/array/array.hpp"

#include <gtest/gtest.h>

#include <functional>

using namespace sedgealgos::algorithms::sort;
using namespace sedgealgos::data_structures::array;

namespace {

using SortingFunc = std::function<void(Array<int>&)>;

struct TestParam {
    Array<int> to_sort;
    Array<int> sorted;
    SortingFunc sort;
};

TestParam make_insertion_sort_test_param(Array<int> to_sort, Array<int> sorted) {
    return TestParam{to_sort, sorted, insertion_sort::sort<int>};
}

struct SortTest : public ::testing::TestWithParam<TestParam> {};

TEST_P(SortTest, SortArray) {
    auto [to_sort, sorted, sort]{GetParam()};
    sort(to_sort);
    EXPECT_EQ(to_sort, sorted);
}

INSTANTIATE_TEST_SUITE_P(SortTest, SortTest, testing::Values(
    make_insertion_sort_test_param({}, {}),
    make_insertion_sort_test_param({1}, {1}),
    make_insertion_sort_test_param({1, 2}, {1, 2}),
    make_insertion_sort_test_param({2, 1}, {1, 2}),
    make_insertion_sort_test_param({2, 1, 3}, {1, 2, 3}),
    make_insertion_sort_test_param({2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 3, 30, 39, 40, 187}),
    make_insertion_sort_test_param({2, 1, 3, -1, 40, 39, 3, 30, 187}, {-1, 1, 2, 3, 3, 30, 39, 40, 187}),
    make_insertion_sort_test_param({2, 2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 2, 3, 30, 39, 40, 187})
));
}
