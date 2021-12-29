#include "sedgealgos/interval1d.hpp"

#include <cmath>

namespace sedgealgos {
    double Interval1d::length() const {
        return std::abs(xaxis - yaxis);
    }

    bool Interval1d::contains(double const point) const {
        return (xaxis <= point) && (point <= yaxis);
    }

    bool Interval1d::intersects(Interval1d const& interval) const {
        auto do_i_contain_it{this->contains(interval.xaxis) || this->contains(interval.yaxis)};
        auto does_it_contain_me{interval.contains(xaxis) || interval.contains(yaxis)};
        return do_i_contain_it || does_it_contain_me;    
    }
}
