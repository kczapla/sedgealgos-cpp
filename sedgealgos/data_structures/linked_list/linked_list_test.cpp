#include "sedgealgos/data_structures/linked_list/single_linked_list.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace {
using ::testing::ThrowsMessage;
using namespace sedgealgos::data_structures::linked_list;

TEST(SingleLinkedListTest, PushesAndPopsOneElement) {
  SingleLinkedList<int> ll;
  ll.push_front(1);
  EXPECT_EQ(ll.pop_front(), 1);
}

TEST(SingleLinkedListTest, PopFrontFromEmptyListThrowsException) {
  SingleLinkedList<int> ll;
  EXPECT_THAT([&ll](){[[ maybe_unused ]] auto i{ll.pop_front()}; }, ThrowsMessage<LinkedListException>("popping from empty list"));
}

TEST(SingleLinkedListTest, PushesElemsToEmptiedList) {
  SingleLinkedList<int> ll;

  ll.push_front(1);
  ll.pop_front();

  ll.push_front(2);
  
  EXPECT_EQ(ll.pop_front(), 2);
}

TEST(SingleLinkedListTest, PushesAndPopsTwoElements) {
  SingleLinkedList<int> ll;

  ll.push_front(1);
  ll.push_front(2);
  
  EXPECT_EQ(ll.size(), 2);

  EXPECT_EQ(ll.pop_front(), 2);
  EXPECT_EQ(ll.size(), 1);

  EXPECT_EQ(ll.pop_front(), 1);
  EXPECT_EQ(ll.size(), 0);
}

TEST(SingleLinkedListTest, PushesAndPopsThreeElements) {
  SingleLinkedList<int> ll;

  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);
  
  EXPECT_EQ(ll.pop_front(), 3);
  EXPECT_EQ(ll.pop_front(), 2);
  EXPECT_EQ(ll.pop_front(), 1);
}
}

