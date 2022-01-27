#include "sedgealgos/numbers/number_exception.hpp"
#include "sedgealgos/numbers/rational.hpp"

#include <gtest/gtest.h>

namespace {
  using namespace ::testing;
  using namespace ::sedgealgos::numbers;

TEST(RationalNumberTest, CtorDoesNotThrowIfNominatorAndDenominatorDoesNotHaveCommonDivisor) {
  EXPECT_NO_THROW(Rational(1, 2));
}

TEST(RationalNumberTest, CtorRemovesNominatorAndDenominatorCommonDivisor) {
  Rational r{2, 4};
  EXPECT_EQ(r.to_string(), "1/2");
}

TEST(RationalNumberTest, IsEqualToTheSameRationalInstance) {
  Rational const r{2, 3};
  EXPECT_TRUE(r.equals(r));
}

TEST(RationalNumberTest, IsNotEqualToDifferentRationalNumber) {
  Rational const r1{2, 3};
  Rational const r2{4, 3};
  EXPECT_FALSE(r1.equals(r2));
}

TEST(RationalNumberTest, IsEqualTheSameRationalNumber) {
  Rational const r1{2, 3};
  Rational const r2{2, 3};

  EXPECT_TRUE(r1.equals(r2));
}

TEST(RationalNumberTest, ReturnsStringRepresentation) {
  Rational const r{2, 3};
  EXPECT_EQ(r.to_string(), "2/3");
}

TEST(RationalNumberTest, SumsTwoRationalsWithTheSameDenominator) {
  Rational const r1{2, 3};
  EXPECT_TRUE(r1.plus(r1).equals(Rational{4, 3}));
}

TEST(RationalNumberTest, SumsFractionAndOne) {
  Rational const r1{2, 3};
  Rational const r2{1, 1};

  EXPECT_TRUE(r1.plus(r2).equals(Rational{5, 3}));
  EXPECT_TRUE(r2.plus(r1).equals(Rational{5, 3}));
}

TEST(RationalNumberTest, SumsFractionsWithDifferentDenominators) {
  Rational const r1{2, 3};
  Rational const r2{3, 5};

  EXPECT_TRUE(r1.plus(r2).equals(Rational{19, 15}));
}

TEST(RationalNumberTest, SumGivesSingleNumber) {
  Rational const r1{3, 4};
  Rational const r2{1, 4};

  EXPECT_TRUE(r1.plus(r2).equals(Rational{1, 1}));
}
}
