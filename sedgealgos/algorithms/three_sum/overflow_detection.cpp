#include "sedgealgos/algorithms/three_sum/overflow_detection.hpp"

#include <limits>

namespace sedgealgos::algorithms::three_sum::overflow_detection {

bool will_sum_overflow_negatively(int a, int b) {
    if (0 <= b) {
        return false;
    }
    return a < std::numeric_limits<int>::min() - b;
}

bool will_sum_overflow_negatively(int a, int b, int c) {
    auto sum_is_overflown{will_sum_overflow_negatively(a, b)};
    sum_is_overflown |= will_sum_overflow_negatively(a, c);
    sum_is_overflown |= will_sum_overflow_negatively(b, c);

    return sum_is_overflown;
}
}
