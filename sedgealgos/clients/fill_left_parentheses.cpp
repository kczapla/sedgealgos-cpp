#include "sedgealgos/stack/linked_list_stack.hpp"
#include "sedgealgos/clients/fill_left_parentheses.hpp"

#include <string>

namespace sedgealgos::clients {
  std::string FillLeftParentheses::fill(std::string_view statement) const {
      stack::LinkedListStack<char> operands{};
      stack::LinkedListStack<char> operators{};
      stack::LinkedListStack<std::string> expressions{};

      for (auto const c : statement) {
          switch(c) {
              case '/':
              case '*':
              case '-':
              case '+':
                  operators.push(c);
                  break;
              case ')':
                  {
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
                  break;
              default:
                  operands.push(c);
                  break;
          }
      }

      return expressions.pop();
  }
}
