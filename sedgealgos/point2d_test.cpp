#include "sedgealgos/point2d.hpp"

#include <cmath>
#include <limits>

#include <gtest/gtest.h>

namespace {
    constexpr double PI{3.141592};

    TEST(Point2d, test_if_x_coord_is_the_same_as_in_ctor) {
        sedgealgos::Point2d point2d{3, 4};
        EXPECT_EQ(point2d.x(), 3);
    }

    TEST(Point2d, test_if_y_coord_is_the_same_as_in_ctor) {
        sedgealgos::Point2d point2d{3, 4};
        EXPECT_EQ(point2d.y(), 4);
    }

    TEST(Point2d, test_if_radius_is_equal_to_hypotenuse_of_x_and_y) {
        sedgealgos::Point2d point2d{3, 4};
        EXPECT_EQ(point2d.radius(), 5);
    }

    TEST(Point2d, test_if_y_is_zero_then_theta_is_zero_radians) {
        sedgealgos::Point2d point2d{1, 0};
        EXPECT_DOUBLE_EQ(point2d.theta(), 0);
    }

    TEST(Point2d, test_if_cords_are_right_angled_isosceles_triangle_then_return_quarter_pi) {
        sedgealgos::Point2d point2d{2, 2};
        EXPECT_NEAR(point2d.theta(), PI/4, 0.0000002);
    }

    TEST(Point2d, test_if_x_is_zero_then_theta_returns_half_pi) {
        sedgealgos::Point2d point2d{0, 1};
        EXPECT_NEAR(point2d.theta(), PI/2, 0.000001);
    }

    TEST(Point2d, test_if_theta_is_one_third_of_pi) {
        sedgealgos::Point2d point2d{0.5, std::sqrt(3)/2};
        EXPECT_NEAR(point2d.theta(), PI/3, 0.000001);
    }
    
    TEST(Point2d, test_if_theta_is_one_sixth_of_pi) {
        sedgealgos::Point2d point2d{0.5, std::sqrt(3)/6};
        EXPECT_NEAR(point2d.theta(), PI/6, 0.000001);
    }

}
