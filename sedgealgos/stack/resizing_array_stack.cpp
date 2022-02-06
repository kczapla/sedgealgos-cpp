#include "sedgealgos/stack/resizing_array_stack.hpp"

namespace sedgealgos::stack {
  ResizingArrayStack::ResizingArrayStack() {
    container = new int[1];
  }

  ResizingArrayStack::~ResizingArrayStack() {
    delete container;
  }

  unsigned long ResizingArrayStack::size() const {
    return next_index;
  }

  bool ResizingArrayStack::is_empty() const {
    return next_index == 0;
  }

  void ResizingArrayStack::push(int item) {
      if (next_index == capacity) {
          resize(2 * capacity);
      }
      container[next_index++] = item;
  }

  int ResizingArrayStack::pop() {
      return container[--next_index];
  }

  void ResizingArrayStack::resize(unsigned long new_capacity) {
      int* larger_container{new int[new_capacity]};

      for (unsigned long i{0}; i < new_capacity; i++) {
          larger_container[i] = container[i];
      }

      delete[] container;
      container = larger_container;
      capacity = new_capacity;
  }
}
