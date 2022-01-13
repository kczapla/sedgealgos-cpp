#include "sedgealgos/date/smart_date.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::date;

TEST(SmartDate, ReturnsDay) {
    SmartDate date{1, 13, 2022};
    EXPECT_EQ(date.day(), 13);
}
}
