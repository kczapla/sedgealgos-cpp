#pragma once

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

        for (typename Container::Size sz{1}; sz <= n; sz = sz + sz) {
            for (typename Container::Size k{0}; k <= n ; k += sz + sz) {
                auto lo{k};
                auto mid{k + sz - 1};
                auto hi{std::min(mid + sz, n)};
                merge(c, lo, mid, std::min(n, hi));
            }
        }

        callbacks->on_sort_stop();
    }

private:
    template<typename Container>
    void merge(Container& c, Container::Size lo, Container::Size mid, Container::Size hi) {
        Container aux(c.size());
        for (typename Container::Size i{lo}; i < hi; i++) {
            aux[i] = c[i];
            callbacks->on_array_access(2);
        }

        auto i{lo};
        auto j{mid + 1};
        for (typename Container::Size k{lo}; k <= hi; k++) {
            if (mid < i) {
                c[k] = aux[j++];
                callbacks->on_array_access(2);
            } else if (hi < j) {
                c[k] = aux[i++];
                callbacks->on_array_access(2);
            } else if (aux[i] < aux[j]) {
                c[k] = aux[i++];
                callbacks->on_array_access(4);
            } else {
                c[k] = aux[j++];
                callbacks->on_array_access(4);
            }
        }
    }

    sort::Callbacks* callbacks{nullptr};
};
}