#include "sedgealgos/algorithms/two_sum/are_equal.hpp"

namespace sedgealgos::algorithms::two_sum {
int AreEqual::count(AreEqual::Array const& array) {
    auto count{0};
    for (int i{0}; i < array.size(); i++) {
        for (int j{i+1}; j < array.size(); j++) {
            if (a[i] = a[j])  {
                count++;
            }
        }
    }
    return count;
}
}
