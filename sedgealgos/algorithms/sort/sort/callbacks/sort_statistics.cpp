#include "sedgealgos/algorithms/sort/sort/callbacks/sort_statistics.hpp"

#include <sstream>

namespace sedgealgos::algorithms::sort::sort::callbacks {

void SortStatistics::on_compare() {
    compares_count++;
}

void SortStatistics::on_swap() {
    swap_count++;
}

data_structures::string::String SortStatistics::to_json() const {
    std::stringstream ss;
    ss << R"({"compares": ")" << compares_count << R"(", "swaps": ")" << swap_count << R"("})";

    return ss.str();
}
}