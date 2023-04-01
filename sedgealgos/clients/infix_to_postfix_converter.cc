#include "sedgealgos/clients/infix_to_postfix_converter.h"
#include "sedgealgos/stack/linked_list_stack.hpp"

#include <string>
#include <iostream>

namespace sedgealgos::clients {
std::string InfixToPostfixConverter::convert(std::string s) {
  stack::LinkedListStack<std::string> operands;
  stack::LinkedListStack<char> operators;

  for (auto const c : s) {
    switch(c) {
      case '*':
      case '/':
        operators.push(c);
        break;
      case '-':
      case '+': {
        if (operators.is_empty()) {
            operators.push(c);
            continue;
        }
        if (operators.peek() == '-' || operators.peek() == '+') {
            auto const op1{operands.pop()};
            auto const op2{operands.pop()};
            operands.push(op2 + " " + op1 + " " + operators.pop());
        }
        operators.push(c);
        break;
      }
      default: {
        operands.push(std::string{c});
        if (operators.is_empty()) {
            continue;
        }
        if (operators.peek() == '*' || operators.peek() == '/') {
            auto const op1{operands.pop()};
            auto const op2{operands.pop()};
            operands.push(op2 + " " + op1 + " " + operators.pop());
        }
        break;
      }
    }
  }

  auto const op1{operands.pop()};
  if (operands.is_empty()) {
      return op1;
  }

  auto const op2{operands.pop()};
  operands.push(op2 + " " + op1 + " " + operators.pop());

  return operands.pop();
}
}
