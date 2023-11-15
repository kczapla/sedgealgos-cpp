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

	Key select(int const rank) const {
		return keys[rank];
	}

	void put(Key key, Value value) {
		auto const new_key_index{rank(key)};

		array::Array<Key> new_keys(keys.size() + 1);
		array::Array<Value> new_values(values.size() + 1);

		for (long long unsigned int i{0}; i < new_key_index; ++i) {
			new_keys[i] = keys[i];
			new_values[i] = values[i];
		}

		new_keys[new_key_index] = key;
		new_values[new_key_index] = value;

		for (auto i{new_key_index}; i < keys.size(); i++) {
			new_keys[i+1] = keys[i];
			new_values[i+1] = values[i];
		}

		keys = new_keys;
		values = new_values;

	}

	Key max() const {
		return keys[keys.size() - 1];
	}

	Key min() const {
		return keys[0];
	}

private:
	array::Array<Key> keys;
	array::Array<Value> values;
};
}
