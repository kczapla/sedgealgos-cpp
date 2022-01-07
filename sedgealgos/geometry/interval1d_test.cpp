#include "sedgealgos/geometry/interval1d.hpp"

#include <tuple>

#include <gtest/gtest.h>

namespace {
    using namespace sedgealgos::geometry;

    TEST(Interval1dStringTest, ReturnsStringProperFormat) {
        Interval1d interval1d{1, 3};
        EXPECT_EQ(interval1d.string(), "Interval1d(lo=1, hi=3)");
    }

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
    
    class Interval1dContainsTest : public ::testing::TestWithParam<Interval1d> {
        protected:
        void SetUp() override {
            lhs_interval = GetParam();
        }

        Interval1d lhs_interval{};
    };

    TEST_P(Interval1dContainsTest, ContainsTwoValue) {
        EXPECT_TRUE(lhs_interval.contains(2));
    }

    TEST_P(Interval1dContainsTest, DoesNotContainValueNearTheLeftEdge) {
        EXPECT_FALSE(lhs_interval.contains(-5));
    }

    TEST_P(Interval1dContainsTest, DoesNotContainValueNearTheRightEdge) {
        EXPECT_FALSE(lhs_interval.contains(-5));
    }

    INSTANTIATE_TEST_CASE_P(
        Interval1dContainsTest,
        Interval1dContainsTest,
        ::testing::Values(
            Interval1d{2, 3},
            Interval1d{0, 2},
            Interval1d{0, 4}
            )
        );

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
