#include "sedgealgos/data_structures/stack/stack_test.hpp"
#include "sedgealgos/data_structures/stack/resizing_array_stack.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::data_structures::stack;

INSTANTIATE_TYPED_TEST_SUITE_P(ResizingArray, StackTest, ResizingArrayStack<int>);
INSTANTIATE_TYPED_TEST_SUITE_P(ResizingArray, StackIteratorTest, ResizingArrayStack<int>);
}
