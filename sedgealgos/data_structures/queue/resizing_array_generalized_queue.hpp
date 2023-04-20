#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::data_structures::queue {
template <typename Item>
class ResizingArrayGeneralizedQueue {
public:
    using Size = long unsigned int;

    bool is_empty() const {
        return data.is_empty();
    }

    void insert(Item item) {
        data.push_back(item);
    }

    Item remove(Size k) {
        auto item{data[k]};
        data.remove(k);

        return item;
    }

private:
    array::Array<Item> data;
};
}
