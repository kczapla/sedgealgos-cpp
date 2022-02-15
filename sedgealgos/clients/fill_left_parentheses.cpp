#include "sedgealgos/clients/fill_left_parentheses.hpp"

#include <string>

namespace sedgealgos::clients {
  std::string FillLeftParentheses::fill(std::string_view statement) {
      for (auto const c : statement) {
          switch(c) {
              case '/':
              case '*':
              case '-':
              case '+':
                  on_operator_detection(c);
                  break;
              case ')':
                  on_make_expr_from_operands_and_ops();
                  break;
              default:
                  on_operand_detection(c);
                  break;
          }
      }

      return expressions.pop();
  }

  void FillLeftParentheses::on_operator_detection(char const c) {
      operators.push(c);
  }

  void FillLeftParentheses::on_operand_detection(char const c) {
      operands.push(c);
  }

  void FillLeftParentheses::on_make_expr_from_operands_and_ops() {
    stack::LinkedListStack<char> reverted_expression{};
    reverted_expression.push(')');
    while(!operators.is_empty()) {
      reverted_expression.push(operands.pop());
      reverted_expression.push(operators.pop());
    }
    reverted_expression.push(operands.pop());
    reverted_expression.push('(');

    std::string new_expression{};
    while(!reverted_expression.is_empty()) {
        new_expression.push_back(reverted_expression.pop());
    }

    expressions.push(new_expression);
  }
}
