#include "sedgealgos/exercises/chapter1/ex1418/ex1418.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::exercises::chapter1::ex1418;

TEST(Ex1418Test, TestCase1) {
    EXPECT_EQ(1, Ex1418::find({1,-1, 2, 3, 4}));
}

TEST(Ex1418Test, TestCase2) {
    EXPECT_EQ(1, Ex1418::find({1,-1, 2, 3, 4, 5, 6, 10, 7, -1}));
}

TEST(Ex1418Test, TestCase3) {
    // current implementation is not capable of finding 7 as local minimum
    EXPECT_EQ(0, Ex1418::find({0, 1, 2, 3, 4, 5, 6, 10, 7, 11}));
}

TEST(Ex1418Test, TestCase4) {
    EXPECT_EQ(5, Ex1418::find({5, 4, 3, 2, 1, 0, 6, -1}));
}
}

