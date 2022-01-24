#pragma once

#include <string>

namespace sedgealgos::numbers {
  class Rational {
  public:
    Rational(long, long);

    bool equals(Rational const&) const;
    std::string to_string() const;

  private:
    long nominator;
    long denominator;
  };
}

