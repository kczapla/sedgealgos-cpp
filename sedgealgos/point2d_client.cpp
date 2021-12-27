#include "sedgealgos/point2d.hpp"

#include <limits>
#include <random>
#include <string>
#include <vector>
#include <iostream>


using namespace sedgealgos;

namespace {
auto generate_random_number() {
    std::random_device r;
    std::default_random_engine e1{r()};
    std::uniform_int_distribution<int> uniform_dist{-99, 99};
    
    return uniform_dist(e1);
}

std::vector<Point2d> generate_n_random_2d_points(int n) {
    std::vector<Point2d> points;
    for (auto i{0}; i < n; i++) {
        points.push_back({generate_random_number()/1.0, generate_random_number()/1.0});
    }

    return points;
}
}


int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "please provide number of points" << std::endl;
    }

    auto number_of_points{0};
    try {
        number_of_points = std::stoi(argv[1]);
    } catch (std::invalid_argument const&) {
        std::cerr << "input argument is not a digit" << std::endl;
        return 1;
    } catch (std::out_of_range const&) {
        std::cerr << "can convert input number" << std::endl;
        return 1;
    }

    auto points{::generate_n_random_2d_points(number_of_points)};
    for (auto&& p : points) {
        std::cout << "Point(x=" << p.x() << ", y=" << p.y() << ")" << std::endl;
    }

    auto min_distance{std::numeric_limits<double>::max()};
    Point2d a{0, 0};
    Point2d b{0, 0};

    for (std::size_t i{0}; i < points.size() - 1; i++) {
        for (std::size_t j{i + 1}; j < points.size(); j++) {
            auto current_distance{points[i].distance_to(points[j])};
            if (current_distance < min_distance) {
                min_distance = current_distance;
                a = points[i];
                b = points[j];
            }
        }
    }

    std::cout << "min distance equal is equal to " << min_distance << " between points a(x=" << a.x() << ", y=" << a.y() << ") and ";
    std::cout << "b(x=" << b.x() << ", y=" << b.y() << ")" << std::endl;

    return 0;
}

