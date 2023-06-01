#include "sedgealgos/algorithms/sort/sort/callbacks/sort_statistics.hpp"

#include <cmath>
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

void SortStatistics::on_array_access(int no) {
    array_access += no;
}

data_structures::string::String SortStatistics::to_json() const {
    std::stringstream ss;

    auto upper_bound{6 * container_size * std::log2(container_size)};

    ss << R"({"compares": ")" << compares_count
       << R"(", "swaps": ")" << swap_count
       << R"(", "duration": ")" << sort_duration
       << R"(", "array_access": ")" << array_access
       << R"(", "array_access_upper_bound": ")" << upper_bound
       << R"("})";

    return ss.str();
}
}