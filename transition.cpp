#include "transition.h"

Transition::Transition(State* current_, std::string input_, std::string top, State* next_,  std::vector<std::string> push, int id_) {
  current = current_;
  input = input_;
  stack_pop = top;
  next = next_;
  stack_push = push;
  id = id_;
}

void Transition::print() {
  std::cout << id << " (" << next -> getId() << ",";
  for(auto push : stack_push) std::cout << " " << push;
  std::cout << ") ∈ δ(" << next -> getId() << ", " <<
  input << ", " << stack_pop << ")\n";
}
/*
bool Transition::canTransitate(State* now, Stack* stack, std::string in) {
  if (stack.empty()) return false;
    return (now == current && stack.top() == stack_pop && in == input);
}*/