#include "sedgealgos/data_structures/text_buffer/text_buffer.hpp"

#include <gtest/gtest.h>

namespace {
using namespace sedgealgos::data_structures::text_buffer;

class TextBufferTest : public ::testing::Test {
protected:
    TextBuffer tb;
};

TEST_F(TextBufferTest, EmptyBufferHasZeroSize) {
    EXPECT_EQ(tb.size(), 0);
}

TEST_F(TextBufferTest, InsertCharIncreasesSize) {
    tb.insert('c');
    EXPECT_EQ(tb.size(), 1);
}

TEST_F(TextBufferTest, DeleteDecreasesSize) {
    tb.insert('c');
    EXPECT_EQ(tb.size(), 1);

    tb.remove();
    EXPECT_EQ(tb.size(), 0);
}
}

