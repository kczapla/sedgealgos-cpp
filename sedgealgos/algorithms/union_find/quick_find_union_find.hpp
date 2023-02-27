#pragma once

namespace sedgealgos::algorithms::union_find {
    class QuickFindUnionFind {
    public:
        QuickFindUnionFind(int n);
        ~QuickFindUnionFind();

        void connect(int p, int q);
        bool connected(int p, int q) const;

        int count() const;

    private:
        int size;
        int trees_count;
        int* id;

        int find(int p) const;
    };
}
