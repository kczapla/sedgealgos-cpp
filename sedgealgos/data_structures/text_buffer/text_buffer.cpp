#include "sedgealgos/data_structures/text_buffer/text_buffer.hpp"
namespace sedgealgos::data_structures::text_buffer {

void TextBuffer::insert(char c) {
    no_elements++;
}

TextBuffer::Size TextBuffer::size() const {
    return no_elements;
}

char TextBuffer::remove() {
    no_elements--;
    return '0';
}
}

