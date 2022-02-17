#include "sedgealgos/stack/linked_list_stack.hpp"

#include <string>
#include <string_view>

namespace sedgealgos::clients {
class FillLeftParentheses {
public:
  std::string fill(std::string_view);

private:
  void on_operator_detection(char c);
  void on_operand_detection(char c);
  void on_close_paren();

  stack::LinkedListStack<char> operands{};
  stack::LinkedListStack<char> operators{};
  stack::LinkedListStack<std::string> expressions{};
};
}
