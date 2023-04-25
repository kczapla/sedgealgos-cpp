#pragma once

template <typename Stack>
Stack copy(Stack const& stack) {
  Stack tmp;

  for (auto const& s : stack) {
    tmp.push(s);
  }

  Stack new_stack;
  for (auto const& t : tmp) {
    new_stack.push(t);
  }

  return new_stack;
}
