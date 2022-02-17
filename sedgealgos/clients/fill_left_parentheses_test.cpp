#include "sedgealgos/clients/fill_left_parentheses.hpp"

#include <gtest/gtest.h>

namespace {
  using namespace ::sedgealgos::clients;

  class FillLeftParenthesesTests : public ::testing::Test {
  protected:
      std::string fill(std::string_view s) {
        return FillLeftParentheses{}.fill(s);
      }
  };

  TEST_F(FillLeftParenthesesTests, WrapsSingleDigitAdditionOperation) {
    EXPECT_EQ(fill("1+2)"), "(1+2)");
  }

  TEST_F(FillLeftParenthesesTests, AddParenAroundSubtraction) {
    EXPECT_EQ(fill("1-2)"), "(1-2)");
  }

  TEST_F(FillLeftParenthesesTests, AddParenAroundMultiplication) {
    EXPECT_EQ(fill("1*2)"), "(1*2)");
  }

  TEST_F(FillLeftParenthesesTests, AddParenAroundDivision) {
    EXPECT_EQ(fill("1/2)"), "(1/2)");
  }

  TEST_F(FillLeftParenthesesTests, AddParenAroundCompoundArithmeticOps) {
    EXPECT_EQ(fill("1/2+3*4-5)"), "(1/2+3*4-5)");
  }

  TEST_F(FillLeftParenthesesTests, AddsParensAroundExprAndSingleChar) {
    EXPECT_EQ(fill("1/2)+3))"), "((1/2)+(3))");
  }

  TEST_F(FillLeftParenthesesTests, AddsParensAroundExprAndMultipleChars) {
    EXPECT_EQ(fill("1/2)+3*4-5))"), "((1/2)+(3*4-5))");
  }

  TEST_F(FillLeftParenthesesTests, WrapThreeExpressionsWithParams) {
    EXPECT_EQ(fill("1+2)*3-4)*5-6)))"), "((1+2)*((3-4)*(5-6)))");
  }
}
