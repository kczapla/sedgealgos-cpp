#pragma once

#include <utility>

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

public:
    template <typename T>
    class Iterator {
    public:
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;

        Iterator(Node* first) : first{first} {}

        reference operator*() {
            return first->item;
        }

        Iterator& operator++() {
            first = first->next;
            return *this;
        }

        Iterator operator++(int) {
            auto tmp{*this};
            ++*this;
            return tmp;
        }

        bool operator==(Iterator const& rhs) const {
            return this->first == rhs.first;
        }

    private:
        Node* first{nullptr};
    };

    using iterator = Iterator<Item>;
    using const_iterator = Iterator<const Item>;

    iterator begin() {
        return iterator{first};
    }

    iterator end() {
        return iterator{nullptr};
    }

    const_iterator cbegin() {
        return const_iterator{first};
    }

    const_iterator cend() {
        return const_iterator{nullptr};
    }
};
}

