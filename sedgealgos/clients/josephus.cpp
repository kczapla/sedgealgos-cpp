#include "sedgealgos/data_structures/queue/queue.hpp"
#include "sedgealgos/io/in.hpp"
#include "sedgealgos/io/std_out.hpp"

using namespace sedgealgos::io;

int main() {
    In in{};
    StdOut std_out{};

    std_out.print("n > ");
    int n{in.read_int()};

    std_out.print("m > ");
    int m{in.read_int()};

    sedgealgos::data_structures::queue::Queue<int> q;

    auto next_jump{m - 1};
    auto jumps{1};

    q.enqueue(next_jump);

    while (jumps != n) {
        next_jump = (next_jump + m) % n;
        q.enqueue(next_jump);
        jumps++;
    }

    while (!q.is_empty()) {
        std_out.printf("%d ", q.dequeue());
    }

    std_out.println();

    return 0;
}
