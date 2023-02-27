#include "sedgealgos/algorithms/three_sum/three_sum.hpp"
#include "sedgealgos/algorithms/three_sum/overflow_detection.hpp"

#include <limits>
#include <iostream>

namespace sedgealgos::algorithms::three_sum {
    int ThreeSum::count(ConstArrayRef a) {
        auto count{0};
        for (std::size_t i = 0; i < a.size(); i++) {
            for (std::size_t j = i + 1; j < a.size(); j++) {
                for (std::size_t k = j + 1; k < a.size(); k++) {
                    if (overflow_detection::will_sum_overflow(a[i], a[j], a[k])) {
                        continue;
                    }

                    auto const sum = a[i] + a[j] + a[k];
                    if (sum == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}
