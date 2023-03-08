#include "sedgealgos/algorithms/two_sum/closest_pair/closest_pair.hpp"

#include <cmath>
#include <limits>

namespace sedgealgos::algorithms::two_sum::closest_pair {

std::ostream& operator<<(std::ostream& os, ClosestPair::Pair const& pair) {
    os << "{first: " << pair.first << ", second: " << pair.second << "}" << std::endl;
    return os;
}

bool ClosestPair::Pair::operator==(Pair const& pair) const {
    return first == pair.first && second == pair.second;
}

ClosestPair::Pair ClosestPair::find(Array const& array) {
    auto smallest_diff{std::numeric_limits<double>::max()};
    Pair smallest_pair;
    for (std::size_t i{0}; i < array.size(); i++) {
        for (std::size_t j{i+1}; j < array.size(); j++) {
            auto const diff{std::abs(array[j] - array[i])};
            if (diff < smallest_diff) {
                smallest_pair.first = array[i];
                smallest_pair.second = array[j];
                smallest_diff = diff;
            }
        }
    }
    return smallest_pair;
}
}

