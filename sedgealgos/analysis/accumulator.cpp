#include "sedgealgos/analysis/accumulator.hpp"

#include <cmath>
#include <numeric>

namespace sedgealgos::analysis {

void Accumulator::add_data_value(double value) {
    elements.push_back(value);
}


double Accumulator::var() const {
    if (elements.empty()) {
      return 0;
    }
    auto const m{mean()};
    auto const ss{std::accumulate(elements.cbegin(), elements.cend(), 0.0, [m](auto const a, auto const b) {return a + (b - m)*(b-m);})};
    return ss / elements.size();
}

double Accumulator::stddev() const {
    return std::sqrt(var());
}

double Accumulator::mean() const {
  if (elements.empty()) {
      return 0;
  }
  return std::accumulate(elements.cbegin(), elements.cend(), 0.0) / elements.size();
}
}
