#include "sedgealgos/date/smart_date.hpp"
#include "sedgealgos/transaction/transaction.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::date;
using namespace sedgealgos::transaction;

TEST(TransactionTest, CreatesTransaction) {
    Transaction t{"adam", SmartDate{1, 21, 2022}, 1};
}
}
