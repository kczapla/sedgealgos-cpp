#pragma once

namespace sedgealgos::data_structures::linked_list {
template<typename Item>
class DoubleLinkedList {
public:
    using Size = unsigned long;

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

    Size size() const {
        return no_elements;
    }

private:
    struct Node {
        Node* next{nullptr};
        Node* previous{nullptr};
        Item item;
    };

    Node* head{nullptr};
    Node* tail{nullptr};

    Size no_elements{0};
};
}
