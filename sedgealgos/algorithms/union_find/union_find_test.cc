#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "quick_find_union_find.hpp"
#include "sedgealgos/algorithms/union_find/quick_find_union_find.hpp"

#include <stdexcept>

namespace {
    using namespace ::testing;
    using namespace ::sedgelagos::algorithms::union_find;

    template <typename T>
    class UnionFindTest : public ::testing::Test {};

    TYPED_TEST_SUITE_P(UnionFindTest);

    TYPED_TEST_P(UnionFindTest, NoPointsAreConnectedIfZeroUnionsWerePerformed) {
        TypeParam union_find{10};

        ASSERT_FALSE(union_find.connected(3, 2));
    }

    TYPED_TEST_P(UnionFindTest, DetectsConnectionBetweenTwoElemsAfterSingleUnion) {
        TypeParam union_find{10};
        union_find.connect(3, 2);

        ASSERT_TRUE(union_find.connected(3, 2));
        ASSERT_TRUE(union_find.connected(2, 3));
    }

    TYPED_TEST_P(UnionFindTest, NotAllPointsAreConnectedAfterSomeUnionOperations) {
        TypeParam union_find{10};
        union_find.connect(3, 2);
        union_find.connect(4, 2);
        union_find.connect(1, 5);

        ASSERT_FALSE(union_find.connected(1, 6));
    }

    TYPED_TEST_P(UnionFindTest, ConnectsAllPoints) {
        TypeParam union_find{10};
        union_find.connect(0, 1);
        union_find.connect(1, 2);
        union_find.connect(2, 3);
        union_find.connect(3, 4);
        union_find.connect(4, 5);
        union_find.connect(5, 6);
        union_find.connect(6, 7);
        union_find.connect(7, 8);
        union_find.connect(8, 9);

        ASSERT_TRUE(union_find.connected(0, 9));
    }

    TYPED_TEST_P(UnionFindTest, ConnectsRandomPoints) {
        TypeParam union_find{10};
        union_find.connect(4, 3);
        union_find.connect(3, 8);
        union_find.connect(6, 5);
        union_find.connect(9, 4);
        union_find.connect(2, 1);

        ASSERT_TRUE(union_find.connected(8, 9));

        union_find.connect(5, 0);
        union_find.connect(7, 2);
        union_find.connect(6, 1);

        ASSERT_TRUE(union_find.connected(1, 0));
        ASSERT_TRUE(union_find.connected(6, 7));
    }

    REGISTER_TYPED_TEST_SUITE_P(
            UnionFindTest,
            NoPointsAreConnectedIfZeroUnionsWerePerformed,
            DetectsConnectionBetweenTwoElemsAfterSingleUnion,
            NotAllPointsAreConnectedAfterSomeUnionOperations,
            ConnectsAllPoints,
            ConnectsRandomPoints
    );

    INSTANTIATE_TYPED_TEST_SUITE_P(QuickFind, UnionFindTest, QuickFindUnionFind);
}
