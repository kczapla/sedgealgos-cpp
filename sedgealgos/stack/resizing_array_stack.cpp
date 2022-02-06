#include "sedgealgos/stack/resizing_array_stack.hpp"

namespace sedgealgos::stack {
  ResizingArrayStack::ResizingArrayStack() {
    container = new int[1];
  }

  ResizingArrayStack::~ResizingArrayStack() {
    delete container;
  }

  bool ResizingArrayStack::is_empty() const {
    return index == 0;
  }

  void ResizingArrayStack::push(int item) {
      container[index++] = item;
  }

  int ResizingArrayStack::pop() {
      return container[--index];
  }
}
