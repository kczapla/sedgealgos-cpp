#include "sedgealgos/algorithms/union_find/quick_union_union_find_with_weights.hpp"

namespace sedgelagos::algorithms::union_find {

    QuickUnionUnionFindWithWeights::QuickUnionUnionFindWithWeights(int n) {
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

    QuickUnionUnionFindWithWeights::~QuickUnionUnionFindWithWeights() {
        delete id;
        delete sz;
    }

    void QuickUnionUnionFindWithWeights::connect(int p, int q) {
        auto p_root{find(p)};
        auto q_root{find(q)};

        if (p_root == q_root) return;

        if (sz[p_root] < sz[q_root]) {
            id[p_root] = q_root;
            sz[q_root] += sz[p_root];
        } else {
            id[q_root] = p_root;
            sz[p_root] += sz[q_root];
        }
        size--;
    }

    int QuickUnionUnionFindWithWeights::find(int p) const {
        while(id[p] != p) p = id[p];
        return p;
    }

    bool QuickUnionUnionFindWithWeights::connected(int p, int q) const {
        return find(p) == find(q);
    }
}
