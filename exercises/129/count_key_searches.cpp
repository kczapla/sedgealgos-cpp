#include "sedgealgos/analysis/counter.hpp"

#include <vector>
#include <iostream>


int rank(int key, std::vector<int> a, sedgealgos::analysis::Counter& c) {
    std::size_t lo{0};
    std::size_t hi{a.size() - 1};

    while (lo <= hi) {
        std::size_t mid{lo + (hi - lo)/2};
        if (key < a[mid]) {
            hi = mid - 1;
            c.increment();
        } else if (key > a[mid]) {
            lo = mid + 1;
            c.increment();
        } else {
            return mid;
        }
    }
    
    return -1;


}

int main() {
    sedgealgos::analysis::Counter counter{"search key"};
    std::vector<int> x{1,2,3,4,5,6,7,8,9};
    auto r{rank(5, x, counter)};
    std::cout << counter.string() << ": " << r << std::endl;

    return 0;
}
