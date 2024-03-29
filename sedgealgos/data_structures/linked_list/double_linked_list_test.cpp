#include "sedgealgos/data_structures/linked_list/double_linked_list.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace {
using namespace sedgealgos::data_structures::linked_list;

TEST(DoubleLinkedListTest, IsEmptyReturnsTrueWhenEmptyDeque) {
    DoubleLinkedList<int> l;

    EXPECT_TRUE(l.is_empty());
}

TEST(DoubleLinkedListTest, IsEmptyReturnsFalseWhenDequeIsNotEmpty) {
    DoubleLinkedList<int> l;

    l.push_front(1);

    EXPECT_FALSE(l.is_empty());
}

TEST(DoubleLinkedListTest, PushFrontIncreasesSize) {
    DoubleLinkedList<int> l;
    l.push_front(1);
    l.push_front(2);

    EXPECT_EQ(l.size(), 2);
}

TEST(DoubleLinkedListTest, PopFrontDecreasesSize) {
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

TEST(DoubleLinkedListTest, InsertBeforeIncreasesSize) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.insert_before(l.begin(), 3);

    EXPECT_EQ(l.size(), 2);
}

TEST(DoubleLinkedListTest, InsertAfterIncreasesSize) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.insert_after(l.begin(), 3);

    EXPECT_EQ(l.size(), 2);
}

TEST(DoubleLinkedListTest, RemoveDescreasesSize) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);

    l.remove(l.begin());

    EXPECT_EQ(l.size(), 1);
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

TEST(DoubleLinkedListTest, PushFrontThenPopBackAllElements) {
    DoubleLinkedList<int> l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);

    EXPECT_EQ(l.pop_back(), 1);
    EXPECT_EQ(l.pop_back(), 2);
    EXPECT_EQ(l.pop_back(), 3);
}

TEST(DoubleLinkedListTest, PushBackThenPopFrontAllElements) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    EXPECT_EQ(l.pop_front(), 1);
    EXPECT_EQ(l.pop_front(), 2);
    EXPECT_EQ(l.pop_front(), 3);
}

TEST(DoubleLinkedListTest, PushFrontThenPopFrontThenPushFrontSingleElement) {
    DoubleLinkedList<int> l;
    l.push_front(1);
    l.pop_front();
    l.push_front(2);

    EXPECT_EQ(l.pop_front(), 2);
}

TEST(DoubleLinkedListTest, PushBackThenPopBackThenPushBackSingleElement) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.pop_back();
    l.push_back(2);

    EXPECT_EQ(l.pop_back(), 2);
}

TEST(DoubleLinkedListTest, PushFrontThenPopBackThenPushFrontSingleElement) {
    DoubleLinkedList<int> l;
    l.push_front(1);
    l.pop_back();
    l.push_front(2);

    EXPECT_EQ(l.pop_back(), 2);
}

TEST(DoubleLinkedListTest, PushBackThenPopFrontThenPushBackSingleElement) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.pop_front();
    l.push_back(2);

    EXPECT_EQ(l.pop_front(), 2);
}

TEST(DoubleLinkedListTest, BeginInteratorIsEqualEndIteratorWhenListIsEmpty) {
    DoubleLinkedList<int> l;
    EXPECT_TRUE(l.begin() == l.end());
}

TEST(DoubleLinkedListTest, BeginInteratorIsNotEqualToEndIteratorWhenListIsNotEmpty) {
    DoubleLinkedList<int> l;

    l.push_back(1);

    EXPECT_TRUE(l.begin() != l.end());
}

TEST(DoubleLinkedListTest, CBeginInteratorIsEqualCEndIteratorWhenListIsEmpty) {
    DoubleLinkedList<int> l;
    EXPECT_TRUE(l.cbegin() == l.cend());
}

TEST(DoubleLinkedListTest, CBeginInteratorIsNotEqualToCEndIteratorWhenListIsNotEmpty) {
    DoubleLinkedList<int> l;

    l.push_back(1);

    EXPECT_TRUE(l.cbegin() != l.cend());
}

TEST(DoubleLinkedListTest, IterateOverListForwardWithPrefixIncrement) {
    DoubleLinkedList<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    auto curr{l.begin()};

    EXPECT_EQ(*curr, 1);
    EXPECT_EQ(*(++curr), 2);
    EXPECT_EQ(*(++curr), 3);
    EXPECT_EQ(++curr, l.end());
}

TEST(DoubleLinkedListTest, IterateOverListForwardWithPostfixIncrement) {
    DoubleLinkedList<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    auto curr{l.begin()};

    EXPECT_EQ(*(curr++), 1);
    EXPECT_EQ(*(curr++), 2);
    EXPECT_EQ(*(curr++), 3);
    EXPECT_EQ(curr, l.end());
}

TEST(DoubleLinkedListTest, IterateWithForRangeLoop) {
    DoubleLinkedList<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    for ([[ maybe_unused ]] auto i : l) {}
}

TEST(DoubleLinkedListTest, InsertsBeforeFrontInEmptyList) {
    DoubleLinkedList<int> l;

    l.insert_before(l.begin(), 2);

    EXPECT_EQ(l.pop_front(), 2);
}

TEST(DoubleLinkedListTest, InsertsBeforeFront) {
    DoubleLinkedList<int> l;

    l.push_front(1);
    l.insert_before(l.begin(), 2);

    EXPECT_EQ(l.pop_front(), 2);
    EXPECT_EQ(l.pop_front(), 1);
}

TEST(DoubleLinkedListTest, InsertsBeforeMiddleElement) {
    DoubleLinkedList<int> l;

    l.push_front(1);
    l.push_front(2);
    l.insert_before(++l.begin(), 3);

    EXPECT_EQ(l.pop_front(), 2);
    EXPECT_EQ(l.pop_front(), 3);
    EXPECT_EQ(l.pop_front(), 1);
}

TEST(DoubleLinkedListTest, InsertsBeforeInsertedBeforeElement) {
    DoubleLinkedList<int> l;

    l.push_front(1);
    l.push_front(2);
    l.insert_before(++l.begin(), 3);
    l.insert_before(++l.begin(), 4);

    EXPECT_EQ(l.pop_front(), 2);
    EXPECT_EQ(l.pop_front(), 4);
    EXPECT_EQ(l.pop_front(), 3);
    EXPECT_EQ(l.pop_front(), 1);
}

TEST(DoubleLinkedListTest, InsertBeforeElementAgain) {
    DoubleLinkedList<int> l;

    l.push_front(1);
    l.push_front(2);
    l.insert_before(++l.begin(), 3);
    l.insert_before(++(++l.begin()), 4);

    EXPECT_EQ(l.pop_front(), 2);
    EXPECT_EQ(l.pop_front(), 3);
    EXPECT_EQ(l.pop_front(), 4);
    EXPECT_EQ(l.pop_front(), 1);
}

TEST(DoubleLinkedListTest, InsertAfterLastElem) {
    DoubleLinkedList<int> l;

    l.push_back(1);
    l.insert_after(l.begin(), 2);

    EXPECT_EQ(l.pop_back(), 2);
    EXPECT_EQ(l.pop_back(), 1);
}

TEST(DoubleLinkedListTest, InsertAfterMiddleElem) {
    DoubleLinkedList<int> l;

    l.push_back(1);
    l.push_back(2);
    l.insert_after(l.begin(), 3);

    EXPECT_EQ(l.pop_back(), 2);
    EXPECT_EQ(l.pop_back(), 3);
    EXPECT_EQ(l.pop_back(), 1);
}

TEST(DoubleLinkedListTest, InsertAfterMiddleElemNotBeforeLast) {
    DoubleLinkedList<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.insert_after(l.begin(), 4);

    EXPECT_EQ(l.pop_back(), 3);
    EXPECT_EQ(l.pop_back(), 2);
    EXPECT_EQ(l.pop_back(), 4);
    EXPECT_EQ(l.pop_back(), 1);
}

TEST(DoubleLinkedListTest, InsertAfterTheSameElementAgain) {
    DoubleLinkedList<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.insert_after(l.begin(), 4);
    l.insert_after(l.begin(), 5);

    EXPECT_EQ(l.pop_back(), 3);
    EXPECT_EQ(l.pop_back(), 2);
    EXPECT_EQ(l.pop_back(), 4);
    EXPECT_EQ(l.pop_back(), 5);
    EXPECT_EQ(l.pop_back(), 1);
}

TEST(DoubleLinkedListTest, InsertAfterToTheEmptyList) {
    DoubleLinkedList<int> l;

    l.insert_after(l.begin(), 4);

    EXPECT_EQ(l.pop_back(), 4);
}

TEST(DoubleLinkedListTest, MixPushBacksPushFrontsInsertBeforeInsertAfter) {
    DoubleLinkedList<int> l;

    l.push_back(1);
    l.push_front(2);
    l.push_back(3);
    l.insert_after(l.begin(), 4);
    l.insert_before(++l.begin(), 5);

    EXPECT_EQ(l.pop_back(), 3);
    EXPECT_EQ(l.pop_back(), 1);
    EXPECT_EQ(l.pop_back(), 4);
    EXPECT_EQ(l.pop_back(), 5);
    EXPECT_EQ(l.pop_back(), 2);
}

TEST(DoubleLinkedListTest, RemoveElementFromSingleElementList) {
    DoubleLinkedList<int> l;
    l.push_back(1);

    l.remove(l.begin());

    EXPECT_TRUE(l.begin() == l.end());
}

TEST(DoubleLinkedListTest, RemoveFirstElementFromList) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);

    l.remove(l.begin());

    EXPECT_EQ(l.pop_front(), 2);
}

TEST(DoubleLinkedListTest, RemoveLastElementFromList) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);

    l.remove(++l.begin());

    EXPECT_EQ(l.pop_front(), 1);
}

TEST(DoubleLinkedListTest, RemoveMiddleElementFromList) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    l.remove(++l.begin());

    EXPECT_EQ(l.pop_front(), 1);
    EXPECT_EQ(l.pop_front(), 3);
}

TEST(DoubleLinkedListTest, RemoveFirstElementFromListAndPopBackAllElements) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);

    l.remove(l.begin());

    EXPECT_EQ(l.pop_back(), 2);
}

TEST(DoubleLinkedListTest, RemoveLastElementFromListPopBackAllElements) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);

    l.remove(++l.begin());

    EXPECT_EQ(l.pop_back(), 1);
}

TEST(DoubleLinkedListTest, RemoveMiddleElementFromListPopBackAllElements) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    l.remove(++l.begin());

    EXPECT_EQ(l.pop_back(), 3);
    EXPECT_EQ(l.pop_back(), 1);
}

TEST(DoubleLinkedListTest, IteratreOverListAfterRemoval) {
    DoubleLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    l.remove(++l.begin());

    auto iter{l.begin()};
    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 3);
    EXPECT_TRUE(iter == l.end());
}
}
