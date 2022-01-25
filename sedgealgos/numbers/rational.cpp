#include "sedgealgos/numbers/rational.hpp"
#include "sedgealgos/numbers/number_exception.hpp"

#include <string>
#include <sstream>

namespace {
  int gcd(int p, int q) {
    if (q == 0) return p;
    int r{p % q};
    return gcd(q, r);
  }
}

namespace sedgealgos::numbers {
  Rational::Rational(long n, long d) : nominator{n}, denominator{d} {
    if (nominator == 1 && denominator == 1) {
      return;
    }
    
    auto g{::gcd(n, d)};
    if (g != 1) {
      throw NumberException{"nominator and denominator have common divisor"};
    }
  }

  Rational Rational::plus(Rational const& other) const {
    if (other.denominator == 1) {
      return Rational{nominator + denominator, denominator};
    } else if (denominator == 1) {
      return other.plus(*this);
    }
    if ( denominator != other.denominator) {
      auto const cd{::gcd(denominator, other.denominator)};
      auto const n{nominator * other.denominator + other.nominator * denominator};
      auto const d{denominator * other.denominator};
      return Rational{n, d};
    }
    return Rational{nominator + other.nominator, denominator};
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

  std::string Rational::to_string() const {
    std::stringstream ss;
    ss << nominator << "/" << denominator;
    return ss.str();
  }
}
