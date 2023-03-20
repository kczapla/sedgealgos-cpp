#include "sedgealgos/exercises/chapter1/ex1418/ex1418.hpp"

#include <iostream>

namespace sedgealgos::exercises::chapter1::ex1418 {

int Ex1418::find(Ex1418::Array const& arr) {

    auto lower{0};
    auto upper{arr.size()};

    while (lower != upper) {
        int n{(lower + upper) / 2};

        if (n == 0) {
            if (arr[n] < arr[n+1]) {
                return n;
            }
            return -1;
        }
        std::cout << "lower = " << lower << std::endl;
        std::cout << "n = " << n << std::endl;
        std::cout << "upper = " << upper << std::endl;
        if ((arr[n] < arr[n-1]) && (arr[n] < arr[n+1])) {
            return n;
        }

        if (arr[n - 1] < arr[n]) {
            upper = n;
        } else {
            lower = n;
        }
    }
    return -1;
}
}

