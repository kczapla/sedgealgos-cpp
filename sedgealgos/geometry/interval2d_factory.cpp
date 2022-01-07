#include "sedgealgos/geometry/interval1d.hpp"
#include "sedgealgos/geometry/interval2d.hpp"
#include "sedgealgos/geometry/interval1d_factory.hpp"
#include "sedgealgos/geometry/interval2d_factory.hpp"

namespace sedgealgos {
    Interval2d make_interval2d(double const xlo, double const xhi, double const ylo, double const yhi) {
       return {make_interval1d(xlo, xhi), make_interval1d(ylo, yhi)}; 
    }
}
