#include <gtest/gtest.h>

template <typename T>
class SymbolTableTest : public ::testing::Test {
};

TYPED_TEST_SUITE_P(SymbolTableTest);

TYPED_TEST_P(SymbolTableTest, IsEmptyReturnsTrueWhenNoElementsInSymbolTable) {
	TypeParam st{};

	ASSERT_TRUE(st.is_empty());
}

REGISTER_TYPED_TEST_SUITE_P(SymbolTableTest,
			    IsEmptyReturnsTrueWhenNoElementsInSymbolTable);
