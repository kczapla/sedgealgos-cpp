#include "sedgealgos/algorithms/two_sum/farthest_pair/farthest_pair.hpp"

#include <cmath>
#include <limits>
#include <ostream>

namespace sedgealgos::algorithms::two_sum::farthest_pair {
FarthestPair::Pair FarthestPair::find(Array const& arr) {
    Pair p{};
    auto min{0};
    for (std::size_t i{0}; i < arr.size(); i++) {
        for (std::size_t j{i +1}; j < arr.size(); j++) {
            auto const diff{std::abs(arr[j] - arr[i])};
            if (diff > min) {
                p.first = arr[i];
                p.second = arr[j];
                min = diff;
            }
        }
    }

    return p;
}

bool FarthestPair::Pair::operator==(FarthestPair::Pair const& pair) const {
    return (first == pair.first) && (second == pair.second);
}

std::ostream& operator<<(std::ostream& os, FarthestPair::Pair const& pair) {
    os << "{first: " << pair.first << ", second: " << pair.second << "}" << std::endl;
    return os;
}
}

