#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/top_down/sort.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/improved_top_down/merge_sort.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/bottom_up/sort.hpp"
#include "sedgealgos/algorithms/sort/sort/callbacks_mock.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/merge/merge.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/merge/faster_merge.hpp"

#include "sedgealgos/data_structures/array/array.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <random>

using namespace sedgealgos::algorithms::sort;
using namespace sedgealgos::data_structures::array;

namespace {

using Container = Array<int>;

struct TestParam {
    Container to_sort;
};

std::ostream& operator<<(std::ostream& os, TestParam const& tp) {
    os << "{ to_sort: " << tp.to_sort << " }";
    
    return os;
}

struct MergeSortTest : public ::testing::TestWithParam<TestParam> {
protected:
    MergeSortTest() {
        EXPECT_CALL(callbacks, on_array_access).Times(::testing::AnyNumber());
        EXPECT_CALL(callbacks, on_sort_start).Times(::testing::AnyNumber());
        EXPECT_CALL(callbacks, on_sort_stop).Times(::testing::AnyNumber());
    }

    sort::CallbacksMock callbacks;
};

TEST_P(MergeSortTest, TopDownStandardMerge) {
    auto [to_sort]{GetParam()};

    merge_sort::top_down::Sort<Container, merge_sort::merge::StandardMerge> ms{&callbacks};

    ms.sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end())) << "after sorting = " << ::testing::PrintToString(to_sort);
}

TEST_P(MergeSortTest, TopDownFasterMerge) {
    auto [to_sort]{GetParam()};

    merge_sort::top_down::Sort<Container, merge_sort::merge::FasterMerge> ms{&callbacks};

    ms.sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end())) << "after sorting = " << ::testing::PrintToString(to_sort);
}

TEST_P(MergeSortTest, ImprovedTopDownStandardMerge) {
    auto [to_sort]{GetParam()};

    merge_sort::improved_top_down::Sort<Container, insertion_sort::InsertionSort, merge_sort::merge::StandardMerge> ms{&callbacks};

    ms.sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end())) << "after sorting = " << ::testing::PrintToString(to_sort);
}

TEST_P(MergeSortTest, ImprovedTopDownFasterMerge) {
    auto [to_sort]{GetParam()};

    merge_sort::improved_top_down::Sort<Container, insertion_sort::InsertionSort, merge_sort::merge::FasterMerge> ms{&callbacks};

    ms.sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end())) << "after sorting = " << ::testing::PrintToString(to_sort);
}

TEST_P(MergeSortTest, BottomUpStandardMerge) {
    auto [to_sort]{GetParam()};

    merge_sort::bottom_up::Sort<Container, merge_sort::merge::StandardMerge> ms{&callbacks};

    ms.sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end())) << "after sorting = " << ::testing::PrintToString(to_sort);
}

TEST_P(MergeSortTest, BottomUpFasterMerge) {
    auto [to_sort]{GetParam()};

    merge_sort::bottom_up::Sort<Container, merge_sort::merge::FasterMerge> ms{&callbacks};

    ms.sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end())) << "after sorting = " << ::testing::PrintToString(to_sort);
}

Container generate_test_container(typename Container::Size size) {
    std::random_device rd;
    std::mt19937 gen{rd()};

    Container container;
    std::uniform_int_distribution<> d{0, static_cast<int>(size)};
    for (typename Container::Size i{0}; i < size; i++) {
        container.push_back(d(gen));
    }

    return container;
}

INSTANTIATE_TEST_SUITE_P(MergeSort, MergeSortTest, testing::Values(
    TestParam{generate_test_container(0)},
    TestParam{generate_test_container(1)},
    TestParam{generate_test_container(2)},
    TestParam{generate_test_container(4)},
    TestParam{generate_test_container(10)},
    TestParam{generate_test_container(32)},
    TestParam{generate_test_container(1024)}
    ));
}
