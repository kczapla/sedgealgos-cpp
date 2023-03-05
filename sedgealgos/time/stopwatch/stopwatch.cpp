#include "sedgealgos/time/stopwatch/stopwatch.hpp"

#include <chrono>

namespace sedgealgos::time::stopwatch {
    sedgealgos::time::stopwatch::Stopwatch::Stopwatch()
        : start{std::chrono::system_clock::now()} {}
    
    int sedgealgos::time::stopwatch::Stopwatch::elapsed() const {
        auto const stop{std::chrono::system_clock::now()};
        auto const duration{stop - start};
        return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    }
}

