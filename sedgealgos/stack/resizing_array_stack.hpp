namespace sedgealgos::stack {
  template <typename Item>
  class ResizingArrayStack {
  public:
    ResizingArrayStack();
    ~ResizingArrayStack();

    unsigned long size() const;
    bool is_empty() const;
    void push(int a);
    int pop();

  private:
    void resize(unsigned long);

    unsigned long next_index{0};
    unsigned long capacity{1};
    int* container{nullptr};
  };

  template <typename Item>
  ResizingArrayStack<Item>::ResizingArrayStack() {
    container = new int[capacity];
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
  void ResizingArrayStack<Item>::push(int item) {
      if (next_index == capacity) {
          resize(2 * capacity);
      }
      container[next_index++] = item;
  }

  template <typename Item>
  int ResizingArrayStack<Item>::pop() {
      auto top_elem{container[--next_index]};
      if (next_index == capacity / 4) {
          resize(capacity / 2);
      }

      return top_elem;
  }

  template <typename Item>
  void ResizingArrayStack<Item>::resize(unsigned long new_capacity) {
      int* larger_container{new int[new_capacity]};

      for (unsigned long i{0}; i < new_capacity; i++) {
          larger_container[i] = container[i];
      }

      delete[] container;
      container = larger_container;
      capacity = new_capacity;
  }
}
