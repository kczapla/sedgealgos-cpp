#pragma once

#include <string>
#include <stdexcept>

namespace sedgealgos::data_structures::linked_list {

class LinkedListException : std::runtime_error {
public:
    LinkedListException(std::string const& message) : std::runtime_error{message} {}

    const char* what() const noexcept override {
        return std::runtime_error::what();
    }
};

template <typename Item>
class SingleLinkedList {
public:
    void push_front(Item item) {
        auto* old_head{head};
        head = new Node;
        head->next = old_head;
        head->item = item;
        items_no++;
    }

    Item pop_front() {
        if (head == nullptr) {
            throw LinkedListException{"popping from empty list"};
        }

        auto* next_node{head->next};
        auto current_item{head->item};

        delete head;

        head = next_node;

        items_no--;

        return current_item;
    }

    Item& front() {
        return head->item;
    }

    Item const& front() const {
        return front();
    }

    std::size_t size() const {
        return items_no;
    }

private:
  struct Node {
      Item item;
      Node* next{nullptr};
  };

  Node* head{nullptr};
  std::size_t items_no{};

public:
  template <typename T>
  struct Iterator {
      using iterator_category = std::forward_iterator_tag;
      using difference_type = std::ptrdiff_t;
      using value_type = T;
      using pointer = value_type*;
      using reference = value_type&;

      Iterator(Node* n) : node{n} {}

      reference operator*() const { return node->item; };
      pointer operator->() const { return &node->item; };

      Iterator& operator++() {
          node = node->next;
          return *this;
      }

      Iterator operator++(int) {
          Iterator tmp{*this};
          node = node->next;
          return tmp;
      }

      bool operator==(Iterator const& left) const {
          return this->node == left.node;
      }

      bool operator!=(Iterator const& left) const {
          return !(*this == left);
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

  const_iterator cbegin() const {
      return const_iterator{head};
  }

  const_iterator cend() const {
      return const_iterator{nullptr};
  }

  const_iterator begin() const {
      return cbegin();
  }

  const_iterator end() const {
      return cend();
  }
};
}

