#pragma once

namespace sedgealgos::data_structures::stack {
  template <typename Item>
  class ResizingArrayStack {
  public:
    ResizingArrayStack();
    ResizingArrayStack(ResizingArrayStack const&);
    ResizingArrayStack& operator=(ResizingArrayStack const&);
    ~ResizingArrayStack();

    unsigned long size() const;
    bool is_empty() const;
    void push(Item a);
    Item pop();
    Item& peek();
    Item const& peek() const;

    bool operator==(ResizingArrayStack const& lhs) const;

  private:
    void resize(unsigned long);

    unsigned long next_index{0};
    unsigned long capacity{1};
    Item* container{nullptr};

  public:
    template <typename T>
    struct Iterator {
      using iterator_category = std::forward_iterator_tag;
      using difference_type = std::ptrdiff_t;
      using value_type = T;
      using pointer = value_type*;
      using reference = value_type&;

      Iterator(pointer p) : ptr{p} {}

      reference operator*() const { return *ptr; };
      pointer operator->() const { return ptr; };

      Iterator& operator++() {
          --ptr;
          return *this;
      }

      Iterator operator++(int) {
          Iterator tmp{*this};
          --ptr;
          return tmp;
      }

      bool operator==(Iterator const& left) const {
          return this->ptr == left.ptr;
      }

      bool operator!=(Iterator const& left) const {
          return !(*this == left);
      }

    private:
      pointer ptr{nullptr};
    };

    using iterator = Iterator<Item>;
    using const_iterator = Iterator<const Item>;

    iterator begin() {
        return iterator{container + next_index - 1};
    }

    iterator end() {
        return iterator{container - 1};
    }

    const_iterator cbegin() const {
        return const_iterator{container + next_index - 1};
    }

    const_iterator cend() const {
        return const_iterator{container - 1};
    }

    const_iterator begin() const {
        return cbegin();
    }

    const_iterator end() const {
        return cend();
    }
  };

  template <typename Item>
  ResizingArrayStack<Item>::ResizingArrayStack() {
    container = new Item[capacity];
  }

  template <typename Item>
  ResizingArrayStack<Item>::ResizingArrayStack(ResizingArrayStack const& other) {
    next_index = other.next_index;
    capacity = other.capacity;

    container = new Item[capacity];
    for (unsigned long i{0}; i < capacity; ++i) {
        container[i] = other.container[i];
    }
  }

  template <typename Item>
  ResizingArrayStack<Item>& ResizingArrayStack<Item>::operator=(ResizingArrayStack const& other) {
    next_index = other.next_index;
    capacity = other.capacity;

    container = new Item[capacity];
    for (unsigned long i{0}; i < capacity; ++i) {
        container[i] = other.container[i];
    }

    return *this;
  }

  template <typename Item>
  unsigned long ResizingArrayStack<Item>::size() const {
    return next_index;
  }

  template <typename Item>
  ResizingArrayStack<Item>::~ResizingArrayStack() {
    delete container;
  }

  template <typename Item>
  bool ResizingArrayStack<Item>::is_empty() const {
    return next_index == 0;
  }

  template <typename Item>
  void ResizingArrayStack<Item>::push(Item item) {
      if (next_index == capacity) {
          resize(2 * capacity);
      }
      container[next_index++] = item;
  }

  template <typename Item>
  Item ResizingArrayStack<Item>::pop() {
      auto top_elem{container[--next_index]};
      if (next_index == capacity / 4) {
          resize(capacity / 2);
      }

      return top_elem;
  }

  template <typename Item>
  void ResizingArrayStack<Item>::resize(unsigned long new_capacity) {
      Item* larger_container{new Item[new_capacity]};

      for (unsigned long i{0}; i < new_capacity; i++) {
          larger_container[i] = container[i];
      }

      delete[] container;
      container = larger_container;
      capacity = new_capacity;
  }

  template <typename Item>
  Item& ResizingArrayStack<Item>::peek() {
      return container[next_index - 1];
  }

  template <typename Item>
  Item const& ResizingArrayStack<Item>::peek() const {
      return const_cast<ResizingArrayStack<Item>*>(this)->peek();
  }

  template <typename Item>
  bool ResizingArrayStack<Item>::operator==(ResizingArrayStack<Item> const& lhs) const {
      if (this->size() != lhs.size()) {
          return false;
      }

      for (long unsigned int i{0}; i < lhs.size(); i++) {
          if (this->container[i] != lhs.container[i]) {
              return false;
          }
      }

      return true;
  }
}
