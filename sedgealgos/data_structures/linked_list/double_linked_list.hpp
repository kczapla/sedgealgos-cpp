#pragma once

namespace sedgealgos::data_structures::linked_list {
template<typename Item>
class DoubleLinkedList {
private:
    struct Node {
        Node* next{nullptr};
        Node* previous{nullptr};
        Item item;
    };

public:
    using Size = unsigned long;

    template <typename T>
    class Iterator {
    public:
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;

        Iterator(Node* node) : node{node} {}

        bool operator==(Iterator const& rhs) const {
            return node == rhs.node;
        }

        bool operator!=(Iterator const& rhs) const {
            return !(*this == rhs);
        }

        Iterator& operator++() {
            node = node->next;
            return *this;
        }

        Iterator operator++(int) {
            auto tmp{node};
            node = node->next;

            return tmp;
        }

        reference operator*() {
            return node->item;
        }

        friend DoubleLinkedList;

    private:
        Node* node{nullptr};
    };

    ~DoubleLinkedList() {
        if (head == nullptr) {
            return;
        }

        auto curr{head};
        auto next{curr->next};
        while (next != nullptr) {
            delete curr;

            curr = next;
            next = curr->next;
        }
        
    }


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

    void push_front(Item item) {
        auto new_node{new Node};
        new_node->item = item;
        new_node->next = head;

        if (head != nullptr) {
            head->previous = new_node;
        } else {
            tail = new_node;
        }
        head = new_node;

        no_elements++;
    }

    Item pop_front() {
        auto new_head{head->next};
        if (new_head == nullptr) {
            tail = nullptr;
        }
        auto tmp_item{head->item};

        delete head;

        head = new_head;

        no_elements--;

        return tmp_item;
    }

    void push_back(Item item) {
        auto new_node{new Node};

        new_node->item = item;
        new_node->previous = tail;
        if (tail != nullptr) {
            tail->next = new_node;
        } else {
            head = new_node;
        }
        tail = new_node;

        no_elements++;
    }

    Item pop_back() {
        auto new_tail{tail->previous};
        if (new_tail != nullptr) {
            new_tail->next = nullptr;
        } else {
            head = nullptr;
        }

        auto tmp_item{tail->item};

        delete tail;

        tail = new_tail;

        no_elements--;

        return tmp_item;
    }

    void insert_before(iterator iter, Item item) {
        if (head == nullptr) {
            push_front(item);
            return;
        }
        auto first{iter.node->previous};

        auto second{new Node};
        second->item = item;

        auto third{iter.node};

        if (first == nullptr) {
            head = second;
        } else {
            first->next = second;
        }

        second->previous = first;
        second->next = third;
        
        third->previous = second;

        no_elements++;
    }

    void insert_after(iterator iter, Item item) {
        if (tail == nullptr) {
            push_back(item);
            return;
        }

        auto first{iter.node};
        auto second{new Node};
        auto third{first->next};

        if (third == nullptr) {
            tail = second;
        } else {
            third->previous = second;
        }


        second->item = item;
        second->previous = first;
        second->next = third;
        first->next = second;

        no_elements++;
    }

    void remove(iterator iter) {
        auto first{iter.node->previous};
        auto second{iter.node};
        auto third{iter.node->next};

        if (first != nullptr) {
            first->next = third;
        } else {
            head = third;
        }

        if (third != nullptr) {
            third->previous = first;
        } else {
            tail = first;
        }

        delete second;

        no_elements--;
    }

    bool is_empty() const {
        return no_elements == 0;
    }

    Size size() const {
        return no_elements;
    }

private:
    Node* head{nullptr};
    Node* tail{nullptr};

    Size no_elements{0};
};
}
