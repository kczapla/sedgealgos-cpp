#include "sedgealgos/numbers/number_exception.hpp"
#include "sedgealgos/numbers/rational.hpp"

#include <gtest/gtest.h>

namespace {
  using namespace ::testing;
  using namespace ::sedgealgos::numbers;

TEST(RationalNumberTest, CtorDoesNotThrowIfNominatorAndDenominatorDoesNotHaveCommonDivisor) {
  EXPECT_NO_THROW(Rational(1, 2));
}

TEST(RationalNumberTest, CtorThrowsIfNominatorAndDenominatorHaveCommonDivisior) {
  EXPECT_THROW({Rational(2, 4);}, NumberException);
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
}
