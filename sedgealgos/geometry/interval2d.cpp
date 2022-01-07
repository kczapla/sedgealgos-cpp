#include "sedgealgos/geometry/point2d.hpp"
#include "sedgealgos/geometry/interval2d.hpp"

#include <sstream>

namespace sedgealgos::geometry {
    double Interval2d::area() const {
        return xinterval.length() * yinterval.length();
    }

    bool Interval2d::contains(geometry::Point2d const& point2d) const {
        return xinterval.contains(point2d.x()) && yinterval.contains(point2d.y());
    }

    bool Interval2d::intersects(Interval2d const& interval2d) const {
        auto const xinterval_intersects{xinterval.intersects(interval2d.xinterval)};
        auto const yinterval_intersects{yinterval.intersects(interval2d.yinterval)};
        
        return xinterval_intersects && yinterval_intersects;
    }

    std::string Interval2d::string() const {
        std::stringstream ss;
        ss << "Intrerval2d(";
        ss << "x=" << xinterval.string() << ", ";
        ss << "y=" << yinterval.string() << ")";

        return ss.str();
    }
}
