#pragma once

namespace sedgealgos::algorithms::union_find {
    class QuickUnionUnionFind {
    public:
        QuickUnionUnionFind(int n);
        ~QuickUnionUnionFind();

        void connect(int p, int q);
        bool connected(int p, int q) const;

        int count() const;

    private:
        int size;
        int* id;

        int find(int p) const;
    };
}
