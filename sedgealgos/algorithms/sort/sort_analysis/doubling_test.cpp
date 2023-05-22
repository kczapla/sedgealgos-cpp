#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/selection_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_selection_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_precalc_gaps_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort_with_sentry.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort_without_exchange.hpp"
#include "sedgealgos/data_structures/array/array.hpp"
#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/random/std_random.hpp"
#include "sedgealgos/time/stopwatch/stopwatch.hpp"

#include <string>

using String = std::string;
using IntArray = sedgealgos::data_structures::array::Array<int>;

struct TimeResult {
    double elapsed;
    int complexity;
};

TimeResult time(String alg, IntArray& arr) {
    sedgealgos::time::stopwatch::Stopwatch s;
    auto complexity{0};
    if (alg == "insertion") {
        complexity = 4;
        sedgealgos::algorithms::sort::insertion_sort::sort(arr);
    } else if (alg == "selection") {
        complexity = 4;
        sedgealgos::algorithms::sort::selection_sort::sort(arr);
    } else if (alg == "shell") {
        complexity = 2.8;
        sedgealgos::algorithms::sort::shell_sort::sort(arr);
    } else if (alg == "shell-selection") {
        complexity = 2.8;
        sedgealgos::algorithms::sort::shell_selection_sort::sort(arr);
    } else if (alg == "shell-precalc-gaps") {
        complexity = 2.8;
        sedgealgos::algorithms::sort::shell_precalc_gaps_sort::sort(arr);
    } else if (alg == "insertion-with-sentry") {
        complexity = 4;
        sedgealgos::algorithms::sort::insertion_sort_with_sentry::sort(arr);
    } else if (alg == "insertion-without-exchange") {
        complexity = 4;
        sedgealgos::algorithms::sort::insertion_sort_without_exchange::sort(arr);
    }

    return {s.elapsed(), complexity};
}

TimeResult time_random_input(String alg, int n) {
    IntArray ia;
    
    for (int i{0}; i < n; i++) {
        ia.push_back(sedgealgos::random::StdRandom::uniform(1000000));
    }

    return time(alg, ia);
}

void run_doubling_test(String alg) {
    sedgealgos::io::StdOut std_out;
    auto prev{1};
    for (auto i{1000}; i < 10024000; i *= 2) {
        auto t{time_random_input(alg, i)};
        std_out.printf("%d\t%d\t%d\t%d\n", i, t.elapsed, t.elapsed/prev, prev*t.complexity);
        prev = t.elapsed;
    }
}

int main(int argc, char** argv) {
    sedgealgos::io::StdOut std_out;
    if (argc != 2) {
        std_out.println("please provide cmdline arg");
        return 1;
    }

    run_doubling_test(argv[1]);

    return 0;
}
