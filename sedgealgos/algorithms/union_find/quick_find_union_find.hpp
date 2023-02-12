#pragma once

namespace sedgelagos::algorithms::union_find {
    class QuickFindUnionFind {
    public:
        QuickFindUnionFind(int n);
        ~QuickFindUnionFind();

        void connect(int p, int q);
        bool connected(int p, int q) const;

    private:
        int size;
        int* id;

        int find(int p) const;
    };
}
