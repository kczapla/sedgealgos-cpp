#include "sedgealgos/algorithms/sort/heap_sort/heap_sort.hpp"
#include "sedgealgos/data_structures/array/array.hpp"

using namespace sedgealgos::algorithms::sort::heap_sort;
using namespace sedgealgos::data_structures::array;

namespace {

using Container = Array<int>;

struct TestParam {
    Container to_sort;
};

struct HeapSortTest : public ::testing::TestWithParam<TestParam> {};

TEST_P(HeapSortTest, SortContainer) {
    auto [to_sort]{GetParam()};

    HeapSort<Container>::sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end())) << "after sorting = " << ::testing::PrintToString(to_sort);
}

INSTANTIATE_TEST_SUITE_P(HeapSort, HeapSortTest, testing::Values(
    TestParam{Container{5, 4, 3, 2, 1}},
    TestParam{Container{ 3, 1, 2, 4, 7, 5, 0, 9, 5, 6 }}
    ));
}
