#pragma once

#include <vector>

namespace sedgealgos::analysis {
class Accumulator {
public:
  void add_data_value(double);

  double var() const;
  double mean() const;
  double stddev() const;

private:
  std::vector<double> elements;
};
}
