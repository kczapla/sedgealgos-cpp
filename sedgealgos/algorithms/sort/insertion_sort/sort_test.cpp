#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/selection_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_selection_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_precalc_gaps_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort_with_sentry.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort_without_exchange.hpp"

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

struct SortTest : public ::testing::TestWithParam<TestParam> {};

TEST_P(SortTest, SortArray) {
    auto [to_sort, sorted, sort]{GetParam()};
    sort(to_sort);
    EXPECT_EQ(to_sort, sorted);
}

TestParam make_insertion_sort_test_param(Array<int> const& to_sort, Array<int> const& sorted) {
    return TestParam{to_sort, sorted, insertion_sort::sort<int>};
}

TestParam make_selection_sort_test_param(Array<int> const& to_sort, Array<int> const& sorted) {
    return TestParam{to_sort, sorted, selection_sort::sort<int>};
}

TestParam make_shell_sort_test_param(Array<int> const& to_sort, Array<int> const& sorted) {
    return TestParam{to_sort, sorted, shell_sort::sort<int>};
}

TestParam make_shell_selection_sort_test_param(Array<int> const& to_sort, Array<int> const& sorted) {
    return TestParam{to_sort, sorted, shell_selection_sort::sort<int>};
}

TestParam make_shell_precalc_gaps_sort_test_param(Array<int> const& to_sort, Array<int> const& sorted) {
    return TestParam{to_sort, sorted, shell_precalc_gaps_sort::sort<int>};
}

TestParam make_insertion_sort_with_sentry(Array<int> const& to_sort, Array<int> const& sorted) {
    return TestParam{to_sort, sorted, insertion_sort_with_sentry::sort<int>};
}

TestParam make_insertion_sort_without_exchange(Array<int> const& to_sort, Array<int> const& sorted) {
    return TestParam{to_sort, sorted, insertion_sort_without_exchange::sort<int>};
}

INSTANTIATE_TEST_SUITE_P(InsertionSort, SortTest, testing::Values(
    make_insertion_sort_test_param({}, {}),
    make_insertion_sort_test_param({1}, {1}),
    make_insertion_sort_test_param({1, 2}, {1, 2}),
    make_insertion_sort_test_param({2, 1}, {1, 2}),
    make_insertion_sort_test_param({2, 1, 3}, {1, 2, 3}),
    make_insertion_sort_test_param({2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 3, 30, 39, 40, 187}),
    make_insertion_sort_test_param({2, 1, 3, -1, 40, 39, 3, 30, 187}, {-1, 1, 2, 3, 3, 30, 39, 40, 187}),
    make_insertion_sort_test_param({2, 2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 2, 3, 30, 39, 40, 187})
));

INSTANTIATE_TEST_SUITE_P(SelectionSort, SortTest, testing::Values(
    make_selection_sort_test_param({}, {}),
    make_selection_sort_test_param({1}, {1}),
    make_selection_sort_test_param({1, 2}, {1, 2}),
    make_selection_sort_test_param({2, 1}, {1, 2}),
    make_selection_sort_test_param({2, 1, 3}, {1, 2, 3}),
    make_selection_sort_test_param({2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 3, 30, 39, 40, 187}),
    make_selection_sort_test_param({2, 1, 3, -1, 40, 39, 3, 30, 187}, {-1, 1, 2, 3, 3, 30, 39, 40, 187}),
    make_selection_sort_test_param({2, 2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 2, 3, 30, 39, 40, 187})
));

INSTANTIATE_TEST_SUITE_P(ShellSort, SortTest, testing::Values(
    make_shell_sort_test_param({}, {}),
    make_shell_sort_test_param({1}, {1}),
    make_shell_sort_test_param({1, 2}, {1, 2}),
    make_shell_sort_test_param({2, 1}, {1, 2}),
    make_shell_sort_test_param({2, 1, 3}, {1, 2, 3}),
    make_shell_sort_test_param({2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 3, 30, 39, 40, 187}),
    make_shell_sort_test_param({2, 1, 3, -1, 40, 39, 3, 30, 187}, {-1, 1, 2, 3, 3, 30, 39, 40, 187}),
    make_shell_sort_test_param({2, 2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 2, 3, 30, 39, 40, 187})
));

INSTANTIATE_TEST_SUITE_P(ShellSelectionSort, SortTest, testing::Values(
    make_shell_selection_sort_test_param({}, {}),
    make_shell_selection_sort_test_param({1}, {1}),
    make_shell_selection_sort_test_param({1, 2}, {1, 2}),
    make_shell_selection_sort_test_param({2, 1}, {1, 2}),
    make_shell_selection_sort_test_param({2, 1, 3}, {1, 2, 3}),
    make_shell_selection_sort_test_param({2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 3, 30, 39, 40, 187}),
    make_shell_selection_sort_test_param({2, 1, 3, -1, 40, 39, 3, 30, 187}, {-1, 1, 2, 3, 3, 30, 39, 40, 187}),
    make_shell_selection_sort_test_param({2, 2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 2, 3, 30, 39, 40, 187})
));

INSTANTIATE_TEST_SUITE_P(ShellPrecalcGapsSort, SortTest, testing::Values(
    make_shell_precalc_gaps_sort_test_param({}, {}),
    make_shell_precalc_gaps_sort_test_param({1}, {1}),
    make_shell_precalc_gaps_sort_test_param({1, 2}, {1, 2}),
    make_shell_precalc_gaps_sort_test_param({2, 1}, {1, 2}),
    make_shell_precalc_gaps_sort_test_param({2, 1, 3}, {1, 2, 3}),
    make_shell_precalc_gaps_sort_test_param({2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 3, 30, 39, 40, 187}),
    make_shell_precalc_gaps_sort_test_param({2, 1, 3, -1, 40, 39, 3, 30, 187}, {-1, 1, 2, 3, 3, 30, 39, 40, 187}),
    make_shell_precalc_gaps_sort_test_param({2, 2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 2, 3, 30, 39, 40, 187})
));

INSTANTIATE_TEST_SUITE_P(InsertionSortWithSentry, SortTest, testing::Values(
    make_insertion_sort_with_sentry({}, {}),
    make_insertion_sort_with_sentry({1}, {1}),
    make_insertion_sort_with_sentry({1, 2}, {1, 2}),
    make_insertion_sort_with_sentry({2, 1}, {1, 2}),
    make_insertion_sort_with_sentry({2, 1, 3}, {1, 2, 3}),
    make_insertion_sort_with_sentry({2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 3, 30, 39, 40, 187}),
    make_insertion_sort_with_sentry({2, 1, 3, -1, 40, 39, 3, 30, 187}, {-1, 1, 2, 3, 3, 30, 39, 40, 187}),
    make_insertion_sort_with_sentry({2, 2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 2, 3, 30, 39, 40, 187})
));

INSTANTIATE_TEST_SUITE_P(InsertionSortWithoutExchange, SortTest, testing::Values(
    make_insertion_sort_without_exchange({}, {}),
    make_insertion_sort_without_exchange({1}, {1}),
    make_insertion_sort_without_exchange({1, 2}, {1, 2}),
    make_insertion_sort_without_exchange({2, 1}, {1, 2}),
    make_insertion_sort_without_exchange({2, 1, 3}, {1, 2, 3}),
    make_insertion_sort_without_exchange({2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 3, 30, 39, 40, 187}),
    make_insertion_sort_without_exchange({2, 1, 3, -1, 40, 39, 3, 30, 187}, {-1, 1, 2, 3, 3, 30, 39, 40, 187}),
    make_insertion_sort_without_exchange({2, 2, 1, 3, -1, 40, 39, 30, 187}, {-1, 1, 2, 2, 3, 30, 39, 40, 187})
));
}
