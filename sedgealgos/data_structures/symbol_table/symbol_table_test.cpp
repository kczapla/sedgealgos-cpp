#include "sedgealgos/data_structures/symbol_table/ordered_binary_search_symbol_table.hpp"
#include "sedgealgos/data_structures/symbol_table/sequential_search_symbol_table.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

template <typename T>
class UnorderedSymbolTableTest : public ::testing::Test {};

template <typename T>
class OrderedSymbolTableTest : public ::testing::Test {};

TYPED_TEST_SUITE_P(UnorderedSymbolTableTest);
TYPED_TEST_SUITE_P(OrderedSymbolTableTest);

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

	ASSERT_THROW({ st.get("test1"); }, std::out_of_range);
}

TYPED_TEST_P(OrderedSymbolTableTest, DeleteMaxDeletesBiggestElement) {
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
			    DeleteMaxDeletesBiggestElement,
			    ContainsLastElementReturnFalseAfterDeleteMax
			   );

using SISSST = sedgealgos::data_structures::symbol_table::SequentialSearchSymbolTable<std::string, int>;
using OBSST = sedgealgos::data_structures::symbol_table::OrderedBinarySearchSymbolTable<std::string, int>;

INSTANTIATE_TYPED_TEST_SUITE_P(SISSST, UnorderedSymbolTableTest, SISSST);
INSTANTIATE_TYPED_TEST_SUITE_P(OBSST, UnorderedSymbolTableTest, OBSST);
INSTANTIATE_TYPED_TEST_SUITE_P(OBSST, OrderedSymbolTableTest, OBSST);
