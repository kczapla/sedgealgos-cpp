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

using MinuedSubtrahendDifference = std::tuple<Rational, Rational, Rational>;

MinuedSubtrahendDifference make_minued_subtrahend_difference(Rational const& minued, Rational const& subtrahend, Rational const& difference) {
    return std::make_tuple(minued, subtrahend, difference);
}

class RationalNumberSubtractionTest : public TestWithParam<MinuedSubtrahendDifference> {};

TEST_P(RationalNumberSubtractionTest, TermsSubtractionEqualsDifference) {
    auto const [minued, subtrahend, difference]{GetParam()};
    EXPECT_EQ(minued - subtrahend, difference);
}

INSTANTIATE_TEST_CASE_P(
    MinusOperator,
    RationalNumberSubtractionTest,
    Values(
        make_minued_subtrahend_difference({1, 1024}, {1, 500}, {-131, 128000}),
        make_minued_subtrahend_difference({1, 1}, {-1, 4}, {5, 4}),
        make_minued_subtrahend_difference({1, 3}, {-1, 4}, {7, 12}),
        make_minued_subtrahend_difference({-1, 3}, {-1, 4}, {-1, 12}),
        make_minued_subtrahend_difference({-1, 3}, {1, 4}, {-7, 12}),
        make_minued_subtrahend_difference({1, 3}, {1, 4}, {1, 12}),
        make_minued_subtrahend_difference({2, 3}, {1, 1}, {-1, 3}),
        make_minued_subtrahend_difference({2, 3}, {1, 3}, {1, 3}),
        make_minued_subtrahend_difference({2, 3}, {2, 3}, {0, 3})
    )
);
}
