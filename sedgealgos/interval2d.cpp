#include "sedgealgos/point2d.hpp"
#include "sedgealgos/interval2d.hpp"

namespace sedgealgos {
    double Interval2d::area() const {
        return xinterval.length() * yinterval.length();
    }

    bool Interval2d::contains(Point2d const& point2d) const {
        return xinterval.contains(point2d.x()) && yinterval.contains(point2d.y());
    }
}
