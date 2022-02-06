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

  TEST(ResizingArrayStack, PopsLatestElement) {
      ResizingArrayStack stack{};
      stack.push(1);
      stack.push(2);

      EXPECT_EQ(stack.pop(), 2);
  }

  TEST(ResizingArrayStack, IsLIFO) {
      ResizingArrayStack stack{};
      stack.push(1);
      stack.push(2);
      stack.push(3);
      stack.push(4);
      stack.push(5);
      stack.push(6);
      stack.push(7);
      stack.push(8);

      auto is_lifo{true};
      is_lifo &= stack.pop() == 8;
      is_lifo &= stack.pop() == 7;
      is_lifo &= stack.pop() == 6;
      is_lifo &= stack.pop() == 5;
      is_lifo &= stack.pop() == 4;
      is_lifo &= stack.pop() == 3;
      is_lifo &= stack.pop() == 2;
      is_lifo &= stack.pop() == 1;

      EXPECT_TRUE(is_lifo);
  }

  TEST(ResizingArrayStack, SizeReturnsZeroAfterPopingAllElements) {
      ResizingArrayStack stack{};
      stack.push(1);
      stack.push(2);
      stack.push(3);

      stack.pop();
      stack.pop();
      stack.pop();

      EXPECT_EQ(stack.size(), 0);
  }

  TEST(ResizingArrayStack, ShrinkStackSize) {
      ResizingArrayStack stack{};
      stack.push(1);
      stack.push(2);
      stack.push(3);
      stack.push(4);
      stack.push(5);
      stack.push(6);
      stack.push(7);
      stack.push(8);
      stack.push(9);
      stack.push(10);

      stack.pop();
      stack.pop();
      stack.pop();
      stack.pop();
      stack.pop();
      stack.pop();
      stack.pop();
      stack.pop();
      stack.pop();
  }
}
