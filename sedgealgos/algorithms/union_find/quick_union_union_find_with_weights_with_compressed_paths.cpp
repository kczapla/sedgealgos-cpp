#include "sedgealgos/algorithms/union_find/quick_union_union_find_with_weights_with_compressed_paths.hpp"

namespace sedgelagos::algorithms::union_find {

    QuickUnionUnionFindWithWeightsWithCompressedPaths::QuickUnionUnionFindWithWeightsWithCompressedPaths(int n) {
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

    QuickUnionUnionFindWithWeightsWithCompressedPaths::~QuickUnionUnionFindWithWeightsWithCompressedPaths() {
        delete id;
        delete sz;
    }

    void QuickUnionUnionFindWithWeightsWithCompressedPaths::connect(int p, int q) {
        auto p_root{find(p)};
        auto q_root{find(q)};

        if (p_root == q_root) return;

        auto root{p_root};
        if (sz[p_root] < sz[q_root]) {
            root = q_root;
            id[p_root] = q_root;
            sz[q_root] += sz[p_root];
        } else {
            id[q_root] = p_root;
            sz[p_root] += sz[q_root];
        }

        auto next_jump{p};
        while(next_jump != id[next_jump]) {
            auto const index_to_change{next_jump};
            next_jump = id[next_jump];
            id[index_to_change] = root;
        }

        next_jump = q;
        while(next_jump != id[next_jump]) {
            auto const index_to_change{next_jump};
            next_jump = id[next_jump];
            id[index_to_change] = root;
        }
        
        size--;
    }

    int QuickUnionUnionFindWithWeightsWithCompressedPaths::find(int p) const {
        auto root{p};
        while(id[root] != root) root = id[root];

        return root;
    }

    bool QuickUnionUnionFindWithWeightsWithCompressedPaths::connected(int p, int q) const {
        return find(p) == find(q);
    }
}
