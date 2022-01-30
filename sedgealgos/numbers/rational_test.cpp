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

TEST(RationalNumberTest, IsNotEqualToRationalWithDifferentDenominator) {
  Rational const r1{0, 3};
  Rational const r2{0, 4};
  EXPECT_NE(Rational(0, 3), Rational(0, 4));

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

using MultiplierMultiplicandProduct = std::tuple<Rational, Rational, Rational>;

MultiplierMultiplicandProduct make_multiplier_multiplicand_product(Rational const& multiplier, Rational const& multiplicand, Rational const& product) {
    return std::make_tuple(multiplier, multiplicand, product);
}

class RationalNumberMultiplicationTest : public TestWithParam<MultiplierMultiplicandProduct> {};

TEST_P(RationalNumberMultiplicationTest, MultiplyingFactorsGivesProduct) {
    auto const [multiplier, multiplicand, product]{GetParam()};
    EXPECT_EQ(multiplier * multiplicand, product);
}

INSTANTIATE_TEST_CASE_P(
    MultiplicationOperator,
    RationalNumberMultiplicationTest,
    Values(
        make_multiplier_multiplicand_product({1, 1}, {-1, 1}, {-1, 1}),
        make_multiplier_multiplicand_product({1, 1}, {2, 3}, {2, 3}),
        make_multiplier_multiplicand_product({1, 4}, {-2, 3}, {-2, 12}),
        make_multiplier_multiplicand_product({-2, 3}, {1, 4}, {-2, 12}),
        make_multiplier_multiplicand_product({2, 3}, {0, 4}, {0, 12}),
        make_multiplier_multiplicand_product({2, 3}, {2, 3}, {4, 9})
    )
);

using DividentDivisorFraction = std::tuple<Rational, Rational, Rational>;

MultiplierMultiplicandProduct make_divident_divisor_fraction(Rational const& divident, Rational const& divisor, Rational const& fraction) {
    return std::make_tuple(divident, divisor, fraction);
}

class RationalNumberDivisionTest : public TestWithParam<DividentDivisorFraction> {};

TEST_P(RationalNumberDivisionTest, DividingDividentByDivisorEqualsToFraction) {
    auto const [divident, divisor, fraction]{GetParam()};
    EXPECT_EQ(divident / divisor, fraction);
}

INSTANTIATE_TEST_CASE_P(
    DivisionOperator,
    RationalNumberDivisionTest,
    Values(
        make_divident_divisor_fraction({0, 3}, {1, 4}, {0, 3}),
        make_divident_divisor_fraction({-1, 3}, {-1, 2}, {2, 3}),
        make_divident_divisor_fraction({1, 3}, {-1, 2}, {-2, 3}),
        make_divident_divisor_fraction({1, 3}, {1, 2}, {2, 3}),
        make_divident_divisor_fraction({1, 1}, {1, 2}, {2, 1}),
        make_divident_divisor_fraction({1, 1}, {1, 1}, {1, 1})
    )
);
}
