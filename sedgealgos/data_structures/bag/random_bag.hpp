#pragma once

#include "sedgealgos/data_structures/array/array.hpp"
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

    template<typename T>
    class Iterator {
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(array::Array<Item>& data) : data{data} {}

        reference operator*() { 
            auto i{random::StdRandom::uniform(static_cast<int>(data.size() - 1))};
            return data[i];
        }

        Iterator& operator++() {
            return *this;
        }

        bool operator==(Iterator const& rhs) const {
            auto point_to_the_same_array{data.begin() == rhs.data.begin()};
            auto array_is_empty{data.is_empty()};
            return point_to_the_same_array && array_is_empty;
        }

    private:
        array::Array<Item>& data;
    };

    using iterator = Iterator<Item>;
    using const_iterator = Iterator<const Item>;

    iterator begin() {
        return iterator{data};
    }

    iterator end() {
        return iterator{data};
    }

    const_iterator cbegin() {
        return const_iterator{data};
    }

    const_iterator cend() {
        return const_iterator{data};
    }

private:
    array::Array<Item> data;
};
}

