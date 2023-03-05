#include "sedgealgos/algorithms/four_sum/four_sum.hpp"

namespace sedgealgos::algorithms::four_sum {
    int FourSum::count(Array arr) {
        auto const array_size{arr.size()};
        auto count{0};
        for (std::size_t i{0}; i < array_size; i++) {
            for (std::size_t j{i + 1}; j < array_size; j++) {
                for (std::size_t k{j + 1}; k < array_size; k++) {
                    for (std::size_t l{k + 1}; l < array_size; l++) {
                        if (arr[i] + arr[j] + arr[k] + arr[l] == 0) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
}

