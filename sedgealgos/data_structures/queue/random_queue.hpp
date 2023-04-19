#pragma once

#include "sedgealgos/data_structures/array/array.hpp"
#include "sedgealgos/data_structures/linked_list/single_linked_list.hpp"
#include "sedgealgos/random/std_random.hpp"
#include "sedgealgos/stack/stack.hpp"

namespace sedgealgos::data_structures::queue {

using LinkedListStack = stack::Stack<unsigned int, linked_list::SingleLinkedList<unsigned int>>;

template<typename Item, typename RandomGenerator = sedgealgos::random::StdRandom>
class RandomQueue {
public:
    template<typename T>
    class Iterator {
    public:
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;

        struct Begin {};
        struct End {};


        Iterator() = default;

        Iterator(array::Array<value_type>* data, Begin) : data{data} {
            if (data == nullptr) {
                return;
            }

            array::Array<bool> set(data->size(), false);

            auto any_false{[](auto const& set) {
                for (auto flag : set) {
                    if (!flag) {
                        return true;
                    }
                }
                return false;
            }};

            while(any_false(set)) {
                auto i{RandomGenerator::uniform(static_cast<int>(data->size() - 1))};
                if (set[i]) {
                    continue;
                }
                set[i] = true;
                indices.push(i);
            }
        }

        Iterator(array::Array<value_type>* data, End) : data{data} {}

        reference operator*() {
            return (*data)[indices.peek()];
        }

        Iterator& operator++() {
            indices.pop();
            return *this;
        }

        bool operator==(Iterator const& rhs) {
            auto points_to_the_same_data{data == rhs.data};
            auto have_the_same_indices{indices == rhs.indices};
            return points_to_the_same_data && have_the_same_indices;
        }

    private:
        array::Array<value_type>* data;
        LinkedListStack indices;
    };

    using iterator = Iterator<Item>;

    iterator begin() {
        return iterator{&data, typename iterator::Begin{}};
    }

    iterator end() {
        return iterator{&data, typename iterator::End{}};
    }

    bool is_empty() const {
        return data.is_empty();
    }

    void enqueue(Item item) {
        data.push_back(item);
    }

    Item dequeue() {
        auto const index{RandomGenerator::uniform(static_cast<int>(data.size() - 1))};
        auto tmp{data[index]};
        data[index] = data[data.size() - 1];
        data[data.size() - 1] = tmp;

        return data.pop_back();
    }

    Item sample() {
        auto const index{RandomGenerator::uniform(static_cast<int>(data.size() - 1))};
        return data[index];
    }

private:
    array::Array<Item> data;
};
}
