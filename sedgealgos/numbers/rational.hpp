#pragma once

#include <string>
#include <ostream>

namespace sedgealgos::numbers {
  class Rational {
  public:
    Rational(long, long);

    Rational plus(Rational const&) const;

    bool equals(Rational const&) const;
    std::string to_string() const;

  private:
    long nominator;
    long denominator;
  };

  std::ostream& operator<<(std::ostream&, Rational const&);
  bool operator==(Rational const&, Rational const&);
}

