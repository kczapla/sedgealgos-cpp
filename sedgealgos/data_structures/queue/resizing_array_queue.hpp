#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::data_structures::queue {

template <typename Item>
class ResizingArrayQueue {
public:
    using Size = unsigned int;

    void enqueue(Item item) {
        data.push_back(item);
        last_next++;
    }

    Item dequeue() {
        return data[first_next++];
    }

    bool is_empty() const {
        return (last_next - first_next) == 0;
    }

    Size size() const {
        return last_next - first_next;
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
    Size first_next = 0;
    Size last_next = 0;
};
}
