#include "sedgealgos/exercises/chapter13/ex11/ex11.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <string>

namespace {

using TestCaseData = std::tuple<std::string, int>;

class Ex11Test : public ::testing::TestWithParam<TestCaseData> {
protected:
    sedgealgos::exercises::chapter13::ex11::Ex11 evaluator{};
};

TEST_P(Ex11Test, EvaluateExpression) {
  EXPECT_EQ(evaluator.eval(std::get<0>(GetParam())), std::get<1>(GetParam()));
}

INSTANTIATE_TEST_CASE_P(
    Evaluation,
    Ex11Test,
    ::testing::Values(
      std::make_tuple("1", 1),
      std::make_tuple("1 2 +", 3),
      std::make_tuple("1 2 -", -1),
      std::make_tuple("1 2 *", 2),
      std::make_tuple("1 2 /", 0),
      std::make_tuple("1 2 + 3 +", 6),
      std::make_tuple("1 2 + 3 -", 0),
      std::make_tuple("1 2 3 * +", 7),
      std::make_tuple("1 2 3 / +", 1),
      std::make_tuple("1 2 + 3 + 4 +", 10),
      std::make_tuple("1 2 + 3 - 4 +", 4),
      std::make_tuple("1 2 3 * 4 * +", 25),
      std::make_tuple("1 2 3 * 4 * + 5 +", 30),
      std::make_tuple("1 2 + 3 4 * 5 * + 6 + 7 +", 76)
    )
);
}
