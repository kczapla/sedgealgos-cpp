#pragma once

namespace sedgealgos::algorithms::sort::sort {
template <typename Container>
bool is_sorted(Container const& c) {
    for (typename Container::Size i{1}; i < c.size(); i++) {
        if (c[i-1] > c[i]) {
            return false;
        }
    }
    return true;
}
}