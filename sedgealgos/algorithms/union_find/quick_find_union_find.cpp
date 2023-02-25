#include "sedgealgos/algorithms/union_find/quick_find_union_find.hpp"

namespace sedgelagos::algorithms::union_find {

    QuickFindUnionFind::QuickFindUnionFind(int n) {
        size = n;
        id = new int[n];
        for (int i{0}; i < n; i++) {
            id[i] = i;
        }
    }

    QuickFindUnionFind::~QuickFindUnionFind() {
        delete id;
    }

    void QuickFindUnionFind::connect(int p, int q) {
        auto p_root{find(p)};
        auto r_root{find(q)};

        if (p_root == r_root) return;

        for (int i{0}; i < size; i++) {
            if (id[i] == p_root) {
                id[i] = r_root;
            }
        }

        size--;
    }

    int QuickFindUnionFind::find(int p) const {
        return id[p];
    }

    bool QuickFindUnionFind::connected(int p, int q) const {
        return find(p) == find(q);
    }

    int QuickFindUnionFind::count() const {
        return size;
    }
}
