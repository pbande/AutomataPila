#include <string>
#include <vector>

class State;
class Transition;
class Stack;

struct ap_info {
  State* now;
  std::string tape;
  Stack* stack;
  std::vector<Transition*> transitions;

  ap_info(State* now_, std::string tape_, Stack* stack_, std::vector<Transition*> t_) {
    now = now_;
    tape = tape_;
    stack = stack_;
    transitions = t_;
  }
};