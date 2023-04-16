#pragma once

#include <iterator>

namespace sedgealgos::data_structures::array {

template <typename Item>
class Array {
public:
    using Size = unsigned long;

    Array() {
        data = new Item[capacity];
    }

    Array(Size size) : Array{size, Item{}} {}

    Array(Size size, Item item) {
        data = new Item[size];
        for (Size i{0}; i < size; i++) {
            data[i] = item;
        }
        next_index = size;
        capacity = size;
    }

    ~Array() {
        delete[] data;
    }

    Item& operator[](Size index) {
        return data[index];
    }

    void push_back(Item item) {
        data[next_index++] = item;
        if (next_index == capacity) {
            resize(capacity * 2);
        }
    }

    Item pop_back() {
        return data[--next_index];
        if (next_index == (capacity/4)) {
            resize(capacity / 2);
        }
    }

    Size size() const {
        return next_index;
    }

    bool is_empty() const {
        return size() == 0;
    }

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
          ++ptr;
          return *this;
      }

      Iterator operator++(int) {
          Iterator tmp{*this};
          ++ptr;
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
        return iterator{data};
    }

    iterator end() {
        return iterator{data + next_index};
    }

    const_iterator cbegin() const {
        return const_iterator{data};
    }

    const_iterator cend() const {
        return const_iterator{data + next_index};
    }

    const_iterator begin() const {
        return cbegin();
    }

    const_iterator end() const {
        return cend();
    }

private:
    void resize(Size const new_capacity) {
        auto* new_data{new Item[new_capacity]};
        for (Size i{0}; i < next_index; ++i) {
            new_data[i] = data[i];
        }
        capacity = new_capacity;
    }

    Item* data;
    Size next_index{0};
    Size capacity{1};
};
}

