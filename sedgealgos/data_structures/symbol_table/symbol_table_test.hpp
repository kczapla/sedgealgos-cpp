#include <gtest/gtest.h>

#include <string>

template <typename T>
class UnorderedSymbolTableTest : public ::testing::Test {
protected:
};

TYPED_TEST_SUITE_P(UnorderedSymbolTableTest);

TYPED_TEST_P(UnorderedSymbolTableTest, PutPlacesElementInSymbolTable) {
	TypeParam st{};

	st.put("test1", 1);
	ASSERT_EQ(st.get("test1"), 1);
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

	ASSERT_TRUE(st.is_empty());
}

TYPED_TEST_P(UnorderedSymbolTableTest, DelKeyOnEmptySymbolTableDoesNothing) {
	TypeParam st{};
	ASSERT_NO_THROW({ st.del("test2"); });
}

REGISTER_TYPED_TEST_SUITE_P(UnorderedSymbolTableTest,
			    DelKeyOnEmptySymbolTableDoesNothing,
			    IsEmptyReturnsFalseWhenElementIsDeletedFromSymbolTableWithMoreThanOneElements,
 			    IsEmptyReturnsTrueWhenLastElementIsDeletedFromSymbolTable,
			    IsEmptyReturnsFalseWhenMoreThanOneElementIsInSymbolTable,
			    IsEmptyReturnsFalseWhenOneElementIsInSymbolTable,
			    IsEmptyReturnsTrueWhenNoElementsInSymbolTable,
			    PutPlacesElementInSymbolTable
			    );
