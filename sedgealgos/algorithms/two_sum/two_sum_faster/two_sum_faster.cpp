#include "sedgealgos/algorithms/two_sum/two_sum_faster/two_sum_faster.hpp"

#include <iterator>
#include <iostream>

namespace sedgealgos::algorithms::two_sum::two_sum_faster {
using Set = sedgealgos::array::Array<bool>;

int TwoSumFaster::count(Array const& arr) {
    if (arr.empty()) {
        return 0;
    }

    if (arr[0] >= 0) {
        return 0;
    }

    Set set(0 - arr[0] + 1);

    auto const set_size{static_cast<int>(set.size())}; // this is ok, because set size is within int boundries
    auto count{0};

    for (std::size_t i{0}; i < arr.size(); i++) {
        if (arr[i] <= 0) {
            auto const set_index{0 - arr[i]};
            set[set_index] = true;
            continue;
        }

        if (arr[i] >= set_size) {
            break;
        }

        if (set[arr[i]]) {
            count++;
        }
    }
    return count;
}
}

