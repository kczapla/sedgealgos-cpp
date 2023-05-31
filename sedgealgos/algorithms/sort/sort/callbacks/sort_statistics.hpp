#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"
#include "sedgealgos/data_structures/string/string.hpp"
#include "sedgealgos/time/stopwatch/stopwatch.hpp"

namespace sedgealgos::algorithms::sort::sort::callbacks {

class SortStatistics : public Callbacks {
public:
    void on_compare() override;
    void on_swap() override;
    void on_sort_start() override;
    void on_sort_stop() override;

    data_structures::string::String to_json() const;

private:
    int compares_count{0};
    int swap_count{0};
    int sort_duration{};

    time::stopwatch::Stopwatch stopwatch;
};

}