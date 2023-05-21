#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::algorithms::sort::insertion_sort_without_exchange {

template <typename T>
void sort(sedgealgos::data_structures::array::Array<T>& arr) {
    for (long unsigned int i{1}; i < arr.size(); i++) {
        auto aux{arr[i]};

        long unsigned int j;
        for (j = i; j > 0 && aux < arr[j-1]; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = aux;
    } 
}
}

