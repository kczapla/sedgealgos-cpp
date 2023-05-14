#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::algorithms::sort::shell_sort {

template <typename T>
void sort(sedgealgos::data_structures::array::Array<T>& arr) {
    typename sedgealgos::data_structures::array::Array<T>::Size n{arr.size()};
    typename sedgealgos::data_structures::array::Array<T>::Size h{1};
    
    while (h < n/3) h = 3*h + 1;
    while (h >= 1) {
        for (auto i{h}; i < n; i++) {
            for (auto j{i}; j >= h && arr[j] < arr[j-h]; j -= h) {
                auto tmp{arr[j]};
                arr[j] = arr[j-h];
                arr[j-h] = tmp;
            }
        }
        h = h/3;
    }
}
}

