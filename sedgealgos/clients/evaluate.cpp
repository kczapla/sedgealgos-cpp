#include "sedgealgos/io/in.hpp"
#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/stack/resizing_array_stack.hpp"

using namespace sedgealgos::io;
using namespace sedgealgos::stack;

class Evaluator {
public:
    using ValStack = ResizingArrayStack<int>;
    using OpStack = ResizingArrayStack<char>;

    double evaluate(std::string const& expression) {
        operators = OpStack{};
        values = ValStack{};

        for (auto const c : expression) {
            process_char(c);
        }

        return values.pop();
    }

private:
    void process_char(char const c) {
        switch(c) {
            case ')':
                process_operator();
            case '(':
                break;
            case '-':
            case '+':
            case '*':
            case '/':
                operators.push(c);
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                values.push(c - '0');
                break;
        }
    }

    void process_operator() {
        auto const val2{values.pop()};
        auto const val1{values.pop()};
        auto const op{operators.pop()};
        switch(op) {
            case '/':
                values.push(val1 / val2);
                break;
            case '-':
                values.push(val1 - val2);
                break;
            case '+':
                values.push(val1 + val2);
                break;
            case '*':
                values.push(val1 * val2);
                break;
        }
    }

    OpStack operators{};
    ValStack values{};
};

int main() {
    In in{};
    StdOut std_out{};

    std_out.print("expression>\n");
    auto const input{in.reads_all()};

    Evaluator evaluator{};
    auto const no{evaluator.evaluate(input)};
    std_out.printf("result> %d\n", no);
    
    return 0;
}
