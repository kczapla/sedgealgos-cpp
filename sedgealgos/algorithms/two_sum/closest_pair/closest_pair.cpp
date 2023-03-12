#include "sedgealgos/algorithms/two_sum/closest_pair/closest_pair.hpp"

#include <cmath>
#include <limits>
#include <algorithm>

namespace sedgealgos::algorithms::two_sum::closest_pair {

std::ostream& operator<<(std::ostream& os, ClosestPair::Pair const& pair) {
    os << "{first: " << pair.first << ", second: " << pair.second << "}" << std::endl;
    return os;
}

bool ClosestPair::Pair::operator==(Pair const& pair) const {
    return first == pair.first && second == pair.second;
}

ClosestPair::Pair ClosestPair::find(Array& array) {
    if (array.size() < 2) {
        return {std::numeric_limits<double>::max(), std::numeric_limits<double>::max()};
    }

    std::sort(array.begin(), array.end());

    auto min{std::numeric_limits<double>::max()};
    Pair p;
    for (std::size_t i{1}; i < array.size(); i++) {
        auto diff = array[i] - array[i-1];
        if (diff < min) {
            min = diff;
            p.first = array[i-1];
            p.second = array[i];
        }
    }

    return p;
}
}

