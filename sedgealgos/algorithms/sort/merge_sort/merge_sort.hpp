#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"

#include <functional>

namespace sedgealgos::algorithms::sort::merge_sort {

template <typename Container>
using MergeFunc = std::function<void(
        sort::Callbacks*,
        Container&,
        Container&,
        typename Container::Size,
        typename Container::Size,
        typename Container::Size)
    >;
}