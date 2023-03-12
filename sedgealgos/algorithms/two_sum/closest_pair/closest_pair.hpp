#pragma once

#include "sedgealgos/array/array.hpp"

#include <ostream>

namespace sedgealgos::algorithms::two_sum::closest_pair {
class ClosestPair {
public:
    using Array = sedgealgos::array::Array<double>;

    struct Pair {
        double first;
        double second;

        bool operator==(Pair const&) const;
    };

    static Pair find(Array&);
};

std::ostream& operator<<(std::ostream&, ClosestPair::Pair const&); 
}

