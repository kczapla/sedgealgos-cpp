// #include "sedgealgos/algorithms/sort/merge_sort/bottom_up/sort.hpp"
#include "sedgealgos/algorithms/sort/merge_sort/top_down/sort.hpp"
#include "sedgealgos/algorithms/sort/sort_analysis/generate_array.hpp"
#include "sedgealgos/data_structures/string/string.hpp"
#include "sedgealgos/io/std_out.hpp"

sedgealgos::data_structures::string::String run(auto alg, auto distribution, auto n) {
    auto arr{sedgealgos::algorithms::sort::sort_analysis::generate_array<int>(n, distribution)};

    return "";
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