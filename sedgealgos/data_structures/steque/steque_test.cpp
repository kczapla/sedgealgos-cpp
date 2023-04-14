#include "sedgealgos/data_structures/steque/steque.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::data_structures::steque; 

TEST(StequeTest, PushFrontIncreasesSize) {
    Steque<int> s;
    s.push_front(1);

    EXPECT_EQ(s.size(), 1);
}

TEST(StequeTest, PopFrontDecreasesSize) {
    Steque<int> s;
    s.push_front(1);

    s.pop_front();

    EXPECT_EQ(s.size(), 0);
}

TEST(StequeTest, EnqueueIncreasesSize) {
    Steque<int> s;
    s.enqueue(1);

    EXPECT_EQ(s.size(), 1);
}

TEST(StequeTest, EnqeueElementInEmptyList) {
    Steque<int> s;
    s.enqueue(1);

    EXPECT_EQ(s.pop_front(), 1);
}

TEST(StequeTest, EnqeueElementInListWithOneElement) {
    Steque<int> s;
    s.push_front(1);
    s.enqueue(2);

    EXPECT_EQ(s.pop_front(), 1);
    EXPECT_EQ(s.pop_front(), 2);
}

TEST(StequeTest, PushPopEnqueuePush) {
    Steque<int> s;
    s.push_front(1);
    s.pop_front();
    s.enqueue(2);
    s.push_front(1);

    EXPECT_EQ(s.pop_front(), 1);
    EXPECT_EQ(s.pop_front(), 2);
}

TEST(StequeTest, EnqueuePopPushEnqueue) {
    Steque<int> s;
    s.enqueue(2);
    s.pop_front();
    s.push_front(1);
    s.enqueue(2);

    EXPECT_EQ(s.pop_front(), 1);
    EXPECT_EQ(s.pop_front(), 2);
}

TEST(StequeTest, IterateOverElementsWithPrefixOperator) {
    Steque<int> s;
    s.enqueue(2);
    s.push_front(1);
    s.enqueue(3);

    auto iter{s.begin()};
    EXPECT_EQ(*iter, 1);
    EXPECT_EQ(*(++iter), 2);
    EXPECT_EQ(*(++iter), 3);
    EXPECT_TRUE(++iter == s.end());
}

TEST(StequeTest, IterateOverElementsWithPostfixOperator) {
    Steque<int> s;
    s.enqueue(2);
    s.push_front(1);
    s.enqueue(3);

    auto iter{s.begin()};
    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 2);
    EXPECT_EQ(*(iter++), 3);
    EXPECT_TRUE(iter == s.end());
}

TEST(StequeTest, ConstIterateOverElementsWithPrefixOperator) {
    Steque<int> s;
    s.enqueue(2);
    s.push_front(1);
    s.enqueue(3);

    auto iter{s.cbegin()};
    EXPECT_EQ(*iter, 1);
    EXPECT_EQ(*(++iter), 2);
    EXPECT_EQ(*(++iter), 3);
    EXPECT_TRUE(++iter == s.cend());
}

TEST(StequeTest, ConstIterateOverElementsWithPostfixOperator) {
    Steque<int> s;
    s.enqueue(2);
    s.push_front(1);
    s.enqueue(3);

    auto iter{s.cbegin()};
    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 2);
    EXPECT_EQ(*(iter++), 3);
    EXPECT_TRUE(iter == s.cend());
}

TEST(StequeTest, NotEqualIterator) {
    Steque<int> s;
    s.enqueue(2);
    s.push_front(1);
    s.enqueue(3);

    EXPECT_TRUE(s.begin() != s.end());
}

TEST(StequeTest, ForRangeLoop) {
    Steque<int> s;
    s.enqueue(2);
    s.push_front(1);
    s.enqueue(3);

    for ([[maybe_unused]] auto e : s) {}
}
}
