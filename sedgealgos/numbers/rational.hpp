#pragma once

namespace sedgealgos::numbers {
  class Rational {
  public:
    Rational(long, long);

    bool equals(Rational const&) const;

  private:
    long nominator;
    long denominator;
  };
}

