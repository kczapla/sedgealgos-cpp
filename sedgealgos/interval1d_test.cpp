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

    class Interval1dIntersectsTest : public ::testing::TestWithParam<Interval1d> {
        protected:
        void SetUp() override {
            lhs_interval = GetParam();
        }

        Interval1d lhs_interval{};
    };

    TEST_P(Interval1dIntersectsTest, ReturnsTrueWhenIntersects) {
        ASSERT_TRUE(lhs_interval.intersects({-3, 3}));
    }

    TEST_P(Interval1dIntersectsTest, ReturnsFalseWhenDoesNotIntersects) {
        ASSERT_FALSE(lhs_interval.intersects({-6, -5.01}));
        ASSERT_FALSE(lhs_interval.intersects({5.001, 6}));
    }

    INSTANTIATE_TEST_CASE_P(
            Interval1dIntersects,
            Interval1dIntersectsTest,
            ::testing::Values(
                Interval1d{2, 3},
                Interval1d{0, 1},
                Interval1d{1.5, 3},
                Interval1d{-5, 5},
                Interval1d{3, 5},
                Interval1d{-5.009, -3},
                Interval1d{-1.5, 2.5}
                )
            );
}
