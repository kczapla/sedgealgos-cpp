#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::algorithms::sort::shell_precalc_gaps_sort {

template <typename T>
void sort(sedgealgos::data_structures::array::Array<T>& arr) {
    if (arr.size() == 0 || arr.size() == 1) {
        return;
    }

    typename sedgealgos::data_structures::array::Array<T>::Size n{arr.size()};
    
    typename sedgealgos::data_structures::array::Array<T>::Size h{1};
    sedgealgos::data_structures::array::Array<typename sedgealgos::data_structures::array::Array<T>::Size> hs;
    hs.push_back(h);
    while (h < n/3) {
        h = 3*h + 1;
        hs.push_back(h);
    }

    for (auto x{hs.size()}; x > 0; x--) {
        for (auto i{hs[x-1]}; i < n; i++) {
            for (auto j{i}; j >= hs[x-1] && arr[j] < arr[j-hs[x-1]]; j -= hs[x-1]) {
                auto tmp{arr[j]};
                arr[j] = arr[j-hs[x-1]];
                arr[j-hs[x-1]] = tmp;
            }
        }
    }
}
}

