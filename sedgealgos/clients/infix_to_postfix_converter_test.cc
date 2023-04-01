#include "sedgealgos/clients/infix_to_postfix_converter.h"

#include <gtest/gtest.h>

#include <tuple>
#include <string>

namespace {
using namespace sedgealgos::clients;

using TestCaseData = std::tuple<std::string, std::string>;

class InfixToPostfixConverterTest : public ::testing::TestWithParam<TestCaseData> {
protected:
  InfixToPostfixConverter converter{};
};

TEST_P(InfixToPostfixConverterTest, ConvertArithmeticOperations) {
  EXPECT_EQ(converter.convert(std::get<0>(GetParam())), std::get<1>(GetParam()));
}

INSTANTIATE_TEST_CASE_P(
    ArithemticOps,
    InfixToPostfixConverterTest,
    ::testing::Values(
      std::make_tuple("1", "1"),
      std::make_tuple("1+2", "1 2 +"),
      std::make_tuple("1-2", "1 2 -"),
      std::make_tuple("1*2", "1 2 *"),
      std::make_tuple("1/2", "1 2 /"),
      std::make_tuple("1+2+3", "1 2 + 3 +"),
      std::make_tuple("1+2-3", "1 2 + 3 -"),
      std::make_tuple("1+2*3", "1 2 3 * +"),
      std::make_tuple("1+2/3", "1 2 3 / +"),
      std::make_tuple("1+2+3+4", "1 2 + 3 + 4 +"),
      std::make_tuple("1+2-3+4", "1 2 + 3 - 4 +"),
      std::make_tuple("1+2*3*4", "1 2 3 * 4 * +"),
      std::make_tuple("1+2*3*4+5", "1 2 3 * 4 * + 5 +"),
      std::make_tuple("1+2+3*4*5+6+7", "1 2 + 3 4 * 5 * + 6 + 7 +")
    )
);
}
