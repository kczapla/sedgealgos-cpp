#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::algorithms::sort::insertion_sort_with_sentry {

template <typename T>
void sort(sedgealgos::data_structures::array::Array<T>& arr) {
    auto min_index{0};
    auto min_value{arr[min_index]};

    for (long unsigned int i{1}; i < arr.size(); i++) {
        if (arr[i] < min_value) {
            min_index = i;
            min_value = arr[i];
        }
    }

    arr[min_index] = arr[0];
    arr[0] = min_value;

    for (long unsigned int i{2}; i < arr.size(); i++) {
        for (long unsigned int j{i}; arr[j] < arr[j-1]; j--) {
                auto tmp{arr[j]};
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        } 
    }
}

