#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

#include <stdexcept>

namespace sedgealgos::data_structures::symbol_table {

template <typename Key, typename Value>
class BinarySearchTree {
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
		return Key{};
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
		return 0;
	}

	bool contains(Key key) const {
		auto const node{get(root, key)};

		return node ? true : false;
	}

	array::Array<Key> keys() const {
		array::Array<Key> arr;
		keys(root, arr);
		return arr;
	}

	array::Array<Key> keys(Key from, Key to) const {
		return array::Array<Key>( 0 );
	}

private:
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;
		Size size;
	};

	void put(Node** node, Key key, Value value) {
		if (!(*node)) {
			*node = new Node{key, value, nullptr, nullptr, 1};
			return;
		}

		if (key < (*node)->key) {
			put(&((*node)->left), key, value);
		} else if ((*node)->key < key) {
			put(&((*node)->right), key, value);
		} else {
			(*node)->value = value;
		}

		(*node)->size = 1 + size((*node)->left) + size((*node)->right);
	}

	Node* get(Node* node, Key key) const {
		if (!node) {
			return node;
		} else if (node->key == key) {
			return node;
		} else if (key < node->key) {
			return get(node->left, key);
		}

		return get(node->right, key);
	}

	Node* del(Node* node, Key key) {
		if (!node) {
			return nullptr;
		}

		if (node->key < key) {
			node->right = del(node->right, key);
			node->size = 1 + size(node->left) + size(node->right);
			return node;
		}

		if (key < node->key) {
			node->left = del(node->left, key);
			node->size = 1 + size(node->left) + size(node->right);
			return node;
		}

		auto node_to_delete{node};
		if (!node->left) {
			auto node_to_return{node->right};

			delete node_to_delete;

			return node_to_return;
		}

		if (!node->right) {
			auto node_to_return{node->left};

			delete node_to_delete;

			return node_to_return;
		}

		node = min(node->right);
		node->left = node_to_delete->left;
		node->right = deleteMinRef(node_to_delete->right);

		node->size = size(node->left) + size(node->right);

		delete node_to_delete;

		return node;
	}

	Node* deleteMin(Node* node) {
		if (!node->left) {
			auto node_to_delete{node};
			auto node_to_return{node->right};
			delete node_to_delete;
			return node_to_return;
		}
		node->left = deleteMin(node->left);
		return node;
	}

	Node* deleteMinRef(Node* node) {
		if (!node->left) {
			return node->right;
		}
		node->left = deleteMin(node->left);
		return node;
	}

	Node* deleteMax(Node* node) {
		if (!node->right) {
			auto node_to_delete{node};
			auto node_to_return{node->left};
			delete node_to_delete;
			return node_to_return;
		}
		node->right = deleteMax(node->right);
		return node;
	}

	Size rank(Node* node, Key key) const {
		if (!node) {
			return 0;
		}

		if (node->key == key) {
			return size(node->left);
		} else if (node->key < key) {
			return size(node->left) + 1 + rank(node->right, key);
		}

		return rank(node->left, key);
	}

	Node* min(Node* node) const {
		if (node->left == nullptr) return node;
		return min(node->left);
	}

	Node* max(Node* node) const {
		if (node->right == nullptr) return node;
		return max(node->right);
	}

	Node* floor(Node* node, Key key) const {
		if (node->key <= key) {
			if (!node->right) {
				return node;
			}

			auto const n{floor(node->right, key)};
			return n ? n : node;
		} else {
			if (!node->left) {
				return nullptr;
			}
			return floor(node->left, key);
		}
	}

	Node* ceiling(Node* node, Key key) const {
		if (!node) {
			return nullptr;
		}
		if (key <= node->key) {
			auto n{ceiling(node->left, key)};
			return n ? n : node; 
		}

		return ceiling(node->right, key);
	}

	Size size(Node* node) const {
		if (!node) {
			return 0;
		}
		return node->size;
	}

	void keys(Node* node, array::Array<Key>& arr) const {
		if (!node) {
			return;
		}

		if (node->left) {
			keys(node->left, arr);
		}

		arr.push_back(node->key);

		if (node->right) {
			keys(node->right, arr);
		}
	}

	Node* root;
};
}
