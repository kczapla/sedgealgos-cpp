#include "sedgealgos/point2d.hpp"

#include <gtest/gtest.h>

namespace {
    TEST(Point2d, test_if_x_coord_is_the_same_as_in_ctor) {
        sedgealgos::Point2d point2d{3, 4};
        EXPECT_EQ(point2d.x(), 3);
    }

    TEST(Point2d, test_if_y_coord_is_the_same_as_in_ctor) {
        sedgealgos::Point2d point2d{3, 4};
        EXPECT_EQ(point2d.y(), 4);
    }

    TEST(Point2d, test_if_radius_is_equal_hypotenuse_of_x_and_y) {
        sedgealgos::Point2d point2d{3, 4};
        EXPECT_EQ(point2d.radius(), 5);
    }

    TEST(Point2d, test_if_radius_is_theta_is_equal_ctg_x_y) {

    }
}
