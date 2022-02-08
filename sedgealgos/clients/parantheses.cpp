#include "sedgealgos/io/in.hpp"
#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/stack/resizing_array_stack.hpp"

using namespace sedgealgos::io;
using namespace sedgealgos::stack;

int main() {
    In in{};
    StdOut std_out{};

    std_out.print("input>\n");
    auto const input{in.reads_all()};
    
    ResizingArrayStack<char> stack{};
    for (auto const c : input) {
        switch(c) {
            case '{':
            case '(':
            case '[':
                stack.push(c);
                break;
            case '}':
                if (stack.pop() != '{') {
                    return 1;
                }
                break;
            case ')':
                if (stack.pop() != '(') {
                    return 1;
                }
                break;
            case ']':
                if (stack.pop() != '[') {
                    return 1;
                }
                break;
            default:
                break;
        }
    }
    if (!stack.is_empty()) {
        return 1;
    }
    std_out.println("No issues with parantheses.");
    return 0;
}
