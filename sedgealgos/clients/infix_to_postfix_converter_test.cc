#include "sedgealgos/clients/infix_to_postfix_converter.h"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::clients;

TEST(InfixToPostfixConverterTest, ConverArithmeticOperations) {
  InfixToPostfixConverter converter;
  EXPECT_EQ(converter.convert("1+2"), "(1 2 +)");
  EXPECT_EQ(converter.convert("1-2"), "(1 2 -)");
  EXPECT_EQ(converter.convert("1*2"), "(1 2 *)");
  EXPECT_EQ(converter.convert("1/2"), "(1 2 /)");
}
}
