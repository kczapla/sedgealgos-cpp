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

TEST(TransactionTest, GetTransactionAmount) {
    SmartDate const date{1, 21, 2022};
    Transaction t{"adam", date, 1};

    EXPECT_EQ(t.amount(), 1);
}

TEST(TransactionTest, EqualsToTheSameTransactionObject) {
    SmartDate const date{1, 21, 2022};
    Transaction t{"adam", date, 1};
    EXPECT_TRUE(t.equals(t));
}

TEST(TransactionTest, EqualsToTheSameTransaction) {
    SmartDate const date{1, 21, 2022};
    Transaction t1{"adam", date, 1};
    Transaction t2{t1};

    EXPECT_TRUE(t1.equals(t2));
}

TEST(TransactionTest, DoesNotEqualToOtherTransaction) {
    Transaction const t1{"adam", SmartDate{1, 21, 2022}, 1};
    Transaction const t2{"adam", SmartDate{4, 21, 2022}, 1};

    EXPECT_FALSE(t1.equals(t2));
}
}
