#include <gtest/gtest.h>

namespace {
  using namespace ::testing;

template <typename T>
class StackTest : public ::testing::Test {
protected:
    T stack{};
};

TYPED_TEST_SUITE_P(StackTest);


  TYPED_TEST_P(StackTest, CreatesUsingCopyCtor) {
      this->stack.push(1);

      TypeParam new_stack{this->stack};

      EXPECT_FALSE(new_stack.is_empty());
      EXPECT_EQ(this->stack.pop(), new_stack.pop());
  }

  TYPED_TEST_P(StackTest, CreatesUsingCopyAssignmentOperator) {
      this->stack.push(1);

      TypeParam new_stack{};
      new_stack = this->stack;

      EXPECT_FALSE(new_stack.is_empty());
      EXPECT_EQ(this->stack.pop(), new_stack.pop());
  }

  TYPED_TEST_P(StackTest, IsEmptyAfterCreated) {
      EXPECT_TRUE(this->stack.is_empty());
  }

  TYPED_TEST_P(StackTest, IsNotEmptyAfterPushingElement) {
      this->stack.push(1);

      EXPECT_FALSE(this->stack.is_empty());
  }

  TYPED_TEST_P(StackTest, PopsLatestElement) {
      this->stack.push(1);
      this->stack.push(2);

      EXPECT_EQ(this->stack.pop(), 2);
  }

  TYPED_TEST_P(StackTest, IsLIFO) {
      this->stack.push(1);
      this->stack.push(2);
      this->stack.push(3);
      this->stack.push(4);
      this->stack.push(5);
      this->stack.push(6);
      this->stack.push(7);
      this->stack.push(8);

      auto is_lifo{true};
      is_lifo &= this->stack.pop() == 8;
      is_lifo &= this->stack.pop() == 7;
      is_lifo &= this->stack.pop() == 6;
      is_lifo &= this->stack.pop() == 5;
      is_lifo &= this->stack.pop() == 4;
      is_lifo &= this->stack.pop() == 3;
      is_lifo &= this->stack.pop() == 2;
      is_lifo &= this->stack.pop() == 1;

      EXPECT_TRUE(is_lifo);
  }

  TYPED_TEST_P(StackTest, SizeReturnsZeroAfterPopingAllElements) {
      this->stack.push(1);
      this->stack.push(2);
      this->stack.push(3);

      this->stack.pop();
      this->stack.pop();
      this->stack.pop();

      EXPECT_EQ(this->stack.size(), 0);
  }

  TYPED_TEST_P(StackTest, ShrinkStackSize) {
      this->stack.push(1);
      this->stack.push(2);
      this->stack.push(3);
      this->stack.push(4);
      this->stack.push(5);
      this->stack.push(6);
      this->stack.push(7);
      this->stack.push(8);
      this->stack.push(9);
      this->stack.push(10);

      this->stack.pop();
      this->stack.pop();
      this->stack.pop();
      this->stack.pop();
      this->stack.pop();
      this->stack.pop();
      this->stack.pop();
      this->stack.pop();
      this->stack.pop();
  }

  TYPED_TEST_P(StackTest, PeeksTopElement) {
    this->stack.push(1);
    this->stack.push(2);
    this->stack.push(3);

    EXPECT_EQ(this->stack.peek(), 3);
  }

  TYPED_TEST_P(StackTest, PeekDoesNotPopsTopElement) {
    this->stack.push(1);
    [[maybe_unused]] auto elem{this->stack.peek()};

    EXPECT_EQ(this->stack.size(), 1);
  }

  TYPED_TEST_P(StackTest, PeekReturnsConstItemIfConstStack) {
    this->stack.push(1);

    auto const f{[](auto const& s) {
      const auto is_const{std::is_const_v<typename std::remove_reference<decltype(s.peek())>::type>};
      EXPECT_TRUE(is_const);
    }};

    f(this->stack);
  }

template <typename T>
class StackIteratorTest : public ::testing::Test {
protected:
    T stack{};
};

TYPED_TEST_SUITE_P(StackIteratorTest);


  TYPED_TEST_P(StackIteratorTest, IterateOverElements) {
    this->stack.push(1); 
    this->stack.push(2); 
    this->stack.push(3); 

    auto iter{std::begin(this->stack)};
    EXPECT_EQ(*iter, 3);

    EXPECT_EQ(*(++iter), 2);

    EXPECT_EQ(*(++iter), 1);

    iter++;
    EXPECT_TRUE(iter == std::end(this->stack));
  }

  TYPED_TEST_P(StackIteratorTest, EmptyIteratorIsEqualToLastElement) {
    EXPECT_TRUE(std::begin(this->stack) == std::end(this->stack));
  }

  REGISTER_TYPED_TEST_SUITE_P(
    StackTest,
    CreatesUsingCopyCtor,
    CreatesUsingCopyAssignmentOperator,
    IsEmptyAfterCreated,
    IsNotEmptyAfterPushingElement,
    PopsLatestElement,
    IsLIFO,
    SizeReturnsZeroAfterPopingAllElements,
    ShrinkStackSize,
    PeeksTopElement,
    PeekDoesNotPopsTopElement,
    PeekReturnsConstItemIfConstStack
  );


  REGISTER_TYPED_TEST_SUITE_P(
    StackIteratorTest,
    IterateOverElements,
    EmptyIteratorIsEqualToLastElement
  );
}
