#include "sedgealgos/io/in.hpp"

#include <fstream>
#include <iostream>

namespace sedgealgos::io {

In::In(std::string s) : filename{std::move(s)}, is{filename} {}

bool In::is_empty() {
    return is.peek() == std::ifstream::traits_type::eof();
}

void In::close() {
    is.close();
}

int In::read_int() {
    if (is_empty()) {
        throw InException{"Input reached eof"};
    }
    int a;
    is >> a;
    return a;
}

double In::read_double() {
    if (is_empty()) {
        throw InException{"Input reached eof"};
    }
    double a;
    is >> a;
    return a;
}
}
