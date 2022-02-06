#include "sedgealgos/stack/resizing_array_stack.hpp"

#include <gtest/gtest.h>

namespace {
  using namespace ::testing;
  using namespace ::sedgealgos::stack;

  TEST(ResizingArrayStack, CreatesObject) {
      ResizingArrayStack stack{};
  }

  TEST(ResizingArrayStack, IsEmptyAfterCreated) {
      ResizingArrayStack stack{};
      EXPECT_TRUE(stack.is_empty());
  }

  TEST(ResizingArrayStack, IsNotEmptyAfterPushingElement) {
      ResizingArrayStack stack{};
      stack.push(1);

      EXPECT_FALSE(stack.is_empty());
  }
}
