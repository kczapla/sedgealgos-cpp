#pragma once

#include <concepts>

namespace sedgealgos::data_structures::priority_queue {
template <typename T, typename K>
concept PriorityQueue = requires(T pq, K key) {
    T{};
    std::constructible_from<T, int>;
    std::constructible_from<T, typename T::container>;
    pq.insert(key);
    pq.top() -> key;
    pq.pop() -> key;
    { pq.empty() } -> std::same_as<bool>;
    { pq.size() } -> std::same_as<unsigned int>;
};
};

