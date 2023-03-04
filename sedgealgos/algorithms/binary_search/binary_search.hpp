#pragma once

#include "sedgealgos/array/array.hpp"

namespace sedgealgos::algorithms::binary_search {
class BinarySearch {
public:
    using Key = int;
    using Array = sedgealgos::array::Array<int>;

    static int rank(Key, BinarySearch::Array); 

};
}

