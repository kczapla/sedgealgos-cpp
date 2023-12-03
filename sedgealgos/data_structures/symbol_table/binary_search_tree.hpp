#pragma once

namespace sedgealgos::data_structures::symbol_table {

template <typename Key, typename Value>
class BinarySearchTree {
public:
	using Size = unsigned long long;

	void put(Key key, Value value) {
		put(root, key, value);
	}

	Value get(Key key) const {
		auto const node{get(root, key)};
		if (!node) {
			throw std::out_of_range{"given key does not exist"};
		}
		return node->value;
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

	bool contains(Key key) const {
		auto const node{get(root, key)};

		return node ? true : false;
	}

private:
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;
		Size size;
	};

	void put(Node* node, Key key, Value value) {
		if (!node) {
			node = new Node{key, value, nullptr, nullptr, 1};
			return;
		}

		if (key < node->key) {
			put(node->left, key, value);
		} else if (node->key < key) {
			put(node->right, key, value);
		} else {
			node->value = value;
		}

		node->size = 1 + size(node->left) + size(node->right);
	}

	Node* get(Node* node, Key key) const {
		if (!node) {
			return node;
		} else if (node->key == key) {
			return node;
		} else if (key < node->key) {
			return get(node->left, key);
		} else if (node->key < key) {
			return get(node->right, key);
		}
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
			return n ? n : node
		} else {
			if (!node->left) {
				return nullptr;
			}
			return floor(node->left, key);
		}
	}

	Node* ceiling(Node* node) const {
		if (key <= node->key) {
			if (!node->left) {
				return node;
			}

			auto const n{ceiling(node, key)};
			return n ? n : node;
		}
		if (node->right) {
			return celing(node->right, key);
		}
		return nullptr;
	}

	Size size(Node* node) const {
		if (!node) {
			return 0;
		}
		return node->size;
	}

	Node* root;
};
}
