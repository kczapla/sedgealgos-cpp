#pragma once

#include "sedgealgos/algorithms/sort/merge_sort/merge/merge.hpp"

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"

#include <algorithm>

namespace sedgealgos::algorithms::sort::merge_sort::bottom_up {

class Sort {
public:
    Sort(sort::Callbacks* clbcks) : callbacks{clbcks} {}

    template<typename Container>
    void sort(Container& c) {
        if (c.is_empty() || c.size() == 0) {
            return;
        }

        auto const n{c.size() - 1}; 

        callbacks->on_sort_start();
        Container aux(c.size());
        for (typename Container::Size sz{1}; sz <= n; sz = sz + sz) {
            for (typename Container::Size k{0}; k <= n ; k += sz + sz) {
                auto lo{k};
                auto mid{k + sz - 1};
                auto hi{std::min(mid + sz, n)};
                merge::merge<Container>(callbacks, c, aux, lo, mid, std::min(n, hi));
            }
        }

        callbacks->on_sort_stop();
    }

    sort::Callbacks* callbacks{nullptr};
};
}