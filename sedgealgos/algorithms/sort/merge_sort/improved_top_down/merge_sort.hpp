#pragma once

#include "sedgealgos/algorithms/sort/sort/callbacks.hpp"
#include "sedgealgos/algorithms/sort/sort/is_sorted.hpp"

#include <iostream>
#include <cmath>

namespace sedgealgos::algorithms::sort::merge_sort::improved_top_down {

template<typename Container,
         template<typename = Container> typename CutOffSort,
         template<typename = Container> typename Merge> 
class Sort {
public:
    Sort(sort::Callbacks* clbkcs) : callbacks{clbkcs} {}

    void sort(Container& c) {
        if (c.is_empty() || c.size() == 0) {
            return;
        }

        callbacks->on_sort_start();
        Container aux(c.size());
        std::cout << "before sorting c = " << c << std::endl;

        // sort(c, aux, static_cast<Container::Size>(0), c.size() - 1);
        // sort(aux, c, static_cast<Container::Size>(0), c.size() - 1);

        if (static_cast<int>(std::ceil(std::log2(c.size()))) % 2 == 0) {
            sort(c, aux, static_cast<Container::Size>(0), c.size() - 1);
        } else {
            sort(aux, c, static_cast<Container::Size>(0), c.size() - 1);
            for (int i{0}; i < static_cast<int>(aux.size()); i++) {
                c[i] = aux[i];
            }
        }

        // sort(aux, c, static_cast<Container::Size>(0), c.size() - 1);
        // for (int i{0}; i < static_cast<int>(aux.size()); i++) {
        //     c[i] = aux[i];
        // }

        std::cout << "after sorting c = " << c << std::endl;
        callbacks->on_sort_stop();
    }

private:
    void sort(Container& c, Container& aux, Container::Size lo, Container::Size hi) {
        std::cout << "begin sort(c=" << c << ", aux=" << aux << ", lo=" << lo << "; hi = " << hi << ")" << std::endl;        
        if ((hi - lo) == 0) {
            // c[hi] = aux[hi];
            return;
        }
        // if (hi - lo < 4) {
        //     CutOffSort<>::sort(c, lo, hi);
        //     return;
        // }
        auto const mid{(hi + lo)/2};

        // sort(aux, c, lo, mid);
        // if ((mid - lo == 2) && (hi - (mid + 1) == 1)) {
        //     sort(c, aux, mid+1, hi);
        //     for (auto i{mid+1}; i <= hi; i++) {
        //         aux[i] = c[i];
        //     }
        // } else if (((mid - lo) == 1) && (hi - (mid + 1) == 0)) {
        //     aux[hi] = c[hi];
        // } else {
        //     sort(aux, c, mid + 1, hi);
        // }

        sort(aux, c, lo, mid);
        std::cout << "std::ceil(std::log2(mid=" << mid <<  " - lo=" << lo << " + 1) = " << std::ceil(std::log2(mid - lo + 1)) <<  "; std::ceil(std::log2(hi=" << hi << " - mid=" << mid << " + 1)) = " << std::ceil(std::log2(hi - mid + 1)) << std::endl;
        if (std::ceil(std::log2(mid - lo)) > std::ceil(std::log2(hi - mid))) {
            sort(c, aux, mid+1, hi);
            for (auto i{mid+1}; i <= hi; i++) {
                aux[i] = c[i];
            }
        // if ((mid - lo == 2) && (hi - (mid + 1) == 1)) {
        //     sort(c, aux, mid+1, hi);
        //     for (auto i{mid+1}; i <= hi; i++) {
        //         aux[i] = c[i];
        //     }
        } else if (((mid - lo) == 1) && (hi - (mid + 1) == 0)) {
            aux[hi] = c[hi];
        } else {
            sort(aux, c, mid + 1, hi);
        }

        // if (mid - lo == 1 && (hi - (mid+1) == 0)) {
        //     sort(c, aux, lo, mid);
        //     c[hi] = aux[hi];
        //     std::cout << "merge(aux=" << aux << ", c=" << c << ", lo=" << lo << "; mid = " << mid << "; hi = " << hi << ")" << std::endl;        
        //     Merge<>::merge(callbacks, aux, c, lo, mid, hi);
        // } else {
        //     sort(aux, c, lo, mid);
        //     sort(aux, c, mid + 1, hi);
        //     std::cout << "merge(c=" << c << ", aux=" << aux << ", lo=" << lo << "; mid = " << mid << "; hi = " << hi << ")" << std::endl;        
        //     Merge<>::merge(callbacks, c, aux, lo, mid, hi);
        // }
        // if (hi == 2) {
        //     aux[hi] = c[hi];
        // } else {
        //     sort(aux, c, mid + 1, hi);
        // }
        // sort(aux, c, mid + 1, hi);
        // aux[hi] = c[hi];
        // if (c[mid] <= c[mid+1]) {
        //     return;
        // }

        // std::cout << "before merge(c, aux, lo, mid, hi)" << std::endl;
        // std::cout << "lo = " << lo << ", mid = " << mid << ", hi = " << hi << std::endl;
        // std::cout << "c = " << c << std::endl;
        // std::cout << "aux = " << aux << std::endl << std::endl;

        std::cout << "merge(c=" << c << ", aux=" << aux << ", lo=" << lo << "; mid = " << mid << "; hi = " << hi << ")" << std::endl;        
        Merge<>::merge(callbacks, c, aux, lo, mid, hi);
        
        // std::cout << "after merge(c, aux, lo, mid, hi)" << std::endl;
        // std::cout << "lo = " << lo << ", mid = " << mid << ", hi = " << hi << std::endl;
        // std::cout << "c = " << c << std::endl;
        // std::cout << "aux = " << aux << std::endl << std::endl << std::endl;

        std::cout << "end sort(c=" << c << ", aux=" << aux << ", lo=" << lo << "; hi = " << hi << ")" << std::endl;        
    }

    sort::Callbacks* callbacks{nullptr};
};
}