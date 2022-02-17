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
                  on_close_paren();
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

  void FillLeftParentheses::on_close_paren() {
      if (!operands.is_empty()) {
        std::string expr{')'};
        expr += operands.pop();
        while(!operands.is_empty()) {
          expr += operators.pop();
          expr += operands.pop();
        }
        expr += '(';
        expressions.push(std::string{expr.rbegin(), expr.rend()});

        return;
      }

      auto const second{expressions.pop()};
      auto const first{expressions.pop()};

      std::string expr{'('};
      expr += first;
      expr += operators.pop();
      expr += second;
      expr += ')';

      expressions.push(expr);
  }
}
