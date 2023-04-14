#pragma once

namespace sedgealgos::data_structures::steque {

template<typename Item>
class Steque {
    struct Node {
        Item item;
        Node* next{nullptr};
    };
public:
    using Size = unsigned int;

    void push_front(Item item) {
        auto new_node{new Node};
        new_node->item = item;
        new_node->next = head;

        if (head == nullptr) {
            tail = new_node;
        }
        head = new_node;

        number_of_elements++;
    }

    Item pop_front() {
        auto tmp_item{head->item};
        auto tmp_next{head->next};

        delete head;

        head = tmp_next;

        number_of_elements--;
        
        return tmp_item;
    }

    void enqueue(Item item) {
        auto node{new Node};

        node->item = item;

        if (head == nullptr) {
            head = node;
        }

        if (tail != nullptr) {
            tail->next = node;
        }
        tail = node;

        number_of_elements++;
    }

    Size size() const {
        return number_of_elements;
    }

private:
    Size number_of_elements{0};
    Node* head{nullptr};
    Node* tail{nullptr};

public:
    template <typename T>
    class Iterator {
    public:
        using value_type = T;
        using reference = value_type&;

        Iterator(Node* node) : node{node} {}

        reference operator*() {
            return node->item;
        }

        Iterator& operator++() {
            node = node->next;
            return *this;
        }

        Iterator operator++(int) {
            auto tmp{*this};
            node = node->next;
            return tmp;
        }

        bool operator==(Iterator const& rhs) const {
            return node == rhs.node;
        }

    private:
        Node* node{nullptr};
    };

    using iterator = Iterator<Item>;
    using const_iterator = Iterator<const Item>;

    iterator begin() {
        return iterator{head};
    }

    iterator end() {
        return iterator{nullptr};
    }

    const_iterator cbegin() {
        return const_iterator{head};
    }

    const_iterator cend() {
        return const_iterator{nullptr};
    }
};
}

