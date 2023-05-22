#include <string>
#include <iostream>

#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/data_structures/array/array.hpp"
#include "sedgealgos/random/std_random.hpp"

namespace {

using IntArray = sedgealgos::data_structures::array::Array<int>;

void sort(IntArray& arr) {
    sedgealgos::io::StdOut out;
    typename IntArray::Size n{arr.size()};
    typename IntArray::Size h{1};
    
    unsigned long int cmps{0};

    while (h < n/3) h = 3*h + 1;
    while (h >= 1) {
        for (auto i{h}; i < n; i++) {
            cmps++;
            for (auto j{i}; j >= h && arr[j] < arr[j-h]; j -= h) {
                auto tmp{arr[j]};
                arr[j] = arr[j-h];
                arr[j-h] = tmp;
            }
        }
        std::cout << h << ": cmps=" << static_cast<double>(cmps)/n << std::endl;
        cmps = 0;
        
        h = h/3;
    }
}

IntArray make_random_array(int n) {
    IntArray ia;

    for (int i{0}; i < n; i++) {
        ia.push_back(sedgealgos::random::StdRandom::uniform(n));
    }

    return ia;
}
}

int main(int argc, char** argv) {
    sedgealgos::io::StdOut out;
    if (argc != 2) {
        out.println("please provide arry size"); 
        return 1;
    }
    auto arr{make_random_array(std::stoi(argv[1]))};
    sort(arr);
    
    return 0;
}