#pragma once

#include <chrono>

namespace sedgealgos::time::stopwatch {
class Stopwatch {
public:
    Stopwatch();

    int elapsed() const;

private:
    std::chrono::time_point<std::chrono::system_clock> start;
};
}

