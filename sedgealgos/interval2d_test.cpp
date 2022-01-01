#include "sedgealgos/point2d.hpp"
#include "sedgealgos/interval2d.hpp"
#include "sedgealgos/interval1d_factory.hpp"

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
        EXPECT_TRUE(interval2d.contains(Point2d{2, 4}));
    }

    TEST_P(Interval2dContainsTest, DoesNotContain2dPoint) {
        EXPECT_FALSE(interval2d.contains(Point2d{6.001, 5.001}));
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
}
