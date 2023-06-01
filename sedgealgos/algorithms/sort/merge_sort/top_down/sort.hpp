#pragma once

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
        sort(c, static_cast<Container::Size>(0), c.size() - 1);
        callbacks->on_sort_stop();
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