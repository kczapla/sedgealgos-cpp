#include "sedgealgos/point2d.hpp"

#include <cmath>
#include <tuple>
#include <limits>

#include <gtest/gtest.h>

namespace {
    using namespace sedgealgos;

    constexpr auto PI{3.141592};
    constexpr auto SQUARE_ROOT_2{1.414213};

    TEST(Point2d, test_if_x_coord_is_the_same_as_in_ctor) {
        Point2d point2d{3, 4};
        EXPECT_EQ(point2d.x(), 3);
    }

    TEST(Point2d, test_if_y_coord_is_the_same_as_in_ctor) {
        Point2d point2d{3, 4};
        EXPECT_EQ(point2d.y(), 4);
    }

    TEST(Point2d, test_if_radius_is_equal_to_hypotenuse_of_x_and_y) {
        Point2d point2d{3, 4};
        EXPECT_EQ(point2d.radius(), 5);
    }

    TEST(Point2d, test_if_y_is_zero_then_theta_is_zero_radians) {
        Point2d point2d{1, 0};
        EXPECT_DOUBLE_EQ(point2d.theta(), 0);
    }

    TEST(Point2d, test_if_cords_are_right_angled_isosceles_triangle_then_return_quarter_pi) {
        Point2d point2d{2, 2};
        EXPECT_NEAR(point2d.theta(), PI/4, 0.0000002);
    }

    TEST(Point2d, test_if_x_is_zero_then_theta_returns_half_pi) {
        Point2d point2d{0, 1};
        EXPECT_NEAR(point2d.theta(), PI/2, 0.000001);
    }

    TEST(Point2d, test_if_theta_is_one_third_of_pi) {
        Point2d point2d{0.5, std::sqrt(3)/2};
        EXPECT_NEAR(point2d.theta(), PI/3, 0.000001);
    }
    
    TEST(Point2d, test_if_theta_is_one_sixth_of_pi) {
        Point2d point2d{0.5, std::sqrt(3)/6};
        EXPECT_NEAR(point2d.theta(), PI/6, 0.000001);
    }

    class Point2dDistanceToTest : public ::testing::TestWithParam<std::tuple<Point2d, Point2d, double>> {
    };

    TEST_P(Point2dDistanceToTest, does_match_expected) {
        auto const from_point2d{std::get<0>(GetParam())};
        auto const to_point2d{std::get<1>(GetParam())};
        auto const expected_distance{std::get<2>(GetParam())};

        auto const distance{from_point2d.distance_to(to_point2d)};
        EXPECT_NEAR(distance, expected_distance, 0.000001);
    }

    INSTANTIATE_TEST_CASE_P(
            Point2dDistanceToTest,
            Point2dDistanceToTest, 
            ::testing::Values(
                std::make_tuple(Point2d{2.5, 1}, Point2d{2.5, 2}, 1),
                std::make_tuple(Point2d{1, 1}, Point2d{2, 2}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{1, 2}, Point2d{2, 1}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{1, 2.5}, Point2d{2, 2.5}, 1),
                std::make_tuple(Point2d{-0.5, 1}, Point2d{0.5, 2}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-0.5, 2}, Point2d{0.5, 1}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-0.5, 2.5}, Point2d{0.5, 2.5}, 1),
                std::make_tuple(Point2d{-2, 1}, Point2d{-1, 2}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-2, 2}, Point2d{-1, 1}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-2, 2.5}, Point2d{-1, 2.5}, 1),
                std::make_tuple(Point2d{-2.5, 1}, Point2d{-2.5, 2}, 1),
                std::make_tuple(Point2d{-2, -0.5}, Point2d{-1, 0.5}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-2, 0.5}, Point2d{-1, -0.5}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-2.5, -0.5}, Point2d{-2.5, 0.5}, 1),
                std::make_tuple(Point2d{-2, -2}, Point2d{-1, -1}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-2, -1}, Point2d{-1, -2}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-2.5, -1}, Point2d{-2.5, -2}, 1),
                std::make_tuple(Point2d{-2, -2.5}, Point2d{-1, -2.5}, 1),
                std::make_tuple(Point2d{-0.5, -2}, Point2d{0.5, -1}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-0.5, -1}, Point2d{0.5, -2}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-0.5, -2.5}, Point2d{0.5, -2.5}, 1),
                std::make_tuple(Point2d{1, -2}, Point2d{2, -1}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{1, -1}, Point2d{2, -2}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{1, -2.5}, Point2d{2, -2.5}, 1),
                std::make_tuple(Point2d{2.5, -2}, Point2d{2.5, -1}, 1),
                std::make_tuple(Point2d{1, -0.5}, Point2d{2, 0.5}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{1, 0.5}, Point2d{2, -0.5}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{2.5, -0.5}, Point2d{2.5, 0.5}, 1),
                std::make_tuple(Point2d{-0.5, -0.5}, Point2d{0.5, 0.5}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-0.5, 0.5}, Point2d{0.5, -0.5}, SQUARE_ROOT_2),
                std::make_tuple(Point2d{-0.5, 0}, Point2d{0.5, 0}, 1),
                std::make_tuple(Point2d{0, -0.5}, Point2d{0, 0.5}, 1)
                )); 

}
