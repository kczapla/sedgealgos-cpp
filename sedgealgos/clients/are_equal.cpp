#include "sedgealgos/io/in.hpp"
#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/algorithms/two_sum/are_equal.hpp"

int main(int argc, char** argv) {
    sedgealgos::io::StdOut out;
    if (argc != 2) {
        out.println("please provide path to the file with numbers"); 
        return 1;
    }

    sedgealgos::io::In in{argv[1]};
    auto const ints{in.read_ints()};
    
    sedgealgos::algorithms::two_sum::AreEqual are_equal{};
    auto const equal_elems{are_equal.count(ints)};

    out.printf("there are %d equal elements\n", equal_elems);

    return 0;
}
