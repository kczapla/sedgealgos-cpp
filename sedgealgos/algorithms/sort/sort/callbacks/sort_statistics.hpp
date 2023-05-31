#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"
#include "sedgealgos/data_structures/string/string.hpp"

namespace sedgealgos::algorithms::sort::sort::callbacks {

class SortStatistics : public Callbacks {
public:
    void on_compare() override;
    void on_swap() override;

    data_structures::string::String to_json() const;

private:
    int compares_count{0};
    int swap_count{0};
};

}