#pragma once

#include "sedgealgos/algorithms/sort/merge_sort/merge/merge.hpp"
#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"

#include <iostream>

namespace sedgealgos::algorithms::sort::merge_sort::top_down {

class Sort {
public:
    Sort(sort::Callbacks* clbkcs) : callbacks{clbkcs} {}

    template<typename Container>
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
    template<typename Container>
    void sort(Container& c, Container& aux, Container::Size lo, Container::Size hi) {
        if ((hi - lo) == 0) {
            return;
        }
        auto const mid{(hi + lo)/2};
        sort(c, aux, lo, mid);
        sort(c, aux, mid + 1, hi);
        merge::merge(callbacks, c, aux, lo, mid, hi);
    }
    
    sort::Callbacks* callbacks{nullptr};
};
}