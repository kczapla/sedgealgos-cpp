#include "sedgealgos/geometry/interval1d_factory.hpp"

#include <stdexcept>

#include <gtest/gtest.h>

namespace {
    using namespace sedgealgos;

    TEST(MakeInterval1dTest, ReturnsInterval1d) {
        [[maybe_unused]] auto interval1d{make_interval1d(2, 2)};
    }

    TEST(MakeInterval1dTest, ThrowsForInvalidInput) {
        EXPECT_THROW({[[ maybe_unused ]] auto i{make_interval1d(3, 2)}; }, std::invalid_argument);
    }
}
