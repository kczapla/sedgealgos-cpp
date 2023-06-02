#include "sedgealgos/algorithms/sort/merge_sort/top_down/sort.hpp"
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

struct TopDownMergeSortTest : public ::testing::TestWithParam<TestParam> {
protected:
    TopDownMergeSortTest() {
        EXPECT_CALL(callbacks, on_array_access).Times(::testing::AnyNumber());
        EXPECT_CALL(callbacks, on_sort_start).Times(::testing::AnyNumber());
        EXPECT_CALL(callbacks, on_sort_stop).Times(::testing::AnyNumber());
    }

    sort::CallbacksMock callbacks;
};

TEST_P(TopDownMergeSortTest, StandardMerge) {
    auto [to_sort]{GetParam()};

    merge_sort::top_down::Sort<Container> ms{merge_sort::merge::merge<Container>, &callbacks};

    ms.sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end()));
}

TEST_P(TopDownMergeSortTest, FasterMerge) {
    auto [to_sort]{GetParam()};

    merge_sort::top_down::Sort<Container> ms{merge_sort::merge::faster_merge<Container>, &callbacks};

    ms.sort(to_sort);

    EXPECT_TRUE(std::is_sorted(to_sort.begin(), to_sort.end()));
}


Container generate_test_container(typename Container::Size size) {
    std::random_device rd;
    std::mt19937 gen{rd()};

    Container container;
    std::uniform_int_distribution<> d{static_cast<int>(size)};
    for (typename Container::Size i{0}; i < size; i++) {
        container.push_back(d(gen));
    }

    return container;
}

INSTANTIATE_TEST_SUITE_P(MergeSort, TopDownMergeSortTest, testing::Values(
    TestParam{generate_test_container(0)},
    TestParam{generate_test_container(1)},
    TestParam{generate_test_container(2)},
    TestParam{generate_test_container(4)},
    TestParam{generate_test_container(10)},
    TestParam{generate_test_container(32)},
    TestParam{generate_test_container(1024)}
    ));
}
