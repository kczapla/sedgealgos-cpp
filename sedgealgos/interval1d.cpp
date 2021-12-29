#include "sedgealgos/interval1d.hpp"

#include <cmath>

namespace sedgealgos {
    double Interval1d::length() const {
        return std::abs(lo - hi);
    }

    bool Interval1d::contains(double const point) const {
        return (lo <= point) && (point <= hi);
    }

    bool Interval1d::intersects(Interval1d const& interval) const {
        auto do_i_contain_it{this->contains(interval.lo) || this->contains(interval.hi)};
        auto does_it_contain_me{interval.contains(lo) || interval.contains(hi)};
        return do_i_contain_it || does_it_contain_me;    
    }
}
