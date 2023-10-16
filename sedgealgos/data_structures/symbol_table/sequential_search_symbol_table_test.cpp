#include "sedgealgos/data_structures/symbol_table/sequential_search_symbol_table.hpp"
#include "sedgealgos/data_structures/symbol_table/symbol_table_test.hpp"

#include <string>

namespace {
	using SISSST = sedgealgos::data_structures::symbol_table::SequentialSearchSymbolTable<std::string, int>;
}

INSTANTIATE_TYPED_TEST_SUITE_P(ST, UnorderedSymbolTableTest, SISSST);
