#include "sedgealgos/io/in.hpp"

#include <fstream>

namespace sedgealgos::io {

In::In(std::string s) : filename{std::move(s)}, is{filename} {}

bool In::is_empty() {
    return is.peek() == std::ifstream::traits_type::eof();
}

void In::close() {
}
}
