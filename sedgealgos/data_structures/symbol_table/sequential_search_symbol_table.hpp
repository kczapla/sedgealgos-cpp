#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

#include <stdexcept>

namespace sedgealgos::data_structures::symbol_table {

template <typename Key, typename Value>
class SequentialSearchSymbolTable {
public:
	using Size = unsigned long long;

	SequentialSearchSymbolTable() : number_of_elements{0} {}

	bool is_empty() const {
		return head == nullptr;
	}

	Size size() const {
		return number_of_elements;
	}

	bool contains(Key key) const {
		auto curr{head};
		while (curr != nullptr) {
			if (curr->key == key) {
				return true;
			}

			curr = curr->next;
		}

		return false;
	}

	void put(Key key, Value value) {
		++number_of_elements;

		Node* prev{nullptr};
		auto curr{head};
		while(curr != nullptr) {
			if (curr->key == key) {
				curr->value = value;
				return;
			}
			prev = curr;
			curr = curr->next;
		}

		Node* n{new Node};
		n->key = key;
		n->value = value;
		n->next = nullptr;

		if (head == nullptr) {
			head = n;
			return;
		}

		prev->next = n;
	}

	Value& get(Key key) {
		auto curr{head};
		
		while (curr != nullptr) {
			if (curr->key == key) {
				return curr->value;
			}
			curr = curr->next;
		}

		throw std::out_of_range{"key not found"};
	}

	void del(Key key) {
		delete head;
		head = nullptr;

		number_of_elements--;
	}

	array::Array<Key> keys() const {
		array::Array<Key> arr{};
		auto curr{head};
		while (curr != nullptr) {
			arr.push_back(curr->key);
			curr = curr->next;
		}

		return arr;
	}

private:
	struct Node {
		Node* next{nullptr};
		Key key;
		Value value;
	};

	Size number_of_elements{};
	Node* head{nullptr};
};
}
