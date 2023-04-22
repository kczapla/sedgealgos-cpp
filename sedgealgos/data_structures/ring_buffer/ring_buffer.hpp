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
        return next_pop == next_push;
    }

    void push(Item item) {
        if (next_push / buffer_size == 1) {
            next_push = 0;
            if (next_push == next_pop) {
                next_pop++;
            }
        }
        
        data[next_push++] = item;
    }

    Item pop() {
        if (next_pop / buffer_size == 1) {
            next_pop = 0;
        }
        return data[next_pop++];
    }

private:
    Size next_pop{0};
    Size next_push{0};

    Size buffer_size{0};
    Item* data{nullptr};
};
}

