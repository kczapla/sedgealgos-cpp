#include "sedgealgos/date/smart_date.hpp"
#include "sedgealgos/date/date_exception.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <tuple>

namespace {
using namespace sedgealgos::date;

TEST(SmartDate, ReturnsDay) {
    SmartDate date{1, 13, 2022};
    EXPECT_EQ(date.day(), 13);
    EXPECT_EQ(date.month(), 1);
    EXPECT_EQ(date.year(), 2022);
}

class SmartDateWithValidInputTest : public ::testing::TestWithParam<std::tuple<int, int, int>> {
};

TEST_P(SmartDateWithValidInputTest, DoesNotThrowExceptionOnValidData) {
    EXPECT_NO_THROW({std::make_from_tuple<SmartDate>(GetParam());});
}

INSTANTIATE_TEST_CASE_P(
    SmartDateTest,
    SmartDateWithValidInputTest,
    ::testing::Values(
        std::make_tuple(2, 29, 2000),
        std::make_tuple(2, 29, 2004),
        std::make_tuple(2, 29, 800)
    )
);

class SmartDateWithInvalidInputTest : public ::testing::TestWithParam<std::tuple<int, int, int>> {
};

TEST_P(SmartDateWithInvalidInputTest, ThrowsExceptionOnInvalidDate) {
    EXPECT_THROW(
        {std::make_from_tuple<SmartDate>(GetParam());}, DateException
    );
}

INSTANTIATE_TEST_CASE_P(
    SmartDateTest,
    SmartDateWithInvalidInputTest,
    ::testing::Values(
        std::make_tuple(2, 29, 2001),
        std::make_tuple(2, 29, 700),
        std::make_tuple(2, 29, 1900),
        std::make_tuple(2, 29, 2001),
        std::make_tuple(2, 30, 2001),
        std::make_tuple(2, 30, 2000)
    )
);
}
