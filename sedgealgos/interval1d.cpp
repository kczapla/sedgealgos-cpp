#include "sedgealgos/interval1d.hpp"

#include <cmath>

namespace sedgealgos {
    double Interval1d::length() const {
        return std::abs(xaxis - yaxis);
    }

    bool Interval1d::contains(double const point) const {
        return (xaxis <= point) && (point <= yaxis);
    }
}
