#include "sedgealgos/interval1d.hpp"

#include <tuple>

#include <gtest/gtest.h>

namespace {
    using namespace sedgealgos;

    class Interval1dLengthTest : public ::testing::TestWithParam<std::tuple<Interval1d, double>> {
    };

    TEST_P(Interval1dLengthTest, ReturnsExpectedLength) {
        auto const interval1d{std::get<0>(GetParam())}; 
        auto const expected_length{std::get<1>(GetParam())};

        auto const length{interval1d.length()};

        EXPECT_NEAR(length, expected_length, 0.000001);
    }

    INSTANTIATE_TEST_CASE_P(
            Interval1dLengthTest,
            Interval1dLengthTest,
            ::testing::Values(
                std::make_tuple(Interval1d{}, 0),
                std::make_tuple(Interval1d{2, 3}, 1),
                std::make_tuple(Interval1d{-2, 3}, 5),
                std::make_tuple(Interval1d{-2, -3}, 1),
                std::make_tuple(Interval1d{2, -3}, 5)
                )
            );

    TEST(Interval1dContains, PointInTheMiddleOfInterval) {
        Interval1d const interval{0, 3};
        ASSERT_TRUE(interval.contains(2));
    }

    TEST(Interval1dContains, PointAtTheIntervalLeftEdge) {
        Interval1d const interval{0, 3};
        ASSERT_TRUE(interval.contains(0));
    }

    TEST(Interval1dContains, PointAtTheIntervalRightEdge) {
        Interval1d const interval{0, 3};
        ASSERT_TRUE(interval.contains(3));
    }

    TEST(Interval1DoesNotContain, PointBeforeTheIntervalsLeftEdge) {
        Interval1d const interval{0, 3};
        ASSERT_FALSE(interval.contains(-1));
    }

    TEST(Interval1DoesNotContain, PointAfterTheIntervalsRightEdge) {
        Interval1d const interval{0, 3};
        ASSERT_FALSE(interval.contains(4));
    }
}
