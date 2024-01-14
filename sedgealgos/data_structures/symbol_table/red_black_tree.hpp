#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

#include <stdexcept>

namespace sedgealgos::data_structures::symbol_table {

template <typename Key, typename Value>
class RedBlackTree {
public:
	using Size = unsigned long long;

	void put(Key key, Value value) {
		put(&root, key, value);
	}

	Value get(Key key) const {
		auto const node{get(root, key)};
		if (!node) {
			throw std::out_of_range{"given key does not exist"};
		}
		return node->value;
	}

	bool is_empty() const {
		return size(root) == 0;
	}

	void del(Key key) {
		if (!root) {
			return;
		}
		root = del(root, key);
	}

	void deleteMin() {
		if (!root) {
			return;
		}
		root = deleteMin(root);
	}

	void deleteMax() {
		if (!root) {
			return;
		}
		root = deleteMax(root);
	}

	Size rank(Key key) const {
		return rank(root, key);
	}

	Key select(Size i) const {
		return select(root, i)->key;
	}

	Key min() const {
		return min(root)->key;
	}

	Key max() const {
		return max(root)->key;
	}

	Key floor(Key key) const {
		return floor(root, key)->key;
	}

	Key ceiling(Key key) const {
		return ceiling(root, key)->key;
	}

	Size size() const {
		return size(root);
	}

	Size size(Key from, Key to) const {
		array::Array<Key> arr;
		keys(root, arr, from, to);

		return arr.size();
	}

	bool contains(Key key) const {
		auto const node{get(root, key)};

		return node ? true : false;
	}

	array::Array<Key> keys() const {
		array::Array<Key> arr;

		if (!root) {
			return arr;
		}

		keys(root, arr, min(), max());

		return arr;
	}

	array::Array<Key> keys(Key from, Key to) const {
		array::Array<Key> arr;
		keys(root, arr, from, to);
		return arr;
	}

private:
	struct Node {
		using Color = bool;
		static const Color RED = true;
		static const Color BLACK = false;

		Key key;
		Value value;
		Node* left;
		Node* right;
		Size size;
		bool color;

		bool is_red() const {
			return color;
		}
	};



	void put(Node** node, Key key, Value value) {
	}

	Node* get(Node* node, Key key) const {
		return nullptr;
	}

	Node* del(Node* node, Key key) {
		return nullptr;
	}

	Node* deleteMin(Node* node) {
		return nullptr;
	}

	Node* deleteMinRef(Node* node) {
		return nullptr;
	}

	Node* deleteMax(Node* node) {
		return nullptr;
	}

	Size rank(Node* node, Key key) const {
		return 0;
	}


	Node* select(Node* node, Size rank) const {
		return nullptr;
	}

	Node* min(Node* node) const {
		return nullptr;
	}

	Node* max(Node* node) const {
		return nullptr;
	}

	Node* floor(Node* node, Key key) const {
		return nullptr;
	}

	Node* ceiling(Node* node, Key key) const {
		return nullptr;
	}

	Size size(Node* node) const {
		return 0;
	}

	void keys(Node* node, array::Array<Key>& arr, Key from, Key to) const {
	}
	Node* root;
};
}
