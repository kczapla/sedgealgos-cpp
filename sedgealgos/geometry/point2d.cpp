#include "sedgealgos/geometry/point2d.hpp"

#include <cmath>

namespace sedgealgos::geometry {
    double Point2d::radius() const {
        auto squared_hypotenuse{x() * x() + y() * y()};
        return std::sqrt(squared_hypotenuse);
    }

    double Point2d::theta() const {
        return std::atan(y() / x());
    }

    double Point2d::distance_to(Point2d const& other) const {
        auto const x{std::abs(this->x() - other.x())};
        auto const y{std::abs(this->y() - other.y())};

        return std::hypot(x, y);
    }
}
