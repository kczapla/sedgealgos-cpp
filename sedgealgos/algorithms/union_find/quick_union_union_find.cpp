#include "sedgealgos/algorithms/union_find/quick_union_union_find.hpp"

namespace sedgealgos::algorithms::union_find {

    QuickUnionUnionFind::QuickUnionUnionFind(int n) {
        size = n;
        id = new int[n];
        for (int i{0}; i < n; i++) {
            id[i] = i;
        }
    }

    QuickUnionUnionFind::~QuickUnionUnionFind() {
        delete id;
    }

    void QuickUnionUnionFind::connect(int p, int q) {
        auto p_root{find(p)};
        auto r_root{find(q)};

        if (p_root == r_root) return;

        id[p_root] = r_root;
        
        size--;
    }

    int QuickUnionUnionFind::find(int p) const {
        while(id[p] != p) p = id[p];
        return p;
    }

    bool QuickUnionUnionFind::connected(int p, int q) const {
        return find(p) == find(q);
    }

    int QuickUnionUnionFind::count() const {
        return size;
    }
}
