#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::algorithms::sort::insertion_sort {

template <typename Container>
struct InsertionSort {
    static void sort(Container& c) {
        if (c.is_empty()) {
            return;
        }
        sort(c, 0, c.size() - 1);
    }

    static void sort(Container& c, Container::Size lo, Container::Size hi) {
        for (long unsigned int i{lo + 1}; i <= hi; i++) {
            for (long unsigned int j{i}; j > lo && c[j] < c[j-1]; j--) {
                auto tmp{c[j]};
                c[j] = c[j-1];
                c[j-1] = tmp;
            }
        } 

    }
};

template <typename T>
void sort(sedgealgos::data_structures::array::Array<T>& arr) {
    for (long unsigned int i{1}; i < arr.size(); i++) {
        for (long unsigned int j{i}; j > 0 && arr[j] < arr[j-1]; j--) {
                auto tmp{arr[j]};
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        } 
    }
}

