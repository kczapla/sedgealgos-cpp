#pragma once

#include "sedgealgos/array/array.hpp"

namespace sedgealgos::algorithms::two_sum::two_sum_faster {
class TwoSumFaster {
public:
    using Array = sedgealgos::array::Array<int>;
    static int count(Array const&);
};
}

