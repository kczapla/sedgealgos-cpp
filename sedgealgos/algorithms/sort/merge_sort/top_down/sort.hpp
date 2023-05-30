#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"

#include <iostream>

namespace sedgealgos::algorithms::sort::merge_sort::top_down {

class Sort {
public:
    Sort(sort::Callbacks*) {}

    template<typename Container>
    void sort(Container& c) {
        if (c.is_empty() || c.size() == 0) {
            return;
        }

        sort(c, static_cast<Container::Size>(0), c.size() - 1);
    }

private:
    template<typename Container>
    void sort(Container& c, Container::Size lo, Container::Size hi) {
        if ((hi - lo) == 0) {
            return;
        }
        auto const mid{(hi + lo)/2};
        sort(c, lo, mid);
        sort(c, mid + 1, hi);
        merge(c, lo, mid, hi);
    }

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