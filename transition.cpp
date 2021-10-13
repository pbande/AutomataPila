#include "transition.h"

Transition::Transition(State* current_, std::string input_, std::string top, State* next_,  std::vector<std::string> push, int id_) {
  current = current_;
  input = input_;
  stack_pop = top;
  next = next_;
  stack_push = push;
  id = id_;
}

bool Transition::isNull() {
  return (current == NULL || next == NULL);
}

int Transition::getId() {
  return id;
}

void Transition::print() {
  std::cout << id << " (" << current -> getId() << ",";
  for(auto push : stack_push) std::cout << " " << push;
  std::cout << ") ∈ δ(" << next -> getId() << ", " <<
  input << ", " << stack_pop << ")\n";
}


bool Transition::checkAlphabet(Alphabet& tape, Alphabet& stack) {
  bool correct = true;
  for(auto p : stack_push)  
    if(!stack.check(p)) correct = false;
  return (tape.check(input) && stack.check(stack_pop) && (stack_pop != ".") && correct);
}


bool Transition::canTransitate(State* now, Stack* stack, std::string in) {
  if (stack -> empty()) return false; // innnecesario?
    return (now == current && stack_pop == stack -> top() && (input == in) || input == ".");
}

State* Transition::getNext() {
  return next;
}

std::vector<std::string> Transition::getPush() {
  return stack_push;
}

std::string Transition::getInput() {
  return input;
}

bool Transition::consume() {
  return input != ".";
}