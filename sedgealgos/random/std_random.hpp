#pragma once

#include <random>

namespace sedgealgos::random {
    class StdRandom {
    public:
        static int uniform(int);
        static int uniform(int, int);

        static double uniform();
        static double uniform(double);
        static double uniform(double, double);

    private:
        inline static std::random_device random_device{};
        inline static std::mt19937 generator{random_device()};
    };
}
