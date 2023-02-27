#pragma once

namespace sedgealgos::algorithms::union_find {
    class QuickUnionUnionFindWithCompressedPaths {
    public:
        QuickUnionUnionFindWithCompressedPaths(int n);
        ~QuickUnionUnionFindWithCompressedPaths();

        void connect(int p, int q);
        bool connected(int p, int q) const;

    private:
        int size;
        int* id;

        int find(int p) const;
    };
}
