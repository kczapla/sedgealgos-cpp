#include "sedgealgos/analysis/accumulator.hpp"

#include <numeric>

namespace sedgealgos::analysis {

void Accumulator::add_data_value(double value) {
    elements.push_back(value);
}

double Accumulator::mean() const {
  if (elements.empty()) {
      return 0;
  }
  return std::accumulate(elements.cbegin(), elements.cend(), 0.0) / elements.size();
}
}
