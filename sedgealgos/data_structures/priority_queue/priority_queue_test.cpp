#include "sedgealgos/data_structures/priority_queue/binary_heap_priority_queue.hpp"
#include "sedgealgos/data_structures/array/array.hpp"

#include <gtest/gtest.h>

using namespace sedgealgos::data_structures::array;
using namespace sedgealgos::data_structures::priority_queue;

namespace {

using MaxPriorityQueue = MaxBinaryHeapPriorityQueue<int>;

TEST(MaxPriorityQueueTest, MakePriorityListFromArray) {
	MaxPriorityQueue mpq{Array<int>{3, 2, 9, 5, 4, 1, 0, 7, 6, 0}};

	EXPECT_EQ(mpq.pop(), 9);
	EXPECT_EQ(mpq.pop(), 7);
	EXPECT_EQ(mpq.pop(), 6);
	EXPECT_EQ(mpq.pop(), 5);
	EXPECT_EQ(mpq.pop(), 4);
	EXPECT_EQ(mpq.pop(), 3);
	EXPECT_EQ(mpq.pop(), 2);
	EXPECT_EQ(mpq.pop(), 1);
	EXPECT_EQ(mpq.pop(), 0);
	EXPECT_EQ(mpq.pop(), 0);
}

TEST(MaxPriorityQueueTest, MakeOneElementPriorityQueue) {
	MaxPriorityQueue mpq{Array<int>{3}};

	EXPECT_EQ(mpq.size(), 1);
	EXPECT_FALSE(mpq.empty());

	EXPECT_EQ(mpq.pop(), 3);
	EXPECT_EQ(mpq.size(), 0);
	EXPECT_TRUE(mpq.empty());
}

TEST(MaxPriorityQueueTest, MakePriorityListFromInserts) {
	MaxPriorityQueue mpq(10);

	mpq.insert(3);
	EXPECT_EQ(mpq.top(), 3);
	EXPECT_EQ(mpq.size(), 1);

	mpq.insert(2);
	EXPECT_EQ(mpq.top(), 3);
	EXPECT_EQ(mpq.size(), 2);

	mpq.insert(9);
	EXPECT_EQ(mpq.top(), 9);
	EXPECT_EQ(mpq.size(), 3);

	mpq.insert(5);
	EXPECT_EQ(mpq.top(), 9);
	EXPECT_EQ(mpq.size(), 4);

	mpq.insert(4);
	EXPECT_EQ(mpq.top(), 9);
	EXPECT_EQ(mpq.size(), 5);

	mpq.insert(1);
	EXPECT_EQ(mpq.top(), 9);
	EXPECT_EQ(mpq.size(), 6);

	mpq.insert(0);
	EXPECT_EQ(mpq.top(), 9);
	EXPECT_EQ(mpq.size(), 7);

	mpq.insert(7);
	EXPECT_EQ(mpq.top(), 9);
	EXPECT_EQ(mpq.size(), 8);

	mpq.insert(6);
	EXPECT_EQ(mpq.top(), 9);
	EXPECT_EQ(mpq.size(), 9);

	mpq.insert(0);
	EXPECT_EQ(mpq.top(), 9);
	EXPECT_EQ(mpq.size(), 10);

	EXPECT_EQ(mpq.pop(), 9);
	EXPECT_EQ(mpq.pop(), 7);
	EXPECT_EQ(mpq.pop(), 6);
	EXPECT_EQ(mpq.pop(), 5);
	EXPECT_EQ(mpq.pop(), 4);
	EXPECT_EQ(mpq.pop(), 3);
	EXPECT_EQ(mpq.pop(), 2);
	EXPECT_EQ(mpq.pop(), 1);
	EXPECT_EQ(mpq.pop(), 0);
	EXPECT_EQ(mpq.pop(), 0);
}
}

