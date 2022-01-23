#include "sedgealgos/io/in.hpp"

#include <fstream>
#include <iostream>
#include <iterator>

namespace sedgealgos::io {

In::In() : is{std::cin} {}

In::In(std::string s) : filename{std::move(s)}, ifs{filename}, is{ifs} {}

bool In::is_empty() {
    return is.peek() == std::ifstream::traits_type::eof();
}

void In::close() {
    ifs.close();
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

std::string In::reads_all() {
    if (is_empty()) {
      return "";
    }

    std::string all(std::istreambuf_iterator<char>(is), {});
    return all;
}
}
