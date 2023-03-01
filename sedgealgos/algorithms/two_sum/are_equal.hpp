#pragma once

#include "sedgealgos/array/array.hpp"

namespace sedgealgos::algorithms::two_sum {
class AreEqual {
public:
    using Array = sedgealgos::array::Array<int>;

    int count(Array const&) const;
};
}
