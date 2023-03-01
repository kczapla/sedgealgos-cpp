#include "sedgealgos/io/in.hpp"
#include "sedgealgos/io/std_out.hpp"

int main(int argc, char** argv) {
    sedgealgos::io::StdOut out;
    if (argc != 2) {
        out.println("please provide path to the file with numbers"); 
    }

    sedgealgos::io::In in{argv[1]};
    auto const ints{in.read_ints()};

    return 0;
}
