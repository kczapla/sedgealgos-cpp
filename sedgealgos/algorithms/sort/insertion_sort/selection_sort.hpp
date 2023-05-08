#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::algorithms::sort::selection_sort {

template <typename T>
void sort(sedgealgos::data_structures::array::Array<T>& arr) {
    for (long unsigned int i{0}; i < arr.size(); i++) {
        auto min_index{i};
        auto min_value{arr[i]};

        for (long unsigned int j{i+1}; j < arr.size(); j++) {
            if (arr[j] < min_value) {
                min_index = j;
                min_value = arr[j];
            }
        }

        arr[min_index] = arr[i];
        arr[i] = min_value;
    }
}
}

