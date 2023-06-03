#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"

namespace sedgealgos::algorithms::sort::merge_sort::merge {

template<typename Container>
void faster_merge(sort::Callbacks* callbacks,
           Container& c,
           Container& aux,
           typename Container::Size lo,
           typename Container::Size mid,
           typename Container::Size hi) {
    
    for (typename Container::Size i{lo}; i <= mid; i++) {
        aux[i] = c[i];
        callbacks->on_array_access(2);
    }

    typename Container::Size i{mid+1};
    typename Container::Size j{hi};
    while (i <= hi) {
        aux[i++] = c[j--];    
    }

    i = lo;
    j = hi;
    for (typename Container::Size k{lo}; k <= hi; k++) {
        if (aux[i] < aux[j]) {
            c[k] = aux[i++];
            callbacks->on_array_access(4);
        } else {
            c[k] = aux[j--];
            callbacks->on_array_access(4);
        }
    }
}
}