#include "sedgealgos/algorithms/two_sum/are_equal.hpp"

namespace sedgealgos::algorithms::two_sum {
int AreEqual::count(Array const& array) const {
    auto count{0};
    for (std::size_t i{0}; i < array.size(); i++) {
        for (std::size_t j{i+1}; j < array.size(); j++) {
            if (array[i] == array[j])  {
                count++;
            }
        }
    }
    return count;
}
}
