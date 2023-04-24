#include "sedgealgos/data_structures/text_buffer/text_buffer.hpp"
namespace sedgealgos::data_structures::text_buffer {

void TextBuffer::insert(char c) {
    left_stack.push(c);
    no_elements++;
}

TextBuffer::Size TextBuffer::size() const {
    return left_stack.size() + right_stack.size();
}

char TextBuffer::remove() {
    no_elements--;
    auto tmp{left_stack.pop()};

    if (!right_stack.is_empty()) {
        left_stack.push(right_stack.pop());
    }

    return tmp;
}


void TextBuffer::left(Size k) {
    while (k != 0) {
        right_stack.push(left_stack.pop());
        --k;
    }
}

void TextBuffer::right(Size k) {
    while (k != 0) {
        left_stack.push(right_stack.pop());
        --k;
    }
}
}

