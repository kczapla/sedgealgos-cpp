namespace sedgealgos::stack {
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

  private:
    void resize(unsigned long);

    unsigned long next_index{0};
    unsigned long capacity{1};
    Item* container{nullptr};
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
}
