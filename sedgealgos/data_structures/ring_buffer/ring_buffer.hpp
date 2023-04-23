#pragma once

namespace sedgealgos::data_structures::ring_buffer {
template<typename Item>
class RingBuffer {
public:
    using Size = long unsigned int;

    RingBuffer(Size size) : buffer_size{size} {
        data = new Item[size];
    }

    ~RingBuffer() {
        delete[] data;
    }

    bool is_empty() const {
        return number_of_items == 0;
    }

    void push(Item item) {
        if (next_push / buffer_size == 1) {
            if (next_push == next_pop) {
                next_pop = 0;
            }
            next_push = 0;
            rolled_up = true;
        }

        if (rolled_up && (next_push == next_pop)) {
            next_pop++;
        }
        
        if (number_of_items == buffer_size) {
            number_of_items = buffer_size;
        } else {
            ++number_of_items;
        }

        data[next_push++] = item;
    }

    Item pop() {
        if (next_pop / buffer_size == 1) {
            next_pop = 0;
        }
        --number_of_items;
        return data[next_pop++];
    }

private:
    Size next_pop{0};
    Size next_push{0};

    Size number_of_items{0};

    Size buffer_size{0};
    Item* data{nullptr};

    bool rolled_up{false};
};
}

