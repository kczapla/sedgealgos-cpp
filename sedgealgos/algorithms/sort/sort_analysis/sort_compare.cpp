#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/selection_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_selection_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/shell_precalc_gaps_sort.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort_with_sentry.hpp"
#include "sedgealgos/algorithms/sort/insertion_sort/insertion_sort_without_exchange.hpp"
#include "sedgealgos/data_structures/array/array.hpp"
#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/time/stopwatch/stopwatch.hpp"
#include "sedgealgos/algorithms/sort/sort_analysis/generate_array.hpp"

#include <string>

using String = std::string;
using IntArray = sedgealgos::data_structures::array::Array<int>;

double time(String alg, IntArray& arr) {
    sedgealgos::time::stopwatch::Stopwatch s;
    if (alg == "insertion") {
        sedgealgos::algorithms::sort::insertion_sort::sort(arr);
    } else if (alg == "selection") {
        sedgealgos::algorithms::sort::selection_sort::sort(arr);
    } else if (alg == "shell") {
        sedgealgos::algorithms::sort::shell_sort::sort(arr);
    } else if (alg == "shell-selection") {
        sedgealgos::algorithms::sort::shell_selection_sort::sort(arr);
    } else if (alg == "shell-precalc-gaps") {
        sedgealgos::algorithms::sort::shell_precalc_gaps_sort::sort(arr);
    } else if (alg == "insertion-with-sentry") {
        sedgealgos::algorithms::sort::insertion_sort_with_sentry::sort(arr);
    } else if (alg == "insertion-without-exchange") {
        sedgealgos::algorithms::sort::insertion_sort_without_exchange::sort(arr);
    }

    return s.elapsed();
}


double timeRandomInput(String alg, String distribution, int n, int tries) {
    double total{0};
    
    for (int t{0}; t < tries; t++) {
        auto arr{sedgealgos::algorithms::sort::sort_analysis::generate_array<int>(n, distribution)};
        total += time(alg, arr);
    }

    return total;
}

int main(int argc, char** argv) {
    sedgealgos::io::StdOut std_out;
    if (argc != 6) {
        std_out.println("please provide 5 cmdline args");
        return 1;
    }

    String alg1{argv[1]};
    String alg2{argv[2]};

    auto n{std::stoi(argv[3])};
    auto t{std::stoi(argv[4])};
    String d{argv[5]};

    auto t1{timeRandomInput(alg1, d, n, t)};
    auto t2{timeRandomInput(alg2, d, n, t)};

    std_out.printf("%s speed is %d\n", alg1, t1);
    std_out.printf("%s speed is %d\n", alg2, t2);
    std_out.printf("%s is %d faster than %s", alg1, t2/t1, alg2);

    return 0;
}
