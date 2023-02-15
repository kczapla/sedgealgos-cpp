#pragma once

namespace sedgelagos::algorithms::union_find {
    class QuickUnionUnionFindWithWeights {
    public:
        QuickUnionUnionFindWithWeights(int n);
        ~QuickUnionUnionFindWithWeights();

        void connect(int p, int q);
        bool connected(int p, int q) const;

    private:
        int size;
        int* id;
        int* sz;

        int find(int p) const;
    };
}
