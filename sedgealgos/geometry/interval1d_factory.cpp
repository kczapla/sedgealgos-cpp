#include "sedgealgos/geometry/interval1d_factory.hpp"
#include "sedgealgos/geometry/interval1d.hpp"

#include <stdexcept>

namespace sedgealgos {
    Interval1d make_interval1d(double const l, double const h) {
        if (h < l) {
            throw std::invalid_argument("'lower' can not have higer value then 'higher'.");
        }
        return {l, h};
    }
}
