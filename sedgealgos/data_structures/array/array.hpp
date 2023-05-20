#pragma once

#include <initializer_list>
#include <iterator>
#include <iostream>

namespace sedgealgos::data_structures::array {

template <typename Item>
class Array {
public:
    using Size = unsigned long;

    using value_type = Item;

    Array() {
        data = new Item[capacity];
    }

    Array(std::initializer_list<Item> il) {
        data = new Item[il.size()];

        auto counter{0};
        for (auto&& i : il) {
            std::cout << "i = " << i << std::endl;
            data[counter++] = i;
        }
        next_index = counter;
    }

    Array(Size size) : Array(size, Item{}) {}

    Array(Size size, Item item) {
        data = new Item[size];
        for (Size i{0}; i < size; i++) {
            data[i] = item;
        }
        next_index = size;
        capacity = size;
    }

    Array(Array const& arr) {
        data = new Item[arr.size()];

        capacity = arr.capacity;
        next_index = arr.next_index;

        for (Size i{0}; i < next_index; i++) {
            data[i] = arr.data[i];
        }
    }

    Array& operator=(Array const& arr) {
        data = new Item[arr.size()];

        capacity = arr.capacity;
        next_index = arr.next_index;

        for (Size i{0}; i < next_index; i++) {
            data[i] = arr.data[i];
        }

        return *this;
    }

    ~Array() {
        if (data == nullptr) {
            return;
        }
        delete[] data;
        data = nullptr;
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
        auto old_item{data[--next_index]};
        if (next_index == (capacity/4)) {
            resize(capacity / 2);
        }
        return old_item;
    }

    void remove(Size k) {
        for (auto i{k}; i < next_index; i++) {
            data[i] = data[i+1];
        }
        --next_index;
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
        delete data;
        data = new_data;

        capacity = new_capacity;
    }

    Item* data;
    Size next_index{0};
    Size capacity{1};
};

template <typename Item>
bool operator==(Array<Item> const& lhs, Array<Item> const& rhs) {
    if (lhs.is_empty() && rhs.is_empty()) {
        return true;
    }
    
    if (lhs.size() != rhs.size()) {
        return false;
    }

    auto lhs_iter{lhs.cbegin()};
    auto rhs_iter{rhs.cbegin()};

    while(lhs_iter != lhs.cend() && rhs_iter != rhs.cend()) {
        if (*lhs_iter != *rhs_iter) {
            return false;
        }
        ++lhs_iter;
        ++rhs_iter;
    }
    return true;
}
}