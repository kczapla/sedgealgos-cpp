#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::algorithms::sort::shell_selection_sort {

template <typename T>
void sort(sedgealgos::data_structures::array::Array<T>& arr) {
    typename sedgealgos::data_structures::array::Array<T>::Size n{arr.size()};
    typename sedgealgos::data_structures::array::Array<T>::Size h{1};
    
    while (h < n/3) h = 3*h + 1;
    while (h >= 1) {
        for (unsigned long i{0}; i < n; i++) {
            auto min_index{i};
            auto min_value{arr[i]};

            for (auto j{i+h}; j < n; j += h) {
                if (arr[j] < min_value) {
                    min_index = j;
                    min_value = arr[j];
                }
            }
            arr[min_index] = arr[i];
            arr[i] = min_value;
        }
        h = h/3;
    }
}
}

