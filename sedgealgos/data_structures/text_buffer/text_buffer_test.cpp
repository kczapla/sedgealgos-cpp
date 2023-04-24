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

TEST_F(TextBufferTest, DeleteReturnsCharFromTheSamePostionCharWasJustInserted) {
    tb.insert('c');
    EXPECT_EQ(tb.remove(), 'c');
}

TEST_F(TextBufferTest, InsertTextThenMoveCursorToTheBeginingAndRemove) {
    tb.insert('a');
    tb.insert('b');
    tb.insert('c');
    tb.insert('d');
    
    tb.left(3);

    EXPECT_EQ(tb.remove(), 'a');
}

TEST_F(TextBufferTest, InsertTextThenMoveCursorToTheEndAndRemove) {
    tb.insert('a');
    tb.insert('b');
    tb.insert('c');
    tb.insert('d');
    
    EXPECT_EQ(tb.remove(), 'd');
}

TEST_F(TextBufferTest, InsertTextThenMoveCursorToTheMiddleAndRemove) {
    tb.insert('a');
    tb.insert('b');
    tb.insert('c');
    tb.insert('d');
    tb.insert('e');

    tb.left(2);
    
    EXPECT_EQ(tb.remove(), 'c');
    EXPECT_EQ(tb.remove(), 'd');
}
}

