#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::algorithms::sort::selection_sort {

template <typename T>
void sort(sedgealgos::data_structures::array::Array<T>& arr) {
    for (long unsigned int i{1}; i < arr.size(); i++) {
        for (long unsigned int j{i}; j > 0; j--) {
            if (arr[j-1] > arr[j]) {
                auto tmp{arr[j]};
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            } else {
                j = 1;
            }
        } 
    }
}
}

