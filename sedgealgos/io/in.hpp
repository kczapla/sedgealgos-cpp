#pragma once

#include <string>
#include <fstream>
#include <stdexcept>

namespace sedgealgos::io {
    class InException : public std::runtime_error {
    public:
        InException(std::string s) : runtime_error{std::move(s)} {}
    };

    class In {
    public:
        In();
        In(std::string);

        int read_int();
        double read_double();
        std::string reads_all();

        bool is_empty();

        void close();

    private:
        std::string filename;
        std::ifstream ifs;
        std::istream& is;
    };
}
