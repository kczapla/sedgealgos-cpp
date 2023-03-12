#include "sedgealgos/algorithms/two_sum/farthest_pair/farthest_pair.hpp"

#include <cmath>
#include <limits>
#include <ostream>

namespace sedgealgos::algorithms::two_sum::farthest_pair {
FarthestPair::Pair FarthestPair::find(Array const& arr) {
    auto max{std::numeric_limits<double>::lowest()};
    for (auto elem : arr) {
        if (elem > max) {
            max = elem;
        }
    }

    auto min{std::numeric_limits<double>::max()};
    for (auto elem : arr) {
        if (elem < min) {
            min = elem;
        }
    }

    return {min, max};
}

bool FarthestPair::Pair::operator==(FarthestPair::Pair const& pair) const {
    return (first == pair.first) && (second == pair.second);
}

std::ostream& operator<<(std::ostream& os, FarthestPair::Pair const& pair) {
    os << "{first: " << pair.first << ", second: " << pair.second << "}" << std::endl;
    return os;
}
}

