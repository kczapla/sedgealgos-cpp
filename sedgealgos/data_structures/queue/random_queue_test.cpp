#include "sedgealgos/data_structures/queue/random_queue.hpp"
#include "sedgealgos/random/std_random.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::data_structures::queue;
using namespace sedgealgos::random;

template <typename T>
using GenericRandomIntQueue = RandomQueue<int, T>;

using RandomIntQueue = GenericRandomIntQueue<StdRandom>;

class RandomGeneratorMock {
public:
    static int uniform(int) {
        return counter++;
    }

    static void reset_counter() {
        counter = 0;
    }

    static void set_counter(int c) {
        counter = c;
    }

private:
    inline static int counter{0};
};

TEST(RandomQueueTest, IsEmptyReturnsTrueWhenQueueIsEmpty) {
    RandomIntQueue rq;

    EXPECT_TRUE(rq.is_empty());
}

TEST(RandomQueueTest, IsEmptyReturnsFalseWhenQueueIsNotEmpty) {
    RandomIntQueue rq;

    rq.enqueue(1);

    EXPECT_FALSE(rq.is_empty());
}

TEST(RandomQueueTest, WhenQueueHasOneItemThenPeekReturnsThatItem) {
    RandomIntQueue rq;

    rq.enqueue(1);

    EXPECT_EQ(rq.sample(), 1);
}

TEST(RandomQueueTest, WhenQueueHasTwoItemsThenPeekReturnsRandomItem) {
    RandomGeneratorMock::reset_counter();

    GenericRandomIntQueue<RandomGeneratorMock> rq;

    rq.enqueue(0);
    rq.enqueue(1);

    EXPECT_EQ(rq.sample(), 0);
    EXPECT_EQ(rq.sample(), 1);
    EXPECT_FALSE(rq.is_empty());
}

TEST(RandomQueueTest, WhenQueueHasOneItemThenDequeueReturnsThatItem) {
    RandomIntQueue rq;

    rq.enqueue(0);

    EXPECT_EQ(rq.dequeue(), 0);
    EXPECT_TRUE(rq.is_empty());
}

TEST(RandomQueueTest, WhenQueueHasTwoItemsThenDequeuReturnsRandomItem) {
    RandomGeneratorMock::reset_counter();

    GenericRandomIntQueue<RandomGeneratorMock> rq;

    rq.enqueue(1);
    rq.enqueue(0);

    EXPECT_EQ(rq.dequeue(), 1);
    RandomGeneratorMock::set_counter(0);

    EXPECT_EQ(rq.dequeue(), 0);
    RandomGeneratorMock::set_counter(1);

    EXPECT_TRUE(rq.is_empty());
}

TEST(RandomQueueTest, BeginIteratorOfEmptyQueueIsEqualToEndIterator) {
    RandomGeneratorMock::reset_counter();

    GenericRandomIntQueue<RandomGeneratorMock> rq;

    EXPECT_TRUE(rq.begin() == rq.end());
}

TEST(RandomQueueTest, TwoIteratorsOfTheSameNonEmptyQueueAreNotEqual) {
    RandomGeneratorMock::reset_counter();

    GenericRandomIntQueue<RandomGeneratorMock> rq;

    rq.enqueue(1);
    rq.enqueue(2);
    rq.enqueue(3);
    rq.enqueue(4);

    auto iter1{rq.begin()};
    ++iter1;
    ++iter1;

    RandomGeneratorMock::reset_counter();
    auto iter2{rq.begin()};

    EXPECT_TRUE(iter1 != iter2);
}

TEST(RandomQueueTest, IteratingOverRandomQueueReturnsRandomElements) {
    RandomGeneratorMock::reset_counter();

    GenericRandomIntQueue<RandomGeneratorMock> rq;

    rq.enqueue(1);
    rq.enqueue(2);
    rq.enqueue(3);
    rq.enqueue(4);

    auto iter{rq.begin()};
    EXPECT_EQ(*iter, 4);
    EXPECT_EQ(*(++iter), 3);
    EXPECT_EQ(*(++iter), 2);
    EXPECT_EQ(*(++iter), 1);

    EXPECT_TRUE(++iter == rq.end());
}
}
