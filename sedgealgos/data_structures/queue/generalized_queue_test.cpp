#include "sedgealgos/data_structures/queue/linked_list_generalized_queue.hpp"
#include "sedgealgos/data_structures/queue/resizing_array_generalized_queue.hpp"

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

TYPED_TEST_P(GeneralizedQueueTest, WhenItemsInQueueIsEmptyReturnsFalse) {
    this->queue.insert(1);
    EXPECT_FALSE(this->queue.is_empty());
}

TYPED_TEST_P(GeneralizedQueueTest, DeleteItemFromSingleItemQueueMakesItEmpty) {
    this->queue.insert(1);
    this->queue.remove(0);
    EXPECT_TRUE(this->queue.is_empty());
}

TYPED_TEST_P(GeneralizedQueueTest, RemoveOldestElement) {
    this->queue.insert(1);
    this->queue.insert(2);
    this->queue.insert(3);
    this->queue.insert(4);

    EXPECT_EQ(this->queue.remove(0), 1);
}

TYPED_TEST_P(GeneralizedQueueTest, RemoveLatestElement) {
    this->queue.insert(1);
    this->queue.insert(2);
    this->queue.insert(3);
    this->queue.insert(4);

    EXPECT_EQ(this->queue.remove(3), 4);
}

TYPED_TEST_P(GeneralizedQueueTest, RemoveElementFromTheMiddle) {
    this->queue.insert(1);
    this->queue.insert(2);
    this->queue.insert(3);
    this->queue.insert(4);

    EXPECT_EQ(this->queue.remove(1), 2);
}

TYPED_TEST_P(GeneralizedQueueTest, RemoveAllItemsFromQueue) {
    this->queue.insert(1);
    this->queue.insert(2);
    this->queue.insert(3);
    this->queue.insert(4);

    this->queue.remove(0);
    this->queue.remove(0);
    this->queue.remove(0);
    this->queue.remove(0);

    EXPECT_TRUE(this->queue.is_empty());
}

TYPED_TEST_P(GeneralizedQueueTest, AddItemsToQueueFromWhichAllItemsWereDeleted) {
    this->queue.insert(1);
    this->queue.insert(2);
    this->queue.insert(3);
    this->queue.insert(4);

    this->queue.remove(0);
    this->queue.remove(0);
    this->queue.remove(0);
    this->queue.remove(0);

    this->queue.insert(5);
    this->queue.insert(6);
    this->queue.insert(7);
    this->queue.insert(8);

    EXPECT_EQ(this->queue.remove(1), 6);
}

REGISTER_TYPED_TEST_SUITE_P(
        GeneralizedQueueTest,
        WhenNoItemsInQueueIsEmptyReturnsTrue,
        WhenItemsInQueueIsEmptyReturnsFalse,
        DeleteItemFromSingleItemQueueMakesItEmpty,
        RemoveOldestElement,
        RemoveLatestElement,
        RemoveElementFromTheMiddle,
        RemoveAllItemsFromQueue,
        AddItemsToQueueFromWhichAllItemsWereDeleted
);

INSTANTIATE_TYPED_TEST_SUITE_P(LinkedList, GeneralizedQueueTest, sedgealgos::data_structures::queue::LinkedListGeneralizedQueue<int>);
INSTANTIATE_TYPED_TEST_SUITE_P(ResizingArray, GeneralizedQueueTest, sedgealgos::data_structures::queue::ResizingArrayGeneralizedQueue<int>);
}
