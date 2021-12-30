#pragma once

#include <string>

namespace sedgealgos {
    class Interval1d {
    public:
       Interval1d() = default;
       Interval1d(double l, double h) : lo{l}, hi{h} {}

       double length() const;
       bool contains(double) const;
       bool intersects(Interval1d const&) const;

       std::string string() const;

    private:
       double lo{};
       double hi{};
    };
}

