#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/top_down/sort.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/improved_top_down/merge_sort.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/bottom_up/sort.hpp"
#include "sedgealgos/algorithms/sort/sort/callbacks_mock.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/merge/merge.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/merge/faster_merge.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/merge/no_copy_merge.hpp"

#include "sedgealgos/data_structures/array/array.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <algorithm>
#include <random>
#include <unordered_map>

using namespace sedgealgos::algorithms::sort;
using namespace sedgealgos::data_structures::array;

namespace {

using Container = Array<int>;

MATCHER_P(IsSortedVariant, actual_array, "") {
    std::unordered_map<int, int> counter;
    std::for_each(actual_array.cbegin(), actual_array.cend(), [&counter](auto a) { counter[a]++; });
    std::for_each(arg.cbegin(), arg.cend(), [&counter](auto a){ counter[a]--; });
    auto has_additional_items{std::any_of(counter.begin(), counter.end(), [](auto k) { return k.second != 0; })};

    if (has_additional_items) {
        return false;
    }

    return std::is_sorted(arg.cbegin(), arg.cend());
}

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

TEST_P(MergeSortTest, ImprovedTopDownNoCopyMerge) {
    auto [to_sort]{GetParam()};


    merge_sort::improved_top_down::Sort<Container, insertion_sort::InsertionSort, merge_sort::merge::NoCopyMerge> ms{&callbacks};

    auto sorted_to_sort{to_sort};
    ms.sort(sorted_to_sort);

    // EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end())) << "after sorting = " << ::testing::PrintToString(to_sort);
    EXPECT_THAT(sorted_to_sort, IsSortedVariant(to_sort)) << "after sorting = " << ::testing::PrintToString(sorted_to_sort);
    // Container t1{1,2,3};
    // Container t2{1,2,3,4};
    // EXPECT_THAT(t1, IsSortedVariant(t2)) << "after sorting = " << ::testing::PrintToString(sorted_to_sort);
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
    TestParam{Container{2, 1}},
    TestParam{Container{1, -2, -3, -4}},
    TestParam{Container{1, -2, -3, -4, -5}},
    TestParam{Container{1, -2, -3, -4, -5, -6}},
    TestParam{Container{1, -2, -3, -4, -5, -6, -7}},
    TestParam{Container{1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12}},
    TestParam{Container{1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23}},
    TestParam{Container{1, -2, -3, -4, -5, -6, -7, -8}},
    TestParam{Container{1, -2, -3, -4, -5, -6, -7, -8, -9}},
    TestParam{generate_test_container(11)},
    TestParam{Container{1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16}},
    TestParam{Container{1, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27, -28, -29, -31, -32}}
    // TestParam{generate_test_container(0)},
    // TestParam{generate_test_container(1)},
    // TestParam{generate_test_container(2)},
    // TestParam{generate_test_container(4)},
    // TestParam{generate_test_container(5)},
    // TestParam{generate_test_container(6)},
    // TestParam{generate_test_container(7)},
    // TestParam{generate_test_container(8)},
    // TestParam{generate_test_container(9)},
    // TestParam{generate_test_container(10)},
    // TestParam{generate_test_container(32)},
    // TestParam{generate_test_container(1024)}
    ));
}
