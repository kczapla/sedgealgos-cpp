#include "sedgealgos/transaction/transaction.hpp"
#include "sedgealgos/date/smart_date.hpp"

#include <string>

namespace sedgealgos::transaction {
Transaction::Transaction(std::string n, date::SmartDate d, double a) : who{n}, date{std::move(d)}, amount{a} {}
}
