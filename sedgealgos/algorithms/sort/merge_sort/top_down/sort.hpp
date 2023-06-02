#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/merge_sort.hpp"

#include <iostream>

namespace sedgealgos::algorithms::sort::merge_sort::top_down {

template<typename Container> 
class Sort {
public:
    Sort(MergeFunc<Container> merge, sort::Callbacks* clbkcs) : merge{merge}, callbacks{clbkcs} {}

    void sort(Container& c) {
        if (c.is_empty() || c.size() == 0) {
            return;
        }

        callbacks->on_sort_start();
        Container aux(c.size());
        sort(c, aux, static_cast<Container::Size>(0), c.size() - 1);
        callbacks->on_sort_stop();
    }

private:
    void sort(Container& c, Container& aux, Container::Size lo, Container::Size hi) {
        if ((hi - lo) == 0) {
            return;
        }
        auto const mid{(hi + lo)/2};
        sort(c, aux, lo, mid);
        sort(c, aux, mid + 1, hi);
        merge(callbacks, c, aux, lo, mid, hi);
    }

    MergeFunc<Container> merge;
    sort::Callbacks* callbacks{nullptr};
};
}