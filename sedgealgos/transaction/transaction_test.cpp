#include "sedgealgos/date/smart_date.hpp"
#include "sedgealgos/transaction/transaction.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::date;
using namespace sedgealgos::transaction;

TEST(TransactionTest, CreatesTransaction) {
    Transaction t{"adam", SmartDate{1, 21, 2022}, 1};
}

TEST(TransactionTest, GetStransactionAuthor) {
    Transaction t{"adam", SmartDate{1, 21, 2022}, 1};

    EXPECT_EQ(t.who(), "adam");
}

TEST(TransactionTest, GetTransactionDate) {
    SmartDate const date{1, 21, 2022};
    Transaction t{"adam", date, 1};

    EXPECT_EQ(t.when().to_string(), "1/21/2022");
}
}
