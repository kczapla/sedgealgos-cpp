#include "sedgealgos/io/in.hpp"
#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/data_structures/bag/random_bag.hpp"

using namespace sedgealgos::io;
using namespace sedgealgos::stack;

int main() {
    In in{};
    StdOut std_out{};

    sedgealgos::data_structures::bag::RandomBag<int> bag;

    std_out.print("input> ");
    while (int a{in.read_int()}) {
        bag.add(a);

        std_out.print("{ ");
        for (auto i : bag) {
            std_out.printf("%d ", i);
        }
        std_out.print("}\n");
        std_out.print("input> ");
    }
    return 0;
}
