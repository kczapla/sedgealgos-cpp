#pragma once

#include <stdexcept>

namespace sedgealgos::numbers {
  class NumberException : public std::runtime_error {
  public:
    NumberException(std::string const& err) : std::runtime_error{err} {}
  };
}
