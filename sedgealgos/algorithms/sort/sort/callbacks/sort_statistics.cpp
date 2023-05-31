#include "sedgealgos/algorithms/sort/sort/callbacks/sort_statistics.hpp"

#include <sstream>

namespace sedgealgos::algorithms::sort::sort::callbacks {

void SortStatistics::on_compare() {
    compares_count++;
}

void SortStatistics::on_swap() {
    swap_count++;
}

void SortStatistics::on_sort_start() {
    stopwatch = time::stopwatch::Stopwatch{};
}

void SortStatistics::on_sort_stop() {
    sort_duration = stopwatch.elapsed();
}

data_structures::string::String SortStatistics::to_json() const {
    std::stringstream ss;
    ss << R"({"compares": ")" << compares_count
       << R"(", "swaps": ")" << swap_count
       << R"(", "duration": ")" << sort_duration
       << R"("})";

    return ss.str();
}
}