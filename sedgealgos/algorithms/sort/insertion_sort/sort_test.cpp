#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/selection_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_selection_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_precalc_gaps_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort_with_sentry.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort_without_exchange.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/top_down/sort.hpp"
#include "sedgealgos/algorithms/sort/sort/callbacks_mock.hpp"

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
};

struct SortTest : public ::testing::TestWithParam<TestParam> {};

TEST_P(SortTest, InsertionSort) {
    auto [to_sort, sorted]{GetParam()};

    insertion_sort::sort(to_sort);

    EXPECT_EQ(to_sort, sorted);
}

TEST_P(SortTest, SelectionSort) {
    auto [to_sort, sorted]{GetParam()};

    selection_sort::sort(to_sort);

    EXPECT_EQ(to_sort, sorted);
}

TEST_P(SortTest, ShellSort) {
    auto [to_sort, sorted]{GetParam()};

    shell_sort::sort(to_sort);

    EXPECT_EQ(to_sort, sorted);
}

TEST_P(SortTest, ShellSelectionSort) {
    auto [to_sort, sorted]{GetParam()};

    shell_selection_sort::sort(to_sort);

    EXPECT_EQ(to_sort, sorted);
}

TEST_P(SortTest, ShellPrecalcGapsSort) {
    auto [to_sort, sorted]{GetParam()};

    shell_precalc_gaps_sort::sort(to_sort);

    EXPECT_EQ(to_sort, sorted);
}

TEST_P(SortTest, InsertionSortWithSentry) {
    auto [to_sort, sorted]{GetParam()};

    insertion_sort_with_sentry::sort(to_sort);

    EXPECT_EQ(to_sort, sorted);
}

TEST_P(SortTest, InsertionSortWithoutExchange) {
    auto [to_sort, sorted]{GetParam()};

    insertion_sort_without_exchange::sort(to_sort);

    EXPECT_EQ(to_sort, sorted);
}

TEST_P(SortTest, TopDownMergeSort) {
    auto [to_sort, sorted]{GetParam()};

    sort::CallbacksMock cm;
    merge_sort::top_down::Sort ms{&cm};

    ms.sort(to_sort);

    EXPECT_EQ(to_sort, sorted);
}


INSTANTIATE_TEST_SUITE_P(Sort, SortTest, testing::Values(
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
