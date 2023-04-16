#pragma once

#include "sedgealgos/data_structures/array/array.hpp"
#include "sedgealgos/data_structures/linked_list/single_linked_list.hpp"
#include "sedgealgos/stack/stack.hpp"
#include "sedgealgos/random/std_random.hpp"

namespace sedgealgos::data_structures::bag {

template <typename Item>
class RandomBag {
public:
    using Size =  array::Array<Item>::Size;

    void add(Item item) {
        data.push_back(item);
    }

    bool is_empty() const {
        return data.is_empty();
    }

    Size size() const {
        return data.size();
    }

    template<typename T, typename RandomGenerator = random::StdRandom>
    class Iterator {
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(array::Array<value_type>* data, Size size, RandomGenerator rg = RandomGenerator{}) : data{data}, random_generator{rg} {
            if (data == nullptr) {
                return;
            }

            if (size == 0) {
                return;
            }

            array::Array<bool> set(size, false);

            auto any_false{[](auto const& set) {
                for (auto flag : set) {
                    if (!flag) {
                        return true;
                    }
                }
                return false;
            }};

            while(any_false(set)) {
                auto i{random_generator.uniform(static_cast<int>(data->size() - 1))};
                if (set[i]) {
                    continue;
                }
                set[i] = true;
                indices.push(i);
            }
        }

        reference operator*() { 
            return (*data)[indices.peek()];
        }

        Iterator& operator++() {
            indices.pop();
            return *this;
        }

        bool operator==(Iterator const& rhs) const {
            auto point_to_the_same_array{data == rhs.data};
            auto have_the_same_indices{indices == rhs.indices};
            return point_to_the_same_array && have_the_same_indices;
        }

    private:
        typename array::Array<value_type>* data;
        stack::Stack<Size, linked_list::SingleLinkedList<Size>> indices;
        RandomGenerator random_generator;
    };

    using iterator = Iterator<Item>;
    using const_iterator = Iterator<const Item>;

    iterator begin() {
        return iterator{&data, data.size()};
    }

    iterator end() {
        return iterator{&data, 0};
    }

    const_iterator cbegin() {
        return const_iterator{&data, data.size()};
    }

    const_iterator cend() {
        return const_iterator{&data, 0};
    }

private:
    array::Array<Item> data;
};
}

