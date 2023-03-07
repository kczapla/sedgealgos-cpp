#include "sedgealgos/algorithms/three_sum/three_sum_faster/three_sum_faster.hpp"

namespace sedgealgos::algorithms::three_sum::three_sum_faster {
using Set = sedgealgos::array::Array<bool>;

int ThreeSumFaster::count(Array const& array) {
    auto const array_size{array.size()};

    auto count{0};
    for (std::size_t i{0}; i < array_size; i++) {
        Set set;
        for (std::size_t j{i+1}; j < array_size; j++) {
            auto const two_first_elems_sum{array[i] + array[j]};
            auto const sum_index_in_set{static_cast<std::size_t>(-two_first_elems_sum)};
            if (two_first_elems_sum < 0) {
                if (set.size() <= sum_index_in_set) {
                    set.resize(sum_index_in_set + 1);
                }
                set[sum_index_in_set] = true;
                continue;
            }

            if (set.size() <= static_cast<std::size_t>(array[j])) {
                break;
            }

            if (set[array[j]]) {
                count++;
            }
        }
    }

    return count;
}
}

