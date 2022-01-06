#include "sedgealgos/geometry/point2d.hpp"
#include "sedgealgos/geometry/interval1d_factory.hpp"
#include "sedgealgos/interval2d.hpp"
#include "sedgealgos/interval2d_factory.hpp"

#include <gtest/gtest.h>

namespace {
    using namespace sedgealgos;

    TEST(Interval2dArea, ReturnsInterval2dsArea) {
        Interval2d interval2d{make_interval1d(2, 4), make_interval1d(2, 4)};
        EXPECT_EQ(interval2d.area(), 4);
    }

    class Interval2dContainsTest : public ::testing::TestWithParam<Interval2d> {
    protected:
        void SetUp() override {
            interval2d = GetParam();
        }

        Interval2d interval2d{};
    };

    TEST_P(Interval2dContainsTest, Contains2dPoint) {
        EXPECT_TRUE(interval2d.contains(geometry::Point2d{2, 4}));
    }

    TEST_P(Interval2dContainsTest, DoesNotContain2dPoint) {
        EXPECT_FALSE(interval2d.contains(geometry::Point2d{6.001, 5.001}));
    }

    INSTANTIATE_TEST_CASE_P(
        Interval2dContainsTest,
        Interval2dContainsTest,
        ::testing::Values(
            Interval2d{make_interval1d(1, 6), make_interval1d(1, 5)},
            Interval2d{make_interval1d(2, 6), make_interval1d(1, 5)},
            Interval2d{make_interval1d(1, 2), make_interval1d(1, 5)},
            Interval2d{make_interval1d(1, 3), make_interval1d(4, 5)},
            Interval2d{make_interval1d(1, 3), make_interval1d(3, 4)},
            Interval2d{make_interval1d(2, 3), make_interval1d(4, 5)},
            Interval2d{make_interval1d(2, 3), make_interval1d(2, 4)},
            Interval2d{make_interval1d(1, 2), make_interval1d(4, 5)},
            Interval2d{make_interval1d(1, 2), make_interval1d(2, 4)}
        )
    );

    class Interval2dIntersectsTest : public ::testing::TestWithParam<Interval2d> {
    protected:
        void SetUp() override {
            interval2d = GetParam();
        }

        Interval2d interval2d{};
    };

    TEST_P(Interval2dIntersectsTest, IntersectsWithInterval2d) {
        EXPECT_TRUE(interval2d.intersects(make_interval2d(2, 6, 2, 6)));
    }

    TEST_P(Interval2dIntersectsTest, DoesNotIntersectWithInterval2d) {
        EXPECT_FALSE(interval2d.intersects(make_interval2d(-1, -1, -1, -1)));
    }

    INSTANTIATE_TEST_CASE_P(
        Interval2dIntersectsTest,
        Interval2dIntersectsTest,
        ::testing::Values(
            make_interval2d(4, 5, 4, 5),
            make_interval2d(4, 5, 1, 4),
            make_interval2d(4, 5, 5, 7),
            make_interval2d(1, 3, 4, 5),
            make_interval2d(5, 7, 4, 5),
            make_interval2d(1, 3, 5, 7),
            make_interval2d(1, 3, 1, 3),
            make_interval2d(5, 7, 5, 7),
            make_interval2d(5, 7, 1, 3),
            make_interval2d(3, 4, 1, 7),
            make_interval2d(5, 7, 3, 4),
            make_interval2d(1, 7, 1, 7),
            make_interval2d(1, 2, 4, 5)
        )
    );

    TEST(Interval2dStringTest, ReturnsStringRepresentation) {
        auto interval2d{make_interval2d(1, 2, 1, 2)};

        auto const expected_string{"Interval2d(x=Interval1d(lo=1, hi=2), y=Interval1d(lo=1, hi=2))"};
        EXPECT_EQ(interval2d.string(), expected_string);
    }
}
