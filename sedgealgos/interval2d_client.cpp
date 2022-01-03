#include "sedgealgos/interval2d.hpp"
#include "sedgealgos/interval2d_factory.hpp"
#include "sedgealgos/random/std_random.hpp"

#include <vector>
#include <iostream>

using namespace sedgealgos;
using namespace sedgealgos::random;
using namespace sedgealgos::geometry;


int main(int argc, char** argv) {
    if (argc <= 3) {
        std::cerr << "please provide N, min and max" << std::endl;
        return 1;
    }

    auto n{0};
    auto min{0};
    auto max{0};
    try {
        n = std::stoi(argv[1]);
        min = std::stoi(argv[2]);
        max = std::stoi(argv[3]);
    } catch (std::invalid_argument const&) {
        std::cerr << "input argument is not a digit" << std::endl;
        return 1;
    } catch (std::out_of_range const&) {
        std::cerr << "can not convert input number" << std::endl;
        return 1;
    }


    std::vector<Interval2d> interval2ds;
    for (int i{0}; i < n; ++i) {
        auto random_number1{StdRandom::uniform(min, max)};
        auto random_number2{StdRandom::uniform(min, max)};
        auto lo{random_number1 < random_number2 ? random_number1 : random_number2};
        auto hi{random_number1 > random_number2 ? random_number1 : random_number2};
        interval2ds.push_back(make_interval2d(lo, hi, lo, hi));
    }

    for (std::size_t i{0}; i < interval2ds.size() - 1; ++i) {
        for (std::size_t j{0}; j < interval2ds.size(); ++j) {
            if (!interval2ds[i].intersects(interval2ds[j])) {
                continue;
            }
            std::cout << interval2ds[i].string() << " intersects with " << interval2ds[j].string() << std::endl;
        }
    }

    return 0;
}
