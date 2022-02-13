#include "sedgealgos/clients/fill_left_parentheses.hpp"

#include <gtest/gtest.h>

namespace {
  using namespace ::sedgealgos::clients;

  TEST(FillLeftParenthesesTests, WrapsSingleDigitAdditionOperation) {
    FillLeftParentheses flp;  
    EXPECT_EQ(flp.fill("1+2)"), "(1+2)");
  }

  TEST(FillLeftParenthesesTests, AddParenAroundSubtraction) {
    FillLeftParentheses flp;
    EXPECT_EQ(flp.fill("1-2)"), "(1-2)");
  }

  TEST(FillLeftParenthesesTests, AddParenAroundMultiplication) {
    FillLeftParentheses flp;
    EXPECT_EQ(flp.fill("1*2)"), "(1*2)");
  }

  TEST(FillLeftParenthesesTests, AddParenAroundDivision) {
    FillLeftParentheses flp;
    EXPECT_EQ(flp.fill("1/2)"), "(1/2)");
  }
}
