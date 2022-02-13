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
                  auto const second{operands.pop()};
                  auto const first{operands.pop()};
                  auto const op{operators.pop()};
                  std::string new_expression{};
                  new_expression.push_back('(');
                  new_expression.push_back(first);
                  new_expression.push_back(op);
                  new_expression.push_back(second);
                  new_expression.push_back(')');
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
