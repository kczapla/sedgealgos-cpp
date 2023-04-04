#pragma once

#include "sedgealgos/data_structures/linked_list/single_linked_list.hpp"

namespace sedgealgos::data_structures::queue {
template <typename Item>
class Queue {
public:
    using Size = unsigned int;

    void enqueue(Item item) {
        auto new_node{new Node};

        new_node->item = item;

        number_of_nodes++;

        if (last == nullptr) {
            last  = new_node;
            first = last;

            return;
        }
        
        last->next = new_node;
        last = new_node;
    }

    Item dequeue() {
        auto i{std::move(first->item)};
        auto next{first->next};

        if (first == last) {
            last = nullptr;
        }

        delete first;

        first = next;

        number_of_nodes--;

        return i;
    }

    bool is_empty() const {
        return number_of_nodes == 0;
    }

    Size size() const {
        return number_of_nodes;
    }

private:

    class Node {
    public:
        Item item;
        Node* next;
    };

    Node* first{nullptr};
    Node* last{nullptr};

    Size number_of_nodes{0};
};
}

