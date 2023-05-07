#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort.hpp"
#include "sedgealgos/data_structures/array/array.hpp"

#include <gtest/gtest.h>

using namespace sedgealgos::algorithms::sort::insertion_sort;
using namespace sedgealgos::data_structures::array;

namespace {

struct TestParam {
    Array<int> to_sort;
    Array<int> sorted;
};

struct SortTest : public ::testing::TestWithParam<TestParam> {};

TEST_P(SortTest, SortArray) {
    auto [to_sort, sorted]{GetParam()};
    sort(to_sort);
    EXPECT_EQ(to_sort, sorted);
}

INSTANTIATE_TEST_SUITE_P(SortTest, SortTest, testing::Values(
    TestParam{{}, {}},
    TestParam{{1}, {1}},
    TestParam{{1, 2}, {1, 2}},
    TestParam{{2, 1}, {1, 2}},
    TestParam{{2, 1, 3}, {1, 2, 3}},
    TestParam{{2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 3, 30, 39, 40, 187}},
    TestParam{{2, 1, 3, -1, 40, 39, 3, 30, 187}, {-1, 1, 2, 3, 3, 30, 39, 40, 187}},
    TestParam{{2, 2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 2, 3, 30, 39, 40, 187}}
));
}
