#include "sedgealgos/analysis/counter.hpp"

#include <sstream>
#include <iostream>

namespace sedgealgos::analysis {
    void Counter::increment() {
        ++counter;
    }

    int Counter::tally() const {
        return counter;
    }

    std::string Counter::string() const {
       std::stringstream ss;
       ss << counter;
       ss << " " << id;
       return ss.str();
    } 
}
