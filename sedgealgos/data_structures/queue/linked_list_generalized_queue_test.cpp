#include "sedgealgos/data_structures/queue/linked_list_generalized_queue.hpp"

#include <gtest/gtest.h>

namespace {
using namespace ::testing;

template <typename T>
class GeneralizedQueueTest : public Test {
protected:
    T queue;
};

TYPED_TEST_SUITE_P(GeneralizedQueueTest);

TYPED_TEST_P(GeneralizedQueueTest, WhenNoItemsInQueueIsEmptyReturnsTrue) {
    EXPECT_TRUE(this->queue.is_empty());
}

REGISTER_TYPED_TEST_SUITE_P(
        GeneralizedQueueTest,
        WhenNoItemsInQueueIsEmptyReturnsTrue
);

INSTANTIATE_TYPED_TEST_SUITE_P(LinkedList, GeneralizedQueueTest, sedgealgos::data_structures::queue::LinkedListGeneralizedQueue<int>);
}
