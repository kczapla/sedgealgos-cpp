#include "sedgealgos/numbers/number_exception.hpp"
#include "sedgealgos/numbers/rational.hpp"

#include <gtest/gtest.h>

#include <tuple>

namespace {
  using namespace ::testing;
  using namespace ::sedgealgos::numbers;

TEST(RationalNumberTest, CtorRemovesNominatorAndDenominatorCommonDivisor) {
  Rational r{2, 4};
  EXPECT_EQ(r.to_string(), "1/2");
}

TEST(RationalNumberTest, IsEqualToTheSameRationalInstance) {
  Rational const r{2, 3};
  EXPECT_TRUE(r.equals(r));
}

using AugendAddendSum = std::tuple<Rational, Rational, Rational>;

AugendAddendSum make_augend_addend_sum(Rational augend, Rational addened, Rational sum) {
    return std::make_tuple(augend, addened, sum);
}

class RationalNumberAdditionTest : public TestWithParam<AugendAddendSum> {};

TEST_P(RationalNumberAdditionTest, SummandsAdditionEqualsSum) {
    auto [augend, addened, sum] = GetParam();
    EXPECT_EQ(augend + addened, sum);
}

INSTANTIATE_TEST_CASE_P(
        PlusOperator,
        RationalNumberAdditionTest,
        Values(
            make_augend_addend_sum({2, 3}, {2, 3}, {4, 3}),
            make_augend_addend_sum({2, 3}, {1, 1}, {5, 3}),
            make_augend_addend_sum({2, 3}, {3, 5}, {19, 15}),
            make_augend_addend_sum({3, 4}, {1, 4}, {1, 1}),
            make_augend_addend_sum({-3, 4}, {-1, 4}, {-1, 1}),
            make_augend_addend_sum({-3, 4}, {1, 4}, {-1, 2}),
            make_augend_addend_sum({-3, 4}, {5, 4}, {1, 2})
        ));
}
