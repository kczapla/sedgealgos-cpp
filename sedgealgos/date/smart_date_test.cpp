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

TEST(SmartDate, ReturnsStringRepresentationOfDate) {
    SmartDate date{1, 15, 2022};
    EXPECT_EQ(date.to_string(), "1/15/2022");
}

TEST(SmartDateTest, ReturnsDayOfTheWeek) {
    EXPECT_EQ(SmartDate(2, 14, 1992).day_of_the_week(), "Friday");
    EXPECT_EQ(SmartDate(5, 16, 1992).day_of_the_week(), "Saturday");
    EXPECT_EQ(SmartDate(6, 7, 1992).day_of_the_week(), "Sunday");
    EXPECT_EQ(SmartDate(6, 15, 1992).day_of_the_week(), "Monday");
    EXPECT_EQ(SmartDate(6, 16, 1992).day_of_the_week(), "Tuesday");
    EXPECT_EQ(SmartDate(6, 17, 1992).day_of_the_week(), "Wednesday");
    EXPECT_EQ(SmartDate(6, 18, 1992).day_of_the_week(), "Thursday");
    EXPECT_EQ(SmartDate(6, 19, 1992).day_of_the_week(), "Friday");
    EXPECT_EQ(SmartDate(6, 20, 1992).day_of_the_week(), "Saturday");
    EXPECT_EQ(SmartDate(6, 21, 1992).day_of_the_week(), "Sunday");
    EXPECT_EQ(SmartDate(6, 22, 1992).day_of_the_week(), "Monday");
    EXPECT_EQ(SmartDate(7, 21, 1992).day_of_the_week(), "Tuesday");
    EXPECT_EQ(SmartDate(10, 21, 1992).day_of_the_week(), "Wednesday");
    EXPECT_EQ(SmartDate(10, 21, 1993).day_of_the_week(), "Thursday");
    EXPECT_EQ(SmartDate(4, 18, 1997).day_of_the_week(), "Friday");
    EXPECT_EQ(SmartDate(12, 1, 2001).day_of_the_week(), "Saturday");
    EXPECT_EQ(SmartDate(1, 16, 2022).day_of_the_week(), "Sunday");
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
        std::make_tuple(2, 29, 800),
        std::make_tuple(2, 28, 801),
        std::make_tuple(1, 31, 2000),
        std::make_tuple(1, 1, 2000),
        std::make_tuple(4, 30, 2000),
        std::make_tuple(8, 31, 2000)
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
        std::make_tuple(2, 30, 2000),
        std::make_tuple(4, 31, 2000),
        std::make_tuple(5, 32, 2000),
        std::make_tuple(1, 0, 2000),
        std::make_tuple(0, 1, 2000)
    )
);
}
