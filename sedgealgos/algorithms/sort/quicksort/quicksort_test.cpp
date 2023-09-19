#include "sedgealgos/algorithms/sort/quicksort/quicksort.hpp"
#include "sedgealgos/data_structures/array/array.hpp"


using namespace sedgealgos::algorithms::sort::quicksort;
using namespace sedgealgos::data_structures::array;

namespace {

using Container = Array<int>;

struct TestParam {
    Container to_sort;
};

struct QuicksortTest : public ::testing::TestWithParam<TestParam> {};

TEST_P(QuicksortTest, SortContainer) {
    auto [to_sort]{GetParam()};

    Quicksort<Container>::sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end())) << "after sorting = " << ::testing::PrintToString(to_sort);
}

INSTANTIATE_TEST_SUITE_P(Quicksort, QuicksortTest, testing::Values(
    TestParam{Container{5, 4, 3, 2, 1}},
    TestParam{Container{ 3, 1, 2, 4, 7, 5, 0, 9, 5, 6 }}
    ));
}
