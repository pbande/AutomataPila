#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
// #include "alphabet.cpp"
// #include "state.cpp"
#include "stack.cpp"
#include "transition.cpp"
#include "struct.hpp"

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
  void restore(ap_info*);
  void reset();
  void printTraza(ap_info*);
};