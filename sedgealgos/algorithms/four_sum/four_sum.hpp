#pragma once

#include "sedgealgos/array/array.hpp"

namespace sedgealgos::algorithms::four_sum {
class FourSum {
public:
    using Array = sedgealgos::array::Array<int>;
    static int count(Array);
};
}

