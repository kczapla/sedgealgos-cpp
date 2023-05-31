#include "sedgealgos/algorithms/sort/merge_sort/bottom_up/sort.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/top_down/sort.hpp"
#include "sedgealgos/algorithms/sort/sort/callbacks/sort_statistics.hpp"
#include "sedgealgos/algorithms/sort/sort_analysis/generate_array.hpp"
#include "sedgealgos/data_structures/string/string.hpp"
#include "sedgealgos/io/std_out.hpp"

void run_top_down_merge_sort(auto* callbacks, auto arr) {
    sedgealgos::algorithms::sort::merge_sort::top_down::Sort top_down{callbacks};
    top_down.sort(arr);
}

void run_bottom_up_merge_sort(auto* callbacks, auto arr) {
    sedgealgos::algorithms::sort::merge_sort::top_down::Sort bottom_up{callbacks};
    bottom_up.sort(arr);
}

sedgealgos::data_structures::string::String run(auto alg, auto distribution, auto n) {
    auto arr{sedgealgos::algorithms::sort::sort_analysis::generate_array<int>(n, distribution)};
    sedgealgos::algorithms::sort::sort::callbacks::SortStatistics stats_callbacks;

    if (alg == "top-down-merge") {
        run_top_down_merge_sort(&stats_callbacks, arr);
    } else if (alg == "bottom-up-merge") {
        run_bottom_up_merge_sort(&stats_callbacks, arr);
    }

    return stats_callbacks.to_json();
}

int main(int argc, char** argv) {
    sedgealgos::io::StdOut std_out;
    if (argc != 4) {
        std_out.println("please provide 3 cmdline args");
        return 1;
    }

    sedgealgos::data_structures::string::String alg{argv[1]};
    sedgealgos::data_structures::string::String distribution{argv[2]};
    auto n{std::stoi(argv[3])};
    
    auto result{run(alg, distribution, n)};

    std_out.printf("%s\n", result);
    
    return 0;
}