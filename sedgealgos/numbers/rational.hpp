#pragma once

namespace sedgealgos::numbers {
  class Rational {
  public:
    Rational(long, long);

  private:
    long nominator;
    long denominator;
  };
}

