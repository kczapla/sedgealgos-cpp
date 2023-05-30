#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"

namespace sedgealgos::algorithms::sort::merge_sort::top_down {

class Sort {
public:
    Sort(sort::Callbacks*) {}

    template<typename Container>
    void sort(Container&) {}
};
}