#include "sedgealgos/algorithms/binary_search/binary_search.hpp"

#include <iostream>

namespace sedgealgos::algorithms::binary_search {
    int BinarySearch::rank(Key key, BinarySearch::Array array) {
        std::size_t lower_bound{0};
        std::size_t higher_bound{array.size() - 1};

        while (lower_bound != higher_bound) {
            auto const mid{(lower_bound + higher_bound) / 2};
            if (key <= array[mid]) {
                higher_bound = mid;
            } else {
                lower_bound = mid+1;
            }
        }

        if (array[lower_bound] == key) {
            return lower_bound;
        }
        return -1;
    }
}

