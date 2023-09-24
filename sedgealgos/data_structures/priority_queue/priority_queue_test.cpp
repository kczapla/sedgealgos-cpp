#include "sedgealgos/data_structures/priority_queue/binary_heap_priority_queue.hpp"
#include "sedgealgos/data_structures/array/array.hpp"

#include <gtest/gtest.h>

using namespace sedgealgos::data_structures::array;
using namespace sedgealgos::data_structures::priority_queue;

namespace {

using MaxPriorityQueue = MaxBinaryHeapPriorityQueue<int>;

TEST(MaxPriorityQueueTest, MakePriorityListFromArray) {
	MaxPriorityQueue mpq{Array<int>{1, 2}};

	EXPECT_EQ(mpq.pop(), 2);
	EXPECT_EQ(mpq.pop(), 1);
}
}

