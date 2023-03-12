#pragma once

#include "sedgealgos/array/array.hpp"

#include <ostream>

namespace sedgealgos::algorithms::two_sum::farthest_pair {
class FarthestPair {
public:
    using Array = sedgealgos::array::Array<double>;
    struct Pair {
        double first;
        double second;

        bool operator==(Pair const&) const;
    };

    static Pair find(Array const&);
};

std::ostream& operator<<(std::ostream&, FarthestPair::Pair const&);
}

