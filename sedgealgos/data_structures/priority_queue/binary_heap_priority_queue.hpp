#pragma once

#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::data_structures::priority_queue {
template <typename T, typename Container, typename Compare>
class BinaryHeapPriorityQueue {
public:
	using container = Container;

	BinaryHeapPriorityQueue(unsigned int size) : heap_size{0}, heap_capacity{size}, c(size) {};

	BinaryHeapPriorityQueue(Container container)
		: BinaryHeapPriorityQueue(container.size() + static_cast<Container::Size>(1)) {
		
		for (auto&& elem : container) {
			this->insert(elem);
		}
	};

	void insert(T item) {
		c[++heap_size] = item;
		swim(heap_size);
	};

	T const& top() const { return this->c[1]; };

	T pop() { 
		return this->c[heap_size--];
	};

	bool empty() { return false; }

	unsigned int size() const { return 0; };

private:
	unsigned long heap_size;
	unsigned long heap_capacity;
	container c;

	void swim(unsigned long i) {
		while(i > 1) {
			auto const parent{i/2};
			std::swap(c[parent], c[i]);
			i = parent;
		}
	}
};

template <typename T>
using MaxBinaryHeapPriorityQueue = BinaryHeapPriorityQueue<T, array::Array<T>, std::less<T>>;
}
