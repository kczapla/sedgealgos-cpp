#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"

#include <gmock/gmock.h>

namespace sedgealgos::algorithms::sort::sort {
class CallbacksMock : public Callbacks {
public:
    MOCK_METHOD(void, on_compare, ());
    MOCK_METHOD(void, on_swap, ());
    MOCK_METHOD(void, on_sort_start, ());
    MOCK_METHOD(void, on_sort_stop, ());
    MOCK_METHOD(void, on_array_access, (int));
};
}