#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/random/std_random.hpp"
#include "sedgealgos/data_structures/array/array.hpp"
#include "sedgealgos/time/stopwatch/stopwatch.hpp"

namespace {

using IntArray = sedgealgos::data_structures::array::Array<int>;
using DoubleArray = sedgealgos::data_structures::array::Array<double>;
using LongUsignedInt = sedgealgos::data_structures::array::Array<long unsigned int>;

IntArray generate_array(int n) {
    IntArray ia;
    for (int i{0}; i < n; i++) {
        ia.push_back(sedgealgos::random::StdRandom::uniform(1000000));
    }
    return ia;
}

LongUsignedInt generate_gaps(double t, int n) {
    LongUsignedInt ia;
    ia.push_back(1);
    for (auto t{1.10}; t < n - 1; t *= t) {
        ia.push_back(t);
    }
    return ia;
}

void sort(IntArray& arr, LongUsignedInt& gaps) {
    if (arr.size() == 0 || arr.size() == 1) {
        return;
    }

    typename IntArray::Size n{arr.size()};
    
    for (auto x{gaps.size()}; x > 0; x--) {
        for (auto i{gaps[x-1]}; i < n; i++) {
            for (auto j{i}; j >= gaps[x-1] && arr[j] < arr[j-gaps[x-1]]; j -= gaps[x-1]) {
                auto tmp{arr[j]};
                arr[j] = arr[j-gaps[x-1]];
                arr[j-gaps[x-1]] = tmp;
            }
        }
    }
}

double run_test_case(double t) {
    auto n{1000000};
    auto arr{generate_array(n)};
    auto gaps{generate_gaps(t, n)};

    sedgealgos::time::stopwatch::Stopwatch s;

    sort(arr, gaps);

    return s.elapsed();
}

void run_test_cases() {
    sedgealgos::io::StdOut std_out;

    auto best_time{1000000000000.0};
    auto best_t{0.0};
    auto t{1.1};
    while (t < 10.0) {
        std_out.printf("run test case for t = %d\n", t);
        auto elapsed{run_test_case(t)};
        std_out.printf("for t = %d elapsed time is %d\n\n", t, elapsed);
        if (elapsed < best_time) {
            best_t = t;
            best_time = elapsed;
        }
        t += 0.1;
    }
    std_out.printf("best time was %d for t = %d\n", best_time, best_t);
}

}

int main() {
    run_test_cases();

    return 0;
}
