#include "sedgealgos/algorithms/three_sum/three_sum_faster/three_sum_faster.hpp"

#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/random/std_random.hpp"
#include "sedgealgos/time/stopwatch/stopwatch.hpp"

#include <algorithm>
#include <vector>

int timeTrail(int n) {
    auto const max{1000000};

    std::vector<int> array;
    sedgealgos::time::stopwatch::Stopwatch array_generation;
    for (auto i{0}; i < n; i++) {
        array.emplace_back(sedgealgos::random::StdRandom::uniform(-max, max));
    }

    std::sort(array.begin(), array.end());

    sedgealgos::time::stopwatch::Stopwatch counting;
    sedgealgos::algorithms::three_sum::three_sum_faster::ThreeSumFaster::count(array);
    return counting.elapsed();
}

int main() {
    sedgealgos::io::StdOut std_out;
    for (auto n{250}; true; n += n) {
        auto const time{timeTrail(n)};
        std_out.printf("%d\t%d\n", n, time);
    }
}
