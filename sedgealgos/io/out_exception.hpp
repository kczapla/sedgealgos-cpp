#pragma once

#include <stdexcept>

namespace sedgealgos::io {
class OutException : public std::runtime_error {
public:
  OutException(std::string s) : runtime_error{std::move(s)} {}
};
}
