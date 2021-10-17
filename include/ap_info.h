#ifndef AP_INFO_H
#define AP_INFO_H
#include <string>
#include <vector>
#include "stack.h"
#include "state.h"
#include "transition.h"

// estructura para guardar la traza del automata
struct Ap_info {
  State* now;
  std::string tape;
  Stack stack;
  std::vector<Transition*> transitions;

  Ap_info(State*, std::string, Stack, std::vector<Transition*>);
};
#endif 