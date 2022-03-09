#include "sedgealgos/clients/infix_to_postfix_converter.h"
#include "sedgealgos/stack/linked_list_stack.hpp"

#include <string>

namespace sedgealgos::clients {
std::string InfixToPostfixConverter::convert(std::string s) {
  stack::LinkedListStack<char> operands;
  stack::LinkedListStack<char> operators;

  for (auto const c : s) {
    switch(c) {
      case '-':
      case '+':
      case '*':
      case '/':
        operators.push(c);
        break;
      default:
        operands.push(c);
        break;
    }
  }

  auto const second{operands.pop()};
  auto const first{operands.pop()};

  std::string expr{'('};
  expr += first;
  expr += ' ';
  expr += second;
  expr += ' ';
  expr += operators.pop();
  expr += ')';

  return expr;
}
}
