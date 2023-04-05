#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::data_structures::queue {

template <typename Item>
class ResizingArrayQueue {
public:
    using Size = unsigned int;

    void enqueue(Item item) {
        data.push_back(item);
        if (data.size() == 1) {
            return;
        }
    }

    Item dequeue() {
        return data[first_item_in_queue++];
    }

    bool is_empty() const {
        return data.is_empty();
    }

    Size size() const {
        return data.size() - first_item_in_queue;
    }

    template <typename T>
    class Iterator {
    public:
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;

        Iterator(typename sedgealgos::data_structures::array::Array<Item>::Iterator<T> iter) : iter{iter} {}

        reference operator*() {
            return *iter;
        }

        Iterator& operator++() {
            ++iter;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp{iter};
            ++iter;
            return tmp;
        }

        bool operator==(Iterator const& rhs) const {
            return this->iter == rhs.iter;
        }

    private:
        typename sedgealgos::data_structures::array::Array<Item>::Iterator<T> iter;
    };

    using iterator = Iterator<Item>;
    using const_iterator = Iterator<const Item>;

    iterator begin() {
        return iterator{data.begin()};
    }

    iterator end() {
        return iterator{data.end()};
    }

    const_iterator cbegin() {
        return const_iterator{data.cbegin()};
    }

    const_iterator cend() {
        return const_iterator{data.cend()};
    }

private:
    sedgealgos::data_structures::array::Array<Item> data;
    Size first_item_in_queue = 0;
};
}
