#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

#include <stdexcept>

namespace sedgealgos::data_structures::symbol_table {

template <typename Key, typename Value>
class OrderedBinarySearchSymbolTable {
public:
	using Size = unsigned long long;

	OrderedBinarySearchSymbolTable() {}

	bool is_empty() const {
		return keys.is_empty();
	}

	Size size() const {
		return keys.size();
	}

	Size rank(Key key) const {
		Size lo{0};
		Size hi{size()};

		while (lo != hi) {
			auto mid{(hi + lo)/2};
			
			if (keys[mid] == key) {
				return mid;
			}

			if (keys[mid] < key) {
				lo = mid + 1;
				continue;
			}

			hi = mid;
		}

		return lo;
	}

private:
	array::Array<Key> keys;
	array::Array<Value> values;
};
}
