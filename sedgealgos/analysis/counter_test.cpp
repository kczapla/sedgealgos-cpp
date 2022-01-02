#include "sedgealgos/analysis/counter.hpp"

#include <gtest/gtest.h>

namespace {
    using namespace sedgealgos::analysis;

    class CounterTest : public ::testing::Test {
    protected:
        void SetUp() override {
            counter = Counter{"test counter"};
        }

        Counter counter{};
    };

    TEST_F(CounterTest, StringReturnsCounterStringRepresentation) {
        counter.increment();

        EXPECT_EQ(counter.string(), "1 test counter");
    }

    TEST_F(CounterTest, IncrementsAnInternalCounterByOne) {
        counter.increment();
        counter.increment();
        counter.increment();

        EXPECT_EQ(counter.tally(), 3);
    }
}
