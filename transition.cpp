#include "transition.h"


bool Transition::canTransitate(State* now, Stack* stack, std::string in) {
  if (stack.empty()) return false;
    return (now == current && stack.top() == stack_pop && in == input);
}