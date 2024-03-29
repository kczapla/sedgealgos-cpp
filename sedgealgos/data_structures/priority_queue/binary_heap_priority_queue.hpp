#pragma once

#include <iostream>
#include "sedgealgos/data_structures/array/array.hpp"

namespace sedgealgos::data_structures::priority_queue {
template <typename T, typename Container, typename Compare>
class BinaryHeapPriorityQueue {
public:
	using container = Container;

	BinaryHeapPriorityQueue(unsigned int size) : heap_size{0}, heap_capacity{size}, c(size+1) {};

	BinaryHeapPriorityQueue(Container container)
		: BinaryHeapPriorityQueue(container.size() + static_cast<Container::Size>(1)) {
		
		for (auto&& elem : container) {
			insert(elem);
		}
	};

	void insert(T item) {
		c[++heap_size] = item;
		swim(heap_size);
	};

	T const& top() const { return c[1]; };

	T pop() { 
		std::swap(c[1], c[heap_size]);

		auto const top{c[heap_size--]};
		sink(1);

		return top;
	}

	bool empty() { return heap_size == 0; }

	unsigned int size() const { 
		return heap_size;
	}

private:
	unsigned long heap_size;
	unsigned long heap_capacity;
	container c;

	void swim(unsigned long i) {
		while(i > 1) {
			auto const parent{i/2};
			if (Compare{}(c[i], c[parent])) break;
			std::swap(c[parent], c[i]);
			i = parent;
		}
	}

	void sink(unsigned long i) {
		while(i * 2 <= heap_size) {
			auto j{i * 2};
			
			if (j < heap_size && Compare{}(c[j], c[j+1])) ++j;
			if (!Compare{}(c[i], c[j])) break;

			std::swap(c[i], c[j]);

			i = j;
		}
	}
};

template <typename T>
using MaxBinaryHeapPriorityQueue = BinaryHeapPriorityQueue<T, array::Array<T>, std::less<T>>;

template <typename T>
using MinBinaryHeapPriorityQueue = BinaryHeapPriorityQueue<T, array::Array<T>, std::greater<T>>;
}
