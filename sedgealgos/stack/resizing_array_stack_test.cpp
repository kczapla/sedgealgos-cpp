#include "sedgealgos/stack/resizing_array_stack.hpp"

#include <gtest/gtest.h>

namespace {
  using namespace ::testing;
  using namespace ::sedgealgos::stack;

  class ResizingArrayStackTest : public Test {
  protected:
    ResizingArrayStack<int> stack{};
  };

  TEST_F(ResizingArrayStackTest, CreatesUsingCopyCtor) {
      stack.push(1);

      ResizingArrayStack<int> new_stack{stack};

      EXPECT_FALSE(new_stack.is_empty());
      EXPECT_EQ(stack.pop(), new_stack.pop());
  }

  TEST_F(ResizingArrayStackTest, CreatesUsingCopyAssignmentOperator) {
      stack.push(1);

      ResizingArrayStack<int> new_stack{};
      new_stack = stack;

      EXPECT_FALSE(new_stack.is_empty());
      EXPECT_EQ(stack.pop(), new_stack.pop());
  }

  TEST_F(ResizingArrayStackTest, IsEmptyAfterCreated) {
      EXPECT_TRUE(stack.is_empty());
  }

  TEST_F(ResizingArrayStackTest, IsNotEmptyAfterPushingElement) {
      stack.push(1);

      EXPECT_FALSE(stack.is_empty());
  }

  TEST_F(ResizingArrayStackTest, PopsLatestElement) {
      stack.push(1);
      stack.push(2);

      EXPECT_EQ(stack.pop(), 2);
  }

  TEST_F(ResizingArrayStackTest, IsLIFO) {
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

  TEST_F(ResizingArrayStackTest, SizeReturnsZeroAfterPopingAllElements) {
      stack.push(1);
      stack.push(2);
      stack.push(3);

      stack.pop();
      stack.pop();
      stack.pop();

      EXPECT_EQ(stack.size(), 0);
  }

  TEST_F(ResizingArrayStackTest, ShrinkStackSize) {
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
