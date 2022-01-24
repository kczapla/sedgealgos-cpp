#include "sedgealgos/numbers/rational.hpp"
#include "sedgealgos/numbers/number_exception.hpp"

namespace {
  int gcd(int p, int q) {
    if (q == 0) return p;
    int r{p % q};
    return gcd(q, r);
  }
}

namespace sedgealgos::numbers {
  Rational::Rational(long n, long d) : nominator{n}, denominator{d} {
    auto g{::gcd(n, d)};
    if (g != 1) {
      throw NumberException{"nominator and denominator have common divisor"};
    }
  }

  bool Rational::equals(Rational const& other) const {
      if (this == &other) {
        return true;
      }
      auto rationals_are_equal{true};
      rationals_are_equal &= nominator == other.nominator;
      rationals_are_equal &= denominator == other.denominator;

      return rationals_are_equal;
  }
}
