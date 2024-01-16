#include "sedgealgos/data_structures/symbol_table/binary_search_tree.hpp"
#include "sedgealgos/data_structures/symbol_table/red_black_tree.hpp"
#include "sedgealgos/data_structures/symbol_table/ordered_binary_search_symbol_table.hpp"
#include "sedgealgos/data_structures/symbol_table/sequential_search_symbol_table.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

template <typename T>
class UnorderedSymbolTableTest : public ::testing::Test {};

template <typename T>
class OrderedSymbolTableTest : public ::testing::Test {};

template <typename T>
class SelfBalancingSymbolTable : public ::testing::Test {};

TYPED_TEST_SUITE_P(UnorderedSymbolTableTest);
TYPED_TEST_SUITE_P(OrderedSymbolTableTest);
TYPED_TEST_SUITE_P(SelfBalancingSymbolTable);

TYPED_TEST_P(UnorderedSymbolTableTest, PutPlacesElementInSymbolTable) {
	TypeParam st{};

	st.put("test1", 1);
	ASSERT_EQ(st.get("test1"), 1);
}

TYPED_TEST_P(UnorderedSymbolTableTest, PutOverwritesValueOfExistingKey) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test1", 2);
	ASSERT_EQ(st.get("test1"), 2);
}

TYPED_TEST_P(UnorderedSymbolTableTest, ContainsReturnsTrueIfElementExists) {
	TypeParam st{};

	st.put("test1", 1);

	ASSERT_TRUE(st.contains("test1"));
}

TYPED_TEST_P(UnorderedSymbolTableTest, ContainsReturnsFalseIfSymbolTableIsEmpty) {
	TypeParam st{};

	ASSERT_FALSE(st.contains("test1"));
}

TYPED_TEST_P(UnorderedSymbolTableTest, ContainsReturnsFalseIfElementIsNotInSymbolTable) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 1);
	st.put("test3", 1);

	ASSERT_FALSE(st.contains("test4"));
}

TYPED_TEST_P(UnorderedSymbolTableTest, GetOnNonExistentKeyReturnsError) {
	TypeParam st{};

	ASSERT_THROW({ st.get("test1"); }, std::out_of_range);
}

TYPED_TEST_P(UnorderedSymbolTableTest, IsEmptyReturnsTrueWhenNoElementsInSymbolTable) {
	TypeParam st{};

	ASSERT_TRUE(st.is_empty());
}

TYPED_TEST_P(UnorderedSymbolTableTest, IsEmptyReturnsFalseWhenOneElementIsInSymbolTable) {
	TypeParam st{};

	st.put("test", 1);

	ASSERT_FALSE(st.is_empty());
}

TYPED_TEST_P(UnorderedSymbolTableTest, IsEmptyReturnsFalseWhenMoreThanOneElementIsInSymbolTable) {
	TypeParam st{};
	st.put("test", 1);
	st.put("test", 2);

	ASSERT_FALSE(st.is_empty());
}

TYPED_TEST_P(UnorderedSymbolTableTest, IsEmptyReturnsTrueWhenLastElementIsDeletedFromSymbolTable) {
	TypeParam st{};
	st.put("test", 1);
	st.del("test");

	ASSERT_TRUE(st.is_empty());
}

TYPED_TEST_P(UnorderedSymbolTableTest, IsEmptyReturnsFalseWhenElementIsDeletedFromSymbolTableWithMoreThanOneElements) {
	TypeParam st{};
	st.put("test1", 1);
	st.put("test2", 1);
	st.put("test3", 1);
	st.del("test2");

	ASSERT_FALSE(st.is_empty());
}

TYPED_TEST_P(UnorderedSymbolTableTest, DelKeyOnEmptySymbolTableDoesNothing) {
	TypeParam st{};
	ASSERT_NO_THROW({ st.del("test2"); });
}

TYPED_TEST_P(UnorderedSymbolTableTest, DelDecreasesSizeOfTheSymbolTable) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 1);
	st.put("test3", 1);

	ASSERT_EQ(st.size(), 3);

	st.del("test2");

	ASSERT_EQ(st.size(), 2);
}

TYPED_TEST_P(UnorderedSymbolTableTest, KeysAfterDelReturnIterableOfKeysWithoutDeletedKey) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 1);
	st.put("test3", 1);

	st.del("test3");

	ASSERT_THAT(st.keys(), ::testing::ElementsAre("test1", "test2"));
}

TYPED_TEST_P(UnorderedSymbolTableTest, ContainsForNReturnsFalseIfNWasDeletedAndNWasLastElement) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 1);
	st.put("test3", 1);

	st.del("test3");

	ASSERT_FALSE(st.contains("test3"));
}

TYPED_TEST_P(UnorderedSymbolTableTest, CallingDelSecondTimeOnTheSameElementDoesNothing) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 1);
	st.put("test3", 1);

	st.del("test3");
	st.del("test3");

	ASSERT_THAT(st.keys(), ::testing::ElementsAre("test1", "test2"));
}

TYPED_TEST_P(UnorderedSymbolTableTest, SizeReturnsZeroIfSymbolTableIsEmpty) {
	TypeParam st{};

	ASSERT_EQ(st.size(), 0);
}

TYPED_TEST_P(UnorderedSymbolTableTest, SizeReturnsNonZeroIfSymbolTableIsNotEmpty) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 1);

	ASSERT_EQ(st.size(), 2);
}

TYPED_TEST_P(UnorderedSymbolTableTest, KeysReturnsEmptyArrayIfSymbolTableIsEmpty) {
	TypeParam st{};

	ASSERT_TRUE(st.keys().is_empty());
}

TYPED_TEST_P(UnorderedSymbolTableTest, KeysReturnsArrayOfKeys) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 1);
	st.put("test3", 1);
	st.put("test4", 1);

	ASSERT_THAT(st.keys(), ::testing::ElementsAre("test1", "test2", "test3", "test4"));
}

TYPED_TEST_P(OrderedSymbolTableTest, RankReturnsIndexZeroWhenSymbolTableIsEmpty) {
	TypeParam st{};

	ASSERT_EQ(st.rank("test1"), 0);
}

TYPED_TEST_P(OrderedSymbolTableTest, RankReturnsLastIndexWhenKeyIsLargestInTheSymbolTable) {
	TypeParam st{};

	st.put("test1", 1);

	ASSERT_EQ(st.rank("test2"), 1);
}

TYPED_TEST_P(OrderedSymbolTableTest, RankReturnsLastIndexWhenKeyIsLowestInTheSymbolTable) {
	TypeParam st{};

	st.put("test2", 1);

	ASSERT_EQ(st.rank("test1"), 0);
}

TYPED_TEST_P(OrderedSymbolTableTest, RankReturnsNumberOfKeysLessThanGivenKey) {
	TypeParam st{};

	st.put("test8", 1);
	st.put("test7", 1);
	st.put("test4", 1);
	st.put("test3", 1);
	st.put("test2", 1);
	st.put("test1", 1);
	st.put("test0", 1);

	ASSERT_EQ(st.rank("test6"), 5);
}

TYPED_TEST_P(OrderedSymbolTableTest, SelectReturnsKeyForGivenRank) {
	TypeParam st{};

	st.put("test8", 1);
	st.put("test7", 1);
	st.put("test4", 1);
	st.put("test3", 1);
	st.put("test2", 1);
	st.put("test1", 1);
	st.put("test0", 1);

	ASSERT_EQ(st.select(2), "test2");
}

TYPED_TEST_P(OrderedSymbolTableTest, SelectThrowsAnErrorWhenThereIsNoKeyWithGivenRank) {
	GTEST_SKIP();

	TypeParam st{};

	ASSERT_THROW({ st.select(2); }, std::runtime_error);
}

TYPED_TEST_P(OrderedSymbolTableTest, MaxReturnsMaxElement) {
	TypeParam st{};

	st.put("test8", 1);
	st.put("test7", 1);
	st.put("test4", 1);

	ASSERT_EQ(st.max(), "test8");
}

TYPED_TEST_P(OrderedSymbolTableTest, MaxThrowsAnErrorWhenArrayIsEmpty) {
	GTEST_SKIP();

	TypeParam st{};

	ASSERT_THROW({ st.max(); }, std::runtime_error);
}

TYPED_TEST_P(OrderedSymbolTableTest, MinReturnsTheLowestElementInSymbolTable) {
	TypeParam st{};

	st.put("test8", 1);
	st.put("test7", 1);
	st.put("test4", 1);

	ASSERT_EQ(st.min(), "test4");
}

TYPED_TEST_P(OrderedSymbolTableTest, MinThrowsAnErrorWhenSymbolTableIsEmpty) {
	GTEST_SKIP();

	TypeParam st{};

	ASSERT_THROW({ st.min(); }, std::runtime_error);
}

TYPED_TEST_P(OrderedSymbolTableTest, FloorReturnsLargestKeyLessThanOrEqualToKey) {
	TypeParam st{};

	st.put("test8", 1);
	st.put("test7", 1);
	st.put("test4", 1);
	st.put("test2", 1);
	st.put("test3", 1);
	st.put("test1", 1);

	ASSERT_EQ(st.floor("test5"), "test4");
}

TYPED_TEST_P(OrderedSymbolTableTest, FloorThrowsExceptionWhenSymbolTableIsEmpty) {
	GTEST_SKIP();

	TypeParam st{};

	ASSERT_THROW({ st.floor("test5"); }, std::runtime_error);
}

TYPED_TEST_P(OrderedSymbolTableTest, CeilingReturnsLowestKeyLargetThanOrEqualToKey) {
	TypeParam st{};

	st.put("test8", 1);
	st.put("test7", 1);
	st.put("test4", 1);
	st.put("test2", 1);
	st.put("test3", 1);
	st.put("test1", 1);

	ASSERT_EQ(st.ceiling("test5"), "test7");
}

TYPED_TEST_P(OrderedSymbolTableTest, CeilingThrowsExceptionWhenSymbolTableIsEmpty) {
	GTEST_SKIP();

	TypeParam st{};

	ASSERT_THROW({ st.ceiling("test5"); }, std::runtime_error);
}

TYPED_TEST_P(OrderedSymbolTableTest, DeleteMinDeletesSmallestElement) {
	TypeParam st{};

	st.put("test8", 1);
	st.put("test7", 1);
	st.put("test4", 1);
	st.put("test2", 1);
	st.put("test3", 1);
	st.put("test1", 1);

	st.deleteMin();

	ASSERT_THAT(st.keys(), ::testing::ElementsAre("test2", "test3", "test4", "test7", "test8"));
}

TYPED_TEST_P(OrderedSymbolTableTest, DeleteMaxDeletesLargestElement) {
	TypeParam st{};

	st.put("test8", 1);
	st.put("test7", 1);
	st.put("test4", 1);
	st.put("test2", 1);
	st.put("test3", 1);
	st.put("test1", 1);

	st.deleteMax();

	ASSERT_THAT(st.keys(), ::testing::ElementsAre("test1", "test2", "test3", "test4", "test7"));
}

TYPED_TEST_P(OrderedSymbolTableTest, ContainsLastElementReturnFalseAfterDeleteMax) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 2);
	st.put("test3", 3);
	st.put("test4", 4);

	st.deleteMax();

	ASSERT_FALSE(st.contains("test4"));
}

TYPED_TEST_P(OrderedSymbolTableTest, RangeSizeReturnsNumberOfElementsEqualToBothSidesClosedRangeOfElementsBetweenKeys) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 2);
	st.put("test3", 3);
	st.put("test4", 4);
	st.put("test5", 5);
	st.put("test6", 6);
	st.put("test7", 7);
	st.put("test8", 8);

	EXPECT_THAT(st.keys("test2", "test6"), ::testing::ElementsAre("test2", "test3", "test4", "test5", "test6"));
	EXPECT_EQ(st.size("test2", "test6"), 5);
}

TYPED_TEST_P(OrderedSymbolTableTest, RangeSizeReturnsNumberOfElementsThatAreBetweenKeysButWithoutRightOne) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 2);
	st.put("test3", 3);
	st.put("test4", 4);
	st.put("test5", 5);
	st.put("test6", 6);
	st.put("test8", 8);

	EXPECT_THAT(st.keys("test2", "test7"), ::testing::ElementsAre("test2", "test3", "test4", "test5", "test6"));
	EXPECT_EQ(st.size("test2", "test7"), 5);
}

TYPED_TEST_P(OrderedSymbolTableTest, RangeSizeReturnsNumberOfElementsThatAreBetweenKeysButWithoutLeftOne) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test3", 3);
	st.put("test4", 4);
	st.put("test5", 5);
	st.put("test6", 6);
	st.put("test7", 7);
	st.put("test8", 8);

	EXPECT_EQ(st.size("test2", "test7"), 5);
}

TYPED_TEST_P(OrderedSymbolTableTest, RangeSizeReturnsNumberOfElementsThatAreBetweenKeysButWithoutLeftAndRightOne) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test3", 3);
	st.put("test4", 4);
	st.put("test5", 5);
	st.put("test6", 6);
	st.put("test7", 7);
	st.put("test9", 7);

	EXPECT_THAT(st.keys("test2", "test8"), ::testing::ElementsAre("test3", "test4", "test5", "test6", "test7"));
	EXPECT_EQ(st.size("test2", "test8"), 5);
}

TYPED_TEST_P(OrderedSymbolTableTest, RangeSizeReturnsOneIfLoAndHiAreEqualAndInTheRange) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test3", 3);
	st.put("test4", 4);
	st.put("test5", 5);
	st.put("test6", 6);
	st.put("test7", 7);
	st.put("test9", 7);

	EXPECT_THAT(st.keys("test3", "test3"), ::testing::ElementsAre("test3"));
	EXPECT_EQ(st.size("test3", "test3"), 1);
}

TYPED_TEST_P(OrderedSymbolTableTest, RangeSizeReturnsZeroIfLoAndHiAreEqualAndNotInTheRange) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test3", 3);
	st.put("test4", 4);
	st.put("test5", 5);
	st.put("test6", 6);
	st.put("test7", 7);
	st.put("test9", 7);

	EXPECT_THAT(st.keys("test2", "test2"), ::testing::ElementsAre());
	EXPECT_EQ(st.size("test2", "test2"), 0);
}

TYPED_TEST_P(OrderedSymbolTableTest, RangeSizeReturnsSizeOfTheArrayIfLoIsEqualToFirstElemAndHiIsEqualToLastElem) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test3", 3);
	st.put("test4", 4);
	st.put("test5", 5);
	st.put("test6", 6);
	st.put("test7", 7);
	st.put("test9", 7);

	EXPECT_THAT(st.keys("test1", "test9"), ::testing::ElementsAre("test1", "test3", "test4", "test5", "test6", "test7", "test9"));
	EXPECT_EQ(st.size("test1", "test9"), 7);
}

TYPED_TEST_P(SelfBalancingSymbolTable, PutTwoElementsInIncreasingOrder) {
	TypeParam st{};

	st.put("test1", 1);
	st.put("test2", 2);
	ASSERT_TRUE(st.balanced());

	ASSERT_EQ(st.get("test1"), 1);
	ASSERT_EQ(st.get("test2"), 2);
	ASSERT_EQ(st.size(), 2);
}


TYPED_TEST_P(SelfBalancingSymbolTable, PutThreeElementsInIncreasingOrder) {
	TypeParam st{};

	st.put("a", 1);
	st.put("b", 2);
	st.put("c", 3);
	ASSERT_TRUE(st.balanced());

	ASSERT_EQ(st.get("a"), 1);
	ASSERT_EQ(st.get("b"), 2);
	ASSERT_EQ(st.get("c"), 3);

	ASSERT_EQ(st.size(), 3);
}

TYPED_TEST_P(SelfBalancingSymbolTable, PutFiveElementsInIncreasingOrder) {
	TypeParam st{};

	st.put("a", 1);
	st.put("b", 2);
	st.put("c", 3);
	st.put("d", 4);
	st.put("e", 5);
	ASSERT_TRUE(st.balanced());

	ASSERT_EQ(st.get("a"), 1);
	ASSERT_EQ(st.get("b"), 2);
	ASSERT_EQ(st.get("c"), 3);
	ASSERT_EQ(st.get("d"), 4);
	ASSERT_EQ(st.get("e"), 5);
	ASSERT_EQ(st.size(), 5);
}

TYPED_TEST_P(SelfBalancingSymbolTable, PutSevenElementsInIncreasingOrder) {
	TypeParam st{};

	st.put("a", 1);
	st.put("b", 2);
	st.put("c", 3);
	st.put("d", 4);
	st.put("e", 5);
	st.put("f", 6);
	st.put("g", 7);
	ASSERT_TRUE(st.balanced());

	ASSERT_EQ(st.get("a"), 1);
	ASSERT_EQ(st.get("b"), 2);
	ASSERT_EQ(st.get("c"), 3);
	ASSERT_EQ(st.get("d"), 4);
	ASSERT_EQ(st.get("e"), 5);
	ASSERT_EQ(st.get("f"), 6);
	ASSERT_EQ(st.get("g"), 7);
	ASSERT_EQ(st.size(), 7);
}

TYPED_TEST_P(SelfBalancingSymbolTable, PutThreeElementsInDecreasingOrder) {
	TypeParam st{};

	st.put("c", 3);
	st.put("b", 2);
	st.put("a", 1);
	ASSERT_TRUE(st.balanced());

	ASSERT_EQ(st.get("a"), 1);
	ASSERT_EQ(st.get("b"), 2);
	ASSERT_EQ(st.get("c"), 3);
	ASSERT_EQ(st.size(), 3);
}

TYPED_TEST_P(SelfBalancingSymbolTable, PutFiveElementsInDecreasingOrder) {
	TypeParam st{};

	st.put("e", 5);
	st.put("d", 4);
	st.put("c", 3);
	st.put("b", 2);
	st.put("a", 1);
	ASSERT_TRUE(st.balanced());

	ASSERT_EQ(st.get("a"), 1);
	ASSERT_EQ(st.get("b"), 2);
	ASSERT_EQ(st.get("c"), 3);
	ASSERT_EQ(st.get("d"), 4);
	ASSERT_EQ(st.get("e"), 5);
	ASSERT_EQ(st.size(), 5);
}

TYPED_TEST_P(SelfBalancingSymbolTable, PutSevenElementsInDecreasingOrder) {
	TypeParam st{};

	st.put("g", 7);
	st.put("f", 6);
	st.put("e", 5);
	st.put("d", 4);
	st.put("c", 3);
	st.put("b", 2);
	st.put("a", 1);
	ASSERT_TRUE(st.balanced());

	ASSERT_EQ(st.get("a"), 1);
	ASSERT_EQ(st.get("b"), 2);
	ASSERT_EQ(st.get("c"), 3);
	ASSERT_EQ(st.get("d"), 4);
	ASSERT_EQ(st.get("e"), 5);
	ASSERT_EQ(st.get("f"), 6);
	ASSERT_EQ(st.get("g"), 7);
	ASSERT_EQ(st.size(), 7);
}

TYPED_TEST_P(SelfBalancingSymbolTable, PutSevenElementsSoThatMiddleNodeGetsFilled) {
	TypeParam st{};

	st.put("a", 1);
	st.put("k", 2);
	st.put("u", 3);
	st.put("r", 4);
	st.put("n", 5);
	st.put("i", 6);
	st.put("j", 7);
	ASSERT_TRUE(st.balanced());

	ASSERT_EQ(st.get("a"), 1);
	ASSERT_EQ(st.get("k"), 2);
	ASSERT_EQ(st.get("u"), 3);
	ASSERT_EQ(st.get("r"), 4);
	ASSERT_EQ(st.get("n"), 5);
	ASSERT_EQ(st.get("i"), 6);
	ASSERT_EQ(st.get("j"), 7);
	ASSERT_EQ(st.size(), 7);
}

REGISTER_TYPED_TEST_SUITE_P(UnorderedSymbolTableTest,
			    DelKeyOnEmptySymbolTableDoesNothing,
			    IsEmptyReturnsFalseWhenElementIsDeletedFromSymbolTableWithMoreThanOneElements,
 			    IsEmptyReturnsTrueWhenLastElementIsDeletedFromSymbolTable,
			    IsEmptyReturnsFalseWhenMoreThanOneElementIsInSymbolTable,
			    IsEmptyReturnsFalseWhenOneElementIsInSymbolTable,
			    IsEmptyReturnsTrueWhenNoElementsInSymbolTable,
			    PutPlacesElementInSymbolTable,
			    GetOnNonExistentKeyReturnsError,
			    PutOverwritesValueOfExistingKey,
			    ContainsReturnsTrueIfElementExists,
			    ContainsReturnsFalseIfSymbolTableIsEmpty,
			    ContainsReturnsFalseIfElementIsNotInSymbolTable,
			    ContainsForNReturnsFalseIfNWasDeletedAndNWasLastElement,
			    KeysAfterDelReturnIterableOfKeysWithoutDeletedKey,
			    SizeReturnsZeroIfSymbolTableIsEmpty,
			    SizeReturnsNonZeroIfSymbolTableIsNotEmpty,
			    DelDecreasesSizeOfTheSymbolTable,
			    CallingDelSecondTimeOnTheSameElementDoesNothing,
			    KeysReturnsEmptyArrayIfSymbolTableIsEmpty,
			    KeysReturnsArrayOfKeys
			    );

REGISTER_TYPED_TEST_SUITE_P(OrderedSymbolTableTest,
			    RankReturnsIndexZeroWhenSymbolTableIsEmpty,
			    RankReturnsLastIndexWhenKeyIsLargestInTheSymbolTable,
			    RankReturnsLastIndexWhenKeyIsLowestInTheSymbolTable,
			    RankReturnsNumberOfKeysLessThanGivenKey,
			    SelectReturnsKeyForGivenRank,
			    SelectThrowsAnErrorWhenThereIsNoKeyWithGivenRank,
		            MaxReturnsMaxElement,
			    MaxThrowsAnErrorWhenArrayIsEmpty,
			    MinReturnsTheLowestElementInSymbolTable,
			    MinThrowsAnErrorWhenSymbolTableIsEmpty,
			    FloorReturnsLargestKeyLessThanOrEqualToKey,
			    FloorThrowsExceptionWhenSymbolTableIsEmpty,
			    CeilingReturnsLowestKeyLargetThanOrEqualToKey,
			    CeilingThrowsExceptionWhenSymbolTableIsEmpty,
			    DeleteMinDeletesSmallestElement,
			    DeleteMaxDeletesLargestElement,
			    ContainsLastElementReturnFalseAfterDeleteMax,
			    RangeSizeReturnsNumberOfElementsEqualToBothSidesClosedRangeOfElementsBetweenKeys,
			    RangeSizeReturnsNumberOfElementsThatAreBetweenKeysButWithoutRightOne,
			    RangeSizeReturnsNumberOfElementsThatAreBetweenKeysButWithoutLeftOne,
			    RangeSizeReturnsNumberOfElementsThatAreBetweenKeysButWithoutLeftAndRightOne,
			    RangeSizeReturnsOneIfLoAndHiAreEqualAndInTheRange,
			    RangeSizeReturnsZeroIfLoAndHiAreEqualAndNotInTheRange,
			    RangeSizeReturnsSizeOfTheArrayIfLoIsEqualToFirstElemAndHiIsEqualToLastElem
			   );

REGISTER_TYPED_TEST_SUITE_P(SelfBalancingSymbolTable,
		            PutTwoElementsInIncreasingOrder,
			    PutThreeElementsInIncreasingOrder,
			    PutFiveElementsInIncreasingOrder,
			    PutSevenElementsInIncreasingOrder,
			    PutThreeElementsInDecreasingOrder,
			    PutFiveElementsInDecreasingOrder,
			    PutSevenElementsInDecreasingOrder,
			    PutSevenElementsSoThatMiddleNodeGetsFilled
			   );



using SISSST = sedgealgos::data_structures::symbol_table::SequentialSearchSymbolTable<std::string, int>;
using OBSST = sedgealgos::data_structures::symbol_table::OrderedBinarySearchSymbolTable<std::string, int>;
using BST = sedgealgos::data_structures::symbol_table::BinarySearchTree<std::string, int>;
using RBT = sedgealgos::data_structures::symbol_table::RedBlackTree<std::string, int>;

INSTANTIATE_TYPED_TEST_SUITE_P(SISSST, UnorderedSymbolTableTest, SISSST);
INSTANTIATE_TYPED_TEST_SUITE_P(OBSST, UnorderedSymbolTableTest, OBSST);
INSTANTIATE_TYPED_TEST_SUITE_P(OBSST, OrderedSymbolTableTest, OBSST);
INSTANTIATE_TYPED_TEST_SUITE_P(BST, UnorderedSymbolTableTest, BST);
INSTANTIATE_TYPED_TEST_SUITE_P(BST, OrderedSymbolTableTest, BST);
INSTANTIATE_TYPED_TEST_SUITE_P(RBT, UnorderedSymbolTableTest, RBT);
INSTANTIATE_TYPED_TEST_SUITE_P(RBT, OrderedSymbolTableTest, RBT);
INSTANTIATE_TYPED_TEST_SUITE_P(RBT, SelfBalancingSymbolTable, RBT);
