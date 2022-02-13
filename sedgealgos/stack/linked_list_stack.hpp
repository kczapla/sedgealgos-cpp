#pragma once

namespace sedgealgos::stack {

template <typename Item>
class LinkedListStack {
public:
  LinkedListStack() = default;
  LinkedListStack(LinkedListStack const&);
  LinkedListStack& operator=(LinkedListStack const&);
  ~LinkedListStack();

  void push(Item item); 
  Item pop();
  Item& peek();
  Item const& peek() const;

  bool is_empty() const;
  unsigned long size() const;

private:
  struct Node {
      Item item;
      Node* next{nullptr};
  };

  Node* head{nullptr};
};

template<typename Item>
LinkedListStack<Item>::LinkedListStack(LinkedListStack<Item> const& other) {
  for (auto* i{other.head}; i; i = i->next) {
    this->push(i->item);
  }
}

template<typename Item>
LinkedListStack<Item>& LinkedListStack<Item>::operator=(LinkedListStack<Item> const& other) {
  for (auto* i{other.head}; i; i = i->next) {
    this->push(i->item);
  }

  return *this;
}

template<typename Item>
LinkedListStack<Item>::~LinkedListStack() {
  while(!is_empty()) {
    auto* to_delete{head};
    head = head->next;
    delete to_delete;
  }
}

template<typename Item>
void LinkedListStack<Item>::push(Item item) {
  auto* node{new Node};
  node->item = item;
  node->next = head;
  head = node;
}

template<typename Item>
Item LinkedListStack<Item>::pop() {
  auto* node_to_pop{head};
  head = head->next;
  auto value_to_pop{node_to_pop->item};
  delete node_to_pop;

  return value_to_pop;
}

template<typename Item>
bool LinkedListStack<Item>::is_empty() const {
  return !head;
}

template<typename Item>
unsigned long LinkedListStack<Item>::size() const {
  auto count{0};
  for (auto* i{head}; i; i = i->next) {
    ++count;
  }
  return count;
}

template <typename Item>
Item& LinkedListStack<Item>::peek() {
  return head->item;
}

template <typename Item>
Item const& LinkedListStack<Item>::peek() const {
  return const_cast<LinkedListStack<Item>*>(this)->peek();
}
}
