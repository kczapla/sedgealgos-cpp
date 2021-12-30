#include "sedgealgos/interval1d.hpp"
#include "sedgealgos/interval1d_factory.hpp"

#include <vector>
#include <iostream>

int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "please provide number of intervals" << std::endl;
        return 1;
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


    double x{}, y{};
    std::vector<sedgealgos::Interval1d> intervals1d;
    for (int i = 0; i < number_of_points; i++) {
        std::cout << "Interval1d no. " << i + 1 << " - ";
        std::cout << "add low interval end: ";
        std::cin >> x;
        std::cout << "Interval1d no. " << i + 1 << " - ";
        std::cout << "add high interval end: ";
        std::cin >> y;
        intervals1d.push_back(sedgealgos::make_interval1d(x, y));
    }

    for (std::size_t i{0}; i < intervals1d.size() - 1; i++) {
        for (std::size_t j{i + 1}; j < intervals1d.size(); j++) {
            if (!intervals1d[i].intersects(intervals1d[j])) {
                continue;
            }
            std::cout << intervals1d[i].string() << " intersects with " << intervals1d[j].string() << std::endl;
        }
    }

    return 0;
}
