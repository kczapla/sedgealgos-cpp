#include "sedgealgos/data_structures/queue/queue.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::data_structures::queue;

TEST(QueueTest, EnqueuesElementToQueueAndSideEffectIsIncreasedSize) {
    Queue<int> q;
    q.enqueue(1);

    EXPECT_EQ(q.size(), 1);
}

TEST(QueueTest, DequeuesElementFromQueueAndSideEffectIsDecreasedSize) {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);

    EXPECT_EQ(q.dequeue(), 1);
    EXPECT_EQ(q.size(), 1);
}

TEST(QueueTest, EnqueuesElementAfterAllElemsDequeued) {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);

    q.dequeue();
    q.dequeue();

    q.enqueue(3);
    q.enqueue(4);

    EXPECT_EQ(q.size(), 2);
    EXPECT_EQ(q.dequeue(), 3);
}

TEST(QueueTest, IsEmptyAfterDequeuedAllElements) {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);

    q.dequeue();
    q.dequeue();

    EXPECT_EQ(q.size(), 0);
    EXPECT_TRUE(q.is_empty());
}

TEST(QueueTest, IterateOverElementsWithPrefixOperator) {
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    auto iter{q.begin()};

    EXPECT_EQ(*iter, 1);
    EXPECT_EQ(*(++iter), 2);
    EXPECT_EQ(*(++iter), 3);
    EXPECT_EQ(++iter, q.end());
}

TEST(QueueTest, IterateOverElementsWithPostfixOperator) {
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    auto iter{q.begin()};

    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 2);
    EXPECT_EQ(*(iter++), 3);
    EXPECT_EQ(iter, q.end());
}

TEST(QueueTest, ConstIterateOverElementsWithPrefixOperator) {
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    auto iter{q.cbegin()};

    EXPECT_EQ(*iter, 1);
    EXPECT_EQ(*(++iter), 2);
    EXPECT_EQ(*(++iter), 3);
    EXPECT_EQ(++iter, q.cend());
}

TEST(QueueTest, ConstIterateOverElementsWithPostfixOperator) {
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    auto iter{q.cbegin()};

    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 2);
    EXPECT_EQ(*(iter++), 3);
    EXPECT_EQ(iter, q.cend());
}

TEST(QueueTest, IteratesOverWithForRangeLoop) {
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    for ([[maybe_unused]] auto s : q) {}
    for ([[maybe_unused]] auto& s : q) {}
    for ([[maybe_unused]] auto const& s : q) {}
}
}
