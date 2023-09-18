#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace sedgealgos::algorithms::sort::quicksort {
template <typename Container>
class Quicksort {
public:
    static void sort(Container& container) {
        sort(container, 0, container.size() - 1);
    }

private:
    static void sort(Container& container, int lo, int hi) {
        if (hi <= lo) return;

        auto const j{partition(container, lo, hi)};
        sort(container, lo, j-1);
        sort(container, j+1, hi);
    }

    static unsigned long partition(Container& container, int lo, int hi) {
        auto const p{container[lo]};
        auto i{lo};
        auto j{hi + 1};
        
        while (true) {
            while (container[++i] < p) {
                if (i == hi) break;
            }
            while (p < container[--j]) {
                if (lo == j) break;
            }

            if (i >= j) {
                break; 
            }
        }

        container[lo] = container[j];
        container[j] = p;

        return j;
    }
};
}
