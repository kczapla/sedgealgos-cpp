#pragma once

namespace sedgealgos::data_structures::symbol_table {

template <typename Key, typename Value>
class SequentialSearchSymbolTable {
public:
	bool is_empty() const {
		return head == nullptr;
	}

	void put(Key key, Value value) {
		Node* n{new Node};
		n->key = key;
		n->value = value;

		if (head == nullptr) {
			head = n;
			return;
		}
		head->next = n;
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
