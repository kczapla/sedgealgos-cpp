#include "sedgealgos/numbers/rational.hpp"
#include "sedgealgos/numbers/number_exception.hpp"

#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

namespace {
  int gcd(int p, int q) {
    if (q == 0) return p;
    int r{p % q};
    return gcd(q, r);
  }
}

namespace sedgealgos::numbers {

  std::ostream& operator<<(std::ostream& ostream, Rational const& rational) {
      return ostream << rational.to_string();
  }

  bool operator==(Rational const& lhs, Rational const& rhs) {
      return lhs.equals(rhs);
  }

  Rational operator+(Rational const& lhs, Rational const& rhs) {
      return lhs.plus(rhs);
  }

  Rational operator-(Rational const& lhs, Rational const& rhs) {
      return lhs.minus(rhs);
  }

  Rational operator*(Rational const& lhs, Rational const& rhs) {
      return lhs.multiply(rhs);
  }

  Rational::Rational(long n, long d) : nominator{n}, denominator{d} {
    if ((nominator == 1 && denominator == 1) || nominator == 0) {
      return;
    }
    if (denominator < 0) {
        nominator *= -1;
        denominator *= -1;
    }
    
    auto g{::gcd(std::abs( n ), std::abs(d))};
    if (g != 1) {
      nominator = nominator / g;
      denominator = denominator / g;
    }
  }

  Rational Rational::plus(Rational const& other) const {
    if ( denominator != other.denominator) {
      auto const n{nominator * other.denominator + other.nominator * denominator};
      auto const d{denominator * other.denominator};
      return Rational{n, d};
    }
    return Rational{nominator + other.nominator, denominator};
  }

  Rational Rational::minus(Rational const& other) const {
      if (denominator != other.denominator) {
        auto const n{nominator * other.denominator - denominator * other.nominator};
        auto const d{denominator * other.denominator};
        return Rational{n, d};
      }
      return {nominator - other.nominator, denominator};
  }

  Rational Rational::multiply(Rational const& other) const {
    return {nominator * other.nominator, denominator * other.denominator};
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
