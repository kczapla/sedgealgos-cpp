#include "sedgealgos/algorithms/sort/merge_sort/bottom_up/sort.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/merge/merge.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/merge/faster_merge.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/top_down/sort.hpp"
#include "sedgealgos/algorithms/sort/sort/callbacks/sort_statistics.hpp"
#include "sedgealgos/algorithms/sort/sort_analysis/generate_array.hpp"
#include "sedgealgos/data_structures/string/string.hpp"
#include "sedgealgos/io/std_out.hpp"

using Container = sedgealgos::data_structures::array::Array<int>;

template <typename C>
using StandardMerge = sedgealgos::algorithms::sort::merge_sort::merge::StandardMerge<C>;

template <typename C>
using FasterMerge = sedgealgos::algorithms::sort::merge_sort::merge::FasterMerge<C>;

struct Config {
    sedgealgos::data_structures::string::String algorithm_name;
    sedgealgos::data_structures::string::String distribution_name;
    int min_array_size{1};
    int array_size_increment{1};
    int max_array_size{1};
};

void run_bottom_up_merge_sort(auto* callbacks, auto arr) {
    sedgealgos::algorithms::sort::merge_sort::bottom_up::Sort bottom_up{callbacks};
    bottom_up.sort(arr);
}

sedgealgos::data_structures::string::String run(Config const& config) {
    auto arr{sedgealgos::algorithms::sort::sort_analysis::generate_array<int>(config.max_array_size, config.distribution_name)};
    sedgealgos::algorithms::sort::sort::callbacks::SortStatistics stats_callbacks{arr.size()};

    if (config.algorithm_name == "top-down-standard-merge") {
        sedgealgos::algorithms::sort::merge_sort::top_down::Sort<Container, StandardMerge> top_down{&stats_callbacks};
        top_down.sort(arr);
    } else if (config.algorithm_name == "top-down-faster-merge") {
        sedgealgos::algorithms::sort::merge_sort::top_down::Sort<Container, FasterMerge> top_down{&stats_callbacks};
        top_down.sort(arr);
    } else if (config.algorithm_name == "bottom-up-standard-merge") {
        sedgealgos::algorithms::sort::merge_sort::bottom_up::Sort<Container, StandardMerge> bottom_up{&stats_callbacks};
        bottom_up.sort(arr);
    } else if (config.algorithm_name == "bottom-up-faster-merge") {
        sedgealgos::algorithms::sort::merge_sort::bottom_up::Sort<Container, FasterMerge> bottom_up{&stats_callbacks};
        bottom_up.sort(arr);
    }

    return stats_callbacks.to_json();
}

int main(int argc, char** argv) {
    sedgealgos::io::StdOut std_out;
    if (argc != 6) {
        std_out.println("please provide 5 cmdline args");
        return 1;
    }

    Config config;
    config.algorithm_name = argv[1];
    config.distribution_name = argv[2];
    config.min_array_size = std::stoi(argv[3]);
    config.array_size_increment = std::stoi(argv[4]);
    config.max_array_size = std::stoi(argv[5]);
    
    auto result{run(config)};

    std_out.printf("%s\n", result);
    
    return 0;
}