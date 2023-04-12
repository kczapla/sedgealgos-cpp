#pragma once

namespace sedgealgos::data_structures::queue {

template<typename Item>
class CyclingLinkedListQueue {
public:
    using Size = unsigned int;

    void enqueue(Item item) {
        number_of_nodes++;
        if (last == nullptr) {
            last = new Node;
            last->item = item;
            last->next = last;
            return;
        }

        auto new_last{new Node};
        new_last->item = item;
        new_last->next = last->next;
        last->next = new_last;
        last = new_last;
    }

    Item dequeue() {
        if (number_of_nodes == 1) {
            auto tmp_item{last->item};
            delete last;
            last = nullptr;
            number_of_nodes--;
            return tmp_item;
        }

        auto old_first{last->next};
        last->next = old_first->next;

        auto tmp_item{old_first->item};

        delete old_first;

        number_of_nodes--;

        return tmp_item;
    }

    Size size() const {
        return number_of_nodes;
    }

    bool is_empty() const {
        return number_of_nodes == 0;
    }

private:
    class Node {
    public:
        Item item;
        Node* next;
    };

    Node* last{};
    Size number_of_nodes{};

public:
    template <typename T>
    class Iterator {
    public:
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;

        Iterator(Node* curr) : curr{curr} {}

        Iterator& operator++() {
            curr = curr->next;

            return *this;
        }

        Iterator operator++(int) {
            auto tmp{curr};
            curr = curr->next;

            return tmp;
        }

        reference operator*() {
            return curr->item;
        }

        pointer operator->() {
            return &(curr->item);
        }

        bool operator==(Iterator const& lhs) const {
            if ((curr->item == lhs.curr->item) && (curr->next == lhs.curr->next)) {
                return true;
            }
            return false;
        }

    private:
        Node* curr;
    };

    using iterator = Iterator<Item>;
    using const_iterator = Iterator<const Item>;

    iterator begin() {
        return iterator{last->next};
    }

    iterator end() {
        return iterator{last->next};
    }

    const_iterator cbegin() const {
        return const_iterator{last->next};
    }

    const_iterator cend() {
        return const_iterator{last->next};
    }

};
}
