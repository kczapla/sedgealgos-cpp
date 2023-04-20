#pragma once

#include "sedgealgos/data_structures/linked_list/single_linked_list.hpp"

namespace sedgealgos::data_structures::queue {
template <typename Item>
class LinkedListGeneralizedQueue {
public:
    using Size = long unsigned int;

    bool is_empty() const {
        return data.is_empty();
    }

    void insert(Item item) {
        data.push_front(item);
    }

    Item remove(Size k) {
        auto iter{data.begin()};
        Size index{data.size() - k - 1};
        Size counter{0};
        while (counter < index) {
            ++iter;
            ++counter;
        }

        Item val{*iter};

        data.remove(k);

        return val;
    }

private:
    linked_list::SingleLinkedList<Item> data;
};
}
