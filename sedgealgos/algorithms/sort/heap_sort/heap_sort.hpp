#pragma once

namespace sedgealgos::algorithms::sort::heap_sort {

namespace {
void sink(auto& c, long unsigned int i, long unsigned int n) {
	while(i * 2 <= n) {
		auto j{i * 2};
		if (j < n && c[j - 1] < c[j]) j++;
		if (c[j-1] < c[i-1]) break;

		std::swap(c[i-1], c[j-1]);

		i = j;
	}
}
}

template <typename Container>
void sort(Container& c) {
	auto n{static_cast<int>(c.size())};

	if (n < 2) {
		return;
	}

	for (int i{n/2}; 1 <= i; i--) {
		sink(c, i, n);
	}

	while (n > 0) {
		std::swap(c[0], c[--n]);
		sink(c, 1, n);
	}
}
}

