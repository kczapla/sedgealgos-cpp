#include "sedgealgos/data_structures/linked_list/single_linked_list.hpp"

#include "sedgealgos/stack/stack_test.hpp"
#include "sedgealgos/stack/stack.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::stack;
using namespace sedgealgos::data_structures::linked_list;

using LinkedListStack = Stack<int, SingleLinkedList<int>>;

INSTANTIATE_TYPED_TEST_SUITE_P(LinkedList, StackTest, LinkedListStack);
INSTANTIATE_TYPED_TEST_SUITE_P(LinkedList, StackIteratorTest, LinkedListStack);
}
