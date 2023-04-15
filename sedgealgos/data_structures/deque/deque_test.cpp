#include "sedgealgos/data_structures/deque/deque.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::data_structures::deque;

template <typename T>
class DequeTest : public ::testing::Test {
protected:
    T deque{};
};

TYPED_TEST_SUITE_P(DequeTest);

TYPED_TEST_P(DequeTest, IsEmptyReturnsTrueWhenEmptyDeque) {
    Deque<int> d;

    EXPECT_TRUE(d.is_empty());
}

TYPED_TEST_P(DequeTest, IsEmptyReturnsFalseWhenDequeIsNotEmpty) {
    Deque<int> d;

    d.push_left(1);

    EXPECT_FALSE(d.is_empty());
}

TYPED_TEST_P(DequeTest, PushLeftIncreasesSizeOfDeque) {
    Deque<int> d;

    d.push_left(1);

    EXPECT_EQ(d.size(), 1);
}

TYPED_TEST_P(DequeTest, PushRightIncreasesSizeOfDeque) {
    Deque<int> d;

    d.push_right(1);

    EXPECT_EQ(d.size(), 1);
}

TYPED_TEST_P(DequeTest, PopLeftDecreasesSizeOfDeque) {
    Deque<int> d;

    d.push_left(1);
    d.pop_left();

    EXPECT_EQ(d.size(), 0);
}

TYPED_TEST_P(DequeTest, PopRightDecreasesSizeOfDeque) {
    Deque<int> d;

    d.push_right(1);
    d.pop_right();

    EXPECT_EQ(d.size(), 0);
}

TYPED_TEST_P(DequeTest, PopLeftDequeThatHadSinglePushedLeftItem) {
    this->deque.push_left(1);

    EXPECT_EQ(this->deque.pop_left(), 1);
}

TYPED_TEST_P(DequeTest, PopLeftDequeThatHadSinglePushedRightItem) {
    this->deque.push_right(1);

    EXPECT_EQ(this->deque.pop_left(), 1);
}

TYPED_TEST_P(DequeTest, PopRightDequeThatHadSinglePushedLeftItem) {
    this->deque.push_left(1);

    EXPECT_EQ(this->deque.pop_right(), 1);
}

TYPED_TEST_P(DequeTest, PopRightDequeThatHadSinglePushedRightItem) {
    this->deque.push_right(1);

    EXPECT_EQ(this->deque.pop_right(), 1);
}

TYPED_TEST_P(DequeTest, PushLeftPushLeftPopLeftPopLeft) {
    this->deque.push_left(1);
    this->deque.push_left(2);

    EXPECT_EQ(this->deque.pop_left(), 2);
    EXPECT_EQ(this->deque.pop_left(), 1);
}

TYPED_TEST_P(DequeTest, PushRightPushRightPopLeftPopLeft) {
    this->deque.push_right(1);
    this->deque.push_right(2);

    EXPECT_EQ(this->deque.pop_left(), 1);
    EXPECT_EQ(this->deque.pop_left(), 2);
}

TYPED_TEST_P(DequeTest, PushLeftPushLeftPopRightPopRight) {
    this->deque.push_left(1);
    this->deque.push_left(2);

    EXPECT_EQ(this->deque.pop_right(), 1);
    EXPECT_EQ(this->deque.pop_right(), 2);
}

TYPED_TEST_P(DequeTest, PushRightPushRightPopRightPopRight) {
    this->deque.push_right(1);
    this->deque.push_right(2);

    EXPECT_EQ(this->deque.pop_right(), 2);
    EXPECT_EQ(this->deque.pop_right(), 1);
}

TYPED_TEST_P(DequeTest, PushLeftAllItemsThenPopLeftAllItemsThenAgainPushLeftAllItemsAndFinallyPopLeftAllItems) {
    this->deque.push_left(1);
    this->deque.push_left(2);

    this->deque.pop_left();
    this->deque.pop_left();

    this->deque.push_left(1);
    this->deque.push_left(2);

    EXPECT_EQ(this->deque.pop_left(), 2);
    EXPECT_EQ(this->deque.pop_left(), 1);
}

TYPED_TEST_P(DequeTest, PushLeftAllItemsThenPopLeftAllItemsThenAgainPushLeftAllItemsAndFinallyPopRightAllItems) {
    this->deque.push_left(1);
    this->deque.push_left(2);

    this->deque.pop_left();
    this->deque.pop_left();

    this->deque.push_left(1);
    this->deque.push_left(2);

    EXPECT_EQ(this->deque.pop_right(), 1);
    EXPECT_EQ(this->deque.pop_right(), 2);
}

TYPED_TEST_P(DequeTest, PushLeftAllItemsThenPopLeftAllItemsThenAgainPushRightAllItemsAndFinallyPopLeftAllItems) {
    this->deque.push_left(1);
    this->deque.push_left(2);

    this->deque.pop_left();
    this->deque.pop_left();

    this->deque.push_right(1);
    this->deque.push_right(2);

    EXPECT_EQ(this->deque.pop_left(), 1);
    EXPECT_EQ(this->deque.pop_left(), 2);
}

TYPED_TEST_P(DequeTest, PushLeftAllItemsThenPopLeftAllItemsThenAgainPushRightAllItemsAndFinallyPopRightAllItems) {
    this->deque.push_left(1);
    this->deque.push_left(2);

    this->deque.pop_left();
    this->deque.pop_left();

    this->deque.push_right(1);
    this->deque.push_right(2);

    EXPECT_EQ(this->deque.pop_right(), 2);
    EXPECT_EQ(this->deque.pop_right(), 1);
}

TYPED_TEST_P(DequeTest, PushLeftThenPushRightAndFinallyPopAllElems) {
    this->deque.push_left(1);
    this->deque.push_right(2);

    EXPECT_EQ(this->deque.pop_left(), 1);
    EXPECT_EQ(this->deque.pop_left(), 2);
}

TYPED_TEST_P(DequeTest, PushRightThenPushLeftAndFinallyPopAllElems) {
    this->deque.push_right(2);
    this->deque.push_left(1);

    EXPECT_EQ(this->deque.pop_left(), 1);
    EXPECT_EQ(this->deque.pop_left(), 2);
}

TYPED_TEST_P(DequeTest, PushLeftTwoItemThenPopLeftOneItemThenPushLeftOneAndFinallyPopAll) {
    this->deque.push_left(1);
    this->deque.push_left(2);
    this->deque.pop_left();
    this->deque.push_left(3);

    EXPECT_EQ(this->deque.pop_left(), 3);
    EXPECT_EQ(this->deque.pop_left(), 1);
}

TYPED_TEST_P(DequeTest, PushLeftTwoItemThenPopLeftOneItemThenPushRightOneAndFinallyPopAll) {
    this->deque.push_left(1);
    this->deque.push_left(2);
    this->deque.pop_left();
    this->deque.push_right(3);

    EXPECT_EQ(this->deque.pop_left(), 1);
    EXPECT_EQ(this->deque.pop_left(), 3);
}

TYPED_TEST_P(DequeTest, PushLeftTwoItemThenPopRightOneItemThenPushLeftOneAndFinallyPopAll) {
    this->deque.push_left(1);
    this->deque.push_left(2);
    this->deque.pop_right();
    this->deque.push_left(3);

    EXPECT_EQ(this->deque.pop_left(), 3);
    EXPECT_EQ(this->deque.pop_left(), 2);
}

TYPED_TEST_P(DequeTest, PushLeftTwoItemThenPopRightOneItemThenPushRightOneAndFinallyPopAll) {
    this->deque.push_left(1);
    this->deque.push_left(2);
    this->deque.pop_right();
    this->deque.push_right(3);

    EXPECT_EQ(this->deque.pop_left(), 2);
    EXPECT_EQ(this->deque.pop_left(), 3);
}

REGISTER_TYPED_TEST_SUITE_P(
    DequeTest,
    IsEmptyReturnsTrueWhenEmptyDeque,
    IsEmptyReturnsFalseWhenDequeIsNotEmpty,
    PushLeftIncreasesSizeOfDeque,
    PushRightIncreasesSizeOfDeque,
    PopLeftDecreasesSizeOfDeque,
    PopRightDecreasesSizeOfDeque,
    PopLeftDequeThatHadSinglePushedLeftItem,
    PopLeftDequeThatHadSinglePushedRightItem,
    PopRightDequeThatHadSinglePushedLeftItem,
    PopRightDequeThatHadSinglePushedRightItem,
    PushLeftPushLeftPopLeftPopLeft,
    PushRightPushRightPopLeftPopLeft,
    PushLeftPushLeftPopRightPopRight,
    PushRightPushRightPopRightPopRight,
    PushLeftAllItemsThenPopLeftAllItemsThenAgainPushLeftAllItemsAndFinallyPopLeftAllItems,
    PushLeftAllItemsThenPopLeftAllItemsThenAgainPushLeftAllItemsAndFinallyPopRightAllItems,
    PushLeftAllItemsThenPopLeftAllItemsThenAgainPushRightAllItemsAndFinallyPopLeftAllItems,
    PushLeftAllItemsThenPopLeftAllItemsThenAgainPushRightAllItemsAndFinallyPopRightAllItems,
    PushLeftThenPushRightAndFinallyPopAllElems,
    PushRightThenPushLeftAndFinallyPopAllElems,
    PushLeftTwoItemThenPopLeftOneItemThenPushLeftOneAndFinallyPopAll,
    PushLeftTwoItemThenPopLeftOneItemThenPushRightOneAndFinallyPopAll,
    PushLeftTwoItemThenPopRightOneItemThenPushLeftOneAndFinallyPopAll,
    PushLeftTwoItemThenPopRightOneItemThenPushRightOneAndFinallyPopAll
);

using DoubleLinkedListDeque = Deque<int>;
INSTANTIATE_TYPED_TEST_SUITE_P(DoubleLinkedList, DequeTest, DoubleLinkedListDeque);
}
