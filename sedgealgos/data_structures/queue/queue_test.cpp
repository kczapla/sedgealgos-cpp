#include "sedgealgos/data_structures/queue/queue.hpp"
#include "sedgealgos/data_structures/queue/resizing_array_queue.hpp"
#include "sedgealgos/data_structures/queue/cycling_linked_list_queue.hpp"

#include <gtest/gtest.h>

namespace {
using namespace ::testing;

template <typename T>
class QueueTest : public Test {
protected:
    T queue;
};

TYPED_TEST_SUITE_P(QueueTest);

TYPED_TEST_P(QueueTest, EnqueuesElementToQueueAndSideEffectIsIncreasedSize) {
    this->queue.enqueue(1);

    EXPECT_EQ(this->queue.size(), 1);
}

TYPED_TEST_P(QueueTest, DequeuesElementFromQueueAndSideEffectIsDecreasedSize) {
    this->queue.enqueue(1);
    this->queue.enqueue(2);

    EXPECT_EQ(this->queue.dequeue(), 1);
    EXPECT_EQ(this->queue.size(), 1);
}

TYPED_TEST_P(QueueTest, EnqueuesElementAfterAllElemsDequeued) {
    this->queue.enqueue(1);
    this->queue.enqueue(2);

    this->queue.dequeue();
    this->queue.dequeue();

    this->queue.enqueue(3);
    this->queue.enqueue(4);

    EXPECT_EQ(this->queue.size(), 2);
    EXPECT_EQ(this->queue.dequeue(), 3);
}

TYPED_TEST_P(QueueTest, IsEmptyAfterDequeuedAllElements) {
    this->queue.enqueue(1);
    this->queue.enqueue(2);

    this->queue.dequeue();
    this->queue.dequeue();

    EXPECT_EQ(this->queue.size(), 0);
    EXPECT_TRUE(this->queue.is_empty());
}

TYPED_TEST_P(QueueTest, IterateOverElementsWithPrefixOperator) {
    this->queue.enqueue(1);
    this->queue.enqueue(2);
    this->queue.enqueue(3);

    auto iter{this->queue.begin()};

    EXPECT_EQ(*iter, 1);
    EXPECT_EQ(*(++iter), 2);
    EXPECT_EQ(*(++iter), 3);
    EXPECT_EQ(++iter, this->queue.end());
}

TYPED_TEST_P(QueueTest, IterateOverElementsWithPostfixOperator) {
    this->queue.enqueue(1);
    this->queue.enqueue(2);
    this->queue.enqueue(3);

    auto iter{this->queue.begin()};

    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 2);
    EXPECT_EQ(*(iter++), 3);
    EXPECT_EQ(iter, this->queue.end());
}

TYPED_TEST_P(QueueTest, ConstIterateOverElementsWithPrefixOperator) {
    this->queue.enqueue(1);
    this->queue.enqueue(2);
    this->queue.enqueue(3);

    auto iter{this->queue.cbegin()};

    EXPECT_EQ(*iter, 1);
    EXPECT_EQ(*(++iter), 2);
    EXPECT_EQ(*(++iter), 3);
    EXPECT_EQ(++iter, this->queue.cend());
}

TYPED_TEST_P(QueueTest, ConstIterateOverElementsWithPostfixOperator) {
    this->queue.enqueue(1);
    this->queue.enqueue(2);
    this->queue.enqueue(3);

    auto iter{this->queue.cbegin()};

    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 2);
    EXPECT_EQ(*(iter++), 3);
    EXPECT_EQ(iter, this->queue.cend());
}

TYPED_TEST_P(QueueTest, IteratesOverElementsWithForRangeLoop) {
    this->queue.enqueue(1);
    this->queue.enqueue(2);
    this->queue.enqueue(3);

    for ([[maybe_unused]] auto s : this->queue) {}
    for ([[maybe_unused]] auto& s : this->queue) {}
    for ([[maybe_unused]] auto const& s : this->queue) {}
}

TYPED_TEST_P(QueueTest, IterateOverElementsAfterQueueingAndDequeueing) {
    this->queue.enqueue(1);
    this->queue.enqueue(2);
    this->queue.enqueue(3);
    this->queue.enqueue(4);
    this->queue.enqueue(5);
    this->queue.enqueue(6);

    this->queue.dequeue();
    this->queue.dequeue();


    auto iter{this->queue.begin()};

    EXPECT_EQ(*(iter++), 3);
    EXPECT_EQ(*(iter++), 4);
    EXPECT_EQ(*(iter++), 5);
    EXPECT_EQ(*(iter++), 6);
    EXPECT_EQ(iter, this->queue.end());
}

REGISTER_TYPED_TEST_SUITE_P(
        QueueTest,
        EnqueuesElementToQueueAndSideEffectIsIncreasedSize,
        DequeuesElementFromQueueAndSideEffectIsDecreasedSize,
        EnqueuesElementAfterAllElemsDequeued,
        IsEmptyAfterDequeuedAllElements,
        IterateOverElementsWithPrefixOperator,
        IterateOverElementsWithPostfixOperator,
        ConstIterateOverElementsWithPrefixOperator,
        ConstIterateOverElementsWithPostfixOperator,
        IteratesOverElementsWithForRangeLoop,
        IterateOverElementsAfterQueueingAndDequeueing
);


INSTANTIATE_TYPED_TEST_SUITE_P(LinkedList, QueueTest, sedgealgos::data_structures::queue::Queue<int>);
INSTANTIATE_TYPED_TEST_SUITE_P(ResizingArray, QueueTest, sedgealgos::data_structures::queue::ResizingArrayQueue<int>);
INSTANTIATE_TYPED_TEST_SUITE_P(CyclingLinkedList, QueueTest, sedgealgos::data_structures::queue::CyclingLinkedListQueue<int>);
}
