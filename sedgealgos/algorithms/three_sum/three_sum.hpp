#pragma once

#include <vector>

namespace sedgealgos::algorithms::three_sum {
  class ThreeSum {
  public:
    using Array = std::vector<int>;
    using ConstArray = Array const;
    using ConstArrayRef = ConstArray&;

    int count(ConstArrayRef);
  };
}
