#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

#include <algorithm>
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

		if (root) {
			root->color = Node::BLACK;
		}
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

	bool balanced() const {
		Paths paths;
		if (!balanced(root, 0, paths)) {
			return false;
		}

		if (paths.is_empty()) return true;

		return std::all_of(
			paths.cbegin(),
			paths.cend(),
			[&paths](auto item){ return paths[0] == item; }
		);
	}

private:
	using Paths = array::Array<int>;

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

	};


	bool is_red(Node* node) const {
		return node ? node->color : false;
	}

	void put(Node** node, Key key, Value value) {
		if (*node == nullptr) {
			*node = new Node{key, value, nullptr, nullptr, 1, Node::RED};
			return;
		}

		if (key == (*node)->key) {
			(*node)->value = value;
			return;
		}

		if (key < (*node)->key) put(&((*node)->left), key, value);
		else put(&((*node)->right), key, value);

		(*node)->size = 1 + size((*node)->left) + size((*node)->right);

		if (!is_red((*node)->left) && is_red((*node)->right)) {
			*node = rotate_left(*node);
		}

		if (is_red((*node)->left) && is_red((*node)->left->left)) {
			*node = rotate_right(*node);
		}

		if (is_red((*node)->left) && is_red((*node)->right)) {
			flip_colors(*node);
		}
	}

	void flip_colors(Node* node) const {
		node->left->color = Node::BLACK;
		node->right->color = Node::BLACK;
		node->color = Node::RED;
	}

	Node* rotate_left(Node* node) {
		auto* x{node->right};
		node->right = x->left;
		x->left = node;

		x->color = node->color;
		node->color = Node::RED;

		node->size = 1 + size(node->left) + size(node->right);
		x->size = 1 + size(x->left) + size(x->right);

		return x;
	}

	Node* rotate_right(Node* node) {
		auto* x{node->left};
		node->left = x->right;
		x->right = node;

		x->color = node->color;
		node->color = Node::RED;

		node->size = 1 + size(node->left) + size(node->right);
		x->size = 1 + size(x->left) + size(x->right);

		return x;
	}

	Node* get(Node* node, Key key) const {
		if (node == nullptr) return nullptr;

		if (node->key == key) return node;

		if (key < node->key) return get(node->left, key);

		return get(node->right, key);
	}

	Node* del(Node* node, Key key) {
		if (key < node->key) {
			if (is_red(node->left) || is_red(node->left->left)) {
				node->left = del(node->left, key);
				return balance(node);
			}

			if (node->right && is_red(node->right->left)) {
				node->right = rotate_right(node->right);
				node = rotate_left(node);
				node->left = del(node->left, key);
				return balance(node);
			}

			if (node->left && node->right) {
				flip_colors_on_delete(node);
			}

			node->left = del(node->left, key);
			return balance(node);
		} else if (node->key < key) {
			auto node_is_3node{is_red(node->left) && !is_red(node->right)};
			auto right_child_is_3node{node->right && is_red(node->right->left)};
			if (node_is_3node) {
				auto middle_child_is_3node{node->left->right && is_red(node->left->right->left)};

				if (!middle_child_is_3node && !right_child_is_3node) {
					node = rotate_right(node);
					flip_colors_on_delete(node->right);
					node->right = del(node->right, key);
					return balance(node);
				}

				if (middle_child_is_3node && !right_child_is_3node) {
					node->left = rotate_left(node->left);
					node = rotate_right(node);
					node->right = rotate_left(node->right);
					node->right->color = Node::BLACK;
					node->left->right->color = Node::BLACK;

					node->right = del(node->right, key);
					return balance(node);
				}
			}

			auto node_is_4node{is_red(node->left) && is_red(node->right)};
			if (node_is_4node) {
				node->right = del(node->right, key);	
				return balance(node);
			}

			auto left_child_is_3node{node->left && is_red(node->left->left)};
			if (left_child_is_3node && right_child_is_3node) {
				node->right = del(node->right, key);
				return balance(node);
			}

			if (is_red(node->left) || is_red(node->left->left)) {
				node = rotate_right(node);
				node->right = rotate_left(node->right);
			}
			node->right = del(node->right, key);
			return balance(node);
		}

		if (node->left) {
			auto* x{node};
			node = node->left;
			node->color = x->color;

			node->right = x->right;

			delete_node(x);

			if (node->left && node->right) {
				flip_colors(node);
			}

			return balance(node);
		}

		return delete_node(node);
	}

	Node* deleteMin(Node* node) {
		if (!node->left) {
			return delete_node(node);
		}

		if (!is_red(node->left) && !is_red(node->left->left)) {
			flip_colors_on_delete(node);

			if (is_red(node->right->left)) {
				node->right = rotate_right(node->right);
				node = rotate_left(node);
			}
		}

		node->left = deleteMin(node->left);
		return balance(node);
	}

	Node* delete_node(Node* node) {
		delete node;
		return nullptr;
	}

	void flip_colors_on_delete(Node* node) const {
		node->color = Node::BLACK;
		node->left->color = Node::RED;
		node->right->color = Node::RED;
	}

	Node* balance(Node* node) {
		if (is_red(node->right)) {
			node = rotate_left(node);
		}

		if (is_red(node->left) && is_red(node->left->left)) {
			node = rotate_right(node);
			flip_colors(node);
		}

		if (!node->left && (node->right && is_red(node->right->left))) {
			node->right = rotate_right(node->right);
			node = rotate_left(node);
			flip_colors(node);
		}

		return node;
	}

	Node* deleteMinRef(Node* node) {
		return nullptr;
	}

	Node* deleteMax(Node* node) {
		if (!node->right) {
			if (node->left) {
				node = rotate_right(node);
				node->right = deleteMax(node->right);
				return node;
			}
			return delete_node(node);
		}

		if (is_red(node->left)) {
			node = rotate_right(node);
			node->right = deleteMax(node->right);
			return balance(node);
		}

		if (node->left) {
			flip_colors_on_delete(node);
			if (is_red(node->left->left)) {
				node = rotate_right(node);
			}
		}

		node->right = deleteMax(node->right);
		return balance(node);
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
		if (!node) return 0;
		return node->size;
	}

	void keys(Node* node, array::Array<Key>& arr, Key from, Key to) const {
	}

	bool balanced(Node* node, int counter, Paths& paths) const {
		if (node == nullptr) {
			paths.push_back(counter);
			return true;
		}

		auto node_is_3node{node->left && is_red(node->left)};
		if (node_is_3node) {
			auto has_left_child{node->left->left};
			auto has_middle_child{node->left->right};
			auto has_right_child{node->right};

			auto childless_3node{!has_left_child && !has_middle_child && !has_right_child};
			auto fertile_3node{has_left_child && has_middle_child && has_right_child};

			auto is_valid_3node{childless_3node || fertile_3node};

			if (!is_valid_3node) {
				return false;
			}
		}

		if (node->right && !node->left) {
			return false;
		}

		if (is_red(node->left) && is_red(node->left->left)) {
			return false;
		}

		if (is_red(node->right)) {
			return false;
		}

		if (!is_red(node)) {
			counter += 1;
		}

		auto b{balanced(node->left, counter, paths)};
		if (!b) return false;

		return balanced(node->right, counter, paths);
	}

	Node* root{nullptr};
};
}
