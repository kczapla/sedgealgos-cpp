#pragma once

#include <stdexcept>

namespace sedgealgos::date {
class DateException :public std::invalid_argument {
public:
    DateException(std::string what) : std::invalid_argument{std::move(what)} {}
};
}
