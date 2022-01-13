#include "sedgealgos/io/std_out.hpp"

#include <string>
#include <iostream>

namespace sedgealgos::io {

StdOut::StdOut() : os{std::cout} {}

StdOut::StdOut(std::string s) : ofs{s}, os{ofs} {}

void StdOut::print(std::string const& s) {
    os << s;
}

void StdOut::println() {
    os << "\n";
}

void StdOut::println(std::string const& s) {
    print(s);
    println();
}

void StdOut::printf(std::string s) {
    print(s);
}

void StdOut::close() {
    ofs.close();
}
}
