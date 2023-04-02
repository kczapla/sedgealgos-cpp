#include "sedgealgos/stack/stack_test.hpp"
#include "sedgealgos/stack/linked_list_stack.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::stack;

INSTANTIATE_TYPED_TEST_SUITE_P(LinkedList, StackTest, LinkedListStack<int>);
INSTANTIATE_TYPED_TEST_SUITE_P(LinkedList, StackIteratorTest, LinkedListStack<int>);
}
