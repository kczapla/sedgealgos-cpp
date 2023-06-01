#pragma once

#include "sedgealgos/data_structures/array/array.hpp"
#include "sedgealgos/data_structures/string/string.hpp"
#include "sedgealgos/random/std_random.hpp"


namespace sedgealgos::algorithms::sort::sort_analysis {

template <typename T>
using Array = data_structures::array::Array<T>;

template <typename T>
Array<T> generate_array(int n, data_structures::string::String const& distribution) {
    Array<T> ia;
    std::random_device rd;
    std::mt19937 gen{rd()};

    if (distribution == "gauss") {
        std::normal_distribution<> d{5, 2};
        for (auto i{0}; i < n; i++) {
            ia.push_back(std::round(d(gen)));
        }
    } else if (distribution == "poisson") {
        std::poisson_distribution<> d{4};
        for (auto i{0}; i < n; i++) {
            ia.push_back(std::round(d(gen)));
        }
    } else if (distribution == "geometric") {
        std::geometric_distribution<> d;
        for (auto i{0}; i < n; i++) {
            ia.push_back(std::round(d(gen)));
        }
    } else if (distribution == "discrete") {
        std::discrete_distribution<> d({40, 10, 10, 40});
        for (auto i{0}; i < n; i++) {
            ia.push_back(std::round(d(gen)));
        }
    } else if (distribution == "uniform") {
        std::uniform_int_distribution<> d{n};
        for (auto i{0}; i < n; i++) {
            ia.push_back(d(gen));
        }
    } else if (distribution == "first-half-ones") {
        auto i{0};
        for (; i < n/2; i++) {
            ia.push_back(1);
        }
        for (; i < n; i++) {
            ia.push_back(0);
        }
    } else if (distribution == "second-half-ones") {
        auto i{0};
        for (; i < n/2; i++) {
            ia.push_back(0);
        }
        for (; i < n; i++) {
            ia.push_back(1);
        }
    } else if (distribution == "halves") {
        auto val{0};

        auto left{n/2};
        auto start{0};
        auto end{start + left};
        while (left != 0) {
            for (; start < end; start++) {
                ia.push_back(val);
            }
            start = end;
            left /= 2;
            end = start + left;
            val++;
        }
        ia.push_back(val);
    } else if (distribution == "half-zero-half-random") {
        auto i{0};
        for (; i < n/2; i++) {
            ia.push_back(0);
        }
        std::uniform_int_distribution<> d{n};

        for (; i < n; i++) {
            ia.push_back(d(gen));
        }
    } else if (distribution == "95-sorted-5-random") {
        std::uniform_int_distribution<> d{n};

        auto i{0};
        for (i = 0; i < 0.95*n; i++) {
            ia.push_back(i);
        }

        for (; i < n; i++) {
            ia.push_back(d(gen));
        }
    } else if (distribution == "scatter-to-10") {
        for (auto i{0}; i < n; i++) {
            std::uniform_int_distribution<> d{i - 10, i + 10};
            auto random_value{d(gen)};
            ia.push_back(random_value);
        }
        for (auto i{0}; i < n; i++) {
            std::cout << ia[i] << ", ";
        }
    } else if (distribution == "95-sorted-5-scattered") {
        for (auto i{0}; i < n; i++) {
            ia.push_back(i);
        }

        std::uniform_int_distribution<> d{0, n-1};
        for (auto i{0}; i < 0.025 * n; i++) {
            auto random_index1{d(gen)};
            auto random_index2{d(gen)};
            auto tmp{ia[random_index1]};
            ia[random_index1] = ia[random_index2];
            ia[random_index2] = tmp;
        }
    } else if (distribution == "sorted") {
        for (auto i{0}; i < n; i++) {
            ia.push_back(i);
        }
    }

    return ia;
}
}