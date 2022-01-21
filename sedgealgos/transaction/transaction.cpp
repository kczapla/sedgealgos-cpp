#include "sedgealgos/transaction/transaction.hpp"
#include "sedgealgos/date/smart_date.hpp"

#include <string>

namespace sedgealgos::transaction {
Transaction::Transaction(std::string n, date::SmartDate d, double a) : who_{n}, date_{std::move(d)}, amount_{a} {}

std::string Transaction::who() const {
    return who_;
}

date::SmartDate Transaction::when() const {
    return date_;
}
}
