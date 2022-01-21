#pragma once

#include "sedgealgos/date/smart_date.hpp"

#include <string>

namespace sedgealgos::transaction {
class Transaction {
public:
  Transaction(std::string, date::SmartDate, double);

  std::string who() const;
  date::SmartDate when() const;

private:
  std::string who_;
  date::SmartDate date_{1, 1, 2001};
  double amount_{0};
};
}
