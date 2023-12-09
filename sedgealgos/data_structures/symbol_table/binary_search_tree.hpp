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
		del(&root, key);
	}

	void deleteMin() {
		deleteMin(&root);
	}

	void deleteMax() {
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

	void del(Node** node, Key key) {
		if (!*node) {
			return;
		}

		if (key < (*node)->key) {
			del(&(*node)->left, key);
			(*node)->size = 1 + size((*node)->left) + size((*node)->right);
			return;
		} else if ((*node)->key < key) {
			del(&(*node)->right, key);
			(*node)->size = 1 + size((*node)->left) + size((*node)->right);
			return;
		}

		auto node_to_del{*node};
		if ((*node)->right) {
			*node = min((*node)->right);
		} else if ((*node)->left) {
			*node = max((*node)->left);
		} else {
			delete *node;
			*node = nullptr;
			return;
		}

		(*node)->left = node_to_del->left;
		(*node)->right = node_to_del->right;
		deleteMinRef(&(node_to_del->right));

		delete node_to_del;
		node_to_del = nullptr;

		(*node)->size = size((*node)->left) + size((*node)->right);
	}

	void deleteMin(Node** node) {
		if (!(*node)) {
			return;
		}

		if ((*node)->left) {
			deleteMin(&((*node)->left));
			(*node)->size = 1 + size((*node)->left) + size((*node)->right);
			return;
		}

		delete *node;
		*node = nullptr;
	}

	void deleteMinRef(Node** node) {
		if (!(*node)->left) {
			*node = nullptr;
			return;
		}
		deleteMinRef(node);
		(*node)->size = 1 + size((*node)->left) + size((*node)->right);

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
