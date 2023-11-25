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
		return keys_.is_empty();
	}

	Size size() const {
		return keys_.size();
	}

	Size size(Key const lo, Key const hi) const {
		return keys(lo, hi).size();
	}

	Size rank(Key key) const {
		Size lo{0};
		Size hi{size()};

		while (lo != hi) {
			auto mid{(hi + lo)/2};
			
			if (keys_[mid] == key) {
				return mid;
			}

			if (keys_[mid] < key) {
				lo = mid + 1;
				continue;
			}

			hi = mid;
		}

		return lo;
	}

	Key select(int const rank) const {
		return keys_[rank];
	}

	void put(Key key, Value value) {
		auto const new_key_index{rank(key)};

		if (keys_[new_key_index] == key) {
			values[new_key_index] = value;
		}

		array::Array<Key> new_keys(keys_.size() + 1);
		array::Array<Value> new_values(values.size() + 1);

		for (long long unsigned int i{0}; i < new_key_index; ++i) {
			new_keys[i] = keys_[i];
			new_values[i] = values[i];
		}

		new_keys[new_key_index] = key;
		new_values[new_key_index] = value;

		for (auto i{new_key_index}; i < keys_.size(); i++) {
			new_keys[i+1] = keys_[i];
			new_values[i+1] = values[i];
		}

		keys_ = new_keys;
		values = new_values;

	}

	Value get(Key key) const {
		auto const index{rank(key)};
		if (keys_[index] == key) {
			return values[index];
		}

		throw std::out_of_range{"given key does not exist"};
	}

	Key max() const {
		return keys_[keys_.size() - 1];
	}

	Key min() const {
		return keys_[0];
	}

	Key floor(Key key) const {
		return keys_[rank(key)-1];
	}

	Key ceiling(Key key) const {
		return keys_[rank(key)];
	}

	void deleteMin() {
		keys_.remove(0);
		values.remove(0);
	}

	void del(Key key) {
		auto const index{rank(key)};
		if (index >= keys_.size() || keys_[index] != key) {
			return;
		}
		keys_.remove(index);
		values.remove(index);
	}

	void deleteMax() {
		auto const last_element_index{keys_.size() - 1};
		keys_.remove(last_element_index);
		values.remove(last_element_index);
	}

	bool contains(Key key) const {
		auto const index{rank(key)};
		if (index < keys_.size() && keys_[index] == key) {
			return true;
		}
		return false;
	}

	array::Array<Key> keys() const {
		return keys_;
	}

	array::Array<Key> keys(Key lo, Key hi) const {
		auto const all_keys{keys()};

		auto const lo_index{rank(lo)};
		auto const hi_index{rank(hi)};

		auto first{keys_.begin() + lo_index};
		auto last{keys_.begin() + hi_index};

		if (*last == hi) {
			last++;
		}

		return array::Array<Key>(first, last);
	}

private:
	array::Array<Key> keys_;
	array::Array<Value> values;
};
}
