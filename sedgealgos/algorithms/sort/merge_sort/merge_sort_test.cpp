#include "sedgealgos/algorithms/sort/merge_sort/top_down/sort.hpp"
#include "sedgealgos/algorithms/sort/sort/callbacks_mock.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/merge/merge.hpp"

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

struct MergeSortTest : public ::testing::TestWithParam<TestParam> {};

TEST_P(MergeSortTest, TopDownMergeSortWithStandardMerge) {
    auto [to_sort]{GetParam()};

    sort::CallbacksMock cm;
    EXPECT_CALL(cm, on_array_access).Times(::testing::AnyNumber());
    EXPECT_CALL(cm, on_sort_start).Times(::testing::AnyNumber());
    EXPECT_CALL(cm, on_sort_stop).Times(::testing::AnyNumber());
    
    merge_sort::top_down::Sort<Container> ms{merge_sort::merge::merge<Container>, &cm};

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

INSTANTIATE_TEST_SUITE_P(StandardMerge, MergeSortTest, testing::Values(TestParam{generate_test_container(0)}));
}
