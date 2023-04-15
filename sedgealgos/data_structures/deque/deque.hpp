#pragma once

#include "sedgealgos/data_structures/linked_list/double_linked_list.hpp"

namespace sedgealgos::data_structures::deque {

template<typename Item>
class Deque {
public:
    using Size = unsigned int;

    void push_left(Item item) {
        data.push_front(item);
    }

    void push_right(Item item) {
        data.push_back(item);
    }

    Item pop_left() {
        return data.pop_front();
    }

    Item pop_right() {
        return data.pop_back();
    }

    bool is_empty() const {
        return data.is_empty();
    }

    Size size() const {
        return data.size();
    }

private:
    linked_list::DoubleLinkedList<Item> data;
};
}

