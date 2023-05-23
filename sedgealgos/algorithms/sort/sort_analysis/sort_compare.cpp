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

IntArray generate_array(int n, String distribution) {
    IntArray ia;
    std::random_device rd;
    std::mt19937 gen{rd()};

    if (distribution == "gauss") {
        std::normal_distribution<> d{5, 2};
        for (auto i{0}; i < n; i++) {
            ia.push_back(std::round(d(gen)));
        }
    } else if (distribution == "poisson") {
        std::poisson_distribution<> d{4};
        for (auto i{0}; i < n; i++) {
            ia.push_back(std::round(d(gen)));
        }
    } else if (distribution == "geometric") {
        std::geometric_distribution<> d;
        for (auto i{0}; i < n; i++) {
            ia.push_back(std::round(d(gen)));
        }
    } else if (distribution == "discrete") {
        std::discrete_distribution<> d({40, 10, 10, 40});
        for (auto i{0}; i < n; i++) {
            ia.push_back(std::round(d(gen)));
        }
    } else if (distribution == "uniform") {
        std::uniform_int_distribution<> d{1000000};
        for (auto i{0}; i < n; i++) {
            ia.push_back(d(gen));
        }
    } else if (distribution == "first-half-ones") {
        auto i{0};
        for (; i < n/2; i++) {
            ia.push_back(1);
        }
        for (; i < n; i++) {
            ia.push_back(0);
        }
    } else if (distribution == "second-half-ones") {
        auto i{0};
        for (; i < n/2; i++) {
            ia.push_back(0);
        }
        for (; i < n; i++) {
            ia.push_back(1);
        }
    } else if (distribution == "halves") {
        auto val{0};

        auto left{n/2};
        auto start{0};
        auto end{start + left};
        while (left != 0) {
            for (; start < end; start++) {
                ia.push_back(val);
            }
            start = end;
            left /= 2;
            end = start + left;
            val++;
        }
        ia.push_back(val);
    }


    return ia;
}

double timeRandomInput(String alg, String distribution, int n, int tries) {
    double total{0};
    
    for (int t{0}; t < tries; t++) {
        auto arr{generate_array(n, distribution)};
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
