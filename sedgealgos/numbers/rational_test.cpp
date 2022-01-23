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
}
