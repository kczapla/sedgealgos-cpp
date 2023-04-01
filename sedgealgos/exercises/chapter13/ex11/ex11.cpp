#include "sedgealgos/exercises/chapter13/ex11/ex11.hpp"

#include "sedgealgos/stack/linked_list_stack.hpp"

#include <stdexcept>

namespace sedgealgos::exercises::chapter13::ex11 {
    int Ex11::eval(std::string_view s) const {

        stack::LinkedListStack<int> operands;
        stack::LinkedListStack<char> operators;

        for (auto const c : s) {
            switch(c) {
                case ' ':
                    continue;
                case '*':
                case '/':
                case '-':
                case '+': {
                  auto const op1{operands.pop()};
                  auto const op2{operands.pop()};
                  switch(c) {
                      case '+':
                        operands.push(op2 + op1);
                        break;
                      case '-':
                        operands.push(op2 - op1);
                        break;
                      case '*':
                        operands.push(op2 * op1);
                        break;
                      case '/':
                        operands.push(op2 / op1);
                        break;
                      default:
                        throw std::runtime_error{"unsupported operator"};
                  }
                  break;
                }
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9': {
                  operands.push(c - 48);
                  break;
                }
                default:
                    throw std::runtime_error{"unexpected character"};
            }
        }
        return operands.pop();
    }
}

