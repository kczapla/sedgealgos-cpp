#include "sedgealgos/point2d.hpp"

#include <cmath>

namespace sedgealgos {
    double Point2d::radius() const {
        auto squared_hypotenuse{x() * x() + y() * y()};
        return std::sqrt(squared_hypotenuse);
    }

    double Point2d::theta() const {
        return std::atan(y() / x());
    }
}
