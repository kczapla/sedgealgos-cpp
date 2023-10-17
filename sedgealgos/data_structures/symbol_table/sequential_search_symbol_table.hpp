#pragma once

#include <stdexcept>

namespace sedgealgos::data_structures::symbol_table {

template <typename Key, typename Value>
class SequentialSearchSymbolTable {
public:
	bool is_empty() const {
		return head == nullptr;
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
	}

private:
	struct Node {
		Node* next{nullptr};
		Key key;
		Value value;
	};

	Node* head{nullptr};
};
}
