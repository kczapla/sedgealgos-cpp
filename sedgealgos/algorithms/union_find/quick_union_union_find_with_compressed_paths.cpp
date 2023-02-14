#include "sedgealgos/algorithms/union_find/quick_union_union_find_with_compressed_paths.hpp"

namespace sedgelagos::algorithms::union_find {

    QuickUnionUnionFindWithCompressedPaths::QuickUnionUnionFindWithCompressedPaths(int n) {
        size = n;
        id = new int[n];
        for (int i{0}; i < n; i++) {
            id[i] = i;
        }
    }

    QuickUnionUnionFindWithCompressedPaths::~QuickUnionUnionFindWithCompressedPaths() {
        delete id;
    }

    void QuickUnionUnionFindWithCompressedPaths::connect(int p, int q) {
        auto p_root{find(p)};
        auto r_root{find(q)};

        if (p_root == r_root) return;

        id[p_root] = r_root;
    }

    int QuickUnionUnionFindWithCompressedPaths::find(int p) const {
        auto next_jump{p};

        while(id[p] != p) p = id[p];

        while(next_jump != id[next_jump]) {
            auto const index_to_change{next_jump};
            next_jump = id[next_jump];
            id[index_to_change] = p;
        }

        return p;
    }

    bool QuickUnionUnionFindWithCompressedPaths::connected(int p, int q) const {
        return find(p) == find(q);
    }
}
