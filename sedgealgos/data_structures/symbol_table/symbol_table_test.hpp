#include <gtest/gtest.h>

#include <string>

template <typename T>
class UnorderedSymbolTableTest : public ::testing::Test {
};

TYPED_TEST_SUITE_P(UnorderedSymbolTableTest);

TYPED_TEST_P(UnorderedSymbolTableTest, IsEmptyReturnsTrueWhenNoElementsInSymbolTable) {
	TypeParam st{};

	ASSERT_TRUE(st.is_empty());
}

TYPED_TEST_P(UnorderedSymbolTableTest, IsEmptyReturnsFalseWhenAtLeastOneElementIsInSymbolTable) {
	TypeParam st{};

	st.put("test", 1);

	ASSERT_FALSE(st.is_empty());
}

REGISTER_TYPED_TEST_SUITE_P(UnorderedSymbolTableTest,
			    IsEmptyReturnsFalseWhenAtLeastOneElementIsInSymbolTable,
			    IsEmptyReturnsTrueWhenNoElementsInSymbolTable);
