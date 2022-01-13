#pragma once

#include <string>

namespace sedgealgos::date {
class SmartDate {
public:
    SmartDate(int m, int d, int y) : d_{d} {}

    int day() const;

private:
    int d_;
};
}
