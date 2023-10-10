#include "sedgealgos/io/in.hpp"
#include "sedgealgos/io/std_out.hpp"

#include <filesystem>

using namespace sedgealgos::io;

int main(int argc, char** argv) {
	StdOut std_out{};
	if (argc != 3) {
		std_out.printf("got %d args but expected %d\n", argc - 1, 2);
		return 1;
	}

	int minLen{std::stoi(argv[1])};
	auto pathToDatafile{argv[2]};

	In in{pathToDatafile};
	while (!in.is_empty()) {
		auto word{in.read_string()};
		if (static_cast<int>(word.size()) < minLen) continue;
		std_out.println(word);
	}
}
