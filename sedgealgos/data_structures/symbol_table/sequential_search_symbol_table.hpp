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

	Value get(Key key) {
		auto curr{head};
		
		while (curr != nullptr) {
			if (curr->key == key) {
				return curr->value;
			}
			curr = curr->next;
		}

		return {};
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
