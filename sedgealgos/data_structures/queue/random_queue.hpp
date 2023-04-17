#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::data_structures::queue {
template<typename Item, typename RandomGenerator>
class RandomQueue {
public:
    bool is_empty() const {
        return data.is_empty();
    }

    void enqueue(Item item) {
        data.push_back(item);
    }

    Item peek() {
        auto const index{RandomGenerator::uniform(static_cast<int>(data.size() - 1))};
        return data[index];
    }

private:
    array::Array<Item> data;
};
}
