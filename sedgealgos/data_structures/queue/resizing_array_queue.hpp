#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::data_structures::queue {

template <typename Item>
class ResizingArrayQueue {
public:
    using Size = unsigned int;

    ResizingArrayQueue() {
        data = new Item;
    }

    void enqueue(Item item) {
        if (last_next == capacity) {
            resize(capacity * 2);
        }
        data[last_next++] = item;
    }

    Item dequeue() {
        if (size() <= (capacity / 4)) {
            resize(capacity / 2);
        }
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

        Iterator(pointer iter) : iter{iter} {}

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
        pointer iter;
    };

    using iterator = Iterator<Item>;
    using const_iterator = Iterator<const Item>;

    iterator begin() {
        return iterator{data + first_next};
    }

    iterator end() {
        return iterator{data + last_next};
    }

    const_iterator cbegin() {
        return const_iterator{data + first_next};
    }

    const_iterator cend() {
        return const_iterator{data + last_next};
    }

private:
    void resize(Size new_size) {
        auto new_data{new Item[new_size]};
        for (auto i{first_next}; i < last_next; i++) {
            new_data[i - first_next] = data[i];
        }

        delete data;
        data = new_data;

        first_next = 0;
        last_next = last_next - first_next;
    }

    Item* data;
    Size capacity = 1;

    Size first_next = 0;
    Size last_next = 0;
};
}
