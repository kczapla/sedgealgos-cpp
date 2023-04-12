#include "sedgealgos/data_structures/linked_list/double_linked_list.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace {
using namespace sedgealgos::data_structures::linked_list;

TEST(DoubleLinkedList, PushFrontIncreasesSize) {
    DoubleLinkedList<int> l;
    l.push_front(1);
    l.push_front(2);

    EXPECT_EQ(l.size(), 2);
}

TEST(DoubleLinkedList, PopFrontDecreasesSize) {
    DoubleLinkedList<int> l;
    l.push_front(1);
    l.push_front(2);

    l.pop_front();
    l.pop_front();

    EXPECT_EQ(l.size(), 0);
}

TEST(DoubleLinkedListTest, PushBackIncreasesSize) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);

    EXPECT_EQ(l.size(), 2);
}

TEST(DoubleLinkedListTest, PopBackDecreasesSize) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);

    l.pop_back();
    l.pop_back();

    EXPECT_EQ(l.size(), 0);
}

TEST(DoubleLinkedListTest, PushFrontThenPopFrontAllElements) {
    DoubleLinkedList<int> l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);

    EXPECT_EQ(l.pop_front(), 3);
    EXPECT_EQ(l.pop_front(), 2);
    EXPECT_EQ(l.pop_front(), 1);
}

TEST(DoubleLinkedListTest, PushBackThenPopBackAllElements) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    EXPECT_EQ(l.pop_back(), 3);
    EXPECT_EQ(l.pop_back(), 2);
    EXPECT_EQ(l.pop_back(), 1);
}
}
