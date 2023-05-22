#include "sedgealgos/data_structures/array/array.hpp"
#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/random/std_random.hpp"

#include <string>
#include <iostream>
#include <sstream>

using String = std::string;
using IntArray = sedgealgos::data_structures::array::Array<int>;

template <typename T>
int sort(sedgealgos::data_structures::array::Array<T>& arr) {
    typename sedgealgos::data_structures::array::Array<T>::Size n{arr.size()};
    typename sedgealgos::data_structures::array::Array<T>::Size h{1};

    long long cmp{0};
    
    while (h < n/3) h = 3*h + 1;
    while (h >= 1) {
        for (auto i{h}; i < n; i++) {
            for (auto j{i}; j >= h && arr[j] < arr[j-h]; j -= h) {
                auto tmp{arr[j]};
                arr[j] = arr[j-h];
                arr[j-h] = tmp;
                cmp++;
            }
            cmp++;
        }
        h = h/3;
    }

    return cmp;
}

IntArray genereate_array() {
    IntArray ia;
    for (int i{0}; i < 100; i++) {
        ia.push_back(sedgealgos::random::StdRandom::uniform(100));
    }
    return ia;
}

void print_array(IntArray& arr) {
    std::stringstream ss;
    ss << "{";
    for (auto&& a : arr) {
        ss << a << ",";
    }
    ss << "}";

    std::cout << ss.str() << std::endl;
}

void timeRandomInput() {
    sedgealgos::io::StdOut std_out;

    auto max_cmp_no{0};
    IntArray worst_array;

    for (int i{0}; i < 100000000; i++) {
        auto arr{genereate_array()};
        auto to_sort{arr};
        auto cmp_no{sort(to_sort)};

        if (max_cmp_no < cmp_no) {
            max_cmp_no = cmp_no;
            worst_array = arr;
        }
    }
    std::cout << "max number of cmp: " << max_cmp_no << std::endl;
    print_array(worst_array);
}

int main(int argc, char** argv) {
    timeRandomInput();
    return 0;
}
