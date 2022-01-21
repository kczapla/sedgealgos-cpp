#pragma once

#include "sedgealgos/date/smart_date.hpp"

#include <string>

namespace sedgealgos::transaction {
class Transaction {
public:
  Transaction(std::string, date::SmartDate, double);
private:
  std::string who;
  date::SmartDate date{1, 1, 2001};
  double amount{0};
};
}
