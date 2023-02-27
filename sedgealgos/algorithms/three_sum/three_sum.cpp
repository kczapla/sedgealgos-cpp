#include "sedgealgos/algorithms/three_sum/three_sum.hpp"

#include <limits>
#include <iostream>

namespace {
[[maybe_unused]] bool will_sum_overflow(int a, int b) {
  auto max{std::numeric_limits<int>::max()};
  auto sum_exceeds_higher_limit{[max](auto a, auto b) {return a > max - b; }};
  return sum_exceeds_higher_limit(a, b);
}

[[maybe_unused]] bool will_sum_overflow_negatively(int a, int b) {
  auto min{std::numeric_limits<int>::min()};
  return a < min - b;
}
}

namespace sedgealgos::algorithms::three_sum {
    int ThreeSum::count(ConstArrayRef a) {
        auto count{0};
        for (std::size_t i = 0; i < a.size(); i++) {
            for (std::size_t j = i + 1; j < a.size(); j++) {
                for (std::size_t k = j + 1; k < a.size(); k++) {
                    if (a[j] > 0 && will_sum_overflow(a[i], a[j])) {
                        continue;
                    }

                    if (a[i] == std::numeric_limits<int>::min() && a[k] == std::numeric_limits<int>::min()) {
                        continue;
                    }
                    
                    if (a[i] == std::numeric_limits<int>::min() && a[j] == std::numeric_limits<int>::min()) {
                        continue;
                    }

                    if ((std::numeric_limits<int>::min() < std::numeric_limits<int>::min() + a[j]) && (a[i] < std::numeric_limits<int>::min() - a[j])) {
                        continue;
                    }

                    if (a[j] == std::numeric_limits<int>::min() && a[k] == std::numeric_limits<int>::min()) {
                        continue;
                    }

                    auto const sum = a[i] + a[j] + a[k];
                    if (sum == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}
