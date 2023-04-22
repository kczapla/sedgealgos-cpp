#include "sedgealgos/data_structures/ring_buffer/ring_buffer.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::data_structures::ring_buffer;

TEST(RingBufferTest, IsEmptyReturnsTrueWhenRingBufferIsEmpty) {
    RingBuffer<int> rb{1};

    EXPECT_TRUE(rb.is_empty());
}

TEST(RingBufferTest, IsEmptyReturnsFalseWhenRingBufferIsNotEmpty) {
    RingBuffer<int> rb{1};

    rb.push(1);

    EXPECT_FALSE(rb.is_empty());
}

TEST(RingBufferTest, IsEmptyReturnsTrueAfterGettingItemFromSingleElementBuffer) {
    RingBuffer<int> rb{1};

    rb.push(1);
    rb.pop();

    EXPECT_TRUE(rb.is_empty());
}

TEST(RingBufferTest, PopItemFromSingleItemRingBuffer) {
    RingBuffer<int> rb{1};

    rb.push(1);

    EXPECT_EQ(rb.pop(), 1);
}

TEST(RingBufferTest, PopItemFromTwoElementRingBuffer) {
    RingBuffer<int> rb{2};

    rb.push(1);
    rb.push(2);

    EXPECT_EQ(rb.pop(), 1);
}

TEST(RingBufferTest, WhenNSizeBufferIsFullNewItemOverwritesOldestItem) {
    RingBuffer<int> rb{3};

    rb.push(1);
    rb.push(2);
    rb.push(3);
    rb.push(4);

    EXPECT_EQ(rb.pop(), 2);
    EXPECT_EQ(rb.pop(), 3);
    EXPECT_EQ(rb.pop(), 4);
    EXPECT_TRUE(rb.is_empty());
}
}

