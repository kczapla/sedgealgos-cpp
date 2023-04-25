#pragma once


#include <iterator>

namespace sedgealgos::data_structures::stack {

template <typename Item, typename Container>
class Stack {
public:
  Stack() = default;

  void push(Item item); 
  Item pop();
  Item& peek();
  Item const& peek() const;

  bool is_empty() const;
  unsigned long size() const;

  bool operator==(Stack const& lhs) const;

public:
  template <typename T>
  struct Iterator {
      using iterator_category = std::forward_iterator_tag;
      using difference_type = std::ptrdiff_t;
      using value_type = T;
      using pointer = value_type*;
      using reference = value_type&;

      Iterator(typename Container::Iterator<T> iter) : iter{iter} {}

      reference operator*() const { return *iter; };
      pointer operator->() const { return &(*iter); };

      Iterator& operator++() {
          iter++;
          return *this;
      }

      Iterator operator++(int) {
          Iterator tmp{iter};
          iter++;
          return tmp;
      }

      bool operator==(Iterator const& left) const {
          return iter == left.iter;
      }

      bool operator!=(Iterator const& left) const {
          return !(*this == left);
      }

    private:
      typename Container::Iterator<T> iter;
  };

  using iterator = Iterator<Item>;
  using const_iterator = Iterator<const Item>;

  iterator begin() {
      return iterator{container.begin()};
  }

  iterator end() {
      return iterator{container.end()};
  }

  const_iterator cbegin() const {
      return const_iterator{container.cbegin()};
  }

  const_iterator cend() const {
      return const_iterator{container.cend()};
  }

  const_iterator begin() const {
      return cbegin();
  }

  const_iterator end() const {
      return cend();
  }

private:
  Container container;
};


template <typename Item, typename Container>
void Stack<Item, Container>::push(Item item) {
  container.push_front(item);
}

template <typename Item, typename Container>
Item Stack<Item, Container>::pop() {
  return container.pop_front();
}

template <typename Item, typename Container>
bool Stack<Item, Container>::is_empty() const {
  return container.size() == 0;
}

template <typename Item, typename Container>
unsigned long Stack<Item, Container>::size() const {
  return container.size();
}

template <typename Item, typename Container>
Item& Stack<Item, Container>::peek() {
  return container.front();
}

template <typename Item, typename Container>
Item const& Stack<Item, Container>::peek() const {
  return container.front();
}

template <typename Item, typename Container>
bool Stack<Item, Container>::operator==(Stack<Item, Container> const& lhs) const {
  auto rhs_iter{container.cbegin()};
  auto lhs_iter{lhs.container.cbegin()};

  while (rhs_iter != container.cend() && lhs_iter != lhs.container.cend()) {
      if (*rhs_iter != *lhs_iter) {
          return false;
      }
      ++rhs_iter;
      ++lhs_iter;
  }

  return rhs_iter == lhs_iter;
}
}
