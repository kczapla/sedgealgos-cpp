#pragma once

namespace sedgealgos::algorithms::sort::sort {
class Callbacks {
public:
    virtual void on_compare() = 0;
    virtual void on_swap() = 0;
};
}