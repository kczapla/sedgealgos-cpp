#include "sedgealgos/algorithms/three_sum/three_sum.hpp"

#include <limits>

namespace {
[[maybe_unused]] bool will_sum_overflow(int a, int b) {
  auto max{std::numeric_limits<int>::max()};
  auto sum_exceeds_higher_limit{[max](auto a, auto b) {return a > max - b; }};

  auto min{std::numeric_limits<int>::min()};
  auto sum_exceeds_lower_limit{[min](auto a, auto b) {return a < min - b; }};

  if (sum_exceeds_higher_limit(a, b)) {
      return true;
  }
  if (sum_exceeds_higher_limit(b, a)) {
      return true;
  }
  if (sum_exceeds_lower_limit(a, b)) {
      return true;
  }
  if (sum_exceeds_lower_limit(b, a)) {
      return true;
  }

  return false;
}
}

namespace sedgealgos::algorithms::three_sum {
    int ThreeSum::count(ConstArrayRef a) {
        auto count{0};
        for (std::size_t i = 0; i < a.size(); i++) {
            for (std::size_t j = i + 1; j < a.size(); j++) {
                for (std::size_t k = j + 1; k < a.size(); k++) {
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
