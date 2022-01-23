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
double Transaction::amount() const {
    return amount_;
}

  bool Transaction::equals(Transaction const& other) const {
    if (this == &other) {
      return true;
    }

    auto transactions_are_the_same{true};
    transactions_are_the_same &= who() == other.who();
    transactions_are_the_same &= when().equals(other.when());
    transactions_are_the_same &= amount() == other.amount();
    return transactions_are_the_same;
  }
}
