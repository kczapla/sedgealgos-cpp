#include "sedgealgos/stack/stack_test.hpp"
#include "sedgealgos/stack/resizing_array_stack.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::stack;

INSTANTIATE_TYPED_TEST_SUITE_P(ResizingArray, StackTest, ResizingArrayStack<int>);
INSTANTIATE_TYPED_TEST_SUITE_P(ResizingArray, StackIteratorTest, ResizingArrayStack<int>);
}
