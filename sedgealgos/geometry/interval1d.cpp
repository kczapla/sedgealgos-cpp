#include "sedgealgos/geometry/interval1d.hpp"

#include <cmath>
#include <sstream>

namespace sedgealgos::geometry {
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

    std::string Interval1d::string() const {
        std::stringstream ss;
        ss << "Interval1d(lo=" << lo << ", hi=" << hi << ")";
        return ss.str();
    }
}
