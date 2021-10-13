#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// #include "alphabet.cpp"
// #include "state.cpp"
#include "stack.cpp"
#include "transition.cpp"

class AP {
 private:
  Alphabet E;
  std::vector<State*> States;
  Stack stack;
  State* initial_state;
  std::vector<Transition*> transitions;
  std::string tape;

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
  State* transit(Transition*);
  void run(std::string);
};
