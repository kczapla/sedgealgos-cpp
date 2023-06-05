#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"
#include "sedgealgos/algorithms/sort/sort/is_sorted.hpp"

#include <iostream>

namespace sedgealgos::algorithms::sort::merge_sort::improved_top_down {

template<typename Container,
         template<typename = Container> typename CutOffSort,
         template<typename = Container> typename Merge> 
class Sort {
public:
    Sort(sort::Callbacks* clbkcs) : callbacks{clbkcs} {}

    void sort(Container& c) {
        if (c.is_empty() || c.size() == 0) {
            return;
        }

        if (sort::is_sorted(c)) {
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
        if (hi - lo < 16) {
            CutOffSort<>::sort(c, lo, hi);
            return;
        }
        auto const mid{(hi + lo)/2};
        sort(c, aux, lo, mid);
        sort(c, aux, mid + 1, hi);
        Merge<>::merge(callbacks, c, aux, lo, mid, hi);
    }

    sort::Callbacks* callbacks{nullptr};
};
}