#pragma once

#include "sedgealgos/data_structures/linked_list/single_linked_list.hpp"
#include "sedgealgos/stack/stack.hpp"

namespace sedgealgos::data_structures::text_buffer {

using CharStack = stack::Stack<char, linked_list::SingleLinkedList<char>>;
using IntStack = stack::Stack<int, linked_list::SingleLinkedList<int>>;

class TextBuffer {
public:
    using Size = long unsigned int;

    void insert(char c);
    char remove();

    void left(Size k);
    void right(Size k);

    Size size() const;

private:
    Size no_elements{0};

    CharStack left_stack;
    CharStack right_stack;

    int cursor{0};
};
}

