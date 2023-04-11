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
    SingleLinkedList() = default;
    SingleLinkedList(SingleLinkedList const& ll) {
      auto* node{ll.head};
      while (node != nullptr) {
          auto* new_node{new Node};
          new_node->item = node->item;
          new_node->next = head;
          head = new_node;
          node = node->next;
      }

      items_no = ll.items_no;
    }

    SingleLinkedList& operator=(SingleLinkedList const& rhs) {
      auto* node{rhs.head};
      while (node != nullptr) {
          auto* new_node{new Node};
          new_node->item = node->item;
          new_node->next = head;
          head = new_node;
          node = node->next;
      }
      items_no = rhs.items_no;
      return *this;
    }

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

    void remove(std::size_t k) {
        if (k > items_no - 1) {
            return;
        }
        if (k == 0) {
            auto old_head{head};
            head = head->next;
            delete old_head;
            items_no--;
            return;
        }

        auto prev{head};
        auto curr{head};

        std::size_t i{0};
        while (curr->next != nullptr) {
            if (i == k) {
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }

        auto old_curr{curr};
        prev->next = curr->next;
        delete old_curr;

        items_no--;
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
      friend SingleLinkedList;

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

  void remove_after(iterator& iter) {
      if (iter == end()) {
          return;
      }

      auto old_next{iter.node->next};
      if (old_next == nullptr) {
          return;
      }

      iter.node->next = old_next->next;

      delete old_next;

      items_no--;
  }

  void insert_after(iterator& iter, Item item) {
      if (iter == end()) {
        return;
      }

      if (iter.node->next == nullptr) {
          return;
      }

      auto new_node{new Node{item, iter.node->next}};
      iter.node->next = new_node;
      items_no++;
  }
};

template <typename Item>
bool find(SingleLinkedList<Item> const& list, Item key) {
    auto iter{list.cbegin()};
    while (iter != list.cend()) {
        if (*iter == key) {
            return true;
        }
        ++iter;
    }
    return false;
}

template<typename Item>
void remove(SingleLinkedList<Item>& list, Item key) {
    auto prev_iter{list.begin()};
    auto iter{prev_iter};

    if (iter == list.end()) {
        return;
    }

    if (list.size() == 1 && *iter == key) {
        list.remove(0);
        return;
    }

    while (iter != list.end()) {
        if (*iter == key) {
            if (iter == list.begin()) {
                ++prev_iter;
                ++iter;
                list.remove(0);
            } else {
                list.remove_after(prev_iter);
                iter = prev_iter;
            }
        } else {
            prev_iter = iter;
        }
        ++iter;
    }
}

template <typename Item>
Item max(SingleLinkedList<Item> const& l) {
    auto iter{l.begin()};

    auto m{0};
    while(iter != l.end()) {
        if (*iter > m) {
            m = *iter;
        }
        ++iter;
    }

    return m;
}
}

