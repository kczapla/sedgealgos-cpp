#include "sedgealgos/clients/infix_to_postfix_converter.h"
#include "sedgealgos/stack/linked_list_stack.hpp"

#include <string>

namespace sedgealgos::clients {
std::string InfixToPostfixConverter::convert(std::string s) {
  stack::LinkedListStack<char> operands;
  stack::LinkedListStack<char> operators;
  std::string expression;

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

  while (!operators.is_empty()) {
    std::string expr{'('};
    if (expression.empty()) {
      auto const second{operands.pop()};
      auto const first{operands.pop()};
      expr += first;
      expr += ' ';
      expr += second;
      expr += ' ';
      expr += operators.pop();
      expr += ')';
      expression = expr;
      continue;
    }
    expr += operands.pop();
    expr += ' ';
    expr += expression;
    expr += ' ';
    expr += operators.pop();
    expr += ')';

    expression = expr;
  }

  return expression;
}
}
