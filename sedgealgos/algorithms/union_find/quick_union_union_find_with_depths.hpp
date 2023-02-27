#pragma once

namespace sedgealgos::algorithms::union_find {
    class QuickUnionUnionFindWithDepths {
    public:
        QuickUnionUnionFindWithDepths(int n);
        ~QuickUnionUnionFindWithDepths();

        void connect(int p, int q);
        bool connected(int p, int q) const;

    private:
        int size;
        int* id;
        int* sz;

        int find(int p) const;
    };
}
