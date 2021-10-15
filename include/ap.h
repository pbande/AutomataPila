#ifndef AP_H
#define AP_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>

#include <vector>
#include "state.h"
#include "stack.h"
#include "transition.h"
#include "ap_info.h"

class AP {
 private:
  Alphabet E;
  std::vector<State*> States;
  Stack stack;
  State* initial_state;
  std::vector<Transition*> transitions;
  std::string tape;
  State* currentState;

 public:
  AP();
  AP(std::string);
  ~AP();
  void readData(std::string);
  void checkData();
  void showInfo();
  std::vector<std::string> splitLine(std::string);
  State* findState(std::string);
  std::vector<Transition*> possibleMoves(State*);
  void transit(Transition*);
  void run(std::string);
  void restore(Ap_info*);
  void reset();
  void printTraza(Ap_info*);
};
#endif