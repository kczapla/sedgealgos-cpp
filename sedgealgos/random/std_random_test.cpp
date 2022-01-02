#include "sedgealgos/random/std_random.hpp"

#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace {
    using namespace sedgealgos::random;
    using namespace ::testing;

    template <typename T>
    std::vector<T> generate_random_numbers_from_zero_to(T n) {
        std::vector<int> range(100);
        std::vector<T> random_numbers{};
        std::transform(
                std::begin(range),
                std::end(range),
                std::back_inserter(random_numbers), 
                [n](auto){return StdRandom::uniform(n);});

        return random_numbers;
    }

    std::vector<double> generate_random_numbers_from_zero_to_one() {
        std::vector<int> range(100);
        std::vector<double> random_numbers{};
        std::transform(
                std::begin(range),
                std::end(range),
                std::back_inserter(random_numbers), 
                [](auto){return StdRandom::uniform();});
        return random_numbers;
    }

    TEST(StdRandomUniformTest, ReturnsIntValueForIntInput) {
        EXPECT_THAT(StdRandom::uniform(0), TypedEq<int>(0));
    }

    TEST(StdRandomUniformTest, ReturnsDoubleValueForDoubleInput) {
        EXPECT_THAT(StdRandom::uniform(0.0), TypedEq<double>(0.0));
    }

    TEST(StdRandomUniformTest, ReturnsUniformlyDistributedIntValuesFrom0ToN) {
        auto const random_numbers{
            generate_random_numbers_from_zero_to(5)
        };
        EXPECT_THAT(random_numbers, Each(AllOf(Ge(0), Le(5))));
    } 

    TEST(StdRandomUniformTest, ReturnsUniformlyDistributedDoubleValuesFrom0ToN) {
        auto const random_numbers{
            generate_random_numbers_from_zero_to(5.0)
        };
        EXPECT_THAT(random_numbers, Each(AllOf(Ge(0.0), Le(5.0))));
    }

    TEST(StdRandomUniformTest, ReturnsUniformlyDistributedDoubleValuesFrom0To1) {

        auto const random_numbers{
            generate_random_numbers_from_zero_to_one()
        };
        EXPECT_THAT(random_numbers, Each(AllOf(Ge(0.0), Le(1.0))));
    }

    TEST(StdRandomUniformTest, ThrowsIfIntMIsGreaterThanIntN) {
        EXPECT_THROW(
                { [[maybe_unused]] auto r{StdRandom::uniform(2, 1)};},
                std::invalid_argument
        );
    }
    
    TEST(StdRandomUniformTest, ThrowsIfDoubleMIsGreaterThanIntN) {
        EXPECT_THROW(
                { [[maybe_unused]] auto r{StdRandom::uniform(2.0, 1.0)};},
                std::invalid_argument
        );
    }
}
