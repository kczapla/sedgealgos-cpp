#pragma once

#include <string>
#include <fstream>

namespace sedgealgos::io {
    class In {
    public:
        In(std::string);

        int readInt();
        double readDouble();

        bool is_empty();

        void close();

    private:
        std::string filename;
        std::ifstream is;
    };
}
