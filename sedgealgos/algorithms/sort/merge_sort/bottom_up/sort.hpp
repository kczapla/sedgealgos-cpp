#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"

#include <algorithm>

namespace sedgealgos::algorithms::sort::merge_sort::bottom_up {

class Sort {
public:
    Sort(sort::Callbacks*) {}

    template<typename Container>
    void sort(Container& c) {
        if (c.is_empty() || c.size() == 0) {
            return;
        }

        auto const n{c.size() - 1}; 

        for (typename Container::Size sz{1}; sz <= n; sz = sz + sz) {
            for (typename Container::Size k{0}; k <= n ; k += sz + sz) {
                auto lo{k};
                auto mid{k + sz - 1};
                auto hi{std::min(mid + sz, n)};
                merge(c, lo, mid, std::min(n, hi));
            }
        }
    }

private:
    template<typename Container>
    void merge(Container& c, Container::Size lo, Container::Size mid, Container::Size hi) {
        Container aux{c};

        auto i{lo};
        auto j{mid + 1};
        for (typename Container::Size k{lo}; k <= hi; k++) {
            if (mid < i) {
                c[k] = aux[j++];
            } else if (hi < j) {
                c[k] = aux[i++];
            } else if (aux[i] < aux[j]) {
                c[k] = aux[i++];
            } else {
                c[k] = aux[j++];
            }
        }
    }
};
}