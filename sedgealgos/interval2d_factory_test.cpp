#include "sedgealgos/interval2d_factory.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos;

TEST(Interval2dFactoryTest, MakeInterval2d) {
    auto const interval2d{make_interval2d(2, 4, 2, 4)};
}
}
