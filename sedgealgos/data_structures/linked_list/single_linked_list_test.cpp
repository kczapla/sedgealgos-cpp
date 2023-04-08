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

TEST(SingleLinkedListTest, AccessFirstElement) {
  SingleLinkedList<int> ll;

  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);

  EXPECT_EQ(ll.front(), 3);
}

TEST(SingleLinkedListTest, IterateOverElements) {
  SingleLinkedList<int> ll;

  ll.push_front(1); 
  ll.push_front(2); 
  ll.push_front(3); 

  auto iter{std::begin(ll)};
  EXPECT_EQ(*iter, 3);

  EXPECT_EQ(*(++iter), 2);

  EXPECT_EQ(*(++iter), 1);

  iter++;
  EXPECT_TRUE(iter == std::end(ll));
}

TEST(SingleLinkedListTest, EmptyIteratorIsEqualToLastElement) {
  SingleLinkedList<int> ll;
  EXPECT_TRUE(std::begin(ll) == std::end(ll));
}

TEST(SingleLinkedListTest, WorksWithForRangeLoop) {
  SingleLinkedList<int> ll;

  ll.push_front(1); 
  ll.push_front(2); 
  ll.push_front(3); 

  for ([[maybe_unused]] auto const& i : ll) {}
}

TEST(SingleLinkedListTest, DeleteIthElementThatExist) {
  SingleLinkedList<int> ll;

  ll.push_front(1); 
  ll.push_front(2); 
  ll.push_front(3); 

  ll.remove(1);

  EXPECT_EQ(ll.size(), 2);
  EXPECT_EQ(ll.pop_front(), 3);
  EXPECT_EQ(ll.pop_front(), 1);
}

TEST(SingleLinkedListTest, DeleteElementFromBeginning) {
  SingleLinkedList<int> ll;

  ll.push_front(1); 
  ll.push_front(2); 
  ll.push_front(3); 

  ll.remove(0);

  EXPECT_EQ(ll.size(), 2);
  EXPECT_EQ(ll.pop_front(), 2);
  EXPECT_EQ(ll.pop_front(), 1);
}

TEST(SingleLinkedListTest, DeleteElementFromEnd) {
  SingleLinkedList<int> ll;

  ll.push_front(1); 
  ll.push_front(2); 
  ll.push_front(3); 

  ll.remove(2);

  ll.push_front(4); 

  EXPECT_EQ(ll.size(), 3);
  EXPECT_EQ(ll.pop_front(), 4);
  EXPECT_EQ(ll.pop_front(), 3);
  EXPECT_EQ(ll.pop_front(), 2);
}

TEST(SingleLinkedListTest, DeletesElementFromSingleItemLinkedList) {
  SingleLinkedList<int> ll;

  ll.push_front(1); 

  ll.remove(0);
  EXPECT_EQ(ll.size(), 0);

  ll.push_front(2); 

  EXPECT_EQ(ll.size(), 1);
  EXPECT_EQ(ll.pop_front(), 2);
}

TEST(SingleLinkedListTest, DoesNotDeleteNonExistentElement) {
  SingleLinkedList<int> ll;

  ll.push_front(1); 
  ll.remove(1);

  EXPECT_EQ(ll.size(), 1);
  EXPECT_EQ(ll.pop_front(), 1);
}

TEST(SingleLinkedListFindTest, FindsElementInLinkedList) {
    SingleLinkedList<int> ll;
    ll.push_front(0);
    ll.push_front(1);
    ll.push_front(2);
    
    EXPECT_TRUE(find(ll, 1));
}

TEST(SingleLinkedListFindTest, DoesNotFindElementInLinkedList) {
    SingleLinkedList<int> ll;
    ll.push_front(0);
    ll.push_front(1);
    ll.push_front(2);
    
    EXPECT_FALSE(find(ll, 3));
}
}

