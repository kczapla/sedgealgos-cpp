#pragma once

namespace sedgealgos::data_structures::deque {
template <typename Item>
class ResizingArrayDeque {
public:
    using Size = unsigned int;

    ResizingArrayDeque() {
        data = new Item[capacity];
    }

    ~ResizingArrayDeque() {
        if (data == nullptr) {
            return;
        }

        delete[] data;
    }

    void push_left(Item item) {
        if (number_of_items != 0) {
            shift_right();
        }
        data[0] = item;
        number_of_items++;
    }

    void push_right(Item item) {
        if (number_of_items == capacity) {
            resize(2*capacity);
        }
        data[number_of_items++] = item;
    }

    Item pop_left() {
        auto old_item{data[0]};
        shift_left();

        number_of_items--;

        return old_item;
    }

    Item pop_right() {
        return data[(number_of_items--)-1];
    }

    bool is_empty() const {
        return number_of_items == 0;
    }

    Size size() const {
        return number_of_items;
    }

private:
    void shift_right() {
        if (number_of_items == capacity) {
            resize(capacity*2);
        }

        auto new_data{new Item[capacity]};
        for (Size i{0}; i < number_of_items; i++) {
            new_data[i+1] = data[i];
        }

        delete[] data;

        data = new_data;
    }

    void shift_left() {
        if (number_of_items <= capacity / 2) {
            resize(capacity / 4);
        }

        for (Size i{1}; i < number_of_items; i++) {
            data[i-1] = data[i];
        }
    }

    void resize(Size new_capacity) {
        auto new_data{new Item[new_capacity]};
        for (Size i{0}; i < number_of_items; i++) {
            new_data[i] = data[i];
        }

        delete[] data;

        data = new_data;

        capacity = new_capacity;
    }

    Size capacity{1};
    Size number_of_items{};

    Item* data{nullptr};
};
}
