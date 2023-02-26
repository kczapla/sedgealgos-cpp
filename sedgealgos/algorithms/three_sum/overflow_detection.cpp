#include "sedgealgos/algorithms/three_sum/overflow_detection.hpp"

#include <limits>

namespace sedgealgos::algorithms::three_sum::overflow_detection {

bool will_sum_overflow_negatively(int a, int b) {
    if (0 <= b) {
        return false;
    }
    return a < std::numeric_limits<int>::min() - b;
}
}
