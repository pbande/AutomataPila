#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include "state.h"
#include "alphabet.h"
#include "stack.h"

class Transition {
 private:
  State* current;
  State* next;
  std::string input;
  std::string stack_pop;
  std::vector<std::string> stack_push;
  int id;
 public:
  Transition();
  Transition(State*, std::string, std::string, State*, std::vector<std::string>, int);
  ~Transition();
  bool isNull();
  void print();
  int getId();
  bool checkAlphabet(Alphabet&, Alphabet&);
  bool canTransitate(State*, Stack*, std::string);
  bool consume();
  State* getNext();
  std::vector<std::string> getPush();
  std::string getInput();
};
#endif