#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"

namespace sedgealgos::algorithms::sort::merge_sort::merge {

template<typename Container>
void merge(sort::Callbacks* callbacks,
           Container& c,
           Container& aux,
           typename Container::Size lo,
           typename Container::Size mid,
           typename Container::Size hi) {
    
    for (typename Container::Size i{lo}; i <= hi; i++) {
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
}