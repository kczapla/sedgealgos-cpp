#pragma once

#include <string>

namespace sedgealgos::date {
class SmartDate {
public:
    SmartDate(int m, int d, int y);

    int month() const;
    int day() const;
    int year() const;

    std::string day_of_the_week() const;

    std::string to_string() const;

    bool equals(SmartDate const&) const;

private:
    int m_;
    int d_;
    int y_;
};
}
