#pragma once

#include "sedgealgos/array/array.hpp"

namespace sedgealgos::algorithms::three_sum::three_sum_faster {
class ThreeSumFaster {
public:
    using Array = sedgealgos::array::Array<int>;

    static int count(Array const&);
};
}

