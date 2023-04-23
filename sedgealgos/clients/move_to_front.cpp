#include "sedgealgos/data_structures/linked_list/single_linked_list.hpp"
#include "sedgealgos/io/in.hpp"
#include "sedgealgos/io/std_out.hpp"

using namespace sedgealgos::data_structures::linked_list;
using namespace sedgealgos::io;

int main() {
    In in{};
    StdOut std_out{};

    SingleLinkedList<char> sll;

    std_out.print("n > ");
    while (char n{in.read_char()}) {
        if (find(sll, n)) {
            remove(sll, n);
        }
        sll.push_front(n);

        std_out.print("{ ");
        for (auto i : sll) {
            std_out.printf("%d ", i);
        }
        std_out.print("}\n");

        std_out.print("n > ");
    }


    return 0;
}
