#include "sedgealgos/algorithms/union_find/quick_union_union_find_with_depths.hpp"

namespace sedgelagos::algorithms::union_find {

    QuickUnionUnionFindWithDepths::QuickUnionUnionFindWithDepths(int n) {
        size = n;
        id = new int[n];
        sz = new int[n];
        for (int i{0}; i < n; i++) {
            id[i] = i;
        }
        for (int i{0}; i < n; i++) {
            sz[i] = 1;
        }
    }

    QuickUnionUnionFindWithDepths::~QuickUnionUnionFindWithDepths() {
        delete id;
        delete sz;
    }

    void QuickUnionUnionFindWithDepths::connect(int p, int q) {
        auto p_root{find(p)};
        auto q_root{find(q)};

        if (p_root == q_root) return;

        if (sz[p_root] < sz[q_root]) {
            id[p_root] = q_root;
        } else {
            id[q_root] = p_root;
            if (sz[p_root] == sz[q_root]) {
                sz[p_root] += 1;
            }
        }

        size--;
    }

    int QuickUnionUnionFindWithDepths::find(int p) const {
        while(id[p] != p) p = id[p];
        return p;
    }

    bool QuickUnionUnionFindWithDepths::connected(int p, int q) const {
        return find(p) == find(q);
    }
}
